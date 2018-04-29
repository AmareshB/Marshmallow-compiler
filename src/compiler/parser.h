//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PARSER_H
#define SER502_SPRING2018_TEAM15_PARSER_H


#include <string>
#include <vector>
#include "../utils/symbolTable.h"
#include "../utils/node.h"

class Parser {
    std::vector<std::string> tokens;
    int i = 0;
    int instLine = 0;
    int address = 0;
    SymbolTable* globalSymbolTable;
public:
    Parser(const std::vector<std::string> &tokens);
    Node* compar_exp(SymbolTable &symbolTable);
    Node* parseIdentifier();
    Node* getProgram(SymbolTable &symbolTable);
    Node* parseBlock(SymbolTable &symbolTable, std::string type);
    Node* parseStatement(SymbolTable &symbolTable);
    Node* exec_stmt(SymbolTable &symbolTable);
    Node* func_def(SymbolTable &symbolTable);
    Node* parseArguments(SymbolTable &symbolTable);
    Node* parseParameters(SymbolTable &symbolTable);
    Node* if_stmt(SymbolTable &symbolTable);
    Node* while_stmt(SymbolTable &symbolTable);
    Node* cont_stmt();
    Node* break_stmt();
    Node* return_stmt(SymbolTable &symbolTable);
    Node* print_stmt(SymbolTable &symbolTable);
    Node* assign_stmt(SymbolTable &symbolTable);
    Node* expression(SymbolTable &symbolTable);
    Node* or_expr(SymbolTable &symbolTable);
    Node* and_expr(SymbolTable &symbolTable);
    Node* not_expr(SymbolTable &symbolTable);
    Node* a_expr(SymbolTable &symbolTable);
    Node* m_expr(SymbolTable &symbolTable);
    Node* atom(SymbolTable &symbolTable);
    bool lookup(std::string idenName, SymbolTable &symbolTable);

};


#endif //SER502_SPRING2018_TEAM15_PARSER_H

