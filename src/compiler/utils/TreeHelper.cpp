//
// Created by bsampat5 on 4/13/2018.
//

#include <string>
#include <compiler/utils/other_nodes/BinaryNode.h>
#include <compiler/utils/other_nodes/UnaryNode.h>
#include <compiler/utils/stmt/AssignNode.h>
#include <compiler/utils/stmt/PrintNode.h>
#include <compiler/utils/stmt/ContinueNode.h>
#include <compiler/utils/stmt/BreakNode.h>
#include <compiler/utils/stmt/WhileNode.h>
#include <compiler/utils/stmt/ExecFuncNode.h>
#include <compiler/utils/other_nodes/ProgramNode.h>
#include <compiler/utils/other_nodes/ParametersNode.h>
#include <compiler/utils/other_nodes/ArgumentsNode.h>
#include <compiler/utils/stmt/FuncNode.h>
#include <compiler/utils/stmt/BranchNode.h>
#include <map>
#include "TreeHelper.h"
#include "BlockNode.h"

void TreeHelper::initialise() {
    map_values["%"] = mod;
    map_values["/"] = div;
    map_values["*"] = mul;
    map_values["-"] = minus ;
    map_values["+"] = plus;
    map_values["<>"] = not_equals;
    map_values["=="] = equals;
    map_values[">"] = greater_than;
    map_values["<"] = lesser_than;
    map_values[">="] = greater_equals;
    map_values["<="] = lesser_equals;
    map_values["or"] = _or;
    map_values["and"] = _and;
    map_values["not"] = _not;
    map_values["="] = assign;
    map_values["print"] = _print;
    map_values["continue"] = _continue ;
    map_values["break"] = _break;
    map_values["while"] = _while;
    map_values["callFunc"] = _callFunc;
    map_values["block"] = block;
    map_values["program"] = program;
    map_values["parameters"] = parameters;
    map_values["arguments"] = arguments;
    map_values["function"] = _function;
    map_values["else"] = _else;
    map_values["if"] = _if;
    map_values["elif"] = _elif;
};
Node* TreeHelper::makeAST(std::string name, Node& lhs, Node& rhs) {

    initialise();

    Node* resultNode = NULL;
    //will add identifier later
    switch(map_values[name])
    {
        case mod:
        case div:
        case mul:
        case minus:
        case plus:
        case not_equals:
        case equals:
        case greater_than:
        case lesser_than:
        case greater_equals:
        case lesser_equals:
        case _or:
        case _and:
            resultNode = new BinaryNode(name,lhs,rhs);
            break;
        case _not:
            resultNode = new UnaryNode(name,lhs);
            break;
        case assign:
            resultNode = new AssignNode(name,lhs,rhs);
            break;
        case _print:
            resultNode = new PrintNode(name,lhs);
            break;
        case _continue:
            resultNode = new ContinueNode(name);
            break;
        case _break:
            resultNode = new BreakNode(name);
            break;
        case _while:
            resultNode = new WhileNode(name,lhs,rhs);
            break;
        case _callFunc:
            resultNode = new ExecFuncNode(name,lhs,rhs);
    }
    return resultNode;
}

Node* TreeHelper::makeAST(std::string name, std::vector<Node> &nodes) {
    initialise();
    Node* resultNode = NULL;
    //will add identifier later
    switch(map_values[name])
    {
        case block:
            resultNode = new BlockNode(name,nodes);
            break;
        case program:
            resultNode = new ProgramNode(name,nodes);
            break;
        case parameters:
            resultNode = new ParametersNode(name,nodes);
            break;
        case arguments:
            resultNode = new ArgumentsNode(name,nodes);
            break;
    }
    return resultNode;
}

Node* TreeHelper::makeAST(std::string name, Node &exp, Node &newNode1, Node &newNode2) {
    initialise();
    Node* resultNode = NULL;
    switch(map_values[name])
    {
        case _function:
            resultNode = new FuncNode(name,exp,newNode1,newNode2);
            break;
        case _else:
        case _if:
        case _elif:
            resultNode = new BranchNode(name,exp,newNode1,newNode2);
    }
    return resultNode;
}
