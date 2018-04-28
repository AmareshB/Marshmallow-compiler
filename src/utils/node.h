//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_NODE_H
#define SER502_SPRING2018_TEAM15_NODE_H


#include <string>
#include <vector>

class Node {

public:
    virtual std::string getType();
};

class ExpNode : public Node{
public:
    virtual std::string getType();
};

class BinaryNode: public ExpNode {
public:
    std::string name;
    Node *lhs,*rhs;
    BinaryNode(const std::string &name, Node *lhs, Node *rhs);
    std::string getType();
};

class UnaryNode : public ExpNode{
public:
    std::string name;
    Node* onlyChild;
    UnaryNode( std::string &name, Node *onlyChild);
    std::string getType();
};

class ProgramNode : public Node{
public:
    std::string name;
    ProgramNode(std::string &name,std::vector<Node*> &childStmt);
    std::string getType();
    std::vector<Node*> childStmt;
};

class BlockNode : public Node{
public:
    std::string name;
    std::vector<Node*> childStmt;
    BlockNode( std::string &name,  std::vector<Node*> &childStmt);
    std::string getType();
};

class IdenNode : public ExpNode {
public:
    IdenNode( std::string &name);
    std::string name;
    std::string &getName();
    std::string getType();
};

class NumberNode : public ExpNode{
public:
    NumberNode(int v);
    int val;
    std::string getType();
};

class ParametersNode : public Node {
public:
    std::string name;
    std::vector<Node*> parameters;
    ParametersNode( std::string &name,  std::vector<Node*> &parameters);
    std::string getType();
};

class ArgumentsNode : public ExpNode{
public:
    std::string name;
    std::vector<Node*> arguments;
    ArgumentsNode( std::string &name,  std::vector<Node*> &arguments);
    std::string getType();
};

class StatementNode : public Node{
public:
    virtual std::string getType();

};

class AssignNode : public StatementNode{
public:
    std::string name;
    Node* lhs;
    Node* rhs;
    AssignNode( std::string &name, Node *lhs, Node *rhs);
    std::string getType();
};

class BranchNode : public StatementNode{
public:
    std::string name;
    Node* condition;
    Node* bodyBlock;
    Node* branch;
    BranchNode( std::string &name, Node *condition, Node *bodyBlock, Node *branch);
    std::string getType();
};

class BreakNode : public StatementNode {
public:
    std::string name;
    BreakNode( std::string &name);
    std::string getType();
};

class ContinueNode : public StatementNode{
public:
    std::string name;
    ContinueNode( std::string &name);
    std::string getType();
};

class ExecFuncNode : public StatementNode{
public:
    std::string name;
    Node* funcName;
    Node* params;
    ExecFuncNode( std::string &name, Node *funcName, Node *params);
    std::string getType();
};

class FuncNode : public StatementNode{
public:
    std::string name;
    Node* parameters;
    Node* block;
    Node* identifier;
    std::string getType();
    FuncNode(std::string &name, Node *identifier, Node *parameters, Node *block);
};

class PrintNode : public StatementNode {
public:
    std::string name;
    Node* child;
    PrintNode( std::string &name, Node *child);
    std::string getType();
};

class ReturnNode : public StatementNode{
public:
    std::string name;
    Node* child;
    ReturnNode( std::string &name, Node *child);
    std::string getType();
};

class WhileNode : public StatementNode{
public:
    std::string name;
    Node* expression;
    Node* block;
    WhileNode( std::string &name, Node *expression, Node *block);
    std::string getType();
};
#endif //SER502_SPRING2018_TEAM15_NODE_H