//
// Created by bsampat5 on 4/13/2018.
//


#include "Parser.h"
#include <iostream>


Parser::Parser(const std::vector<std::string> &tokens) : tokens(tokens) {}

Node* Parser::parseIdentifier() {
    IdenNode* res = NULL;
    std::cout << tokens[0];
}

int main()
{
    std::vector<std::string> token;
    token.push_back("Bala");
    token.push_back("Hellow");
    Parser* parser = new Parser(token);
    parser -> parseIdentifier();
}


