%{
	/******************************************************************
	Panayiotis Charalambous - pchara20 ID: 952304					***
	Andreas Costi			- acosti01 ID: 1003060					***
	Stephanie Nicolaou		- snikol07 ID: 932787					***
																	***
	Part A - Compiler												***
	bison -d parser_952304_1003060_932787.y							***
	flex preprocessor_952304_1003060_932787.fl						***
	gcc parser_952304_1003060_932787.tab.c lex.yy.c -lfl -o a.out	***
	./a.out inputFile.c outputFile.c								***
	*******************************************************************/
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <string.h>

	extern char *yytext;
	extern int yylex();
	extern int yylineno;
	extern FILE *yyin;
	int yydebug = 1;
	
	#define YYDEBUG_LEXER_TEXT yytext

	void yyerror(const char *s);
%}

%expect 2

%union {	char *word;	}
%union {	char *character;	}

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
%token FLOAT
%token FLOAT_NUM
%token WHILE
%token ID 
%token NUM
%token PLUSEQ
%token MINUSEQ
%token INC  
%token DEC
%token FOR


%type <character> program declaration_list declaration var_declaration
%type <character> type_specifier fun_declaration params param_list param
%type <character> compound_stmt local_declarations statement_list statement
%type <character> expression_stmt selection_stmt iteration_stmt return_stmt
%type <character> expression var simple_expression relop additive_expression
%type <character> addop term mulop factor args arg_list for_stmt
%type <word> error call for

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
		| FLOAT {$$ = "float";}
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
	   | for_stmt {}
	   | WHILE error expression RIGHT_PAREN statement  {yyerrok;}
      | WHILE LEFT_PAREN expression error statement  {yyerrok;};
		;
		
	for_stmt : FOR {exec_for();} LEFT_PAREN expression SEMICOLON expression SEMICOLON expression RIGHT_PAREN      statement {} 
	   | FOR {exec_for();} error expression SEMICOLON expression SEMICOLON expression SEMICOLON statement    {yyerrok;}
      | FOR {exec_for();} LEFT_PAREN expression error expression SEMICOLON expression RIGHT_PAREN statement    {yyerrok;}
      | FOR {exec_for();} LEFT_PAREN expression SEMICOLON expression error expression RIGHT_PAREN statement    {yyerrok;}  
      | FOR {exec_for();} LEFT_PAREN expression SEMICOLON expression SEMICOLON expression error statement    {yyerrok;};

	return_stmt : RETURN SEMICOLON			{}
		| RETURN expression SEMICOLON		{}
	;

	expression : var ASSIGN expression 	{}
	   | var error expression               {yyerrok;}
		| simple_expression				{}
		| var INC                             {}
      | var DEC                         {} 
      | var PLUSEQ NUM                {}
      | var MINUSEQ NUM                {}
      ;	
	

	var : ID 										{}
		| ID LEFT_BRACKET expression RIGHT_BRACKET	{}
		| ID error expression RIGHT_BRACKET                   {yyerrok;}
      | ID LEFT_BRACKET expression error                   {yyerrok;};
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
		| FLOAT_NUM                   {}
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
	} else {
		yyin = fopen(argv[1], "r");
		yyparse();
	}
	return 1;
}

void exec_for(){
             hashtable * hash;
             ht_create(&hash,"for","null",0);
             scope++;
             push(hash,stack); 
             }

void yyerror(const char *s){

	printf("Found error line: %d : %s : %s\n", yylineno, s, yytext);
}
