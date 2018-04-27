//
// Created by prasanth on 19/4/18.
//

#ifndef SER502_SPRING2018_TEAM15_LEXER_H
#define SER502_SPRING2018_TEAM15_LEXER_H

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <ostream>
#include <ctype.h>

class Lexer{
    std::vector<char> input;
    std::vector<std::string> tokens;
    std::map<std::string, std::string> Keyword;
    std::map<std::string, std::string>::iterator it;
public:
    Lexer(std::vector<char> program);
    ~Lexer();
    std::vector<std::string> Tokenize();
    bool isDigit(char c);
    bool isAlpha(char c);
    bool isNewLine(char c);
    int leadingSpaces(int i);
    int getNumber(int i);
    bool isComma(char c);

};

#endif //SER502_SPRING2018_TEAM15_LEXER_H
