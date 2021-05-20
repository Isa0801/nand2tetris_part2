#include <iostream>
#include <vector>


class CodeParser
{
    public:
        CodeParser();
        ~CodeParser();

        std::string getCommand();
        std::string getStack();
        std::string getArgument();
        void operator=(std::string);

    private:
        std::string lineOfCode, command, stack, argument;
        std::string cvrtToStd(std::string);
        void setToLocalVars(std::vector<std::string>);

};
