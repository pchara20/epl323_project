#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct Exp {
	char *position;
	char *code;
	char *value;
	char imm;
} Exp;

typedef struct Stmt {
	char *start;
	char *code;
	char *next;
} Stmt;

typedef struct {
	char *key;
	char *value;
}Node;

typedef struct{
	Node *info[100];
}Array;

char *createTemp();
char *createLabel();
char *mergeStrings(int count, ...);
char * insert(Array *array, char *name);
void clearArray(Array *array);
char *findInTheArray(Array *array,char *key);

