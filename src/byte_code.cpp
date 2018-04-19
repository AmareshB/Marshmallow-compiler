//
// Created by Amaresh on 04/18/18.
//


#include <iostream>
#include "byte_code.h"
using namespace std;

byte_code::byte_code(){
    cout << "  \n inside constructor";
    /*SymbolTable *symbolTable1 = new SymbolTable();
    vector<std::string> program3 = {"function","complete","(","c",",","d",",","e",",","f",")","NEWLINE","INDENT","a","=","5","NEWLINE","i","=","1","NEWLINE","if","(","a","%","2","==","0",")","NEWLINE","INDENT","print","(","a",")","NEWLINE","DEDENT","else","NEWLINE","INDENT","while","(","i","<","10",")","NEWLINE","INDENT","print","(","i",")","NEWLINE","i","=","i","+","1","NEWLINE","DEDENT","DEDENT","DEDENT","complete","(","2","+","3",",","3","6","+","3",",","7",")","NEWLINE"};
    Parser *parser6 = new Parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    TreeHelper treeHelper;
    treeHelper.generateAddress(0,*symbolTable1);
    cout<<node->getType();*/
}

/*vector<int>::generateByteCode() {
    //cout<<"number of children " << programNode->childStmt.size();
    //int children = programNode.child
    int children = 0;
    while(children > 0){
        if() {

        }
    }
}*/


