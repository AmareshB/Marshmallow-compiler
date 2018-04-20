//
// Created by Ejaz on 4/12/2018.
//

#ifndef SER502_SPRING2018_TEAM15_RUNTIME_H
#define SER502_SPRING2018_TEAM15_RUNTIME_H

#include <vector>

class context{

private:
    int nlocals = -1;
    std::vector<int> locals;
public:
    context *caller_context;
    int return_ip;

    context(context *caller, int ip);
    void add_local(int ind, int val);
    int get_local(int ind);
    ~context();
};

class runtime{

private:
    int *code;
    int code_len;
    int nglobals = -1;
    std::vector<int> globals;
    void run(int ip);
    void add_global(int ind, int val);
    int get_global(int ind);

public:
    runtime(std::vector<int> *c, int c_len);
    void run();
    ~runtime();
};

#endif

