//
// Created by Amaresh on 04/18/18.
//


#include <iostream>
#include <compiler/utils/other_nodes/Node.h>
#include <vector>
#include <compiler/utils/other_nodes/ProgramNode.h>
#include <compiler/utils/stmt/PrintNode.h>
#include <compiler/utils/other_nodes/BinaryNode.h>
#include <compiler/utils/other_nodes/NumberNode.h>
#include "byte_code.h"
using namespace std;

byte_code::byte_code(){
    cout << "  \n inside constructor";

}

/*vector<int> byte_code::generateByteCode() {
    cout << "\nInside generatebytecode function\n";

    SymbolTable *symbolTable1 = new SymbolTable();
    vector<string> program3 = {"print","2","+","3","NEWLINE"};
    Parser *parser6 = new Parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    TreeHelper treeHelper;
    treeHelper.generateAddress(0,*symbolTable1);
    cout<<node->getType() <<"\n";
    cout << "----------------- starts\n";

    int children = 0, i = 0;
    ProgramNode *programNode;
    if(node->getType()=="program") {
        programNode = dynamic_cast<ProgramNode *>(node);
        children = programNode->childStmt.size();
    }
    cout <<" Child count" << children;

}*/

vector<int> byte_code::generateByteCode(Node *node,string typeName, std::vector<int> &vec) {

    int children = 0, i = 0;
    string childType = "";
    //cout << "\nchild " << programNode->childStmt[i]->getType();
    //node = new Node();
    //string typeName = node->getType();
    cout << "\ntype " << typeName;
    if(typeName == "program") {
        cout << "\n Inside program block";
        vec.push_back(1);
        ProgramNode *programNode = static_cast<ProgramNode *>(node);
        cout <<programNode->childStmt.size();
        while(i < programNode->childStmt.size()){
            childType = programNode->childStmt[i]->getType();
            generateByteCode(programNode->childStmt[i],childType,vec);
            i++;
        }
        cout << "End of recursion" << int(vec.size())<<"\n";
        for(int j=0; j<vec.size(); j++)
            std::cout<< vec[j] << ' ';
    } else if( typeName == "print") {
        cout <<"\ninside  print block ";
        PrintNode *printNode = static_cast<PrintNode *>(node);
        childType = printNode->child->getType();
        generateByteCode(printNode->child,childType,vec);
        vec.push_back(PRINT);
    } else if( typeName == "binaryNode") {
        cout <<"\ninside  binary block ";
        BinaryNode *binaryNode = static_cast<BinaryNode *>(node);
        generateByteCode(binaryNode->rhs,binaryNode->rhs->getType(),vec);
        generateByteCode(binaryNode->lhs,binaryNode->lhs->getType(),vec);
        cout <<"\nbinary node name" << binaryNode->name;
        string operation = binaryNode->name;
        if(operation == "+") {
            vec.push_back(ADD);
        } else if(operation == "-"){
            vec.push_back(SUB);
        } else if(operation == "*"){
            vec.push_back(MUL);
        } else if(operation == "/") {
            vec.push_back(DIV);
        } else if(operation == "%") {
            vec.push_back(MOD);
        }
    } else if(typeName == "number") {
        NumberNode *numberNode = static_cast<NumberNode *>(node);
        vec.push_back(PUSH);
        vec.push_back(numberNode->val);
    }
}


