%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <string.h>

	extern char *yytext;
	extern int yylex();
	extern int yylineno;
	extern FILE *yyin;
	extern FILE *yyout;
	int yydebug = 1;
	
	#define YYDEBUG_LEXER_TEXT yytext

	void yyerror(const char *s);
%}

%union {
	char *word;
	}
%union {
	char *character;
	}

%start program

%token PLUS 
%token MINUS 
%token TIMES 
%token DIVISION 
%token LT 
%token LTEQ 
%token GT 
%token GTEQ 
%token EQUAL 
%token NEQ 
%token ASSIGN 
%token SEMICOLON 
%token COMMA 
%token LEFT_PAREN 
%token RIGHT_PAREN 
%token LEFT_BRACKET 
%token RIGHT_BRACKET 
%token LEFT_BRACE 
%token RIGHT_BRACE
%token IF 
%token ELSE 
%token RETURN 
%token VOID 
%token INT 
%token WHILE
%token ID 
%token NUM

%type <character> program declaration_list declaration var_declaration
%type <character> type_specifier fun_declaration params param_list param
%type <character> compound_stmt local_declarations statement_list statement
%type <character> expression_stmt selection_stmt iteration_stmt return_stmt
%type <character> expression var simple_expression relop additive_expression
%type <character> addop term mulop factor args arg_list
%type <word> error call

%nonassoc "if"
%nonassoc ELSE

%left PLUS MINUS
%left TIMES DIVISION

%%
	program : declaration_list	{}
	;

	declaration_list : declaration_list declaration		{}
		| declaration									{}
	;

	declaration : var_declaration 				{}
		| fun_declaration						{}
	;

	var_declaration : type_specifier ID SEMICOLON 						{}
		| type_specifier ID LEFT_BRACKET NUM RIGHT_BRACKET SEMICOLON	{}
		| type_specifier error											{yyerrok; yyclearin;}
	;

	type_specifier : INT	{$$ = "int";} 
		| VOID				{$$ = "void";}
		| error				{yyclearin;}
	;

	fun_declaration : type_specifier ID LEFT_PAREN params RIGHT_PAREN compound_stmt		{}
		| type_specifier ID error params RIGHT_PAREN compound_stmt						{yyerrok;}
		| type_specifier ID LEFT_PAREN params error compound_stmt						{yyerrok;}
	;

	params : param_list	{}
		| VOID			{}
	;

	param_list : param_list COMMA param			{}
		| param									{}
	;

	param : type_specifier ID								{}
		| type_specifier ID LEFT_BRACKET RIGHT_BRACKET		{}
		| error												{yyerrok; yyclearin;}
	;

	compound_stmt : LEFT_BRACE local_declarations statement_list RIGHT_BRACE	{}
	;

	local_declarations : local_declarations var_declaration 	{}
		| /*epsilon*/ {}
	;

	statement_list : statement_list statement			{}
		| /*epsilon*/ {}
	;

	statement : expression_stmt		{}
		| compound_stmt				{}
		| selection_stmt			{}
		| iteration_stmt			{}
		| return_stmt				{}
		| error	SEMICOLON				{yyerrok; yyclearin;}
	;

	expression_stmt : expression SEMICOLON		{}
		| SEMICOLON								{}
		| error									{yyclearin;}
	;

	selection_stmt : IF LEFT_PAREN expression RIGHT_PAREN statement %prec "if"			{}
		| IF LEFT_PAREN expression RIGHT_PAREN statement %prec "if" ELSE statement		{}
	;

	iteration_stmt : WHILE LEFT_PAREN expression RIGHT_PAREN statement	{}
		;

	return_stmt : RETURN SEMICOLON			{}
		| RETURN expression SEMICOLON		{}
	;

	expression : var ASSIGN expression 	{}
		| simple_expression				{}
	;

	var : ID 										{}
		| ID LEFT_BRACKET expression RIGHT_BRACKET	{}
	;

	simple_expression : additive_expression relop additive_expression	{}
		| additive_expression											{}
	;

	relop : LTEQ		{}
		| LT			{}
		| GT			{}
		| GTEQ			{}
		| EQUAL			{}
		| NEQ			{}
	;

	additive_expression : additive_expression addop term 	{}
		| term												{}
	;

	addop : PLUS		{}
		| MINUS			{}
	;

	term : term mulop factor	{}
		| factor				{}
	;

	mulop : TIMES		{}
		| DIVISION		{}
	;

	factor : LEFT_PAREN expression RIGHT_PAREN	{}
		| var									{}
		| call									{}
		| NUM									{}
	;

	call : ID LEFT_PAREN args RIGHT_PAREN	{}
	;

	args : arg_list 	{}
		| /*epsilon*/	{}
	;

	arg_list : arg_list COMMA expression 	{}
		| expression						{}
	;
%%
int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Wrong number of arguments given!\n");
		return -1;
	} else if (argc < 3){
		printf("Output file not specified!\n");
		return -1;
	} else {
		yyin = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");
		yyparse();
	}
	return 1;
}

void yyerror(const char *s){

	printf("Found error line: %d : %s\n", yylineno, s);
}
