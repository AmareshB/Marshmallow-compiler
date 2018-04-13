//
// Created by Ejaz on 4/12/2018.
//

#define PUSH  0
#define POP   1
#define STORE 2
#define LOAD  3
#define ADD   4
#define SUB   5
#define MUL   6
#define DIV   7
#define MOD   8
#define EQ    9
#define NEQ   10
#define LT    11
#define GT    12
#define LTE   13
#define GTE   14
#define NOT   15
#define AND   16
#define OR    17
#define BRF   18
#define BR    19
#define CALL  20
#define RET   21
#define PRINT 22
#define EXIT  23
#define NOOP  24

typedef struct {
    int opcode;
    int nargs;
} Instruction;

static Instruction instructions[] = {
        {PUSH,  1},
        {POP,   0},
        {STORE, 1},
        {LOAD,  1},
        {ADD,   0},
        {SUB,   0},
        {MUL,   0},
        {DIV,   0},
        {MOD,   0},
        {EQ,    0},
        {NEQ,   0},
        {LT,    0},
        {GT,    0},
        {LTE,   0},
        {GTE,   0},
        {NOT,   0},
        {AND,   0},
        {OR,    0},
        {BRF,   1},
        {BR,    1},
        {CALL,  3},
        {RET,   0},
        {PRINT, 0},
        {EXIT,  0},
        {NOOP, 0}
};
