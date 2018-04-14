//
// Created by Ejaz on 4/12/2018.
//

#include <iostream>
#include "bytecode.h"
#include "runtime.h"

static int test1[] = {
        2, 0, //Starting opcode and storage mem
        PUSH, 10,
        PUSH, 20,
        DIV,
        PRINT,
        EXIT
};

int main() {
    run(test1, sizeof(test1)/4);
}