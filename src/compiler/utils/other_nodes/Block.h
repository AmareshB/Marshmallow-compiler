//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_BLOCK_H
#define SER502_SPRING2018_TEAM15_BLOCK_H


#include <vector>
#include <string>
#include <ostream>
#include "Node.h"

class Block : public Node {

    std::string name;
    std::vector<Node> childStmt;
public:
    Block(const std::string &name, const std::vector<Node> &childStmt);

    friend std::ostream &operator<<(std::ostream &os, const Block &block);
};


#endif //SER502_SPRING2018_TEAM15_BLOCK_H
