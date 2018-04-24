//
// Created by Amaresh on 04/19/18.
//

#include <iostream>
#include <compiler/Parser.h>
#include <compiler/utils/TreeHelper.h>
#include "bytecode_test.h"
#include "bytecode.h"
#include "runtime.h"

using  namespace std;

int main() {


    SymbolTable *symbolTable1 = new SymbolTable();
    //vector<string> program3 = {"a","=","not","15",">","10","NEWLINE","print","a","NEWLINE"};
    //vector<string> program3 = {"if","(","2",">","1",")","NEWLINE","INDENT","print","3","NEWLINE","DEDENT","else","NEWLINE","INDENT","print","4","NEWLINE","DEDENT"};
    //vector<string> program3 = {"while","(","2",">","1",")","NEWLINE","INDENT","print","3","NEWLINE","DEDENT","print","5","NEWLINE"};
    //vector<string> program3 = {"a","=","10","NEWLINE","while","(","a",">","1",")","NEWLINE","INDENT","print","a","NEWLINE","a","=","a","-","1","NEWLINE","DEDENT","print","a","NEWLINE"};
    vector<string> program3 = {"a","=","10","NEWLINE","b","=","5","NEWLINE","print","a","+","b","NEWLINE"};

    Parser *parser6 = new Parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    TreeHelper treeHelper;
    treeHelper.generateAddress(0,*symbolTable1);
    cout<<node->getType() <<"\n";

    vector<int> byteCodeVector;
    //byteCodeVector.reserve(100);
    bytecode *b = new bytecode(symbolTable1);
    b->generateByteCode(node,node->getType(),byteCodeVector);
    cout<<endl;
  /*  runtime *r = new runtime(&byteCodeVector,byteCodeVector.size());
    r->run();
    */
   //cout << "Hello World";
    return 0;
}