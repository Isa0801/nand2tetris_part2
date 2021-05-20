#include <CodeParser.h>


CodeParser::CodeParser(){

}

CodeParser::~CodeParser(){

}


std::string CodeParser::getCommand(){
    return command;
}

std::string CodeParser::getStack(){
    return stack;
}

std::string CodeParser::getArgument(){
    return argument;
}

// convert string to standard foramt
std::string CodeParser::cvrtToStd(std::string lineOfCode){
    // cuts off the comments
    lineOfCode = lineOfCode.substr(0, lineOfCode.find("//",0));

    // remove double spaces, repeat until there are no longer double spaces
    std::size_t doubleSpace = lineOfCode.find("  ");

    while (doubleSpace != std::string::npos)
    {
        lineOfCode.erase(doubleSpace, 1);
        doubleSpace = lineOfCode.find("  ");
    }

    return lineOfCode;

}

// sets splited code into local command, stack and argument variables
void CodeParser::setToLocalVars(std::vector<std::string> splitCode){
    size_t numOfCode = splitCode.size();
    while (numOfCode >= 1)
    {
        switch (numOfCode)
        {
        case 3:
            this->argument = splitCode.back();
            break;
        case 2:
            this->stack = splitCode.back();
            break;
        case 1:
            this->command = splitCode.back();
            break;
        
        default:
            break;
        }

        splitCode.pop_back();
        numOfCode = splitCode.size();
    }
    
}

void CodeParser::operator=(std::string lineOfCode){
    this->lineOfCode = lineOfCode;

    // reset to empty
    this->command = "";
    this->stack = "";
    this->argument = "";

    // format string
    lineOfCode = cvrtToStd(lineOfCode);

    if(lineOfCode.length()<2){
        return;
    }

    // place holder for code
    std::vector<std::string> code;

    while (lineOfCode.length()>=1)
    {
        std::size_t delimiter = lineOfCode.find(" ");

        if(delimiter == std::string::npos)
            delimiter = lineOfCode.length();

        code.push_back(lineOfCode.substr(0, delimiter));
        lineOfCode.erase(0, delimiter+1);
    }

    setToLocalVars(code);

}