#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <CodeParser.h>
#include <CodeTranslator.h>

// operator overlord
std::string operator<<(CodeParser& cp, std::string input){
    cp = input;
    return (cp.getCommand() + " " +  cp.getStack() + " " + cp.getArgument() + " ");
}

// operator overlord
void operator<<(CodeTranslator& ct, CodeParser& cp){
    ct.setCommand(cp.getCommand());
    ct.setStack(cp.getStack());
    ct.setArg(cp.getArgument());
}

// operator overlord
std::ostream & operator <<(std::ostream & out, CodeTranslator& ct){

    return out << ct.getTranslatedCode();
}

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

    CodeParser codeParser;
    CodeTranslator codeTrans(srcFileName.substr(0,exetensionPos));

    // filter line of code
    while (getline(inputFile, temp))
    {
        codeParser << temp;

        codeTrans << codeParser;

        // int k = 1;
        // for(auto &lineOfCode: code){
        //     SetConsoleTextAttribute(hConsole, k);
        //     std::cout << lineOfCode << " ";
        //     k++;
        // }
        
        if(codeParser.getCommand() == "")
            continue;

        outputFile << "// " << codeParser.getCommand() << " " << codeParser.getStack() << " " << codeParser.getArgument() << "\n";
        
        if(codeParser.getCommand() != ""){
            outputFile << codeTrans;
        }

        SetConsoleTextAttribute(hConsole, 1);
        std::cout << codeParser.getCommand() << " ";
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << codeParser.getStack() << " ";
        SetConsoleTextAttribute(hConsole, 3);
        std::cout << codeParser.getArgument() << " ";        
        std::cout << "\n";
        




        //std::cout << temp << "\r\n";
    }
    
    // close file streams
    inputFile.close();
    outputFile.close();
    return 0;
}