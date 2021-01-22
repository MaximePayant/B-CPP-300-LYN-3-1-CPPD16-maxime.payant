/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** BF_Translator.cpp
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator() :
_instructions()
{
    _instructions['>'] = "++ptr;\n";
    _instructions['<'] = "--ptr;\n";
    _instructions['+'] = "++*ptr;\n";
    _instructions['-'] = "--*ptr;\n";
    _instructions['.'] = "putchar(*ptr);\n";
    _instructions[','] = "*ptr=getchar();\n";
    _instructions['['] = "while (*ptr) {\n";
    _instructions[']'] = "}\n";
}

BF_Translator::~BF_Translator()
{
    _instructions.clear();
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::ifstream inFile(in);
    std::ofstream outFile(out);
    char token;

    if (!outFile || !inFile)
        return (1);
    outFile << "#include <stdio.h>\n"
            << "#include <stdlib.h>\n"
            << "\n"
            << "int main(void)\n"
            << "{\n"
            << "char result[60000] = {0};\n"
            << "char *ptr = result;\n"
            << "\n";

    while ((inFile >> token)) {
        if (_instructions.count(token))
            outFile << _instructions[token];
    }
    outFile << "}\n";
    return (0);
}