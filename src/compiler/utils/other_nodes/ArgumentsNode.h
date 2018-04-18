//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_ARGUMENTSNODE_H
#define SER502_SPRING2018_TEAM15_ARGUMENTSNODE_H


#include <string>
#include <vector>
#include <ostream>
#include "ExpNode.h"

class ArgumentsNode : public ExpNode{
    std::string name;
    std::vector<Node*> arguments;
public:
    ArgumentsNode(const std::string &name, const std::vector<Node*> &arguments);


};


#endif //SER502_SPRING2018_TEAM15_ARGUMENTSNODE_H
