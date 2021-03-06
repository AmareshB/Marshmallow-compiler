//
// Created by bsampat5 on 4/13/2018.
//


#include "parser.h"
#include <iostream>
#include "../utils/treeHelper.h"
#include "../utils/node.h"

using namespace std;

static int blockCount = 0;

Parser::Parser(const std::vector<std::string> &tokens) : tokens(tokens) {}


/**
 * traverse up till you get a identifierName in symbol table
 * @param idenName
 * @param symbolTable
 * @return true if found
 */
bool Parser::lookup(string idenName, SymbolTable &symbolTable) {


    if(symbolTable.symbolTableMap.count(idenName) > 0)
    {
        return true;
    }
    else if(symbolTable.parentMap!= nullptr)
    {
        return lookup(idenName,*symbolTable.parentMap);
    }
    else if(&symbolTable!=globalSymbolTable)
    {
        if(globalSymbolTable->symbolTableMap.count(idenName) > 0)
            return true;
    }
    return false;
}

/**
  * The one generating symbol table
  * @param symbolTable
  * program ::= (stmt)+
  * @return
  */
Node* Parser::getProgram(SymbolTable &symbolTable)
{
    globalSymbolTable = &symbolTable;
    Node* res=nullptr;
    std::vector<Node *> statements;
    while(i<tokens.size())
    {
        statements.push_back(parseStatement(symbolTable));
    }
    TreeHelper treeH;
    res = treeH.makeAST("program", statements);
    return res;
}

/**
 * block ::= NEWLINE INDENT (stmt )+ DEDENT
 * @return
 */
Node* Parser::parseBlock(SymbolTable &symbolTable,std::string type)
{
    SymbolTable *newSymbolTable = new SymbolTable();
    int currentBlockCount;
    if(type != "function"){
        newSymbolTable->parentMap = &symbolTable;
        if(&symbolTable == globalSymbolTable){
            newSymbolTable->currentAddress = -1;
        }else {
            newSymbolTable->currentAddress = symbolTable.currentAddress;
        }
        blockCount++;
        currentBlockCount = blockCount;
        symbolTable.childMaps.insert({"block"+to_string(currentBlockCount), newSymbolTable});
    }

    //symbolTable = *newSymbolTable;
    std::vector<Node*> statements;
    if(tokens[i] != "NEWLINE")
    {
        cout<<"No new line found at "<<tokens[i]<<" at line  "+instLine;
        exit(-1);
    }
    //consume newline
    ++i;
    ++instLine;
    if(tokens[i] == "INDENT")
    {
        //consume indent
        ++i;
        while (true)
        {
            if(tokens[i] == "DEDENT")
            {
                break;
            }
            else
            {
                if(type != "function") {
                    statements.push_back(parseStatement(*newSymbolTable));
                } else {
                    statements.push_back(parseStatement(symbolTable));
                }
            }
        }
        //symbolTable = *symbolTable.parentMap;
        //consume dedent
        ++i;
        TreeHelper treeHelper;
        return treeHelper.makeAST("block"+to_string(currentBlockCount),statements);
    }
    else
    {
        cout<<"no indent inside block"<<tokens[i]<<" at line "<<instLine;
        exit(-1);
    }
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
    Node* stmtNode = nullptr;
    //statements
    //always do lookahead after checking LL0 first
    if(tokens[i] == "print")
    {
        stmtNode = print_stmt(symbolTable);
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<" at line "<<instLine;
            exit(-1);
        }
        //consume newline
        ++i;
        ++instLine;
    }
    else  if(tokens[i] == "return")
    {
        stmtNode = return_stmt(symbolTable);
        if(tokens[i]!="NEWLINE")
        {
            cout<<"No Newline found at "<<tokens[i]<<" at line "<<instLine;
            exit(-1);
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
            cout<<"No Newline found at "<<tokens[i]<<" at line "<<instLine;
            exit(-1);
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
            cout<<"No Newline found at "<<tokens[i]<<" at line "<<instLine;
            exit(-1);
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
            cout<<"No Newline found at "<<tokens[i]<<" at line "<<instLine;
            exit(-1);
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
            cout<<"No Newline found at "<<tokens[i]<<" at line "<<instLine;
            exit(-1);
        }
        //consume newline
        ++i;
        ++instLine;
    } else
    {
        cout<<"Bad syntax "<<tokens[i]<<" at line "<<instLine;
        exit(-1);
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
        cout<<"Missing '(' in function call"<<" at line "<<instLine;
        exit(-1);
    }
    //consume "("
    ++i;
    Node* arguments = parseArguments(symbolTable);
    if(tokens[i]!=")")
    {
        cout<<"Missing ')' in function call"<<" at line "<<instLine;
        exit(-1);
    }
    //consume ")"
    ++i;
    TreeHelper treeH;
    //may need symbol table second glance here
    return treeH.makeAST(name,identifier,arguments);
}

