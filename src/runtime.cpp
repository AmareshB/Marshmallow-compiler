//
// Created by Ejaz on 4/12/2018.
//
// Runtime for Marshmellow
//


#include <iostream>
#include "bytecode.h"
#include "runtime.h"

#define STACK_SIZE 200
#define TRUE 1
#define FALSE 0


    void run(int *code, int codelen) {
        int ip = 0;
        int sp = -1;
        int a = 0;
        int b = 0;
        int saddr = 0;
        int iaddr = 0;

        int storage[code[1]];
        int stack[STACK_SIZE];
        ip = code[0];
        int opcode = code[ip];

        while (opcode != EXIT && ip < codelen) {
            ip++;
            switch (opcode) {
                case PUSH:
                    stack[++sp] = code[ip++];
                    break;
                case POP:
                    sp--;
                    break;
                case STORE:
                    storage[code[ip++]] = stack[sp--];
                    break;
                case LOAD:
                    stack[++sp] = storage[code[ip++]];
                    break;
                case ADD:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a + b;
                    break;
                case SUB:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a - b;
                    break;
                case MUL:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a * b;
                    break;
                case DIV:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a / b;
                    break;
                case MOD:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a % b;
                    break;
                case EQ:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a == b ? TRUE : FALSE;
                    break;
                case NEQ:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a != b ? TRUE : FALSE;
                    break;
                case LT:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a < b ? TRUE : FALSE;
                    break;
                case GT:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a > b ? TRUE : FALSE;
                    break;
                case LTE:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a <= b ? TRUE : FALSE;
                    break;
                case GTE:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a >= b ? TRUE : FALSE;
                    break;
                case NOT:
                    a = stack[sp--];
                    stack[++sp] = !a;
                    break;
                case AND:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a & b;
                    break;
                case OR:
                    a = stack[sp--];
                    b = stack[sp--];
                    stack[++sp] = a | b;
                    break;
                case PRINT:
                    a = stack[sp--];
                    std::cout << a << std::endl;
                    break;
                case BRF:
                    a = stack[sp--];
                    if(a == FALSE)
                        ip = code[ip];
                    else
                        ip++;
                    break;
                case BR:
                    ip = code[ip];
                    break;
            }
            opcode = code[ip];
        }
    }