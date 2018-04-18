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


};


#endif //SER502_SPRING2018_TEAM15_NUMBERNODE_H
