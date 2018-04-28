//
// Created by Ejaz on 4/27/2018.
//

#include <string>
#include <compiler/utils/SymbolTable.h>
#include <compiler/Parser.h>
#include "melloc.h"
#include "Lexer.h"
#include "bytecode.h"
#include "runtime.h"

int main(int argc, const char* argv[]) {

    /*if(argc != 1)
        throw "Invalid input. e.g. melloc <input.mlw>";

    std::string program = argv[0];*/
    std::string program = "../data/simpleProgram.o";

    std::vector<int> byteCode;
    int num;
    std::fstream fin(program, std::fstream::in);
    while (fin >> std::noskipws >> num) {
        byteCode.push_back(num);
    }
    fin.close();

    runtime *r = new runtime(&byteCode,byteCode.size());
    r->run();
    delete(r);

    return 0;

}
