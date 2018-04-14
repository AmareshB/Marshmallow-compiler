//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PARSER_H
#define SER502_SPRING2018_TEAM15_PARSER_H


#include <string>
#include <vector>
#include <compiler/utils/other_nodes/Node.h>
#include <compiler/utils/SymbolTable.h>

class Parser {
    std::vector<std::string> tokens;
    int i = 0;
    int instLine = 0;
    int address = 0;
public:
    Parser(const std::vector<std::string> &tokens);
    Node* parseIdentifier();
    Node* getProgram(SymbolTable &symbolTable);
    Node* parseBlock(SymbolTable &symbolTable);
    Node* parseStatement(SymbolTable &symbolTable);
    Node* exec_stmt(SymbolTable &symbolTable);
    Node* func_def(SymbolTable &symbolTable);
    Node* parseArguments(SymbolTable &symbolTable);
    Node* parseParameters(SymbolTable &symbolTable);
    Node* if_stmt(SymbolTable &symbolTable);
    Node* while_stmt(SymbolTable &symbolTable);
    Node* cont_stmt();
    Node* break_stmt();
    Node* print_stmt();
    Node* assign_stmt();
    Node* expression(SymbolTable &symbolTable);
    Node* or_expr(SymbolTable &symbolTable);
    Node* and_expr(SymbolTable &symbolTable);
    Node* not_expr(SymbolTable &symbolTable);
    Node* compr_expr(SymbolTable &symbolTable);
    Node* a_expr(SymbolTable &symbolTable);
    Node* m_expr(SymbolTable &symbolTable);
    Node* atom(SymbolTable &symbolTable);
    bool lookup(std::string idenName, SymbolTable &symbolTable);

};


#endif //SER502_SPRING2018_TEAM15_PARSER_H
