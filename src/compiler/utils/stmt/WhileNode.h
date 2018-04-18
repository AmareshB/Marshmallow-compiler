//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_WHILENODE_H
#define SER502_SPRING2018_TEAM15_WHILENODE_H


#include <string>
#include <ostream>
#include "StatementNode.h"

class WhileNode : public StatementNode{

    std::string name;
    Node expression;
    Node block;
public:
    WhileNode(const std::string &name, const Node &expression, const Node &block);

    friend std::ostream &operator<<(std::ostream &os, const WhileNode &node);
};


#endif //SER502_SPRING2018_TEAM15_WHILENODE_H
