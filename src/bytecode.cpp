//
// Created by Amaresh on 04/18/18.
//

#include <iostream>
#include <vector>
#include <compiler/utils/other_nodes/Node.h>
#include <compiler/utils/other_nodes/ProgramNode.h>
#include <compiler/utils/stmt/PrintNode.h>
#include <compiler/utils/other_nodes/BinaryNode.h>
#include <compiler/utils/other_nodes/NumberNode.h>
#include <compiler/utils/stmt/AssignNode.h>
#include <compiler/utils/other_nodes/IdenNode.h>
#include <compiler/utils/other_nodes/UnaryNode.h>
#include <compiler/utils/stmt/BranchNode.h>
#include <compiler/utils/BlockNode.h>
#include <compiler/utils/stmt/WhileNode.h>
#include "bytecode.h"

bool isAssign = false;

std::vector<int> current_breaks;
int current_loopAddr;
bool foundInGlobalTable = false;

bytecode::bytecode(){
    std::cout << "  \n inside constructor";
     //symbolTable = new SymbolTable();
}
bytecode::bytecode(SymbolTable *symTable) {
    globalSymbolTable = symTable;
    symbolTable = symTable;
    //cout << "symTable" <<symTable->symbolTableMap[0].;
    //cout <<"symboltable" << this->symbolTable->symbolTableMap.find("a");
}

