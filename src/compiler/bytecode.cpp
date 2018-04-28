//
// Created by Amaresh on 04/18/18.
//

#include <iostream>
#include <vector>
#include "../utils/node.h"
#include <unordered_map>
#include "../utils/symbolTable.h"
#include "../utils/opcodes.h"
#include "bytecode.h"

bool isAssign = false;

std::vector<int> current_breaks;
std::unordered_map<std::string,int> funcAddresses;
int current_loopAddr;
bool foundInGlobalTable = false;
bool inFunction = false;

bytecode::bytecode(){
}
bytecode::bytecode(SymbolTable *symTable) {
    globalSymbolTable = symTable;
    symbolTable = symTable;
}

void bytecode::generateByteCode(Node *node,std::string typeName, std::vector<int> &vec) {

    int i= 0;
    std::string childType = "";
    if(typeName == "program") {
        ProgramNode *programNode = static_cast<ProgramNode *>(node);
        while(i < programNode->childStmt.size()){
            childType = programNode->childStmt[i]->getType();
            generateByteCode(programNode->childStmt[i],childType,vec);
            i++;
        }
        vec.push_back(EXIT);
    } else if( typeName == "print") {
        PrintNode *printNode = static_cast<PrintNode *>(node);
        childType = printNode->child->getType();
        generateByteCode(printNode->child,childType,vec);
        vec.push_back(PRINT);
    } else if( typeName == "binaryNode") {
        BinaryNode *binaryNode = static_cast<BinaryNode *>(node);
        generateByteCode(binaryNode->rhs,binaryNode->rhs->getType(),vec);
        generateByteCode(binaryNode->lhs,binaryNode->lhs->getType(),vec);
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
        IdenNode *idenNode = static_cast<IdenNode *> (node);
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
        AssignNode *assignNode = static_cast<AssignNode *>(node);
        generateByteCode(assignNode->rhs,assignNode->rhs->getType(),vec);
        isAssign = true;
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
        vec.push_back(-1);

        generateByteCode(branchNode->bodyBlock,branchNode->bodyBlock->getType(),vec);
        vec.push_back(BR);
        int complete_addr = vec.size();
        vec.push_back(-1);
        vec.at(fail_addr) = vec.size();
        if(branchNode->branch != nullptr) {
            generateByteCode(branchNode->branch, branchNode->branch->getType(), vec);
        }
        vec.at(complete_addr) = vec.size();
    } else if (typeName == "else"){
        BranchNode *branchNode = static_cast<BranchNode*>(node);
        generateByteCode(branchNode->bodyBlock,branchNode->bodyBlock->getType(),vec);
    } else if(typeName == "block") {
        BlockNode *blockNode = static_cast<BlockNode *>(node);
        if(!inFunction) {
            symbolTable = symbolTable->childMaps.find(blockNode->name)->second;
        }
        while(i < blockNode->childStmt.size()){
            childType = blockNode->childStmt[i]->getType();
            generateByteCode(blockNode->childStmt[i],childType,vec);
            i++;
        }
        if(!inFunction) {
            symbolTable = symbolTable->parentMap;
        }
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
    } else if(typeName == "function") {
        inFunction = true;
        FuncNode *funcNode = static_cast<FuncNode*>(node);
        vec.push_back(BR);
        int funcEndAddr = vec.size();
        vec.push_back(-1);
        int funcAddr = vec.size();
        IdenNode *idenNode = static_cast<IdenNode*>(funcNode->identifier);
        funcAddresses.insert({idenNode->name,funcAddr});
        SymbolTable *oldSymbolTable = symbolTable;
        symbolTable = symbolTable->childMaps.find(idenNode->name)->second;
        generateByteCode(funcNode->block,funcNode->block->getType(),vec);
        vec.at(funcEndAddr) = vec.size();

        symbolTable = oldSymbolTable;
        inFunction = false;
    }  else if(typeName == "callFunc") {
        ExecFuncNode *execFuncNode = static_cast<ExecFuncNode*>(node);
        generateByteCode(execFuncNode->params,execFuncNode->params->getType(),vec);

        IdenNode *idenNode = static_cast<IdenNode*>(execFuncNode->funcName);
        if (funcAddresses.count(idenNode->name) > 0 ) {
            vec.push_back(CALL);
            ArgumentsNode *argumentsNode = static_cast<ArgumentsNode*>(execFuncNode->params);
            vec.push_back(funcAddresses.find(idenNode->name)->second);
            vec.push_back(argumentsNode->arguments.size());
        } else {
            throw "Function <"+idenNode->name+"> not defined";
        }
    } else if(typeName == "arguments") {
        ArgumentsNode *argumentsNode = static_cast<ArgumentsNode*>(node);
        for(int p = argumentsNode->arguments.size() -1 ;p >= 0;p--){
            generateByteCode(argumentsNode->arguments[p],argumentsNode->arguments[p]->getType(),vec);
        }
    } else if(typeName == "return") {
        ReturnNode *returnNode = static_cast<ReturnNode*>(node);
        generateByteCode(returnNode->child,returnNode->child->getType(),vec);
        vec.push_back(RET);
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



