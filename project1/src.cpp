#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>


int main(int argc, char** argv){

    // check if src file is given
    if(argc <2){
        std::cerr << "no file given";
        return -1;
    }

    // get fileNames
    std::string srcFileName = argv[1], outputFileName; 
    
    // change extension to asm
    size_t exetensionPos = srcFileName.find("vm", 0);
    outputFileName = srcFileName.substr(0,exetensionPos) + "asm";

    // change color of output
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // open src file and create new file
    std::ifstream inputFile(srcFileName);
    std::ofstream outputFile(outputFileName);

    if(!inputFile)
    {
        std::cerr << "could not open src file";
        return -1;
    } else if(!outputFile){
        std::cerr << "could not create output file";
        return -1;
    } 

    std::string temp;

    // filter line of code
    while (getline(inputFile, temp))
    {
        // cuts off the comments
        temp = temp.substr(0, temp.find("//",0));

        // remove double spaces, repeat until there are no longer double spaces
        std::size_t doubleSpace = temp.find("  ");

        while (doubleSpace != std::string::npos)
        {
            temp.erase(doubleSpace, 1);
            doubleSpace = temp.find("  ");
        }

        if(temp.length()<2){
            continue;
        }

        // place holder for code
        std::vector<std::string> code;

        outputFile << "//" << temp << "\n";

        

        while (temp.length()>=1)
        {
            std::size_t delimiter = temp.find(" ");

            if(delimiter == std::string::npos)
                delimiter = temp.length();

            code.push_back(temp.substr(0, delimiter));
            temp.erase(0, delimiter+1);
        }

        int k = 1;
        for(auto &lineOfCode: code){
            SetConsoleTextAttribute(hConsole, k);
            std::cout << lineOfCode << " ";
            k++;
        }
        std::cout << "\r\n";
        




        //std::cout << temp << "\r\n";
    }
    
    // close file streams
    inputFile.close();
    outputFile.close();
    return 0;
}