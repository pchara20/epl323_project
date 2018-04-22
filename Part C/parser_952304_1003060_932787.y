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
#include "helper.h"

#define YYDEBUG 1
extern char *yytext;
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
char *name, *function_name, *function_variables;
int function = 0, first_function = 1, empty = 0, a_counter = 0;
Node **function_params;
Array array;

void yyerror(const char *s);
%}



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
%token <str> FLOAT_NUM
%token WHILE
%token <str> ID
%token <str> NUM
%token PLUSEQ
%token MINUSEQ
%token INC
%token DEC
%token FOR

%type <str> error
%type <type> type_specifier
%type <exp> var additive_expression simple_expression expression expression_stmt term factor call args arg_list
%type <stmt> program declaration_list declaration var_declaration fun_declaration params param_list param compound_stmt local_declarations statement_list statement selection_stmt iteration_stmt return_stmt for_stmt
%type  <op> relop addop mulop adds


%nonassoc "if"
%nonassoc ELSE
%nonassoc '<' '>' '=' LTEQ GTEQ EQUAL NEQ

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

declaration_list : declaration_list declaration	{
    $$ = malloc(sizeof(Stmt));
    $$->code = mergeStrings(3, $1->code, "\n", $2->code);
}
| declaration{
    $$ = $1;
}
;

declaration : var_declaration   {$$ = $1;}		
| fun_declaration               {$$ = $1;}						
;

var_declaration : type_specifier ID ';'    {
    $$ = malloc(sizeof(Stmt));
    if (!function)
        $$->code = mergeStrings(3, "\t.align\t2\n", mergeStrings(2, "global_", $2),":\t.space\t4\n");
    else {
        insert(&array, $2);
        function_variables = mergeStrings(4, function_variables, "\t.align\t2\n", mergeStrings(3, function_name, "_", $2), ":\t.space\t4\n");
        $$->code = "";
    }
}
| type_specifier ID '[' NUM ']' ';' {}
;

type_specifier : INT {	$$ = 1; }
| VOID {	$$ = 2;}
| FLOAT {$$ = 3;}
| error {}
;

fun_declaration : fund params ')' compound_stmt   {   
    $$ = malloc(sizeof(Stmt));
    if (first_function == 1) {
        $$->code = mergeStrings(9, "\n\t.text\n\t.globl\t", function_name, "\n", function_name,":\n\t", $2->code, "\n\t", $4->code, "\n");
        $$->code = mergeStrings(2, $$->code, "\n\tjr\t$ra\n");
        first_function = 0;
    } else if (strcmp("main", function_name) == 0) {
        $$->code = mergeStrings(5, function_name, ":\n\t", $2->code, "\n\t", $4->code, "\n");
        first_function = 0;
    } else {
        $$->code = mergeStrings(6, function_name, ":\n\t", $2->code, "\n\t", $4->code, "\n");
        $$->code = mergeStrings(2, $$->code, "\n\tjr\t$ra\n");
    }
    function = 0;
    a_counter = 0;
    clearArray(&array);
}
| fund error ')' compound_stmt {}
;

fund: type_specifier ID '(' {
    function_name = $2; 
    function = 1;
}

params : param_list {
    $$ = $1;
}
| VOID			    {
    $$ = malloc(sizeof(Stmt));
    $$->code = "";
}
;

param_list : param_list ',' param {
    $$ = malloc(sizeof(Stmt));
    $$->code = mergeStrings(2, $1->code, $3->code);
    a_counter = 0;
}
| param {
    $$ = $1;    
}
;

param : type_specifier ID {
    $$ = malloc(sizeof(Stmt));
    $$->start = createTemp();
    char str[15];
    sprintf(str, "%d", a_counter);
    $$->code = mergeStrings(4, "\n\tmove\t", $$->start, ", $a", str);
    function_params[a_counter] = (Node *)malloc(sizeof(Node));
    function_params[a_counter]->key = $2;
    function_params[a_counter]->value = $$->start;
    a_counter++;
}
| type_specifier ID '[' ']' {}
;

