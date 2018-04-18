//
// Created by bsampat5 on 4/13/2018.
//

#include <string>
#include "IdenNode.h"

IdenNode::IdenNode( std::string &name) : name(name) {}

 std::string &IdenNode::getName()  {
    return name;
}



std::string IdenNode::getType() {
    return "identifier";
}



