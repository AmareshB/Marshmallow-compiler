//
// Created by Balachandar on 25-04-2018.
//

#ifndef SER502_SPRING2018_TEAM15_RETURNNODE_H
#define SER502_SPRING2018_TEAM15_RETURNNODE_H


#include "StatementNode.h"

class ReturnNode : public StatementNode{

public:
    std::string name;
    Node* child;
    ReturnNode( std::string &name, Node *child);

    std::string getType();

};


#endif //SER502_SPRING2018_TEAM15_RETURNNODE_H
