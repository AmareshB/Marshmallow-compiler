//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PRINTNODE_H
#define SER502_SPRING2018_TEAM15_PRINTNODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class PrintNode : public StatementNode {

    std::string name;
    Node* child;
public:
    PrintNode( std::string &name, Node *child);

    std::string getType();

};


#endif //SER502_SPRING2018_TEAM15_PRINTNODE_H