/*vector<int> bytecode::generateByteCode() {
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

void bytecode::generateByteCode(Node *node,std::string typeName, std::vector<int> &vec) {

    //int children = 0;
    int i= 0;
    std::string childType = "";
    //cout << "\nchild " << programNode->childStmt[i]->getType();
    //node = new Node();
    //string typeName = node->getType();
    std::cout << "\ntype " << typeName;
    if(typeName == "program") {
        std::cout << "\n Inside program block";
        vec.push_back(1);
        ProgramNode *programNode = static_cast<ProgramNode *>(node);
        std::cout <<programNode->childStmt.size();
        while(i < programNode->childStmt.size()){
            childType = programNode->childStmt[i]->getType();
            generateByteCode(programNode->childStmt[i],childType,vec);
            i++;
        }
        vec.push_back(EXIT);
        std::cout << "\nEnd of recursion" << int(vec.size())<<"\n";
        for(int j=0; j<vec.size(); j++)
            std::cout<< vec[j] << ' ';
    } else if( typeName == "print") {
        std::cout <<"\ninside  print block ";
        PrintNode *printNode = static_cast<PrintNode *>(node);
        childType = printNode->child->getType();
        generateByteCode(printNode->child,childType,vec);
        vec.push_back(PRINT);
    } else if( typeName == "binaryNode") {
        std::cout <<"\ninside  binary block ";
        BinaryNode *binaryNode = static_cast<BinaryNode *>(node);
        generateByteCode(binaryNode->rhs,binaryNode->rhs->getType(),vec);
        generateByteCode(binaryNode->lhs,binaryNode->lhs->getType(),vec);
        std::cout <<"\nbinary node name" << binaryNode->name;
        std::string operation = binaryNode->name;
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
        int val = * new int(numberNode->val);
        vec.push_back(val);
    } else if(typeName == "identifier") {
        std::cout <<"\ninside  identifier block ";
        IdenNode *idenNode = static_cast<IdenNode *> (node);

        //vec.push_back(STORE);
        std::cout << idenNode->getName();
        //cout<<symbolTable->symbolTableMap.find(idenNode->getName())->second;
        //int idenAddr = symbolTable->symbolTableMap.find(idenNode->getName())->second;
        //int val1 = * new int(symbolTable->symbolTableMap.find(idenNode->getName())->second);
        int val1 = findIdentifier(idenNode->getName(),symbolTable);
        if(isAssign){
            if(foundInGlobalTable){
                vec.push_back(GSTORE);
                foundInGlobalTable = false;
            } else {
                vec.push_back(STORE);
            }
        } else{
            if(foundInGlobalTable){
                vec.push_back(GLOAD);
                foundInGlobalTable = false;
            } else {
                vec.push_back(LOAD);
            }
        }
        isAssign =  false;
        vec.push_back(val1);
    } else if (typeName == "assign") {
        std::cout <<"\ninside  assign block ";
        AssignNode *assignNode = static_cast<AssignNode *>(node);
        generateByteCode(assignNode->rhs,assignNode->rhs->getType(),vec);
        //vec.push_back(STORE);
        isAssign = true;
        /*vec.push_back(0);
        vec.push_back(LOAD);
        vec.push_back(0);*/
        generateByteCode(assignNode->lhs,assignNode->lhs->getType(),vec);
    } else if(typeName == "unary") {
        UnaryNode *unaryNode = static_cast<UnaryNode *> (node);
        generateByteCode(unaryNode->onlyChild,unaryNode->onlyChild->getType(),vec);
        std::string operation = unaryNode->name;
        if(operation == "not") {
            vec.push_back(NOT);
        }
    } else if(typeName == "if" || typeName == "elif"){

        BranchNode *branchNode = static_cast<BranchNode*>(node);

        generateByteCode(branchNode->condition,branchNode->condition->getType(),vec);
        vec.push_back(BRF);
        int fail_addr = vec.size();
        //last.push_back(vec.size() + 1);
        vec.push_back(-1);

        generateByteCode(branchNode->bodyBlock,branchNode->bodyBlock->getType(),vec);
        vec.push_back(BR);
        int complete_addr = vec.size();
        vec.push_back(-1);
        vec.at(fail_addr) = vec.size();
        generateByteCode(branchNode->branch,branchNode->branch->getType(),vec);
        vec.at(complete_addr) = vec.size();
        //vec.push_back(BR);
        //vec.push_back(-1);
    } else if (typeName == "else"){
        BranchNode *branchNode = static_cast<BranchNode*>(node);
        generateByteCode(branchNode->bodyBlock,branchNode->bodyBlock->getType(),vec);
    } else if(typeName == "block") {
        BlockNode *blockNode = static_cast<BlockNode *>(node);
         symbolTable = symbolTable->childMaps.find(blockNode->name)->second;
        std::cout <<"block size"<<blockNode->childStmt.size();
        while(i < blockNode->childStmt.size()){
            childType = blockNode->childStmt[i]->getType();
            generateByteCode(blockNode->childStmt[i],childType,vec);
            i++;
        }
        symbolTable = symbolTable->parentMap;
    } else if(typeName == "while") {
        WhileNode *whileNode = static_cast<WhileNode*>(node);

        int old_loop_addr = current_loopAddr;
        std::vector<int> old_break = current_breaks;
        current_breaks.clear();
        current_loopAddr = vec.size();
        generateByteCode(whileNode->expression,whileNode->expression->getType(),vec);
        vec.push_back(BRF);
        int fail_addr = vec.size();
        vec.push_back(-1);
        generateByteCode(whileNode->block,whileNode->block->getType(),vec);
        vec.push_back(BR);
        vec.push_back(current_loopAddr);
        vec.at(fail_addr) = vec.size();

        for (int j =0 ; j < current_breaks.size(); j++){
            vec.at(current_breaks[j]) = vec.size();
        }
        current_breaks = old_break;
        current_loopAddr = old_loop_addr;
    } else if(typeName == "continue") {
        vec.push_back(BR);
        vec.push_back(current_loopAddr);
    }
    else if(typeName == "break") {
        vec.push_back(BR);
        current_breaks.push_back(vec.size());
        vec.push_back(-1);
    }
}

int bytecode::findIdentifier(std::string name, SymbolTable *st){

    if(st->symbolTableMap.count(name) > 0)
    {
        if(st == globalSymbolTable){
            foundInGlobalTable = true;
        }
        return st->symbolTableMap.find(name)->second;
    }
    else if(st->parentMap!= nullptr)
    {
        return findIdentifier(name,symbolTable->parentMap);
    }
    else if(st != globalSymbolTable)
    {
        if(globalSymbolTable->symbolTableMap.count(name) > 0) {
            foundInGlobalTable = true;
            return globalSymbolTable->symbolTableMap.find(name)->second;
        }
    }
    else {
        throw "identifier not found:"+name;
    }
}



