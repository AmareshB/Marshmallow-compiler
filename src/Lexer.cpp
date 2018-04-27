#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <ostream>
#include <ctype.h>
#include <stack>
#include "Lexer.h"

    Lexer::Lexer(std::vector<char> program) {

        std::stack<int> st;
        std::vector<char> input;
        std::map<std::string, std::string> Keyword;
        std::map<std::string, std::string>::iterator it;

        input = program;

        std::string Keywords[] = {"print", "and", "not", "or", "while", "if", "elif", "else", "break", "continue",
                                  "return", "function", "int", "void"};

        for (int i = 0; i < 14; i++) {
            Keyword.insert(std::pair<std::string, std::string>(Keywords[i], Keywords[i]));
        }

    }

    std::vector<std::string> Lexer::Tokenize() {
        std::vector<std::string> tokens;
        int line_number = 1;
        char c;
        int last_indent = -1;
        bool new_line = true;
        int i = 0;

        while (i < input.size()) {
            char c = input.at(i);
            if (isNewLine(c)) {
                new_line = true;
                i++;
                line_number++;
                continue;
            }
            if (new_line) {
                new_line = false;
                int indent = leadingSpaces(i);
                if (indent > last_indent) {
                    st.push(last_indent);
                    tokens.push_back("INDENT");
                    last_indent = indent;
                } else if (indent < last_indent) {
                    st.pop();
                    if (st.top() > last_indent) {
                        tokens.push_back("ERROR");
                        break;
                    }
                    tokens.push_back("DEDENT");
                    last_indent = indent;
                }
                i += indent;
                continue;
            }
            if (isspace(c)) {
                i++;
                continue;
            }

            if (isComma(c)) {
                tokens.push_back(",");
                continue;
            }

            if (c == '(') {
                tokens.push_back("(");
                i++;
                continue;
            }
            if (c == ')') {
                tokens.push_back(")");
                i++;
                continue;
            }
            if (c == '+' || c == '*' || c == '/' || c == '%') {
                std::string op = std::string(1, c);
                tokens.push_back(op);
                i++;
                continue;
            }
            if (c == '-') {
                i++;
                if (isDigit(input.at(i))) {
                    std::string sb;
                    sb += c;
                    sb += std::string(1, input.at(i));
                    i++;
                    while (i < input.size() && isDigit(input.at(i))) {
                        sb += std::string(1, input.at(i));
                        i++;
                    }
                    tokens.push_back(sb);
                } else {
                    std::string op = std::string(1, c);
                    tokens.push_back(op);

                }
            }
            if (c == '=' || c == '<' || c == '>') {
                i++;
                std::string op = std::string(1, c);
                char c1 = input.at(i);
                if (c1 == '=' || c1 == '<' || c1 == '>') {
                    op += c1;
                    tokens.push_back(op);
                    i++;
                } else {

                    if (c == '=') {
                        tokens.push_back(op);
                    } else {
                        tokens.push_back(op);
                    }
                }
                continue;
            }
            if (isAlpha(c)) {

                std::string sb;
                sb += std::string(1, c);
                i++;
                while (i < input.size() && (isAlpha(input.at(i)) || isDigit(input.at(i)))) {
                    sb += std::string(1, input.at(i));
                    i++;
                }
                if (it == Keyword.find(sb)) {
                    tokens.push_back(sb);
                } else {
                    tokens.push_back(sb);
                }
                continue;
            }
            if (isDigit(c)) {
                std::string sb;
                sb += c;
                i++;
                while (i < input.size() && isDigit(input.at(i))) {
                    sb += std::string(1, input.at(i));
                    i++;
                }
                tokens.push_back(sb);
                continue;
            }
        }
        while (last_indent > 0) {
            tokens.push_back("DEDENT");
            last_indent--;
        }
        return tokens;
    }

    bool Lexer::isDigit(char c) {
        return c >= 48 && c <= 59;
    }

    bool Lexer::isAlpha(char c) {
        return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95;
    }

    bool Lexer::isNewLine(char c) {
        return c == '\n';
    }

    int Lexer::leadingSpaces(int i) {
        int indent = 0;
        while (i < input.size() && isspace(input.at(i))) {
            i++;
            indent++;
        }
        return indent;
    }

    int Lexer::getNumber(int i) {
        int indent = 0;
        while (i < input.size() && isspace(input.at(i))) {
            i++;
            indent++;
        }
        return indent;
    }

    bool Lexer::isComma(char c) {
        if (c == ',')
            return true;
        else
            return false;
    }
};




