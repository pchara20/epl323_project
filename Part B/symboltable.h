#include <stdio.h>
#include <stdlib.h>

enum var_type {
    TABLE,
    VARIABLE  
};

typedef struct node{
    char name[50];
    char* type;  
    enum var_type varType;        
    struct node* next;
} NODE;

typedef struct hashtable{
    int isfunc;
    char namefunction[50];
    char typefunction[50]; 
    NODE * node;
    int size;
    int countparamfunc;
    struct hashtable* next;
}hashtable;

typedef struct {
  hashtable *top;
  int size;
} STACK;

