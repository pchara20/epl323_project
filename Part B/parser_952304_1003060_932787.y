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
	char typeofarg[10];
	STACK *stack = NULL;
	STACK *helpstack=NULL;
	int countArgList = 0;
	int positionInHashtable=-1;

#define YYDEBUG_LEXER_TEXT yytext

	void yyerror(const char *s);

%}

%expect 4

%union {	char *word;	}
%union {	char *character; }

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
program : declaration_list	{}
;

declaration_list : declaration_list declaration		{}
| declaration									{}
;

declaration : var_declaration 			//	{printf("DAAAAAAA\n");}
| fun_declaration							//{printf("OOOOOOOOOOO\n");}
;

var_declaration : type_specifier id2 ';'{
	//if stack is empty create it and then create/push a hashtable called global
	if (stack == NULL) {
		//printf("to stack en ofkero\n");
		if ((initStack(&stack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		}
		hashtable *globalHashtable = NULL;
		if (createHashTable(&globalHashtable, "global", "void", -1) != EXIT_SUCCESS) {
			fprintf(stderr, "Global hashtable initialization failed\n!");
			exit(-1);
		}
		push(globalHashtable, stack);
		//printf("esira to hashtable mesa sto stack\n");
		//printStack(stack);
		//printf("printStackended\n");
	}
	//create node and insert to stack in top hashtable
	NODE *hashtableNode= NULL;
	if ((createNode(&hashtableNode, nodeName, $1, (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	}	
	insertNode(hashtableNode, stack);	
	//printStack(stack);	
	}
| type_specifier id2 '[' NUM ']' ';' {
	NODE *tableNode = NULL;
	if ((createNode(&tableNode, nodeName, $1, (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	} 
	//printf("edimiourgisa node\n");
	insertNode(tableNode, stack);
	//printStack(stack);	
   }
| type_specifier error {printf("pppppppppp\n"); yyerrok; yyclearin; }
;

type_specifier : INT
{
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	$$ = "int";
}
| VOID
{
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	$$ = "void";
}
| FLOAT
{
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	$$ = "float";
}
| error
{
	yyclearin;
}
;

fun_declaration : type_specifier id2 '(' {   
	if (stack == NULL) {
	   if ((initStack(&stack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		}
	}
	hashtable *hashTable = NULL;
	if (createHashTable(&hashTable, nodeName, nodeType, 1) != EXIT_SUCCESS) {
		fprintf(stderr, "hashtable initialization failed\n!");
	} 
	push(hashTable, stack);
	//printStack(stack);
   }	params ')' compound_stmt		{}
//| type_specifier ID error params ')' compound_stmt {yyerrok;}
//| type_specifier ID '(' params error compound_stmt {yyerrok;}
;

params : param_list	{}
| VOID			{}
;

param_list : param_list ',' param {
	stack->hashTables[(stack->size) - 1].countparamfunc++;
   }
| param {
	stack->hashTables[(stack->size) - 1].countparamfunc++;
   }
;

param : type_specifier id2 {
	NODE *node = NULL;
	if ((createNode(&node, nodeName, $1, (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	} 
	insertNode(node, stack);		
	}
| type_specifier id2 '[' ']' {
	NODE *node = NULL;
	if ((createNode(&node, nodeName, $1, (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");	
	}
	insertNode(node, stack);			
   }
| error { yyerrok; yyclearin; }
;

compound_stmt : '{' local_declarations statement_list '}' 
{
   if (helpstack==NULL)
      if ((initStack(&helpstack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		}
	hashtable *hashTable = NULL;
	hashTable=pop(stack);
	if (hashTable->isFunction==1)
	   push(hashTable,helpstack);
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
            hashtable *ifHashtable = NULL;
            if (createHashTable(&ifHashtable, "if", "null", 0) != EXIT_SUCCESS) {
		        fprintf(stderr, "IF Hashtable initialization failed!\n");
	        } else {
		        push(ifHashtable, stack);
	        }
    }
;
else : ELSE {
	            hashtable *elseHashtable = NULL;
	            if (createHashTable(&elseHashtable, "else", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "ELSE Hashtable initialization failed!\n");
	            } else {
		            push(elseHashtable, stack);
	            }
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
               printf("ime mes to forloop:for\n");
	            hashtable *forHashtable = NULL;
	            if (createHashTable(&forHashtable, "for", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "FOR Hashtable initialization failed!\n");
	            } else {
		            push(forHashtable, stack);
		            //printStack(stack);
	            }
    }
;

whileloop: WHILE {  
               hashtable *whileHashtable = NULL;
	            if (createHashTable(&whileHashtable, "while", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "WHILE Hashtable initialization failed!\n");
	            } else {
		            push(whileHashtable, stack);
	            }
    }
; 


return_stmt : RETURN ';'    {}
| RETURN expression ';'     {}
;

expression : var '=' expression 
{  
  // printf("ime sto var=expression\n");
  // printf("to typeleft ine %s\n to typeright ine %s\n",typeleft,typeright);
	if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
		if (strcmp(typeleft, typeright) != 0){
			printf("Type error at line: %d\n", yylineno);
		}
		else ;//printf("en pompa\n");
	}
}
| var error expression      {yyerrok;}
| simple_expression			{ printf("simple\n\n");
                                /*if(positionInHashtable != -1) { 
                                    if(compareArgs(stack, typeofarg, positionInHashtable, istable) != 1)
                                        printf("Wrong type of argument at line: %d\n",yylineno); 
                                }*/
                            }
| var INC                   {}
| var DEC                   {}
| var PLUSEQ NUM            {}
| var MINUSEQ NUM           {}
;

var : id2 {
	        $$ = $1;	        	        
	        strcpy(typeleft,searchHash($1, stack));
	       // printf("ime sto var:id2 kai to typeleft ine: %s\n",typeleft);
	        if (strcmp(typeleft, "NULL") ==  0){
		         printf("Type error of %s at line: %d\n", $1, yylineno);
	        }
    }
| id2 '[' expression ']' {
	                        $$ = $1;
	                        strcpy(typeleft,searchHash($1, stack));
	                        if (strcmp(typeleft, "NULL") ==  0){
		                       printf("Type error of %s at line: %d\n", $1, yylineno);
	                        }
    }
| id2 error expression ']'               {yyerrok;}
| id2 '[' expression error               {yyerrok;};
;

simple_expression : additive_expression         {}
| additive_expression relop additive_expression	{
           if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
                                                        if (strcmp(typeleft, typeright) != 0) {
                                                            printf("Wrong type of argument at line: %d\n",yylineno); 
                                                        }
                                                    }
    }
;

relop : LTEQ	{}
| '<'			{}
| '>'			{}
| GTEQ			{}
| EQUAL			{}
| NEQ			{}
;

additive_expression : additive_expression addop term 	{}
| term												    {}
;

addop : '+'		{}
| '-'			{}
;

term : term mulop factor	{
                                if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
                                    if (strcmp(typeleft, typeright) != 0) {
                                        printf("Wrong type of argument at line: %d\n",yylineno); 
                                    }
                                }
    }
| factor	{$$ = $1;}
;

mulop : '*' 	{}
| '/'	    	{}
;

factor : '(' expression ')'	{}
| var									{}
| call									{}
| NUM									
{
	strcpy(typeright,"int");
	if (positionInHashtable != -1) {
	    strcpy(typeofarg,"int");
	}
}
| FLOAT_NUM                   
{
	strcpy(typeright,"float");
	if (positionInHashtable != -1) {
	    strcpy(typeofarg,"float");
	}
}
;

call : id2 
{
	positionInHashtable = -1;
	positionInHashtable = searchPosition($1,helpstack);
	if (positionInHashtable == -1){
		printf("Function '%s' not found at line: %d!\n", $1, yylineno);
	}
}
'(' args ')'	
{
	hashtable *hashTable = &stack->hashTables[positionInHashtable];
	
	if (hashTable[positionInHashtable].countparamfunc != countArgList){
		printf("Arguments do not match function's arguments at line: %d!\n", yylineno);
	}
	countArgList = 0;
	positionInHashtable = -1;

}
;

id2 : ID {
            strcpy(nodeName, yytext);
           // printf("ime sto id2:id kai to nodeName ine: %s\n",nodeName);
            $$ = nodeName;
            if (positionInHashtable != -1) {   
               //printf("empike telika");            
                strcpy(typeofarg,searchHash(nodeName, stack));  
            }
    };

args : arg_list 	{}
| /*epsilon*/	    {}
;

arg_list : arg_list ',' expression
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

