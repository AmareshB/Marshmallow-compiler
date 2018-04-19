//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_IDENNODE_H
#define SER502_SPRING2018_TEAM15_IDENNODE_H


#include "ExpNode.h"
#include <string.h>
#include <string>
#include <ostream>


class IdenNode : public ExpNode {
public:
    IdenNode( std::string &name);

private:
    std::string name;
public:
     std::string &getName() ;

    std::string getType();
};


#endif //SER502_SPRING2018_TEAM15_IDENNODE_H
