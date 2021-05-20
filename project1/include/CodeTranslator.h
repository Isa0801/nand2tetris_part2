#include <iostream>
#include <vector>





class CodeTranslator
{
    public:
        CodeTranslator();
        ~CodeTranslator();
        std::string commandTrans(std::string);
    private:
        int jmpCount, staticVarCount;
        
        std::string stackTrans(std::string);
        std::string argumentTrans(std::string);

};