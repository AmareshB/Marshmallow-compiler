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
assignment_stmt ::=
identifier "=" expression
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
unit ::= integer | identifier | “(” expression“)”
comp_opr ::=
             "<" | ">" | "==" | ">=" | "<=" | "<>"
```
