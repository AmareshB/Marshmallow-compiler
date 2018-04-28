//
// Created by Ejaz on 4/27/2018.
//

#include <string>
#include "utils/SymbolTable.h"
#include "compiler/parser.h"
#include "compiler/lexer.h"
#include "compiler/bytecode.h"
#include "runtime/runtime.h"

int main(int argc, const char* argv[]) {

    /*if(argc != 1)
        throw "Invalid input. e.g. melloc <input.mlw>";

    std::string program = argv[0];*/
    std::string program = "../data/simpleProgram.mlw";

    std::vector<char> programbuff;
    char ch;
    std::fstream fin(program, std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        programbuff.push_back(ch);
    }
    fin.close();

    Lexer *lexer = new Lexer(programbuff);
    std::vector<std::string> tokens = lexer->Tokenize();

    SymbolTable *symbolTable = new SymbolTable();
    Parser *parser = new Parser(tokens);
    Node* ast = parser->getProgram(*symbolTable);

    std::vector<int> byteCode;
    bytecode *b = new bytecode(symbolTable);
    b->generateByteCode(ast,ast->getType(),byteCode);

    runtime *r = new runtime(&byteCode,byteCode.size());
    r->run();
    for(int j=0; j<byteCode.size(); j++)
        std::cout<< byteCode[j] << ' ';

    std::string output = program.replace(program.length()-3,3,"o") ;
    std::ofstream fout(output, std::ios::out | std::ios::binary);
    fout.write((char*)&byteCode[0], byteCode.size() * sizeof(byteCode));
    fout.close();
    return 0;
}
