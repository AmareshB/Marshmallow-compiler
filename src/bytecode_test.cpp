//
// Created by Amaresh on 04/19/18.
//

#include <iostream>
#include <compiler/Parser.h>
#include "bytecode_test.h"
#include "byte_code.h"
using  namespace std;

int main() {
    byte_code *b = new byte_code();

    SymbolTable *symbolTable1 = new SymbolTable();
    vector<string> program3 = {"print","2","+","3","NEWLINE"};
    Parser *parser6 = new Parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    //TreeHelper treeHelper;
    //treeHelper.generateAddress(0,*symbolTable1);
    cout<<node->getType() <<"\n";
    vector<int> byteCode;
    b->generateByteCode(node,node->getType(),byteCode);
    //cout << "Hello World";
    return 0;
}