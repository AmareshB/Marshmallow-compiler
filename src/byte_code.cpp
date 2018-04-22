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
#include <compiler/utils/stmt/AssignNode.h>
#include <compiler/utils/other_nodes/IdenNode.h>
#include <compiler/utils/other_nodes/UnaryNode.h>
#include "byte_code.h"
using namespace std;

bool isAssign = false;

byte_code::byte_code(){
    cout << "  \n inside constructor";
     //symbolTable = new SymbolTable();
}
byte_code::byte_code(SymbolTable *symTable) {
    symbolTable = symTable;
    //cout << "symTable" <<symTable->symbolTableMap[0].;
    //cout <<"symboltable" << this->symbolTable->symbolTableMap.find("a");
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

    //int children = 0;
    int i= 0;
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
        vec.push_back(EXIT);
        cout << "\nEnd of recursion" << int(vec.size())<<"\n";
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
        } else if(operation ==  "==") {
            vec.push_back(EQ);
        } else if(operation ==  "<>") {
            vec.push_back(NEQ);
        } else if(operation ==  ">") {
            vec.push_back(GT);
        } else if(operation ==  ">=") {
            vec.push_back(GTE);
        } else if(operation ==  "<") {
            vec.push_back(LT);
        } else if(operation ==  "<=") {
            vec.push_back(LTE);
        } else if (operation == "and"){
            vec.push_back(AND);
        } else if (operation == "or"){
            vec.push_back(OR);
        }
    } else if(typeName == "number") {
        NumberNode *numberNode = static_cast<NumberNode *>(node);
        vec.push_back(PUSH);
        int *val = new int(numberNode->val);
        vec.push_back(*val);
    } else if(typeName == "identifier") {
        cout <<"\ninside  identifier block ";
        IdenNode *idenNode = static_cast<IdenNode *> (node);
        if(!isAssign){
            cout<<"load inst"<<endl;
            vec.push_back(LOAD);
        }
        isAssign =  false;
        //vec.push_back(STORE);
        cout << idenNode->getName();
        //cout<<symbolTable->symbolTableMap.find(idenNode->getName())->second;
        //int idenAddr = symbolTable->symbolTableMap.find(idenNode->getName())->second;
        int *val1 = new int(symbolTable->symbolTableMap.find(idenNode->getName())->second);
        vec.push_back(*val1);
    } else if (typeName == "assign") {
        cout <<"\ninside  assign block ";
        AssignNode *assignNode = static_cast<AssignNode *>(node);
        generateByteCode(assignNode->rhs,assignNode->rhs->getType(),vec);
        vec.push_back(STORE);
        isAssign = true;
        /*vec.push_back(0);
        vec.push_back(LOAD);
        vec.push_back(0);*/
        generateByteCode(assignNode->lhs,assignNode->lhs->getType(),vec);
    } else if(typeName == "unary") {
        UnaryNode *unaryNode = static_cast<UnaryNode *> (node);
        generateByteCode(unaryNode->onlyChild,unaryNode->onlyChild->getType(),vec);
        string operation = unaryNode->name;
        if(operation == "not") {
            vec.push_back(NOT);
        }
    }
}


