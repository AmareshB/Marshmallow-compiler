//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_EXECFUNCNODE_H
#define SER502_SPRING2018_TEAM15_EXECFUNCNODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class ExecFuncNode : public StatementNode{

public:
    std::string name;
    Node* funcName;
    Node* params;


    ExecFuncNode( std::string &name, Node *funcName, Node *params);

    std::string getType();


};


#endif //SER502_SPRING2018_TEAM15_EXECFUNCNODE_H
