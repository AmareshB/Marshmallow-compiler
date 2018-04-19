//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PROGRAMNODE_H
#define SER502_SPRING2018_TEAM15_PROGRAMNODE_H


#include <string>
#include <vector>
#include <ostream>
#include "Node.h"

class ProgramNode : public Node{
public:
    std::string name;
    ProgramNode(std::string &name,std::vector<Node*> &childStmt);
    std::string getType();

    std::vector<Node*> childStmt;
};

#endif //SER502_SPRING2018_TEAM15_PROGRAMNODE_H