compound_stmt : '{' local_declarations statement_list '}'   {
    $$ = malloc(sizeof(Stmt));
    $$->code = mergeStrings(2, $2->code, $3->code);
};

local_declarations : local_declarations var_declaration {
    $$->code = mergeStrings(2, $1->code, $2->code);
}
| /*epsilon*/   {
    $$ = malloc(sizeof(Stmt));
    $$->code = "";
}
;

statement_list : statement_list statement   {
    $$->code = mergeStrings(2, $1->code, $2->code);
}
| /*epsilon*/   {
    $$ = malloc(sizeof(Stmt));
    $$->code = "";
}
;

statement : expression_stmt		{$$=malloc(sizeof(Stmt)); 
						                $$->code = $1->code;
						               }
| compound_stmt			{$$= $1;}
| selection_stmt			{$$= $1;}
| iteration_stmt			{$$= $1;}
| return_stmt				{$$= $1;}

;

expression_stmt : expression ';'		{$$= $1;}
| ';'								{}
;

selection_stmt : IF '(' expression ')' statement %prec "if"	{
               $$=malloc(sizeof(Stmt)); 	
					$$->start=createLabel();
					$$->code= mergeStrings(7,"\n\t",$3->code,$$->start,$5->code,"\n",$$->start,":" );
			}
| IF '(' expression ')' statement %prec "if" ELSE statement	{
                  $$=malloc(sizeof(Stmt)); 	
						$$->start=createLabel();
						$$->next=createLabel();
						$$->code= mergeStrings(14,"\n\t",$3->code,$$->next,$5->code,"\n\t","j\t", $$->start,"\n",$$->next,":" ,$7->code,"\n",$$->start,":");
			};
			
iteration_stmt : WHILE '(' expression ')' statement	{
               $$=malloc(sizeof(Stmt)); 	
					$$->start=createLabel();
					$$->next=createLabel();
					$$->code= mergeStrings(13,"\n",$$->start,":","\t",$3->code,$$->next,$5->code,"\n\t","j\t", $$->start,"\n",$$->next,":");
						}
| for_stmt {$$=$1;}


;

for_stmt : FOR '(' expression ';' expression ';' expression ')' statement {$$=malloc(sizeof(Stmt)); 	
									$$->start=createLabel();
									$$->next=createLabel();
									$$->code= mergeStrings(16,$3->code,"\n",$$->start,":","\t",$5->code,$$->next,$9->code,"\n\t",$7->code,"\n\t","j\t", $$->start,"\n",$$->next,":");					
			}
;

return_stmt : RETURN ';'    {$$=malloc(sizeof(Exp));$$->code="";}
| RETURN expression ';'     {$$=malloc(sizeof(Exp)); $$->code="";}
;

expression : var equals expression {
                  $$=malloc(sizeof(Exp));
						$$->value=$1->value;
						if (strcmp($3->code,"\n\tjal\tinput")==0) {
							$$->code =mergeStrings(9,$1->code,"\n\t","li\t$v0",", 5","\n\tsyscall","\n\t","move\t",$1->value,", $v0");
							$$->code =mergeStrings(7,$$->code,"\n\t","sw\t",$1->value,", (", $1->position,")");
						}						
						else{
							$$->code =mergeStrings(8,$1->code,$3->code,"\n\t","sw\t",$3->value,", (", $1->position,")");							
		}
						}					
| simple_expression			{$$=$1;}
;

equals: '=' | PLUSEQ | MINUSEQ ;

var : ID {$$=malloc(sizeof(Exp)); 
					 $$->position =createTemp();	
					if(!function){	
						$$->code=mergeStrings(5,"\n\t","la\t",$$->position,", ",mergeStrings(2,"global_",$1)); 
						$$->value=createTemp();	
						$$->code=mergeStrings(6,$$->code,"\n\tlw\t",$$->value,",(",$$->position,")");
						}
					else{
						char *str = findInTheArray(&array,$1);
						if(str) {
							$$->code=mergeStrings(5,"\n\t","la\t",$$->position,", ",mergeStrings(3,function_name,"_",$1)); 
							$$->value=createTemp();	
							$$->code=mergeStrings(6,$$->code,"\n\tlw\t",$$->value,",(",$$->position,")");
						}
						else	{							
							$$->code="";
							int flag=0,i=0;
							while(i<4 && function_params[i]!=NULL){
								if(strcmp(function_params[i]->key,$1)==0){
									$$->value=function_params[i]->value;
									flag=1;
									break;
								}
								i++;							
							}
							if(!flag)
								$$->value=createTemp();	
						}				
					}
					
					$$->imm = 0;
					}
