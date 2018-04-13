//
// Created by Ejaz on 4/12/2018.
//

#include <iostream>
#include "bytecode.h"
#include "runtime.h"

static int test1[] = {
        2, 0, //Starting opcode and storage mem
        //Divide 2 numbers
        PUSH, 10,
        PUSH, 20,
        DIV,
        PRINT,
        EXIT
};

static int test2[]{
        2, 1,
        //Check is number is odd or even -1 if even, -2 if odd
        PUSH, 6,
        STORE, 0,
        PUSH, 2,
        LOAD, 0,
        MOD,
        PUSH, 0,
        EQ,
        BRF, 21,
        PUSH, -1,
        PRINT,
        BR, 26,
        PUSH, -2,
        PRINT,
        BR, 26,
        EXIT

};

int main() {
    //run(test1, sizeof(test1)/ sizeof(int));
    run(test2, sizeof(test2)/ sizeof(int));
}