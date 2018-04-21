//
// Created by Amaresh on 04/19/18.
//

#include <iostream>
#include <compiler/Parser.h>
#include "bytecode_test.h"
#include "byte_code.h"
#include "runtime.h"

using  namespace std;

int main() {


    SymbolTable *symbolTable1 = new SymbolTable();
    vector<string> program3 = {"a","=","15","NEWLINE","b","=","10","NEWLINE","print","(","a","+","b",")","NEWLINE"};
    Parser *parser6 = new Parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    //TreeHelper treeHelper;
    //treeHelper.generateAddress(0,*symbolTable1);
    cout<<node->getType() <<"\n";

    vector<int> byteCodeVector;
    byte_code *b = new byte_code(symbolTable1);
    b->generateByteCode(node,node->getType(),byteCodeVector);
    cout<<endl;
    runtime *r = new runtime(&byteCodeVector,byteCodeVector.size());
    r->run();
    //cout << "Hello World";
    return 0;
}