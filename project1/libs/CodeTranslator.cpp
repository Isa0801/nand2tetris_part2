#include <CodeTranslator.h>
#include <CodeParser.h>


CodeTranslator::CodeTranslator(std::string fileName){
    this->fileName = fileName;
    this->staticVarCount = 1;
    this->jmpCount = 1;
}

CodeTranslator::~CodeTranslator(){

}

std::string CodeTranslator::commandTrans(){
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
        res += "@jmp"+std::to_string(jmpCount);
        res += "\n";
        res += "D;JNE\n";

        // if v1 and 2 are equal
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 and v2 are not equal
        res += "(jmp"+std::to_string(jmpCount);
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+std::to_string(jmpCount);
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
        res += "@jmp"+std::to_string(jmpCount);
        res += "\n";
        res += "D;JEQ\n";

        // if v1 and 2 are not equal 
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 and v2 are equal
        res += "(jmp"+std::to_string(jmpCount);
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+std::to_string(jmpCount);
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
        res += "@jmp"+std::to_string(jmpCount);
        res += "\n";
        res += "D;JGT\n";

        // if v1 is less 2 
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 greater v2 
        res += "(jmp"+std::to_string(jmpCount);
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+std::to_string(jmpCount);
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
        res += "@jmp"+std::to_string(jmpCount);
        res += "\n";
        res += "D;JLT\n";

        // if v1 greater 2 
        res += "@0\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";
        

        // if v1 less v2 
        res += "(jmp"+std::to_string(jmpCount);
        res += ")\n";
        res += "@1\n";
        res += "D=A\n";
        res += "@end"+std::to_string(jmpCount);
        res += "\n";
        res += "0;JMP\n";

    

        // end label
        res += "(end"+std::to_string(jmpCount);
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

    if(command == "pop"){
        res += PopStackTrans();
        return res;
    }

    if(command == "push"){
        res += PushStackTrans();
        return res;
    }

    return res;
}

std::string CodeTranslator::PopStackTrans(){
    std::string res = "";

    if(stack == "local"){
        // get address of local to store data that was poped
        res += "@LCL\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "D=A+D\n";
        

        // store local address temporarily at sp current address
        res += "@SP\n";
        res += "A=M\n";
        res += "M=D\n";

        // get value at sp-1 and store it at d register
        res += "A=A-1\n";
        res += "D=M\n";

        // go back to sp and use that data value which is address for our local addres
        res += "A=A+1\n";
        res += "A=M\n";
        res += "M=D\n";

        // decrease sp
        res += "@SP\n";
        res += "M=M-1\n";      
        
        return res;
    }


    if(stack == "argument"){
        // get address of argument to store data that was poped
        res += "@ARG\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "D=A+D\n";
        

        // store argument address temporarily at sp current address
        res += "@SP\n";
        res += "A=M\n";
        res += "M=D\n";

        // get value at sp-1 and store it at d register
        res += "A=A-1\n";
        res += "D=M\n";

        // go back to sp and use that data value which is address for our argument addres
        res += "A=A+1\n";
        res += "A=M\n";
        res += "M=D\n";

        // decrease sp
        res += "@SP\n";
        res += "M=M-1\n";      
        
        return res;
    }


    if(stack == "this"){
        // get address of that to store data that was poped
        res += "@THIS\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "D=A+D\n";
        

        // store that address temporarily at sp current address
        res += "@SP\n";
        res += "A=M\n";
        res += "M=D\n";

        // get value at sp-1 and store it at d register
        res += "A=A-1\n";
        res += "D=M\n";

        // go back to sp and use that data value which is address for our that addres
        res += "A=A+1\n";
        res += "A=M\n";
        res += "M=D\n";

        // decrease sp
        res += "@SP\n";
        res += "M=M-1\n";      
        
        return res;
    }


    if(stack == "that"){
        // get address of that to store data that was poped
        res += "@THAT\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "D=A+D\n";
        

        // store that address temporarily at sp current address
        res += "@SP\n";
        res += "A=M\n";
        res += "M=D\n";

        // get value at sp-1 and store it at d register
        res += "A=A-1\n";
        res += "D=M\n";

        // go back to sp and use that data value which is address for our that addres
        res += "A=A+1\n";
        res += "A=M\n";
        res += "M=D\n";

        // decrease sp
        res += "@SP\n";
        res += "M=M-1\n";      
        
        return res;
    }


    if(stack == "static"){

        // decrease sp and get value from the sp
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // store data into static address
        res += "@"+fileName+arg+"\n";
        res += "M=D\n";     
        
        return res;
    }


    if(stack == "temp"){

        int tempRegister = 5;
        tempRegister += std::stoi(arg);

        // decrease sp and get value from the sp
        res += "@SP\n";
        res += "M=M-1\n";
        res += "A=M\n";
        res += "D=M\n";

        // store data into temp address
        res += "@"+std::to_string(tempRegister)+"\n";
        res += "M=D\n";     
        
        return res;
    }


    if(stack == "pointer"){

        if(arg == "1"){

            // get address of that to store data that was poped
            res += "@THAT\n";
            res += "D=A\n";

        } else if (arg == "0"){
            // get address of that to store data that was poped
            res += "@THIS\n";
            res += "D=A\n";
        }

        // store that address temporarily at sp current address
        res += "@SP\n";
        res += "A=M\n";
        res += "M=D\n";

        // get value at sp-1 and store it at d register
        res += "A=A-1\n";
        res += "D=M\n";

        // go back to sp and use that data value which is address for our that addres
        res += "A=A+1\n";
        res += "A=M\n";
        res += "M=D\n";

        // decrease sp
        res += "@SP\n";
        res += "M=M-1\n";      
        
        return res;
    }

    return res;

}

std::string CodeTranslator::PushStackTrans(){
    std::string res = "";


    if(stack == "constant"){
        // get value of constant data
        res += "@"+arg+"\n";
        res += "D=A\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }

    if(stack == "local"){
        // get value of local data
        res += "@LCL\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "A=A+D\n";
        res += "D=M\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }

    if(stack == "argument"){
        // get value of argument data
        res += "@ARG\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "A=A+D\n";
        res += "D=M\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }


    if(stack == "this"){
        // get value of this data
        res += "@THIS\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "A=A+D\n";
        res += "D=M\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }

    if(stack == "that"){
        // get value of that data
        res += "@THAT\n";
        res += "D=M\n";
        res += "@"+arg+"\n";
        res += "A=A+D\n";
        res += "D=M\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }

    if(stack == "static"){
        // get value of that data
        res += "@"+fileName+arg+"\n";
        res += "D=M\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }
    
    if(stack == "temp"){

        int tempRegister = 5;
        tempRegister += std::stoi(arg);

        // get value of that data
        res += "@"+std::to_string(tempRegister)+"\n";
        res += "D=M\n";

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }


    if(stack == "pointer"){

        if(arg == "1"){
            res += "@THAT\n";
            res += "D=M\n";
        } else if (arg == "0"){
            res += "@THIS\n";
            res += "D=M\n";
        }

        // pushed to sp
        res += "@SP\n";
        res += "M=M+1\n";
        res += "A=M-1\n";
        res += "M=D\n";
        
        return res;
    }


    return res;
}

void CodeTranslator::setCommand(std::string command){
    this->command = command;
}

void CodeTranslator::setStack(std::string stack){
    this->stack = stack;
}

void CodeTranslator::setArg(std::string arg){
    this->arg = arg;
}

std::string CodeTranslator::getTranslatedCode(){
    return commandTrans();
}

