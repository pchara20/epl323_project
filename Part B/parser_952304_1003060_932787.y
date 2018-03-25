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
	STACK *stack = NULL;
	int countArgList = 0;
	int isFunction = -1;

#define YYDEBUG_LEXER_TEXT yytext

	void yyerror(const char *s);

%}

%expect 4

%union {	char *word;	}
%union {	char *character; }

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

var_declaration : type_specifier ID SEMICOLON
{
	if (stack == NULL) {
		printf("to stack en ofkero\n");
		if ((initStack(&stack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		} else {
			hashtable *globalHashtable = NULL;
			if (createHashTable(&globalHashtable, "global", "void", -1) != EXIT_SUCCESS) {
				fprintf(stderr, "Global hashtable initialization failed\n!");
			} else {
				push(globalHashtable, stack);
				//printf("esira to hashtable mesa sto stack\n");
				//printStack(stack);
				//printf("printStackended\n");
			}
		}
	}
	NODE *hashtableNode = NULL;

	if ((createNode(&hashtableNode, nodeName, $1, (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
	} else {
		//printf("edimiourgisa node\n");
		insertNode(hashtableNode, stack);
		//printStack(stack);
	}
}
| type_specifier ID LEFT_BRACKET NUM RIGHT_BRACKET SEMICOLON
{
	NODE *tableNode = NULL;
	if ((createNode(&hashtableNode, nodeName, $1, (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
	} else {
		//printf("edimiourgisa node\n");
		insertNode(tableNode, stack);
		//printStack(stack);
	}
}
| type_specifier error
{
	yyerrok; yyclearin;
}
;

type_specifier : INT
{
	bzero(nodeType, 50, 0);
	strcpy(nodeType, yytext);
	$$ = "int";
}
| VOID
{
	bzero(nodeType, 50, 0);
	strcpy(nodeType, yytext);
	$$ = "void";
}
| FLOAT
{
	bzero(nodeType, 50, 0);
	strcpy(nodeType, yytext);
	$$ = "float";
}
| error
{
	yyclearin;
}
;

fun_declaration : type_specifier ID LEFT_PAREN
{
	if (stack != NULL) {
		hashtable *hashTable = NULL;
		if (createHashTable(&hashTable, nodeName, nodeType, 1) != EXIT_SUCCESS) {
			fprintf(stderr, "Global hashtable initialization failed\n!");
		} else {
			push(hashTable, stack);
			//printf("esira to hashtable mesa sto stack\n");
			//printStack(stack);
			//printf("printStackended\n");
		}
	} else {
		if ((initStack(&stack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		} else {
			hashtable *hashTable = NULL;
			if (createHashTable(&hashTable, nodeName, nodeType, 1) != EXIT_SUCCESS) {
				fprintf(stderr, "Global hashtable initialization failed\n!");
			} else {
				push(hashTable, stack);
				//printf("esira to hashtable mesa sto stack\n");
				//printStack(stack);
				//printf("printStackended\n");
			}
		}
	}
} params RIGHT_PAREN /*might need something here*/ compound_stmt		{}
| type_specifier ID error params RIGHT_PAREN compound_stmt
{
	yyerrok;
}
| type_specifier ID LEFT_PAREN params error compound_stmt
{
	yyerrok;
}
;

params : param_list	{}
| VOID			{}
;

param_list : param_list COMMA param
{
	stack->hashTables[(stack->size) - 1]->countparamfunc++;
}
| param
{
	stack->hashTables[(stack->size) - 1]->countparamfunc++;
}
;

param : type_specifier ID
{
	NODE *node = NULL;
	if ((createNode(&node, nodeName, $1, (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
	} else {
		//printf("edimiourgisa node\n");
		insertNode(node, stack);
		//printStack(stack);
	}
}
| type_specifier ID LEFT_BRACKET RIGHT_BRACKET
{
	NODE *node = NULL;
	if ((createNode(&node, nodeName, $1, (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
	} else {
		//printf("edimiourgisa node\n");
		insertNode(node, stack);
		//printStack(stack);
	}
}
| error
{
	yyerrok; yyclearin;
}
;

compound_stmt : LEFT_BRACE local_declarations statement_list RIGHT_BRACE 
{
   hashtable *hashTable = NULL;
   if (stack->hashTables[stack->size-1]->isFunction == 1){
      createHashTable(hashTable, stack->hashTables[stack->size-1]->namefunction,stack->hashTables[stack->size-1]->typefunction, stack->hashTables[stack->size-1]->isFunction);
      push(hashTable, stack);
   }
}
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

selection_stmt : if LEFT_PAREN expression RIGHT_PAREN statement %prec "if"			{}
| if LEFT_PAREN expression RIGHT_PAREN statement %prec "if" else statement		{}
		;

if : IF {
hashTable *hashTable = NULL;
if (createHashTable(&hashTable, "if", "null", 0) != EXIT_SUCCESS) {
		fprintf(stderr, "Hashtable initialization failed!\n");
	} else {
		push(hashTable, stack);
	}
}
;

else : ELSE {
	hashTable *hashTable = NULL;
	if (createHashTable(&hashTable, "else", "null", 0) != EXIT_SUCCESS) {
		fprintf(stderr, "Hashtable initialization failed!\n");
	} else {
		push(hashTable, stack);
	}
}
;
iteration_stmt : whileloop LEFT_PAREN expression RIGHT_PAREN statement	{}
| for_stmt {}
| whileloop error expression RIGHT_PAREN statement  {yyerrok;}
| whileloop LEFT_PAREN expression error statement  {yyerrok;};
;

whileloop : WHILE {
	hashTable *hashTable = NULL;
	if (createHashTable(&hashTable, "while", "null", 0) != EXIT_SUCCESS) {
		fprintf(stderr, "Hashtable initialization failed!\n");
	} else {
		push(hashTable, stack);
	}
}
;

for_stmt : forloop LEFT_PAREN expression SEMICOLON expression SEMICOLON expression RIGHT_PAREN      statement {}
| forloop  error expression SEMICOLON expression SEMICOLON expression SEMICOLON statement    {yyerrok;}
| forloop  LEFT_PAREN expression error expression SEMICOLON expression RIGHT_PAREN statement    {yyerrok;}
| forloop  LEFT_PAREN expression SEMICOLON expression error expression RIGHT_PAREN statement    {yyerrok;}
| forloop  LEFT_PAREN expression SEMICOLON expression SEMICOLON expression error statement    {yyerrok;};

forloop : FOR {
	hashTable *hashTable = NULL;
	if (createHashTable(&hashTable, "for", "null", 0) != EXIT_SUCCESS) {
		fprintf(stderr, "Hashtable initialization failed!\n");
	} else {
		push(hashTable, stack);
	}
}
;

return_stmt : RETURN SEMICOLON			{}
| RETURN expression SEMICOLON		{}
;

expression : var ASSIGN expression 	
{
	if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
		if (strcmp(typeleft, typeright) != 0){
			printf("Type error at line: %d\n", yylineno);
		}
	}
}
| var error expression               {yyerrok;}
| simple_expression				{
                        if(isfunction!=-1){ 
                              if(compareArgs(stack,typeofarg,isfunction,istable)!=1)
                                    printf("ERROR, wrong type of argument in line %d\n",yylineno); }
                                                 }
| var INC                             {}
| var DEC                         {}
| var PLUSEQ NUM                {}
| var MINUSEQ NUM                {}
;

var : ID 										
{
	$$ = $1;
	typeleft = searchHash($1, stack);

	if (strcmp(typeleft, "NULL")){
		printf("Type error of %s at line: %d\n", $1, yylineno);
	}
}
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
| NUM									
{
	typeright = "int";
}
| FLOAT_NUM                   
{
	typeright = "float";
}
;

call : ID 
{
	positionInHashtable = -1;
	positionInHashtable = searchInStack();
	if (positionInHashtable == -1){
		printf("Function '%s' not found at line: %d!\n", $1, yylineno);
	}
}
LEFT_PAREN args RIGHT_PAREN	
{
	hashtable *hashTable = stack->hashTables[(stack->size)-1];
	
	if (hashTable[positionInHashtable]->countparamfunc != countArgList){
		printf("Arguments do not match function's arguments at line: %d!\n", yylineno);
	}
	countArgList = 0;
	positionInHashtable = -1;

}
;

args : arg_list 	{}
| /*epsilon*/	{}
;

arg_list : arg_list COMMA expression
{
	countArgList++;
}
| expression
{
	countArgList++;
}
;
%%
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Wrong number of arguments given!\n");
		return -1;
	} else {
		yyin = fopen(argv[1], "r");
		yyparse();
	}
	return 1;
}

//void exec_for(){
//            hashtable * hash;
//          ht_create(&hash,"for","null",0);
//        push(hash,stack);
//      }

void yyerror(const char *s) {

	printf("Found error line: %d : %s : %s\n", yylineno, s, yytext);
}