| ID '[' expression ']' {}

;

simple_expression : additive_expression relop additive_expression	{$$=malloc(sizeof(Exp)); 
					if(strcmp("LTEQ",$2)==0){
						$$->position =createTemp();	
						$$->code= mergeStrings(9,$1->code,$3->code,"\n\t","bgt","\t",$1->value,", ", $3->value,", ");  
						}
					else 	
						if(strcmp("<",$2)==0){
							$$->position =createTemp();	
							$$->code= mergeStrings(9,$1->code,$3->code,"\n\t","bge","\t",$1->value,", ", $3->value,", "); 
					}
					else 	
						if(strcmp(">",$2)==0){						
							$$->position =createTemp();	
							$$->code= mergeStrings(9,$1->code,$3->code,"\n\t","ble","\t",$1->value,", ", $3->value,", "); 
					}
					else
						if(strcmp("GTEQ",$2)==0){	
							$$->position =createTemp();	
							$$->code= mergeStrings(9,$1->code,$3->code,"\n\t","blt","\t",$1->value,", ", $3->value,", "); 
					}
					else
						if(strcmp("EQUAL",$2)==0){				
							$$->position =createTemp();	
							$$->code= mergeStrings(9,$1->code,$3->code,"\n\t","bne","\t",$1->value,", ", $3->value,", "); 
					}
					else{
						$$->position =createTemp();	
						$$->code= mergeStrings(9,$1->code,$3->code,"\n\t","beq","\t",$1->value,", ", $3->value,", "); 		
					}
					}
|additive_expression         {$$=$1;}
|additive_expression error additive_expression {}
;
relop : LTEQ	{$$="LTEQ";}
| '<'			{$$="<";}
| '>'			{$$=">";}
| GTEQ			{$$="GTEQ";}
| EQUAL			{$$="EQUAL";}
| NEQ			{$$="NEQ";}
;

additive_expression : additive_expression addop term {$$=malloc(sizeof(Exp));
													   $$->position = createTemp();
													   $$->value = $$->position;
													   	$$->code = mergeStrings(10,$1->code, $3->code, "\n\t",$2,"\t",$$->position,"," , $1->value , ",",$3->value);
													   	}
| factor adds {$$=malloc(sizeof(Exp)); 
					$$->position = $1->position;
					$$->value =$1->position;
					$$->code= mergeStrings(7,$1->code,"\n\t",$2,$1->value,", ",$1->value,", 1"); 
					$$->code = mergeStrings(7,$$->code,"\n\t","sw\t",$1->value,", (",$$->position,")");
					}
| term							    { $$=$1;}
					
;

addop : '+'		{$$="add";}
| '-'			{$$="sub";}
;

adds: INC			{$$="addi\t";} //edo
| DEC				{$$="addi\t";}	//edo
   ;


term : term mulop factor	{$$=malloc(sizeof(Exp)); 
					$$->position =createTemp();
					$$->value =$$->position;
					$$->code= mergeStrings(11,$1->code,$3->code,"\n\t",$2,"\t",$1->value,", ",$3->value,"\n\t","mflo\t",$$->position); 
					}
| factor	{$$ = $1;}
;

mulop : '*' 	{$$="mult";}
| '/'	    	{$$="div";}
;

factor : '(' expression ')'	{$$=$2;}
| var									{$$=$1;}
| call									{$$=$1;}
| NUM									{$$=malloc(sizeof(Exp)); 
										 $$->position=createTemp();
										 $$->value=$$->position;
										 $$->code=mergeStrings(5,"\n\t","li\t",$$->position,", ",$1);}
