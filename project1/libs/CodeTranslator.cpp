#include <CodeTranslator.h>
#include <CodeParser.h>


CodeTranslator::CodeTranslator(){
    staticVarCount = 1;
    jmpCount = 1;
}

CodeTranslator::~CodeTranslator(){

}

std::string CodeTranslator::commandTrans(std::string command){
    std::string res = "";

    if(command == "add"){
        // get address of the first data value and set it to d register
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, add first data value and store it current address
        res += "A=A-1\n";
        res += "M=M+D\n";

        return res;
    }

    if(command == "sub"){
        // get address of the first data value and set it to d register
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, subtract first data value and store it current address
        res += "A=A-1\n";
        res += "M=M-D\n";

        return res;
    }

    if(command == "neq"){
        // get address of the first data value and set it to d register, and move sp up
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, subtract first data value and store it to d register
        res += "A=A-1\n";
        res += "D=M-D\n";
        res += "@jmp"+jmpCount;
        res += "\n";
        res += "D;JNE\n";

        // if v1 and 2 are equal
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 and v2 are not equal
        res += "(jmp"+jmpCount;
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+jmpCount;
        res += ")\n";

        res += "@SP\n";
        res += "A=M-1\n";
        res += "M=D\n";    

        jmpCount++;
        return res;
    }

    if(command == "eq"){
        // get address of the first data value and set it to d register, and move sp up
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, subtract first data value and store it to d register
        res += "A=A-1\n";
        res += "D=M-D\n";
        res += "@jmp"+jmpCount;
        res += "\n";
        res += "D;JEQ\n";

        // if v1 and 2 are not equal 
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 and v2 are equal
        res += "(jmp"+jmpCount;
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+jmpCount;
        res += ")\n";

        res += "@SP\n";
        res += "A=M-1\n";
        res += "M=D\n";    

        jmpCount++;
        return res;
    }

    if(command == "get"){
        // get address of the first data value and set it to d register, and move sp up
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, subtract first data value and store it to d register
        res += "A=A-1\n";
        res += "D=M-D\n";
        res += "@jmp"+jmpCount;
        res += "\n";
        res += "D;JGT\n";

        // if v1 is less 2 
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 greater v2 
        res += "(jmp"+jmpCount;
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+jmpCount;
        res += ")\n";

        res += "@SP\n";
        res += "A=M-1\n";
        res += "M=D\n";    

        jmpCount++;
        return res;
    }

    if(command == "lt"){
        // get address of the first data value and set it to d register, and move sp up
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, subtract first data value and store it to d register
        res += "A=A-1\n";
        res += "D=M-D\n";
        res += "@jmp"+jmpCount;
        res += "\n";
        res += "D;JLT\n";

        // if v1 greater 2 
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 less v2 
        res += "(jmp"+jmpCount;
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+jmpCount;
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+jmpCount;
        res += ")\n";

        res += "@SP\n";
        res += "A=M-1\n";
        res += "M=D\n";    

        jmpCount++;
        return res;
    }

    if(command == "and"){
        // get address of the first data value and set it to d register
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, AND them and store it current address
        res += "A=A-1\n";
        res += "M=M&D\n";

        return res;
    }
    
    if(command == "or"){
        // get address of the first data value and set it to d register
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // get address of the seconde data value, OR them and store it current address
        res += "A=A-1\n";
        res += "M=M|D\n";

        return res;
    }

    if(command == "not"){
        // get address of the first data value and use NOT and sotre it
        res += "@SP\n";
        res += "A=M-1\n";
        res += "M=!M\n";

        return res;
    }
    return res;
}