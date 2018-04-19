//
// Created by bsampat5 on 4/13/2018.
//

#ifndef SER502_SPRING2018_TEAM15_PARAMETERSNODE_H
#define SER502_SPRING2018_TEAM15_PARAMETERSNODE_H


#include <string>
#include <vector>
#include <ostream>
#include "Node.h"

class ParametersNode : public Node {

    std::string name;
    std::vector<Node*> parameters;
public:
    ParametersNode( std::string &name,  std::vector<Node*> &parameters);
    std::string getType();


};


#endif //SER502_SPRING2018_TEAM15_PARAMETERSNODE_H
