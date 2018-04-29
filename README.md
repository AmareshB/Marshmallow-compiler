# Marshmallow

**Members**

Amaresh Bingumalla

Balachandar Sampath

Ejaz Saifudeen

Prasanth Venugopal

## YouTube Video Link
This video talks gives an overview about the development and abilities of this programming language.

**Platform**
    Windows(Mingw Compiler required)

## Tools
[Cmake] (https://cmake.org/) : CMake is an open-source, cross-platform family of tools designed to build, test and package software.

## Installation and Running
~$ mkdir SER502-Spring2018-Team15

~$ cd SER502-Spring2018-Team15

~$ wget https://github.com/ej-z/SER502-Spring2018-Team15.git

~$ tar xvf master.tar.gz --strip 1

## Design

<img src="/doc/design.PNG" />


## Sample Program
```
a = 5
i = 1
if (a%2 == 0)
 print (a)
else
 while (i<a)
  print(i)
  i = i+1
 
 ```
## SAMPLE PARSE TREE STRUCTURE
<img src="/doc/structure_of_parse_tree.JPG" />

## SAMPLE SYMBOL TABLE TREE STRUCTURE
<img src="/doc/symbolTable.JPG" />

## SAMPLE PROGRAM BYTE CODE

```
0 PUSH 5
2 STORE #0
4 PUSH 1
6 STORE #1
8 PUSH 0
10 PUSH 2
12 LOAD #0
14 MOD
15 EQ
16 BRF $22
18 LOAD #0
20 PRINT
21 BR $40
23 PUSH 10
25 LOAD #1
27 LT
28 BRF $40
30 LOAD #1
32 PRINT
33 PUSH 1
35 LOAD #1
37 ADD
38 STORE #1
40 EXIT
```

## Output

```
1
2
3
4
```


### Grammar

```
program ::= (stmt)+
letter ::= [a-zA-Z]
digit ::= [0-9]
identifier ::= (letter|"_") (letter | digit | "_")*
funcname ::= identifier
integer ::= "-"?digit(digit)*
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


To have a higher learning curve and to **decrease dependency on external tools**, this is language is completely developed from **scratch** using only C++.
1. Lexer: This takes in the program as input and creates tokens out of the program.
	1. This analyzes the input program to create tokens.
2. Parser: Tokens from the Lexer is fed as input to Parser which generates Parse Tree and Symbol table.
    	1. This is a recursive descent parser with look ahead.
	2. This part takes care of semantic analysis and generating the parse tree.
	3. This generates symbol table which is a doubly linked N-ary tree structure.
	4. This throws an error if the given program has syntax errors.
3. Intermediate Code: This generates the bytecode based on the parse tree in which is in agreement with the runtime.
	1. This part recursively walks through the tree and generates the byte code using the opcodes.
4. Runtime Environment:	This takes the bytecode and does the execution of the program written. This gives out the output after completing the execution.
	1. Stack Model is used for execution.
	2. Bytecode is traversed and executed with the stack holding current values.


## Abilities of the Language:

### Datatypes supported:
	Boolean
	Int
### This language supports:

1. #### Assignment Operations

	`a = 10`

2. #### Arithmetic Operators
	1. "+", "-", "*", "/", "%" - modulo
	
	` b = 4 + 8`
3. #### Logical Operators
	1. or
	2. and
	3. not
4. #### Comparision Operators
	1. "<", "<=", ">", ">=", "==", "<>"
5. #### Identifiers
	1. Global variables
	2. Local variables
6. #### Print statements
	
	`print 100`
7. #### Continue Statements.
	
	`continue`
8. #### Return Statements.

	Example 1: `return 10`
	
	Example 2: `return a`
9. #### Break statements.

	`break`
10. #### Conditional Statements
	1. if-elif-else

```a = 10
if ( a % 5 == 0 )
 print 5
elif ( a % 2 == 0 )
 print 2
else 
 print 0
```
## IF BLOCK
<img src="/doc/ByteCode_representation_if.PNG" />

11. #### Loop Statements
	1. while
```
a = 10
while(a > 0)
 print a
 a = a - 1
```
## WHILE BLOCK
<img src="/doc/while_representation.PNG" />

12. #### Functions - Need to be defined at the top of the program
	1. Simple function execution
	2. Function execution with return values
	3. Recursion
	4. Operations on return values
```
function mangle(n)
 d = 5
  if 2 < 3
   n = 2 * 3 + 5 - 8 / 2
  else
   g = 4
 return n
```
13. #### Scopes
	1. Handling block scopes, with different symbol table for each scope.
	2. Handling scopes inside a functions.
	3. Handling scopes inside conditional and Loop Statements.
