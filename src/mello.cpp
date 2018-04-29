/*
//
// Created by Ejaz on 4/27/2018.
//

#include <string>
#include <bits/stdc++.h>
#include "runtime/runtime.h"

int main(int argc, const char* argv[]) {

    */
/*if(argc != 1)
        throw "Invalid input. e.g. melloc <input.mlw>";

    std::string program = argv[0];*//*

    std::string program = "../data/simpleProgram.o";

    std::vector<int> byteCode;
    int num;
    std::fstream fin(program, std::fstream::in);
    while (fin >> num) {
        byteCode.push_back(num);
    }
    fin.close();

    runtime *r = new runtime(&byteCode,byteCode.size());
    r->run();
    delete(r);

    return 0;

}
*/
