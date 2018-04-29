//
// Created by Prasanth Venugopal on 4/28/18.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "../compiler/lexer.h"
#include <stack>
#include <string>

int main()
{
    std::vector<char> input;
    char ch;
    std::string program = "../data/fibonacci.mlw";
    std::string program1 = "../data/IfProgram.mlw";

    std::fstream fin(program1, std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        input.push_back(ch);
    }

    std::vector<std::string> tokens;
    Lexer *l = new Lexer(input);
    tokens = l->Tokenize();
    for (std::vector<std::string>::iterator it = tokens.begin() ; it != tokens.end(); ++it)
        std::cout << ' ' << *it;

}
