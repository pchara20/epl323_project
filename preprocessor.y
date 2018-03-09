%{
	#include <stdio.h>
	extern char *yytext;
%}

%token ELSE IF INT RETURN VOID WHILE
%token ID NUM
%token PLUS MINUS TIMES DIVISION LT LTEQ GT GTEQ EQUAL NEQ ASSIGN SEMICOLON COMMA LEFT_PAREN RIGHT_PAREN LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE
%token ERROR

%nonassoc LT LTEQ GT GTEQ EQUAL NEQ
%left PLUS MINUS
%left TIMES DIVISION

%%

program : declaration_list
	;

declaration_list : declaration_list declaration 
	| declaration
	;

declaration : var_declaration 
	| fun_declaration
	;

var_declaration : type_specifier ID SEMICOLON 
	| type_specifier ID LEFT_BRACKET NUM RIGHT_BRACKET SEMICOLON
	;

type_specifier : INT 
	| VOID
	;

fun_declaration : type_specifier ID LEFT_PAREN params RIGHT_PAREN compound_stmt
	;

params : param_list
	| VOID
	;

param_list : param_list COMMA param
	| param
	;

param : type_specifier ID
	| type_specifier ID LEFT_BRACKET RIGHT_BRACKET
	;

compound_stmt : LEFT_BRACE local_declarations statement_list RIGHT_BRACE
	;

local_declarations : local_declarations var_declaration 
	| /*epsilon*/
	;

statement_list : statement_list statement
	| /*epsilon*/
	;

statement : expression_stmt
	| compound_stmt
	| selection_stmt
	| iteration_stmt
	| return_stmt
	;

expression_stmt : expression SEMICOLON
	| SEMICOLON
	;

selection_stmt : IF LEFT_PAREN expression RIGHT_PAREN statement
	| IF LEFT_PAREN expression RIGHT_PAREN statement ELSE statement
	;

iteration_stmt : WHILE LEFT_PAREN expression RIGHT_PAREN statement
	;

return_stmt : RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

expression : var ASSIGN expression 
	| simple_expression
	;

var : ID 
	| ID LEFT_BRACKET expression RIGHT_BRACKET
	;

simple_expression : additive_expression relop additive_expression
	| additive_expression
	;

relop : LTEQ
	| LT
	| GT
	| GTEQ
	| EQUAL
	| NEQ
	;

additive_expression : additive_expression addop term 
	| term
	;

addop : PLUS
	| MINUS
	;

term : term mulop factor
	| factor
	;

mulop : TIMES
	| DIVISION
	;

factor : LEFT_PAREN expression RIGHT_PAREN
	| var
	| call
	| NUM
	;

call : ID LEFT_PAREN args RIGHT_PAREN
	;

args : arg_list 
	| /*epsilon*/
	;

arg_list : arg_list COMMA expression 
	| expression
	;
%%
void yyerror(const char *s){

	int yylineno;
	printf("Found error line: %d : %s\n", yylineno, s);
}

	
