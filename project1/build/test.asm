// push constant 10
// pop local 0
// push constant 21
// push constant 22
// pop argument 2
// pop argument 1
// push constant 36
// pop this 6
// push constant 42
// push constant 45
// pop that 5
// pop that 2
// push constant 510
// pop temp 6
// push local 0
// push that 5
// add  
@SP
M=M-1
A=M
D=M
A=A-1
M=M+D
// push argument 1
// sub  
@SP
M=M-1
A=M
D=M
A=A-1
M=M-D
// push this 6
// push this 6
// add  
@SP
M=M-1
A=M
D=M
A=A-1
M=M+D
// sub  
@SP
M=M-1
A=M
D=M
A=A-1
M=M-D
// push temp 6
// add  
@SP
M=M-1
A=M
D=M
A=A-1
M=M+D
