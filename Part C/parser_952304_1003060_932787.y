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
#include "symboltable.h"

	extern char *yytext;
	extern int yylex();
	extern int yylineno;
	extern FILE *yyin;
	int yydebug = 1;
	char nodeName[50];
	char nodeType[50];
	char typeleft[10];
	char typeright[10];
	char typeoftemp[10];
	char typeofarg[10];
	STACK *stack = NULL;
	STACK *helpstack=NULL;
	int countArgList = 0;
	int positionInHashtable=-1;
   
#define YYDEBUG_LEXER_TEXT yytext

	void yyerror(const char *s);

%}

%expect 1

%union {
    int a_number;
    float b_number;
    char *str;
    struct Exp *exp;
    struct Stmt *stmt;
    int type;
    char *op;
}

%start program

%token '+'
%token '-'
%token '*'
%token '/'
%token '<'
%token LTEQ
%token '>'
%token GTEQ
%token EQUAL
%token NEQ
%token '='
%token ';'
%token ','
%token '('
%token ')'
%token '['
%token ']'
%token '{'
%token '}'
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
%type <word> error call id2 whileloop forloop if else

%nonassoc "if"
%nonassoc ELSE

%left '+' '-'
%left '*' '/'

%%
program : declaration_list	{
    $$ = malloc(sizeof(Stmt));
    $$->code = mergeStrings(3, "\t.data\n\tnewln:\t.asciiz\t\"\\n\"\n", function_variables, $1->code);
    $$->code = mergeStrings(2, $$->code, "\n\tli\t$v0, 10\n\tsyscall\n");
    fprintf(yyout, "%s\n", $$->code);
    name = $$->code;
}
;

declaration_list : declaration_list declaration		{}
| declaration									{}
;

declaration : var_declaration 			
| fun_declaration						
;

var_declaration : type_specifier id2 ';'{
	
}
| type_specifier id2 '[' NUM ']' ';' {
	
}
| type_specifier error {yyerrok; yyclearin; }
;

type_specifier : INT
{
	
}
| VOID
{
	
}
| FLOAT
{
	
}
| error
{
	yyclearin;
}
;

fun_declaration : type_specifier id2 '(' {   
	
	
   }	params ')' compound_stmt		{}
| type_specifier id2 error params ')' compound_stmt {yyerrok;}

;

params : param_list	{}
| VOID			{}
;

param_list : param_list ',' param {

   }
| param {

   }
;

param : type_specifier id2 {
		
	}
| type_specifier id2 '[' ']' {
			
   }
| error { yyerrok; yyclearin; }
;

compound_stmt : '{' local_declarations statement_list '}' 
{
   
};

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
| error	';'				{yyerrok; yyclearin;}
;

expression_stmt : expression ';'		{}
| ';'								{}
| error									{yyclearin;}
;

selection_stmt : if '(' expression ')' statement %prec "if"			{}
| if '(' expression ')' statement %prec "if" else statement		{}
		;

if : IF {
            
    }
;
else : ELSE {
	            
    }
;
iteration_stmt : whileloop '(' expression ')' statement	{}
| for_stmt {}
| whileloop error expression ')' statement  {yyerrok;}
| whileloop '(' expression error statement  {yyerrok;}
;

for_stmt : forloop '(' expression ';' expression ';' expression ')' statement {}
| forloop error expression ';' expression ';' expression ')' statement    {yyerrok;}
| forloop '(' expression error expression ';' expression ')' statement    {yyerrok;}
| forloop '(' expression ';' expression error expression ')' statement    {yyerrok;}
| forloop '(' expression ';' expression ';' expression error statement    {yyerrok;}
;

forloop : FOR {             
	            
    }
;

whileloop: WHILE {  
               
    }
; 


return_stmt : RETURN ';'    {}
| RETURN expression ';'     {}
;

expression : var {strcpy(typeoftemp,typeleft); strcpy(typeleft,"NULL");} '=' expression 
{    
	
}
| var error expression      {yyerrok;}
| simple_expression			{ }
| var INC                   {}
| var DEC                   {}
| var PLUSEQ NUM            {}
| var MINUSEQ NUM           {}
;

var : id2 {        
	        
}
| id2 '[' expression ']' {
	                        
    }
| id2 error expression ']'               {yyerrok;}
| id2 '[' expression error               {yyerrok;};
;

simple_expression : additive_expression         {}
| additive_expression relop additive_expression	{
             
}
;

relop : LTEQ	{}
| '<'			{}
| '>'			{}
| GTEQ			{}
| EQUAL			{}
| NEQ			{}
;

additive_expression : additive_expression addop term 	
| term												    { }
;

addop : '+'		{}
| '-'			{}
;

term : term mulop factor	{
                                
                                
    }
| factor	{$$ = $1; }
;

mulop : '*' 	{}
| '/'	    	{}
;

factor : '(' expression ')'	{}
| var									{}
| call									{}
| NUM									
{
	
}
| FLOAT_NUM                   
{
	
}
;

call : id2 
{
	
}
'(' args ')'	
{
   
}
;

id2 : ID {
           
          
    };

args : arg_list 	{}
| /*epsilon*/	    {}
;

arg_list : arg_list ',' expression
{

}
| expression
{

}
;
%%
int main(int argc, char *argv[]) {
  
	if (argc < 2) {
		printf("Wrong number of arguments given!\n");
		return -1;
	} else {
		yyin = fopen(argv[1], "r");
	   printf("\n");
		yyparse();
	}
	printf("\n");
	return 1;
}

void yyerror(const char *s) {

	printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): \x1b[32m%s\x1b[0m : \x1b[33m%s\x1b[0m\n", yylineno, s, yytext);
}

