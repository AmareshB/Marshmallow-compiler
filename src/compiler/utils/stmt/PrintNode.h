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
    Node child;
public:
    PrintNode(const std::string &name, const Node &child);

    friend std::ostream &operator<<(std::ostream &os, const PrintNode &node);
};


#endif //SER502_SPRING2018_TEAM15_PRINTNODE_H
