//
// Created by Amaresh on 04/19/18.
//

#include <iostream>
#include "../compiler/parser.h"
#include "../utils/treeHelper.h"
#include "../compiler/bytecode.h"
#include "../runtime/runtime.h"

using  namespace std;

/*int main() {

    SymbolTable *symbolTable1 = new SymbolTable();
    //vector<string> program3 = {"a","=","(","9","*","10",")","/","3","NEWLINE","print","a","NEWLINE"};
    //vector<std::string> program3 = {"function","add","(","c",",","d",")","NEWLINE","INDENT","return","c","+","d","NEWLINE","DEDENT","c","=","add","(","12",",","20",")","NEWLINE","print","c","NEWLINE"};
    //vector<std::string> program3 = {"function","complete","(","c",",","d",",","e",",","f",")","NEWLINE","INDENT","a","=","5","NEWLINE","i","=","1","NEWLINE","if","(","a","%","2","==","0",")","NEWLINE","INDENT","print","(","a",")","NEWLINE","DEDENT","else","NEWLINE","INDENT","while","(","i","<","10",")","NEWLINE","INDENT","print","(","i",")","NEWLINE","i","=","i","+","1","NEWLINE","DEDENT","DEDENT","DEDENT","complete","(","2","+","3",",","3","6","+","3",",","7",")","NEWLINE"};
    //vector<string> program3 = {"if","(","2",">","1",")","NEWLINE","INDENT","print","3","NEWLINE","DEDENT","else","NEWLINE","INDENT","print","4","NEWLINE","DEDENT"};
    //vector<string> program3 = {"while","(","2",">","1",")","NEWLINE","INDENT","print","3","NEWLINE","DEDENT","print","5","NEWLINE"};
    //vector<string> program3 = {"a","=","10","NEWLINE","while","(","a",">","1",")","NEWLINE","INDENT","print","a","NEWLINE","a","=","a","-","1","NEWLINE","DEDENT","print","a","NEWLINE"};
    //vector<string> program3 = {"a","=","10","NEWLINE","b","=","5","NEWLINE","print","a","+","b","NEWLINE"};
   // vector<string> program3 = {"a","=","10","NEWLINE","if","(","a","<","1",")","NEWLINE","INDENT","b","=","a","-","1","NEWLINE", "print","b","NEWLINE","DEDENT","else","NEWLINE","INDENT","b","=","a","+","1","NEWLINE", "print","b","NEWLINE","DEDENT"};
    //vector<std::string> program3 = {"function","add","(","c",",","d",")","NEWLINE","INDENT","print","c","+","d","NEWLINE","return","1","NEWLINE","DEDENT","add","(","10",",","20",")","NEWLINE"};
    vector<std::string> program3 = {"function","fact","(","n",")","NEWLINE","INDENT",
            "if","(","n","==","1",")","NEWLINE","INDENT","return","1","NEWLINE","DEDENT",
                                    "return","(","n","*","fact","(","n","-","1",")",")","NEWLINE","DEDENT",
            "print","fact","(","6",")","NEWLINE"};
    Parser *parser6 = new parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    TreeHelper treeHelper;
  //  treeHelper.generateAddress(0,*symbolTable1);
    cout<<node->getType() <<"\n";

    vector<int> byteCodeVector;
    //byteCodeVector.reserve(100);
    bytecode *b = new bytecode(symbolTable1);
    b->generateByteCode(node,node->getType(),byteCodeVector);
    cout<<endl;
    runtime *r = new runtime(&byteCodeVector,byteCodeVector.size());
    r->run();

   //cout << "Hello World";
    return 0;
}*/