/**
 * funcdef ::= "function" funcname "(" parameters ")" block
*     parameters ::= identifier (',' identifier)*
 * @return
 */
Node* Parser::func_def(SymbolTable &symbolTable) {
    //consume function
    ++i;
    Node* identifier = nullptr;
    identifier = parseIdentifier();
    Node* res=nullptr;
    if(tokens[i]!="(")
    {
        cout<<"Missing '(' in function def"<<" at line "<<instLine;
        exit(-1);
    }
    //consume "("
    ++i;
    //SymbolTable* childTable = new SymbolTable();
    //symbolTable.childMaps.push_back(childTable);

    //childTable->parentMap = &symbolTable;
    SymbolTable *newSymbolTable = new SymbolTable();
    newSymbolTable->currentAddress = -1;
    newSymbolTable->parentMap = nullptr;
    blockCount++;
    symbolTable.childMaps.insert({(static_cast<IdenNode*> (identifier))->name, newSymbolTable});
    Node* parameters = parseParameters(*newSymbolTable);
    if(tokens[i]!=")")
    {
        cout<<"Missing ')' in function def"<<" at line "<<instLine;
        exit(-1);
    }
    //consume ")"
    ++i;

    //    childTable.startAddress=symbolTable.endAddress+1;
    Node* block = parseBlock(*newSymbolTable,"function");
    TreeHelper treeHelp;
    res = treeHelp.makeAST("function",identifier,parameters,block);
    return res;
}

/**
   * arguments ::= expression (‘,’expression)*
   * @return
   */
Node* Parser::parseArguments(SymbolTable &symbolTable) {
    vector<Node*> argumentNodes;
    while(tokens[i]!=")")
    {
        argumentNodes.push_back(expression(symbolTable));
        //consume ,
        if(tokens[i]==",")
            ++i;
    }
    TreeHelper treeHelp;
    Node* res = treeHelp.makeAST("arguments",argumentNodes);
    return res;
}

/**
   * parameters ::= identifier (',' identifier)*
   * @return
   */
Node* Parser::parseParameters(SymbolTable &symbolTable) {
    vector<Node*> parametersNodes;
    while(tokens[i]!=")")
    {
        IdenNode* iden = static_cast<IdenNode *>(parseIdentifier());
        parametersNodes.push_back(iden);
        std::string name = iden->getName();
        symbolTable.symbolTableMap.emplace(name,++symbolTable.currentAddress);
        //consume ,
        if(tokens[i]==",")
            ++i;
    }
    TreeHelper treeHelp;
    Node* res = treeHelp.makeAST("parameters",parametersNodes);
    return res;
}



/**
 if_stmt ::= "if" expression block
            ( "elif" expression block )*
            ("else" block)?
 * @return
 */
Node* Parser::if_stmt(SymbolTable &symbolTable) {
    Node* res = nullptr;
    Node* exp = nullptr;
    Node* block = nullptr;
    Node* newBranch = nullptr;
    string name = "";
    //SymbolTable* childTable = new SymbolTable();
    //symbolTable.childMaps.push_back(childTable);
    //childTable->parentMap = &symbolTable;
    if(tokens[i]=="if" || tokens[i]=="elif")
    {
        name = tokens[i];
        //consume if
        ++i;
        exp = expression(symbolTable);
        block = parseBlock(symbolTable,"");
        if(i<tokens.size() && (tokens[i]=="elif" || tokens[i]=="else"))
        {
            newBranch = if_stmt(symbolTable);
        }
    }
    else if(tokens[i]=="else")
    {
        name = tokens[i];
        //consume else
        ++i;
        block = parseBlock(symbolTable,"");
    }
    TreeHelper treeHelp;
    res = treeHelp.makeAST(name,exp,block,newBranch);
    return res;
}


/**
 * while_stmt ::= "while" expression block
 * @return
 */
Node* Parser::while_stmt(SymbolTable &symbolTable) {
    //consume while
    ++i;
    Node* exp = expression(symbolTable);
    //SymbolTable* childTable = new SymbolTable();
    //symbolTable.childMaps.push_back(childTable);
    //childTable->parentMap = &symbolTable;
    Node* block = parseBlock(symbolTable,"");
    TreeHelper treeHelper;
    return treeHelper.makeAST("while",exp,block);
}

