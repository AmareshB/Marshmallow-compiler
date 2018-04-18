//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_CONTINUENODE_H
#define SER502_SPRING2018_TEAM15_CONTINUENODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class ContinueNode : public StatementNode{

    std::string name;
public:
    ContinueNode(const std::string &name);

    friend std::ostream &operator<<(std::ostream &os, const ContinueNode &node);
};


#endif //SER502_SPRING2018_TEAM15_CONTINUENODE_H
