//
// Created by Ejaz on 4/12/2018.
//

#include <iostream>
#include "../compiler/bytecode.h"
#include "../runtime/runtime.h"
#include "../utils/opcodes.h"

static int test1[] = {
        //Divide 2 numbers
        PUSH, 10, //0
        PUSH, 20, //2
        DIV,      //4
        PRINT,    //5
        EXIT      //6
};

static int test2[]{
        //Check is number is odd or even, -1 if even, -2 if odd
        PUSH, 5,  //0
        STORE, 0, //2
        PUSH, 2,  //4
        LOAD, 0,  //6
        MOD,      //8
        PUSH, 0,  //9
        EQ,       //11
        BRF, 19,  //12
        PUSH, -1, //14
        PRINT,    //16
        BR, 25,   //17
        PUSH, -2, //19
        PRINT,    //21
        BR, 25,   //22
        EXIT      //24

};

static int test3[] = {
        //prints even numbers from 20 - 0
        PUSH, 20,   //0
        GSTORE, 0,  //2
        PUSH, 0,    //4
        GLOAD, 0,   //6
        GT,         //8
        BRF, 35,    //9
        PUSH, 2,    //11
        GLOAD, 0,   //13
        MOD,        //15
        PUSH, 0,    //16
        EQ,         //18
        BRF, 26,    //19
        GLOAD, 0,   //21
        PRINT,      //23
        BR, 26,     //24
        PUSH, 1,    //26
        GLOAD, 0,   //28
        SUB,        //30
        GSTORE, 0,  //31
        BR, 4,      //33
        EXIT        //35

};
static int test4[] = {
        BR, 24,               // 0
// Factorial of a number
//	IF N < 2 RETURN 1
        PUSH, 2,              // 2
        LOAD, 0,              // 4
        LT,                   // 6
        BRF, 12,              // 7
        PUSH, 1,              // 9
        RET,                  // 11
//	RETURN N * FACT(N-1)
        PUSH, 1,              // 12
        LOAD, 0,              // 14
        SUB,                  // 16
        CALL, 2, 1,           // 17
        LOAD, 0,              // 20
        MUL,                  // 22
        RET,                  // 23
// MAIN
        PUSH, 5,              // 24
        CALL, 2, 1,           // 26
        PRINT,                // 29
        EXIT                  // 30
};

int main() {

    runtime *r;
    std::vector<int> test11(test1, test1 + sizeof test1 / sizeof test1[0]);
    r = new runtime(&test11, sizeof(test1)/ sizeof(int)); r->run();
    std::vector<int> test22(test2, test2 + sizeof test2 / sizeof test2[0]);
    r = new runtime(&test22, sizeof(test2)/ sizeof(int)); r->run();
    std::vector<int> test33(test3, test3 + sizeof test3 / sizeof test3[0]);
    r = new runtime(&test33, sizeof(test3)/ sizeof(int)); r->run();
    std::vector<int> test44(test4, test4 + sizeof test4 / sizeof test4[0]);
    r = new runtime(&test44, sizeof(test4)/ sizeof(int)); r->run();
    delete(r);
}