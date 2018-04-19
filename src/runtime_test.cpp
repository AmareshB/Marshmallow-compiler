//
// Created by Ejaz on 4/12/2018.
//

#include <iostream>
#include "bytecode.h"
#include "runtime.h"

static int test1[] = {
        1, //Starting opcode and storage mem
        //Divide 2 numbers
        PUSH, 10, //1
        PUSH, 20, //3
        DIV,      //5
        PRINT,    //6
        EXIT      //7
};

static int test2[]{
        1,
        //Check is number is odd or even, -1 if even, -2 if odd
        PUSH, 5,  //1
        STORE, 0, //3
        PUSH, 2,  //5
        LOAD, 0,  //7
        MOD,      //9
        PUSH, 0,  //10
        EQ,       //12
        BRF, 20,  //13
        PUSH, -1, //15
        PRINT,    //17
        BR, 25,   //18
        PUSH, -2, //20
        PRINT,    //22
        BR, 25,   //23
        EXIT      //25

};

static int test3[] = {
        1,
        //prints even numbers from 20 - 0
        PUSH, 20,   //1
        GSTORE, 0,  //3
        PUSH, 0,    //5
        GLOAD, 0,   //7
        GT,         //9
        BRF, 36,    //10
        PUSH, 2,    //12
        GLOAD, 0,   //14
        MOD,        //16
        PUSH, 0,    //17
        EQ,         //19
        BRF, 27,    //20
        GLOAD, 0,   //22
        PRINT,      //24
        BR, 27,     //25
        PUSH, 1,    //27
        GLOAD, 0,   //29
        SUB,        //31
        GSTORE, 0,  //32
        BR, 5,     //34
        EXIT        //36

};
static int test4[] = {
        23,
// Factorial of a number
//	IF N < 2 RETURN 1
        PUSH, 2,              // 1
        LOAD, 0,              // 3
        LT,                   // 5
        BRF, 11,              // 6
        PUSH, 1,              // 8
        RET,                  // 10
//	RETURN N * FACT(N-1)
        PUSH, 1,              // 11
        LOAD, 0,              // 13
        SUB,                  // 15
        CALL, 1, 1,           // 16
        LOAD, 0,              // 19
        MUL,                  // 21
        RET,                  // 22
// MAIN
        PUSH, 5,              // 23
        CALL, 1, 1,           // 25
        PRINT,                // 28
        EXIT                  // 29
};

int main() {

    runtime *r;

    r = new runtime(test1, sizeof(test1)/ sizeof(int)); r->run();
    r = new runtime(test2, sizeof(test2)/ sizeof(int)); r->run();
    r = new runtime(test3, sizeof(test3)/ sizeof(int)); r->run();
    r = new runtime(test4, sizeof(test4)/ sizeof(int)); r->run();
    delete(r);
}