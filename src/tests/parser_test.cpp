//
// Created by Balachandar on 12-04-2018.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../utils/node.h"
#include "../utils/symbolTable.h"
#include "../compiler/parser.h"
#include "../utils/treeHelper.h"

using namespace std;

void test1();
/*
int main()
{
   test1();
}*/

/**
 * Test case 1 to check the structure of parse tree and its content
 */

void test1()
{
    SymbolTable *symbolTable1 = new SymbolTable();
    vector<string> program3 = {"print","2","+","3","NEWLINE"};
    Parser *parser6 = new Parser(program3);
    Node* node = parser6->getProgram(*symbolTable1);
    TreeHelper treeHelper;
    cout<<"Test Case 1 ";
    if(node->getType()=="program") {
        ProgramNode *programNode = dynamic_cast<ProgramNode *>(node);
        PrintNode *printNode = static_cast<PrintNode *>(programNode->childStmt[0]);
        BinaryNode *binaryNode = static_cast<BinaryNode *>(printNode->child);
        if (binaryNode->name != "+")
        {
            cout << "Failed";
            return;
        }
        NumberNode *numberNode1 = static_cast<NumberNode *>(binaryNode->lhs);
        if(numberNode1->val!=2)
        {
            cout << "Failed";
            return;
        }
        NumberNode *numberNode2 = static_cast<NumberNode *>(binaryNode->rhs);
        if(numberNode2->val!=3)
        {
            cout << "Failed";
            return;
        }
    }
    cout<<"Tested Successfully";
}
