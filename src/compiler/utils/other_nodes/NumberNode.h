//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_NUMBERNODE_H
#define SER502_SPRING2018_TEAM15_NUMBERNODE_H


#include <ostream>
#include "ExpNode.h"

class NumberNode : public ExpNode{
public:
    NumberNode(int val);

public:
    int val;

    friend std::ostream &operator<<(std::ostream &os, const NumberNode &node);
};


#endif //SER502_SPRING2018_TEAM15_NUMBERNODE_H
