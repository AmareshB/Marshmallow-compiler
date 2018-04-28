//
// Created by Ejaz on 4/12/2018.
//
// Runtime for Marshmallow
//


#include <iostream>
#include <vector>
#include "../utils/opcodes.h"
#include "runtime.h"

#define STACK_SIZE 200
#define TRUE 1
#define FALSE 0

context::context(context *caller, int ip) {
    caller_context = caller;
    return_ip = ip;
    locals.clear();
}

void context::add_local(int ind, int val){
    if(ind > nlocals){
        nlocals++;
        locals.push_back(val);
    }else{
        locals.at(ind) = val;
    };
}

int context::get_local(int ind) {
    return locals.at(ind);
}

context::~context(){
     //locals.push_back(-1);
     locals.clear();
}

runtime::runtime(std::vector<int> *c, int c_len){
    code = c->data();
    code_len = c_len;
    globals.clear();
}

void runtime::add_global(int ind, int val){
    if(ind > nglobals){
        nglobals++;
        globals.push_back(val);
    }else{
        globals.at(ind) = val;
    };
}

int runtime::get_global(int ind){
    return globals.at(ind);
}

void runtime::run() {
    int ip = code[0];
    run(ip);
}

void runtime::run(int ip) {
    int sp = -1;
    int a = 0;
    int b = 0;

    int stack[STACK_SIZE];
    int opcode = code[ip];
    context *ctx = new context(NULL, 0);
    while (ip < code_len) {
        ip++;
        switch (opcode) {
            case PUSH: {
                stack[++sp] = code[ip++];
                break;
            }
            case POP: {
                sp--;
                break;
            }
            case STORE: {
                ctx->add_local(code[ip++], stack[sp--]);
                break;
            }
            case LOAD: {
                stack[++sp] = ctx->get_local(code[ip++]);
                break;
            }
            case GSTORE: {
                add_global(code[ip++], stack[sp--]);
                break;
            }
            case GLOAD: {
                stack[++sp] = get_global(code[ip++]);
                break;
            }
            case ADD: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a + b;
                break;
            }
            case SUB: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a - b;
                break;
            }
            case MUL: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a * b;
                break;
            }
            case DIV: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a / b;
                break;
            }
            case MOD: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a % b;
                break;
            }
            case EQ: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a == b ? TRUE : FALSE;
                break;
            }
            case NEQ: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a != b ? TRUE : FALSE;
                break;
            }
            case LT: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a < b ? TRUE : FALSE;
                break;
            }
            case GT: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a > b ? TRUE : FALSE;
                break;
            }
            case LTE: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a <= b ? TRUE : FALSE;
                break;
            }
            case GTE: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a >= b ? TRUE : FALSE;
                break;
            }
            case NOT: {
                a = stack[sp--];
                stack[++sp] = !a;
                break;
            }
            case AND: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a & b;
                break;
            }
            case OR: {
                a = stack[sp--];
                b = stack[sp--];
                stack[++sp] = a | b;
                break;
            }
            case PRINT: {
                a = stack[sp--];
                std::cout << a << std::endl;
                break;
            }
            case BRF: {
                a = stack[sp--];
                if (a == FALSE)
                    ip = code[ip];
                else
                    ip++;
                break;
            }
            case BR: {
                ip = code[ip];
                break;
            }
            case NOOP: {
                ip++;
                break;
            }
            case CALL: {
                int new_ip = code[ip++];
                a = code[ip++]; //Param count
                context *new_ctx = new context(ctx, ip);
                ctx = new_ctx;
                for (int i = 0; i < a; i++) {
                    ctx->add_local(i, stack[sp--]);
                }
                ip = new_ip;
                break;
            }
            case RET: {
                context *old_ctx = ctx;
                ip = ctx->return_ip;
                ctx = ctx->caller_context;
                delete (old_ctx);
                break;
            }
            case EXIT: {
                std::cout << "Program exited successfully" << std::endl;
                delete (ctx);
                return;
            }
            default: {
                std::cout << "Program exited due to invalid op-code. Something went wrong." << std::endl;
                delete (ctx);
                return;
            }
        }
        opcode = code[ip];
    }
}

runtime::~runtime() {
    globals.clear();
}
