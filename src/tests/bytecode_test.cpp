//
// Created by Amaresh on 04/19/18.
//

#include <iostream>
#include "../compiler/parser.h"
#include "../compiler/bytecode.h"
#include "../compiler/lexer.h"

void testCase();

using  namespace std;

int main(){
    testCase();
}

/**
* Test cases to test if the bytecode is generated correctly
*/
void testCase() {

    SymbolTable *symbolTable1 = new SymbolTable();


    vector<string> test1 = {"a","=","10","NEWLINE",
                            "if","(","a","<","1",")","NEWLINE",
                            "INDENT","b","=","a","-","1","NEWLINE",
                            "print","b","NEWLINE","DEDENT",
                            "else","NEWLINE","INDENT","b","=","a","+","1","NEWLINE",
                            "print","b","NEWLINE","DEDENT"};



    vector<std::string> test3 = {"function","fact","(","n",")","NEWLINE","INDENT",
                                 "if","(","n","==","1",")","NEWLINE","INDENT","return","1","NEWLINE","DEDENT",
                                 "return","(","n","*","fact","(","n","-","1",")",")","NEWLINE","DEDENT",
                                 "print","fact","(","5",")","NEWLINE"};


    //vector<int> testBytecode = {0,10,25,0,0,1,26,0,11,18,23,0,1,26,0,5,2,0,3,0,22,19,33,0,1,26,0,4,2,0,3,0,22,23};

    //vector<int> testBytecode = {19,26,0,1,3,0,9,18,14,0,1,21,19,14,0,1,3,0,5,20,2,1,3,0,6,21,0,5,20,2,1,22,23};

    //vector<string> test3 = {"a","=","(","9","*","10",")","/","3","NEWLINE","print","a","NEWLINE"};
    //vector<string> test6 = {"a","=","10","NEWLINE","while","(","a",">","1",")","NEWLINE","INDENT","print","a","NEWLINE","a","=","a","-","1","NEWLINE","DEDENT","print","a","NEWLINE"};
    /*vector<std::string> test9 = {"function","add","(","c",",","d",")","NEWLINE",
                                 "INDENT","print","c","+","d","NEWLINE",
                                        "return","1","NEWLINE",
                                 "DEDENT","add","(","10",",","20",")","NEWLINE"};*/


    /*a = 47
    if ( a % 10 == 0 )
     print 10
    elif ( a % 5 == 0 )
     print 5
    elif ( a % 2 == 0 )
     print 2
    else
     print 0

 */
    vector<string> test2 = {"a","=","47","NEWLINE",
                            "if","(","a","%","10","==","0",")","NEWLINE",
                            "INDENT","print","10","NEWLINE", "DEDENT",
                            "elif","(","a","%","5","==","0",")","NEWLINE",
                            "INDENT","print","5","NEWLINE", "DEDENT",
                            "else","NEWLINE","INDENT",
                            "print","0","NEWLINE","DEDENT"};



    Parser *parser6 = new Parser(test2);
    vector<int> testBytecode= {0, 47, 25, 0, 0, 0, 0, 10, 26, 0, 8, 9, 18, 19, 0, 10, 22, 19, 37, 0, 0, 0, 5, 26, 0, 8, 9, 18, 34, 0, 5, 22, 19, 37, 0, 0, 22, 23};
    Node* node = parser6->getProgram(*symbolTable1);


    vector<int> byteCodeVector;
    bytecode *b = new bytecode(symbolTable1);
    b->generateByteCode(node,node->getType(),byteCodeVector);
    for(int i = 0; i < byteCodeVector.size();i++){
        std::cout<<byteCodeVector[i]<<" ";
    }
    std::cout<<endl;
    if(testBytecode == byteCodeVector){
        std::cout<<"Test Passed";
    } else {
        std::cout<<"Test Failed";
    }

}

