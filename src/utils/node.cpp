//
// Created by Balachandar on 13-04-2018.
//

#include "node.h"

std::string Node::getType() {return "node";}

std::string UnaryNode::getType() {return "unary";}
UnaryNode::UnaryNode(std::string &name, Node *onlyChild) : name(name), onlyChild(onlyChild) {}

std::string BinaryNode::getType() {return "binaryNode";}
BinaryNode::BinaryNode(const std::string &name, Node *lhs, Node *rhs) : name(name), lhs(lhs), rhs(rhs) {}

ProgramNode::ProgramNode( std::string &name, std::vector<Node*> &childStmt) : name(name), childStmt(childStmt) {}
std::string ProgramNode::getType() {return name;}

std::string ExpNode::getType() {return "expnode";}

BlockNode::BlockNode( std::string &name,  std::vector<Node*> &childStmt) : name(name), childStmt(childStmt) {}
std::string BlockNode::getType() {return "block";}

NumberNode::NumberNode(int v){val = v;}
std::string NumberNode::getType() {return "number";}

IdenNode::IdenNode( std::string &name) : name(name) {}
std::string &IdenNode::getName()  {return name;}
std::string IdenNode::getType() {return "identifier";}

ParametersNode::ParametersNode( std::string &name,  std::vector<Node*> &parameters) : name(name), parameters(parameters) {}
std::string ParametersNode::getType() {return name;}

ArgumentsNode::ArgumentsNode( std::string &name,  std::vector<Node*> &arguments) : name(name), arguments(arguments) {}
std::string ArgumentsNode::getType() {return name;}

std::string StatementNode::getType() {return "statement";}

std::string AssignNode::getType() {return "assign";}
AssignNode::AssignNode(std::string &name, Node *lhs, Node *rhs) : name(name), lhs(lhs), rhs(rhs) {}

std::string BranchNode::getType() {return name;}
BranchNode::BranchNode( std::string &name, Node *condition, Node *bodyBlock, Node *branch) : name(name), condition(condition), bodyBlock(bodyBlock), branch(branch) {}

BreakNode::BreakNode( std::string &name) : name(name) {}
std::string BreakNode::getType() {return name;}

ContinueNode::ContinueNode( std::string &name) : name(name) {}
std::string ContinueNode::getType() {return name;}

std::string ExecFuncNode::getType() {return name;}
ExecFuncNode::ExecFuncNode( std::string &name, Node *funcName, Node *params) : name(name), funcName(funcName), params(params) {}

std::string FuncNode::getType() {return name;}
FuncNode::FuncNode( std::string &name, Node *identifier, Node *parameters, Node *block) : name(name), parameters(parameters), block(block), identifier(identifier) {}

std::string PrintNode::getType() {return name;}
PrintNode::PrintNode( std::string &name, Node *child) : name(name), child(child) {}

std::string ReturnNode::getType() {return name;}
ReturnNode::ReturnNode( std::string &name, Node *child) : name(name), child(child) {}

std::string WhileNode::getType() {return name;}
WhileNode::WhileNode( std::string &name, Node *expression, Node *block) : name(name), expression(expression), block(block) {}