/**
 * continue ::= “continue”
 * @return
 */
Node* Parser::cont_stmt() {
    //consume continue
    ++i;
    TreeHelper treeHelper;
    Node* lhs = nullptr;
    Node* rhs = nullptr;
    return treeHelper.makeAST("continue",lhs,rhs);
}

/**
 * break ::= “break”
 * @return
 */
Node* Parser::break_stmt() {
    //consume break
    ++i;
    TreeHelper treeHelper;
    Node* lhs = nullptr;
    Node* rhs = nullptr;
    return treeHelper.makeAST("break",lhs,rhs);
}

/**
 * print ::= “print” expression
 * @param symbolTable
 * @return
 */
Node* Parser::print_stmt(SymbolTable &symbolTable) {
    //consume print
    ++i;
    Node* res = expression(symbolTable);
    Node* rhs = nullptr;
    TreeHelper treeHelper;
    res = treeHelper.makeAST("print",res,rhs);
    return res;
}

/**
 * return ::= “return” expression
 * @param symbolTable
 * @return
 */
Node* Parser::return_stmt(SymbolTable &symbolTable) {
    //consume print
    ++i;
    Node* res = expression(symbolTable);
    Node* rhs = nullptr;
    TreeHelper treeHelper;
    res = treeHelper.makeAST("return",res,rhs);
    return res;
}

/**
 * assignment_stmt ::= identifier "=" expression
 * @param symbolTable
 * @return
 */
Node* Parser::assign_stmt(SymbolTable &symbolTable) {
    Node* res = nullptr;
    res = parseIdentifier();
    IdenNode* iden = (IdenNode*)res;
    if(!lookup(iden->getName(),symbolTable))
        symbolTable.symbolTableMap.emplace(iden->getName(),++symbolTable.currentAddress);
    //consume
    i+=1;
    Node* rhs = expression(symbolTable);
    TreeHelper treeHelper;
    res = treeHelper.makeAST("=",res,rhs);
    return res;
}


/**
 * expression ::= or_expr
 * @param symbolTable
 * @return
 */
Node* Parser::expression(SymbolTable &symbolTable){

    Node* res = nullptr;
    res = or_expr(symbolTable);
    return res;
}

/**
 * or_expr ::= and_expr | and_expr "or" or_expr
 * @param symbolTable
 * @return
 */
Node* Parser::or_expr(SymbolTable &symbolTable){
    Node* res = nullptr;
    res = and_expr(symbolTable);
    if(i >= tokens.size())
        return res;
    if(tokens[i] == "or"){
        i++;
        Node* rhs = or_expr(symbolTable);
        TreeHelper treeHelper;
        res = treeHelper.makeAST("or",res/*lhs*/,rhs);
    }
    return res;
}

/**
 * and_expr ::= not_expr | not_expr "and" and_expr
 * @param symbolTable
 * @return
 */
Node* Parser::and_expr(SymbolTable &symbolTable){
    Node* res = nullptr;
    res = not_expr(symbolTable);
    if(i >= tokens.size())
        return res;
    if(tokens[i] == "and"){
        i++;
        Node* rhs = and_expr(symbolTable);
        TreeHelper treeHelper;
        res = treeHelper.makeAST("and",res/*lhs*/,rhs);
    }
    return res;
}

/**
 * not_expr ::= comp_expr | "not" not_expr
 * @param symbolTable
 * @return
 */
Node* Parser::not_expr(SymbolTable &symbolTable){
    Node* res = nullptr;
    if(i >= tokens.size())
        return res;
    if(tokens[i] == "not") {
        i++;
        // This should go to top expression i guess like here or || will correct later
        //changed
        Node* res1 = or_expr(symbolTable);
        TreeHelper treeHelper;
        Node *rhs = nullptr;
        res = treeHelper.makeAST("not", res1, rhs);
    }
    else {
        res = compar_exp(symbolTable);
    }
    return res;
}


/**
 * comp_expr ::= a_expr | a_expr  comp_opr comp_expr
 * @param symbolTable
 * @return
 */