| FLOAT_NUM      {$$=malloc(sizeof(exp)); 
					$$->position=createTemp();
					$$->value=$$->position;
					$$->code=mergeStrings(5,"\n\t","li\t",$$->position,", ",$1); 
	
}
;

call : ID 	'(' args ')'	{
if(strcmp($1,"print")==0){			
						$$=malloc(sizeof(Exp)); 
						$$->position =$1;	
						$$->code=mergeStrings(2,$3->code,"\n\tli\t$v0, 1"); 
						$$->code=mergeStrings(4,$$->code,"\n\tmove\t$a0, ",$3->value,"\n\tsyscall"); 
					}
					else 
						if(strcmp($1,"println")==0){
							$$=malloc(sizeof(Exp)); 
							$$->position =$1;	
							$$->value =$1;	
							if (empty==0) {
								$$->code=mergeStrings(2,$3->code,"\n\tli\t$v0, 1"); 
								$$->code=mergeStrings(4,$$->code,"\n\tmove\t$a0, ",$3->value,"\n\tsyscall"); 
								$$->code=mergeStrings(2,$$->code,"\n\tli\t$v0, 4"); 
								$$->code=mergeStrings(4,$$->code,"\n\tla\t$a0, ","newln","\n\tsyscall"); 
							}
							else { 
								$$->code=mergeStrings(4,"\n\tli\t$v0, 4","\n\tla\t$a0, ","newln","\n\tsyscall"); 
								empty=0;
							}
						}else
							if(strcmp($1,"read")==0){
								$$=malloc(sizeof(Exp)); 
								$$->position =$3->position;	
								$$->value = $3->position;
								$$->code=mergeStrings(1,"\n\tli\t$v0, 5"); 
								$$->code=mergeStrings(5,$$->code,"\n\tsyscall","\n\tmove\t",$3->position,",$v0\n\t"); 								
							}
							else
								if (strcmp($1,"input")==0){
									$$=malloc(sizeof(Exp)); 
									$$->code=mergeStrings(2,"\n\tjal\t",$1); 
								}
								else 
									if (strcmp($1,"output")==0) {
										$$=malloc(sizeof(Exp)); 
										$$->position =$1;	
										$$->value =$1;	
										$$->code =mergeStrings(8,$3->code,"\n\t","li\t$v0",", 1","\n\t","move\t$a0, ",$3->value,"\n\tsyscall");
									}
									else 
										{
											$$=malloc(sizeof(Exp)); 
											$$->position =$3->position;	
											$$->value = $3->position;
											$$->code=mergeStrings(2,"\n\tjal\t",$1); 
											$$->code=mergeStrings(3,$3->code,"\n\tjal\t",$1); 
											a_counter=0;
										}
   
									}
;

args : arg_list 	{$$=$1;empty=0;a_counter=0;}
| /*epsilon*/	    {empty=1;}
;

arg_list : arg_list ',' expression { 
									$$=$3;char str[15];sprintf(str, "%d", a_counter);$$->code=mergeStrings(6,$1->code,$3->code,"\n\tmove\t$a",str,", ",$3->value);
									a_counter=0; 
								   }
| expression         { 
					$$=$1;char str[15];sprintf(str, "%d", a_counter);
					$$->code=mergeStrings(5,$1->code,"\n\tmove\t$a",str,", ",$1->value); a_counter++; }
					;
%%
int main(int argc, char *argv[]) {
  
	if (argc < 2) {
		fprintf(stderr,"Wrong number of arguments given!\n");
		return -1;
	} 
		
		if(argc==3)
		yyout=fopen(argv[2],"w");
	yyin = fopen(argv[1], "r");
		
	if(yyin == NULL){
		fprintf(stderr,"File doesn't exist!\n");
		return 0;
	}
	
	int i;
	for (i=0; i<100; i++)
		array.info[i]=NULL;      //edo
	function_variables = mergeStrings(1,"");
	function_params = (Node **) malloc(sizeof(Node*)*4);
		
	printf("\n");
	yyparse();
	return 1;
}

void yyerror(const char *s) {

	printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): \x1b[32m%s\x1b[0m : \x1b[33m%s\x1b[0m\n", yylineno, s, yytext);
}

