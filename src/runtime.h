//
// Created by Ejaz on 4/12/2018.
//
#include <vector>

class context{

private:
    int nlocals = -1;
    std::vector<int> locals;
public:
    context *caller_context;
    int return_ip;

    context(context *caller, int ip){

        caller_context = caller;
        return_ip = ip;
    }

    void add_local(int ind, int val){

        if(ind > nlocals){
            nlocals++;
            locals.push_back(val);
        }else{
            locals.at(ind) = val;
        };
    }

    int get_local(int ind) {

        return locals.at(ind);
    }

    ~context(){

        locals.clear();
    }
};

void run(int *code, int codelen);

void run(int *code, int codelen, int ip);

void add_global(int ind, int val);

int get_global(int ind);


