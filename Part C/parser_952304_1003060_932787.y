%{
	/******************************************************************
	Panayiotis Charalambous - pchara20 ID: 952304					***
	Andreas Costi			- acosti01 ID: 1003060					***
	Stephanie Nicolaou		- snikol07 ID: 932787					***
																	***
	Part C - Compilers												***
	bison -d parser_952304_1003060_932787.y							***
	flex preprocessor_952304_1003060_932787.fl						***
	gcc parser_952304_1003060_932787.tab.c lex.yy.c -lfl -o a.out	***
	./a.out inputFile.c outputFile.c								***
	*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helper_functions_952304_1003060_932787.h"

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
    
    char buffer[10000] = { };
    sprintf(buffer, "\t.data\n\tnewln:\t.asciiz\t\"\\n\"\n\n%s%s\n\tli\t$v0, 10\n\tsyscall\n", function_variables, $1->code);
    $$->code = malloc(sizeof(strlen(buffer) + 1));
    strcpy($$->code, buffer);
    fprintf(yyout, "%s\n", $$->code);
    name = $$->code;
}
;

declaration_list : declaration_list declaration	{
    $$ = malloc(sizeof(Stmt));
    char buffer[10000] = { };
    sprintf(buffer, "%s\n%s", $1->code, $2->code);
    $$->code = malloc(sizeof(strlen(buffer) + 1));
    strcpy($$->code, buffer);
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
    if (!function){
      char buffer[10000];
      sprintf(buffer, "\t.align\t2\nglobal_%s:\t.space\t4\n",$2);
      char *tempstr=malloc(strlen(buffer)+1);      
      strcpy(tempstr, buffer);
      $$->code=tempstr;
    }
    else {
      insert(&array, $2);
      char buffer[10000];
      sprintf(buffer, "%s\t.align\t2\n%s_%s:\t.space\t4\n",function_variables, function_name, $2);
      strcpy(function_variables, buffer);
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
      char buffer[10000];
      sprintf(buffer, "\n\t.text\n\t.globl\t%s\n%s:\n\t%s\t%s\n\tjr\t$ra\n",function_name, function_name, $2->code, $4->code);
      char *tempstr=malloc(strlen(buffer)+1);      
      strcpy(tempstr, buffer);
      $$->code=tempstr;      
      first_function = 0;
    } else if (strcmp("main", function_name) == 0) {
         char buffer[10000];
         sprintf(buffer, "%s:\n\t%s\t%s\n",function_name,$2->code, $4->code);
         char *tempstr=malloc(strlen(buffer)+1);      
         strcpy(tempstr, buffer);
         $$->code=tempstr;    
        first_function = 0;
    } else {
      char buffer[10000];
         sprintf(buffer, "%s:\n\t%s\t%s\n\n\tjr\t$ra\n",function_name,$2->code,$4->code);
         char *tempstr=malloc(strlen(buffer)+1);      
         strcpy(tempstr, buffer);
         $$->code=tempstr;           
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
     char buffer[10000];
     sprintf(buffer, "%s%s",$1->code, $3->code);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;     
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
    
    char buffer[10000];
    sprintf(buffer, "\n\tmove\t%s, $a%s",$$->start,str);
    char *tempstr=malloc(strlen(buffer)+1);      
    strcpy(tempstr, buffer);
    $$->code=tempstr;
    function_params[a_counter] = (Node *)malloc(sizeof(Node));
    function_params[a_counter]->key = $2;
    function_params[a_counter]->value = $$->start;
    a_counter++;
}
| type_specifier ID '[' ']' {}
;

compound_stmt : '{' local_declarations statement_list '}'   {
    $$ = malloc(sizeof(Stmt));
    char buffer[10000];
     sprintf(buffer, "%s%s",$2->code, $3->code);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;
};

local_declarations : local_declarations var_declaration {
     char buffer[10000];
     sprintf(buffer, "%s%s",$1->code, $2->code);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;

}
| /*epsilon*/   {
    $$ = malloc(sizeof(Stmt));
    $$->code = "";
}
;

statement_list : statement_list statement   {
 char buffer[10000];
     sprintf(buffer, "%s%s",$1->code, $2->code);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;
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
					
					 char buffer[10000];
     sprintf(buffer, "\n\t%s%s%s\n%s:",$3->code,$$->start,$5->code,$$->start);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;
}
| IF '(' expression ')' statement %prec "if" ELSE statement	{
                  $$=malloc(sizeof(Stmt)); 	
						$$->start=createLabel();
						$$->next=createLabel();
						
						char buffer[10000];
     sprintf(buffer, "\n\t%s%s%s\n\tj\t%s\n%s:%s\n%s:",$3->code,$$->next,$5->code,$$->start,$$->next,$7->code,$$->start);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;
			};
			
iteration_stmt : WHILE '(' expression ')' statement	{
               $$=malloc(sizeof(Stmt)); 	
					$$->start=createLabel();
					$$->next=createLabel();
					char buffer[10000];
     sprintf(buffer, "\n%s:\t%s%s%s\n\tj\t%s\n%s:",$$->start,$3->code,$$->next,$5->code,$$->start,$$->next);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;
						}
| for_stmt {$$=$1;}


;

for_stmt : FOR '(' expression ';' expression ';' expression ')' statement {$$=malloc(sizeof(Stmt)); 	
									$$->start=createLabel();
									$$->next=createLabel();
									char buffer[10000];
     sprintf(buffer, "%s\n%s:\t%s%s%s\n\t%s\n\tj\t%s\n%s:",$3->code,$$->start,$5->code,$$->next,$9->code,$7->code,$$->start,$$->next);
     char *tempstr=malloc(strlen(buffer)+1);      
     strcpy(tempstr, buffer);
     $$->code=tempstr;
			}
;

return_stmt : RETURN ';'    {$$=malloc(sizeof(Exp));$$->code="";}
| RETURN expression ';'     {$$=malloc(sizeof(Exp)); $$->code="";}
;

expression : var equals expression {
                  $$=malloc(sizeof(Exp));
						$$->value=$1->value;
						if (strcmp($3->code,"\n\tjal\tinput")==0) {
						   char buffer[10000];
                     sprintf(buffer, "%s\n\tli\t$v0, 5\n\tsyscall\n\tmove\t%s, $v0\n\tsw\t%s, (%s)",$1->code, $1->value, $1->value, $1->position);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;
						 
						}						
						else{
						   char buffer[10000];
                     sprintf(buffer, "%s%s\n\tsw\t%s, (%s)",$1->code, $3->code, $3->value, $1->position);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;					
		}
						}					
| simple_expression			{$$=$1;}
;

equals: '=' | PLUSEQ | MINUSEQ ;

var : ID {$$=malloc(sizeof(Exp)); 
					 $$->position =createTemp();	
					if(!function){
					   $$->value=createTemp();
					   char buffer[10000];
                  sprintf(buffer, "\n\tla\t%s, global_%s\n\tlw\t%s, (%s)",$$->position, $1, $$->value, $$->position);
                  char *tempstr=malloc(strlen(buffer)+1);      
                  strcpy(tempstr, buffer);
                  $$->code=tempstr;
						
						}
					else{
						char *str = findInTheArray(&array,$1);
						if(str) {
						   $$->value=createTemp();
						   char buffer[10000];
                     sprintf(buffer, "\n\tla\t%s, %s_%s\n\tlw\t%s, (%s)",$$->position, function_name, $1, $$->value, $$->position);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;
						 
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
						char buffer[10000];
                  sprintf(buffer, "%s%s\n\tbgt\t%s, %s, ", $1->code, $3->code, $1->value, $3->value);
                  char *tempstr=malloc(strlen(buffer)+1);      
                  strcpy(tempstr, buffer);
                  $$->code=tempstr;	

						}
					else 	
						if(strcmp("<",$2)==0){
							$$->position =createTemp();
							char buffer[10000];
                     sprintf(buffer, "%s%s\n\tbge\t%s, %s, ", $1->code, $3->code, $1->value, $3->value);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;	

					}
					else 	
						if(strcmp(">",$2)==0){						
							$$->position =createTemp();
							char buffer[10000];
                     sprintf(buffer, "%s%s\n\tble\t%s, %s, ", $1->code, $3->code, $1->value, $3->value);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;	

					}
					else
						if(strcmp("GTEQ",$2)==0){	
							$$->position =createTemp();
							char buffer[10000];
                     sprintf(buffer, "%s%s\n\tblt\t%s, %s, ", $1->code, $3->code, $1->value, $3->value);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;	

					}
					else
						if(strcmp("EQUAL",$2)==0){				
							$$->position =createTemp();
							char buffer[10000];
                     sprintf(buffer, "%s%s\n\tbne\t%s, %s, ", $1->code, $3->code, $1->value, $3->value);
                     char *tempstr=malloc(strlen(buffer)+1);      
                     strcpy(tempstr, buffer);
                     $$->code=tempstr;	

					}
					else{
						$$->position =createTemp();	
						char buffer[10000];
                  sprintf(buffer, "%s%s\n\tbeq\t%s, %s, ", $1->code, $3->code, $1->value, $3->value);
                  char *tempstr=malloc(strlen(buffer)+1);      
                  strcpy(tempstr, buffer);
                  $$->code=tempstr;

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
													   char buffer[10000];
                                          sprintf(buffer, "%s%s\n\t%s\t%s, %s, %s", $1->code, $3->code, $2, $$->position, $1->value, $3->value);
                                          char *tempstr=malloc(strlen(buffer)+1);      
                                          strcpy(tempstr, buffer);
                                          $$->code=tempstr;   

													   	}
| factor adds {$$=malloc(sizeof(Exp)); 
					$$->position = $1->position;
					$$->value =$1->position;
					char buffer[10000];
               sprintf(buffer, "%s\n\t%s%s, %s, 1\n\tsw\t%s, (%s)", $1->code, $2, $1->value, $1->value, $1->value, $$->position);
               char *tempstr=malloc(strlen(buffer)+1);      
               strcpy(tempstr, buffer);
               $$->code=tempstr;
					
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
					char buffer[10000];
               sprintf(buffer, "%s%s\n\t%s\t%s, %s\n\tmflo\t%s", $1->code, $3->code, $2, $1->value, $3->value, $$->position);
               char *tempstr=malloc(strlen(buffer)+1);      
               strcpy(tempstr, buffer);
               $$->code=tempstr;

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
										 char buffer[10000];
               sprintf(buffer, "\n\tli\t%s, %s", $$->position, $1);
               char *tempstr=malloc(strlen(buffer)+1);      
               strcpy(tempstr, buffer);
               $$->code=tempstr;			   

										 }
| FLOAT_NUM      {$$=malloc(sizeof(exp)); 
					$$->position=createTemp();
					$$->value=$$->position;
					char buffer[10000];
               sprintf(buffer, "\n\tli\t%s, %s", $$->position, $1);
               char *tempstr=malloc(strlen(buffer)+1);      
               strcpy(tempstr, buffer);
               $$->code=tempstr;

	
}
;

call : ID '(' args ')'	{
if(strcmp($1,"print")==0){	
                        char buffer[10000];
               
                         sprintf(buffer, "%s\n\tli\t$v0, 1%s\n\tmove\t$a0, %s\n\tsyscall",$3->code,$$->code,$3->value );
                         char *tempstr=malloc(strlen(buffer)+1);      
                         strcpy(tempstr, buffer);
                         $$->code=tempstr;
		
						$$=malloc(sizeof(Exp)); 
						$$->position =$1;	
						 
					}
					else 
						if(strcmp($1,"println")==0){
							$$=malloc(sizeof(Exp)); 
							$$->position =$1;	
							$$->value =$1;	
							if (empty==0) {
							
							
							    char buffer[10000];
               
                                sprintf(buffer, "%s\n\tli\t$v0, 1\n\tmove\t$a0, %s\n\tsyscall\n\tli\t$v0, 4\n\tla\t$a0, newln\n\tsyscall",$3->code,$3->value);
                                char *tempstr=malloc(strlen(buffer)+1);      
                                strcpy(tempstr, buffer);
                                $$->code=tempstr;
							
							}
							else { 
							
							char buffer[10000];
               
                                sprintf(buffer, "\n\tli\t$v0, 4\n\tla\t$a0, newln\n\tsyscall");
                                char *tempstr=malloc(strlen(buffer)+1);      
                                strcpy(tempstr, buffer);
                                $$->code=tempstr;
							

								empty=0;
							}
						}else
							if(strcmp($1,"read")==0){
								$$=malloc(sizeof(Exp)); 
								$$->position =$3->position;	
								$$->value = $3->position;
								 char buffer[10000];
								 sprintf(buffer, "\n\tli\t$v0, 5%s\n\tsyscall,\n\tmove\t%s,$v0\n\t",$$->code,$3->position);
                         char *tempstr=malloc(strlen(buffer)+1);      
                         strcpy(tempstr, buffer);
                         $$->code=tempstr;
						}
							else
								if (strcmp($1,"input")==0){
									$$=malloc(sizeof(Exp)); 
									char buffer[10000];
               
                                sprintf(buffer, "\n\tjal\t%s",$1);
                                char *tempstr=malloc(strlen(buffer)+1);      
                                strcpy(tempstr, buffer);
                                $$->code=tempstr;
							
									

								}
								else 
									if (strcmp($1,"output")==0) {
										$$=malloc(sizeof(Exp)); 
										$$->position =$1;	
										$$->value =$1;	
										char buffer[10000];
               
                                sprintf(buffer, "%s\n\t,li\t$v0, 1\n\tmove\t$a0%s\n\tsyscall",$3->code,$3->value);
                                char *tempstr=malloc(strlen(buffer)+1);      
                                strcpy(tempstr, buffer);
                                $$->code=tempstr;
                        }
									else 
										{
											$$=malloc(sizeof(Exp)); 
											$$->position =$3->position;	
											$$->value = $3->position;
											
											char buffer[10000];
               
                                sprintf(buffer, "\n\tjal\t%s%s\n\tjal\t%s",$1,$3->code,$1);
                                char *tempstr=malloc(strlen(buffer)+1);      
                                strcpy(tempstr, buffer);
                                $$->code=tempstr;
											
									
											a_counter=0;
										}
   
									}
;

args : arg_list 	{$$=$1;empty=0;a_counter=0;}
| /*epsilon*/	    {empty=1;}
;

arg_list : arg_list ',' expression { 
									$$=$3;char str[15];sprintf(str, "%d", a_counter);
									
									char buffer[10000];
               sprintf(buffer, "%s%s\n\tmove\t$a%s, %s", $1->code, $3->code,str,$3->value);
               char *tempstr=malloc(strlen(buffer)+1);      
               strcpy(tempstr, buffer);
               $$->code=tempstr;
			   

									a_counter=0; 
								   }
| expression         { 
					$$=$1;char str[15];sprintf(str, "%d", a_counter);
					
					char buffer[10000];
               sprintf(buffer, "%s\n\tmove\t$a%s, %s", $1->code, str,$1->value);
               char *tempstr=malloc(strlen(buffer)+1);      
               strcpy(tempstr, buffer);
               $$->code=tempstr;
					

					a_counter++; }
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
		array.info[i]=NULL;  
	function_variables = malloc(sizeof(char *) * 10000);
	function_params = (Node **) malloc(sizeof(Node*)*4);
		
	printf("\n");
	yyparse();
	return 1;
}

void yyerror(const char *s) {

	printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): \x1b[32m%s\x1b[0m : \x1b[33m%s\x1b[0m\n", yylineno, s, yytext);
}

