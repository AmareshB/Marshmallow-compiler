//
// Created by bsampat5 on 4/13/2018.
//


#include "Parser.h"
#include <iostream>
#include <compiler/utils/TreeHelper.h>
using namespace std;

Parser::Parser(const std::vector<std::string> &tokens) : tokens(tokens) {}

Node* Parser::parseIdentifier() {
    IdenNode* res = NULL;
    if(tokens[i][0]!='_' && (tokens[i][0]<'a' || tokens[i][0]>'z') && (tokens[i][0]<'A' || tokens[i][0]>'Z'))
        std::cout << "Identifier wrong "<<tokens[0]<<"at line"+instLine;
    else
    {
        res = new IdenNode(tokens[i]);
        //consume identifier
        ++i;
    }
    return res;

}
/**
  * The one generating symbol table
  * @param symbolTable
  * program ::= (stmt)+
  * @return
  */
Node* Parser::getProgram(SymbolTable &symbolTable)
{
    Node* res=NULL;
    std::vector<Node> statements;
    while(i<tokens.size())
    {
        statements.push_back(*parseStatement(symbolTable));
    }
    TreeHelper treeH;
    res = treeH.makeAST("program", statements);
    return res;
}

/**
    * stmt     ::= assignment_stmt NEWLINE
    | print_stmt NEWLINE
    | return_stmt NEWLINE
    | break_stmt NEWLINE
    | continue_stmt NEWLINE
    | exec_stmt NEWLINE
    | if_stmt
    | while_stmt
    | for_stmt
    | funcdef

    * @return
    */
Node* Parser::parseStatement( SymbolTable& symbolTable)
{
    Node* stmtNode = NULL;
    //statements
    //always do lookahead after checking LL0 first
    if(tokens[i] == "print")
    {
        stmtNode = print_stmt(symbolTable);
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<"at line"<<instLine);
            return NULL;
        }
        //consume newline
        ++i;
        ++instLine;
    }
    else if(tokens[i] == "break")
    {
        stmtNode = break_stmt();
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<"at line"<<instLine);
            return NULL;
        }
        //consume newline
        ++i;
        ++instLine;
    }
    else if(tokens[i] == "continue")
    {
        stmtNode = cont_stmt();
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<"at line"<<instLine);
            return NULL;
        }
        //consume newline
        ++i;
        ++instLine;
    }
    else if(tokens[i] == "while")
    {
        stmtNode = while_stmt(symbolTable);
    }
    else if(tokens[i] == "if")
    {
        stmtNode = if_stmt(symbolTable);
    }
    else if(tokens[i] == "function")
    {
        stmtNode = func_def(symbolTable);
    }
    else if(i+1 < tokens.size() && tokens[i+1] == "(")
    {
        stmtNode = exec_stmt(symbolTable);
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<"at line"<<instLine);
            return NULL;
        }
        //consume newline
        ++i;
        ++instLine;
    }
    else if(i+1 < tokens.size() && tokens[i+1] == "=")
    {
        stmtNode = assign_stmt(symbolTable);
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<"at line"<<instLine);
            return NULL;
        }
        //consume newline
        ++i;
        ++instLine;
    }
    //else if stay tuned for other statements
    return stmtNode;
}


/**
 * exec_stmt ::= funcname "(" arguments ")"
 * @return
 */
Node* Parser::exec_stmt(SymbolTable &symbolTable) {
    string name = "callFunc";
    Node* identifier = parseIdentifier();
    if(tokens[i]!="(")
    {
        cout<<"Missing '(' in function call"<<"at line"<<instLine);
        return NULL;
    }
    //consume "("
    ++i;
    Node* arguments = parseArguments(symbolTable);
    if(tokens[i]!=")")
    {
        cout<<"Missing ')' in function call"<<"at line"<<instLine);
        return NULL;
    }
    //consume ")"
    ++i;
    TreeHelper treeH;
    //may need symbol table second glance here
    return treeH.makeAST(name,*identifier,*arguments);
}

/**
 * funcdef ::= "function" funcname "(" parameters ")" block
*     parameters ::= identifier (',' identifier)*
 * @return
 */
Node* Parser::func_def(SymbolTable &symbolTable) {
    //consume function
    ++i;
    Node* identifier = NULL;
    identifier = parseIdentifier();
    Node* res=NULL;
    if(tokens[i]!="(")
    {
        cout<<"Missing '(' in function def"<<"at line"<<instLine;
        return NULL;
    }
    //consume "("
    ++i;
    SymbolTable* childTable = new SymbolTable();
    symbolTable.childMaps.push_back(childTable);
    childTable->parentMap = &symbolTable;
    Node* parameters = parseParameters(*childTable);
    if(tokens[i]!=")")
    {
        cout<<"Missing ')' in function def"<<"at line"<<instLine;
        return NULL;
    }
    //consume ")"
    ++i;

    //    childTable.startAddress=symbolTable.endAddress+1;
    Node* block = parseBlock(*childTable);
    TreeHelper treeHelp;
    res = treeHelp.makeAST("function",*identifier,*parameters,*block);
    return res;
}

/**
   * arguments ::= expression (‘,’expression)*
   * @return
   */
Node* Parser::parseArguments(SymbolTable &symbolTable) {
    vector<Node> argumentNodes;
    while(tokens[i]!=")")
    {
        argumentNodes.push_back(*expression(symbolTable));
        //consume ,
        if(tokens[i]==",")
            ++i;
    }
    TreeHelper treeHelp;
    Node* res = treeHelp.makeAST("arguments",argumentNodes);
    return res;
}



int main()
{
    std::vector<IdenNode *> token;
    token.push_back(new IdenNode("bala"));
    token.push_back(new IdenNode("bals"));
    std::cout<<token[0]->getName();
    token[0]->setName("Ejaz");
    std::cout<<token[0]->getName();
   // Parser* parser = new Parser(token);
    //parser -> parseIdentifier();
}