Node* Parser::compar_exp(SymbolTable &symbolTable) {
    Node* res = nullptr;
    Node* res1 = nullptr;
    TreeHelper treeHelper;
    res = a_expr(symbolTable);
    if(i >= tokens.size())
        return res;
    if(tokens[i] == "=="){
        i++;
        res1 = compar_exp(symbolTable);
        res = treeHelper.makeAST("==",res,res1);
    } else if(tokens[i] == "<>"){
        i++;
        res1 = compar_exp(symbolTable);
        res = treeHelper.makeAST("<>",res,res1);
    } else if(tokens[i] == "<"){
        i++;
        res1 = compar_exp(symbolTable);
        res = treeHelper.makeAST("<",res,res1);
    } else if(tokens[i] == ">"){
        i++;
        res1 = compar_exp(symbolTable);
        res = treeHelper.makeAST(">",res,res1);
    } else if(tokens[i] == "<="){
        i++;
        res1 = compar_exp(symbolTable);
        res = treeHelper.makeAST("<=",res,res1);
    } else if(tokens[i] == ">="){
        i++;
        res1 = compar_exp(symbolTable);
        res = treeHelper.makeAST(">=",res,res1);
    }
    return res;
}

/**
 * a_expr ::= m_expr | m_expr "+" a_expr | m_expr "-" a_expr
 * @param symbolTable
 * @return
 */
Node* Parser::a_expr(SymbolTable &symbolTable){
    Node* res = nullptr;
    Node* res1 = nullptr;
    TreeHelper treeHelper;
    res = m_expr(symbolTable);
    if(i >= tokens.size())
        return res;
    if(tokens[i] == "+"){
        i++;
        res1 = a_expr(symbolTable);
        res = treeHelper.makeAST("+",res,res1);
    } else if(tokens[i] == "-"){
        i++;
        res1 = a_expr(symbolTable);
        res = treeHelper.makeAST("-",res,res1);
    }
    return res;
}

/**
 * m_expr ::= unit| unit "*" m_expr | unit "/" m_expr | unit "%" m_expr
 * @param symbolTable
 * @return
 */
Node* Parser::m_expr(SymbolTable &symbolTable){
    Node* res = nullptr;
    Node* res1 = nullptr;
    res = atom(symbolTable);
    TreeHelper treeHelper;
    //need an else condition to throw error i guess
    //i++;
    if(i >= tokens.size())
        return res;
    if(tokens[i] == "*"){
        i++;
        res1 = m_expr(symbolTable);
        res = treeHelper.makeAST("*",res,res1);
    } else if(tokens[i] == "/"){
        i++;
        res1 = m_expr(symbolTable);
        res = treeHelper.makeAST("/",res,res1);
    } else if(tokens[i] == "%"){
        i++;
        res1 = m_expr(symbolTable);
        res = treeHelper.makeAST("%",res,res1);
    }
    return res;
}

/**
 * unit ::= integer | identifier | “(” expression“)” | exec_stmt
 * @param symbolTable
 * @return
 */
Node* Parser::atom(SymbolTable &symbolTable)
{
    Node* res = nullptr;
    Node* res1 = nullptr;
    if(tokens[i] == "("){ //(3+4)*5
        i++;
        //need minor changes i guess if we are allowing (3<4)*4...should be top expression like here or_exp
        res = expression(symbolTable);
        if(tokens[i] != ")") {
            cout<<"Expected )"<<" at line "<<instLine<<"\n";
            exit(-1);
        }
        i++;
    }else if((tokens[i][0] == '-' && tokens[i][1] >= '0' && tokens[i][1] <= '9') || (tokens[i][0] >= '0' && tokens[i][0] <= '9')){
        //should here be parsing number
        res = new NumberNode(stoi(tokens[i]));
        i++;
    } else if(i+1 < tokens.size() && tokens[i+1] == "(") {
        res = exec_stmt(symbolTable);
    }
    else { // java bugs ; can be written after if
        if(!lookup(tokens[i],symbolTable))
        {
            cout<<tokens[i]<<" not defined earlier  at line  no "<<instLine<<"\n";
            exit(-1);
        }
        res = new IdenNode(tokens[i]);
        i++;
    }
    return res;
}


/**
 * This is to parse a identifier
 * @return
 */
Node* Parser::parseIdentifier() {
    IdenNode* res = nullptr;
    if(tokens[i][0]!='_' && (tokens[i][0]<'a' || tokens[i][0]>'z') && (tokens[i][0]<'A' || tokens[i][0]>'Z'))
        std::cout << "Identifier wrong "<<tokens[0]<<" at line "+instLine;
    else
    {
        res = new IdenNode(tokens[i]);
        //consume identifier
        ++i;
    }
    return res;
}

