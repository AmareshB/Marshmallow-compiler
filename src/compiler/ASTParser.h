//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PARSER_H
#define SER502_SPRING2018_TEAM15_PARSER_H


#include <string>
#include <vector>

class Parser {
    std::vector<std::string> tokens;
    int i = 0;
    int instLine = 0;
    int address = 0;
public:
    Parser(const std::vector<std::string> &tokens);
    Parser::parseIdentifier();

};


#endif //SER502_SPRING2018_TEAM15_PARSER_H
