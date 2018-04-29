//
// Created by Ejaz on 4/27/2018.
//

#include <string>
#include <bits/stdc++.h>
#include "runtime/runtime.h"

int main(int argc, const char* argv[]) {

if(argc != 1)
        throw "Invalid input. e.g. melloc <input.mlw>";

    std::string program = argv[0];

    std::string program = "../data/simpleProgram.o";

    std::vector<int> byteCode;
    char byte[sizeof(int)];
    std::ifstream ipstream;
    ipstream.open(program, std::ios::in | std::ios::binary);
    while( ipstream.read(byte, sizeof(int) ) ) {
        int num = 1;
        if(*(char *)&num == 1){
            byteCode.push_back((byte[3] << 24) | (byte[2] << 16) | (byte[1] << 8) | (byte[0])); //little endian
        } else {
            byteCode.push_back((byte[0] << 24) | (byte[1] << 16) | (byte[2] << 8) | (byte[0])); //big endian
        }
    }

    runtime *r = new runtime(&byteCode,byteCode.size());
    r->run();
    delete(r);

    return 0;

}
