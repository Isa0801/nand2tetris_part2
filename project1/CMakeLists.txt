cmake_minimum_required(VERSION 3.00)
project(VMTranslator)

# includes code parser header and lib file
include_directories(./include)
add_library(CodeParser ./libs/CodeParser.cpp)

add_executable(VMTranslator src.cpp)

target_link_libraries(VMTranslator CodeParser)