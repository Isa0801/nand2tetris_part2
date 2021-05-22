#include <iostream>
#include <vector>
#include <string>





class CodeTranslator
{
    public:
        CodeTranslator(std::string);
        ~CodeTranslator();

        std::string getTranslatedCode();
        void setCommand(std::string);
        void setStack(std::string);
        void setArg(std::string);

    private:
        std::string commandTrans();
        std::string PopStackTrans();
        std::string PushStackTrans();
        int jmpCount, staticVarCount;
        std::string fileName, command = "", stack = "", arg = "";
        


};