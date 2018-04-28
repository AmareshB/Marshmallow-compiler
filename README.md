# Marshmallow

### Grammar

```
program ::= (stmt)+
letter ::= [a-zA-Z]
digit ::= [0-9]
identifier ::= (letter|"_") (letter | digit | "_")*
funcname ::= identifier
integer ::= digit(digit)*
stmt     ::= assignment_stmt NEWLINE
                | print_stmt NEWLINE
                | return_stmt NEWLINE
                | break_stmt NEWLINE
                | continue_stmt NEWLINE
                | exec_stmt NEWLINE
	    | if_stmt
                | while_stmt
                | func_def
block ::= NEWLINE INDENT (stmt )+ DEDENT
if_stmt ::= "if" expression block
            ( "elif" expression block )*
            ("else" block)?
while_stmt ::= "while" expression block
funcdef ::= "function" funcname "(" parameters ")" block
parameters ::= identifier (',' identifier)*
print ::= “print” expression
assignment_stmt ::= identifier "=" expression
return ::= “return” expression
break ::= “break”
continue ::= “continue”
arguments ::= expression (‘,’expression)*
exec_stmt ::= funcname "(" arguments ")"
expression ::= or_expr
or_expr ::= and_expr | and_expr "or" or_expr
and_expr ::= not_expr | not_expr "and" and_expr
not_expr ::= comp_expr | "not" not_expr
comp_expr ::= a_expr | a_expr  comp_opr comp_expr
a_expr ::= m_expr | m_expr "+" a_expr | m_expr "-" a_expr
m_expr ::= unit| unit "*" m_expr | unit "/" m_expr | unit "%" m_expr
unit ::= integer | identifier | “(” expression“)” | exec_stmt
comp_opr ::=
             "<" | ">" | "==" | ">=" | "<=" | "<>"
```

This is language is completely developed from **scratch** using only C++ without any tools to have higher learning curve.

1. Lexer: This takes in the program as input and creates tokens out of the program.
	1. This analyzes the input program to create tokens.
2. Parser: Tokens from the Lexer is fed as input to Parser which generates Parse Tree and Symbol table.
    1. This is a recursive descent parser with look ahead.
	2. This part takes care of semantic analysis and generating the parse tree.
	3. This generates symbol table which is a doubly linked N-ary tree structure.
	4. This throws an error if the given program has syntax errors.
3. Intermediate Code: This generates the bytecode based on the parse tree in which is in agreement with the runtime.
	1. This traverses the parse tree and generates the bytecode using opcodes.
4. Runtime Environment:	This takes the bytecode and does the execution of the program written. This gives out the output after completing the execution.
	1. Stack Model is used for execution.
	2. Bytecode is traversed and executed with the stack holding current values.

-- place holder to write about cmake.

## Abilities of the Language:

### This language supports:

1. #### Assignments
2. #### Arithmetic Operators
	1. "+", "-", "*", "/", "%" - modulo
3. #### Logical Operators
	1. or
	2. and
	3. not
4. #### Comparision Operators
	1. "<", "<=", ">", ">=", "==", "<>"
5. #### Assignment Operations
6. #### Identifiers
	1. Global variables
	2. Local variables
7. #### Print statements
8. #### Continue Statements.
9. #### Return Statements.
10. #### Break statements.
11. #### Conditional Statements
	1. if-elif-else
12. #### Loop Statements
	1. while
13. #### Functions - Need to be defined at the top of the program
	1. Simple function execution
	2. Function execution with return values
	3. Recursion
	4. Operations on return values
14. #### Scopes
	1. Handling block scopes, with different symbol table for each scope.
	2. Handling scopes inside a functions.
	3. Handling scopes inside conditional and Loop Statements.
