#include <stdio.h>
#include <stdlib.h>

enum  var_type{
    TABLE,
    VARIABLE  
};

typedef struct node{
    char name[50];
    char type[50];  
    enum var_type varType;    
    int lineNumber;
    int parentPosition;
} NODE;

typedef struct hashtable{
    int isFunction;
    char namefunction[50];
    char typefunction[50]; 
    NODE node[100];
    int size;
    int countparamfunc;    
}hashtable;

typedef struct {
  hashtable hashTables[100];
  int size;
} STACK;


//FUNCTION DECLARATIONS
void printHashTable(hashtable *hashTable);
void printNode(NODE *node);


// STACK OPERATIONS //
int initStack(STACK**stack) {
  *stack = (STACK* )malloc(sizeof(STACK));
  if ((*stack) == NULL) return EXIT_FAILURE; 
  (*stack)->size = 0;
  return EXIT_SUCCESS;
}

void push(hashtable *newHash, STACK *stack){
      stack->hashTables[stack->size]=*newHash;
      stack->size++;
}

void pop(STACK *stack){
   if (stack->size==0)
      printf("Stack is empty\n");
   else{    
   stack->size--;
   }
}

void printStack(STACK *stack){
   int i=0;
   for (i=0;i<stack->size;i++){
      printf("Position %d \n",i);
      printHashTable(&stack->hashTables[i]);
   }
}    

// STACK OPERATIONS // 

//HASHTABLE OPERATIONS // 

int createHashTable(hashtable ** hashTable, char *name,char *type, int isFunc){   
    (*hashTable) = (hashtable*)malloc(sizeof(hashtable));
     if ((*hashTable) == NULL) 
      return EXIT_FAILURE;
    memset((*hashTable)->namefunction, '\0', sizeof((*hashTable)->namefunction));
    memset((*hashTable)->typefunction, '\0', sizeof((*hashTable)->typefunction));
    strcpy((*hashTable)->namefunction,name);
    strcpy((*hashTable)->typefunction,type);
    (*hashTable)->isFunction=isFunc;
    (*hashTable)->size=0;
    (*hashTable)->countparamfunc=0;
    return EXIT_SUCCESS;
}

void printHashTable(hashtable *hashTable){
   printf("Name: %s\n",hashTable->namefunction);
   printf("Type: %s\n",hashTable->typefunction);
   printf("Is function (1 for yes, else no): %d\n",hashTable->isFunction);
   printf("Variables in this hashTable %d\n",hashTable->size);
   printf("Parameters %d\n",hashTable->countparamfunc);
   int i;
   for (i=0;i<hashTable->size;i++)
      printNode(&hashTable->node[i]);
}

int isEmpty(hashtable *hashTable){
   return (hashTable->size==0);   
}

// HASHTABLE OPERATIONS //

// NODE OPERATIONS // 

int createNode(NODE **node, char *name,char *type, int hashTablePosition, int lineNumber,int varType) {  
  *node = (NODE *)malloc(sizeof(NODE));
  if (*node== NULL) {
    return EXIT_FAILURE;
  }  
  strcpy((*node)->name,name);   
  strcpy((*node)->type,type);
  (*node)->parentPosition=hashTablePosition;
  (*node)->lineNumber=lineNumber;
  if (varType==1)
  (*node)->varType=VARIABLE;
  else
  (*node)->varType=TABLE;  
  return EXIT_SUCCESS;
}

void printNode(NODE *node){ 
       printf("name: %s \n", node->name);
       printf("type: %s \n", node->type);
       printf("whatfunction: %d\n", node->parentPosition);
       printf("line number %d\n",node->lineNumber);
       printf("type %d\n",node->varType);                             
}        

int insertNode(NODE* node,STACK *stack){
   stack->hashTables[node->parentPosition].node[stack->hashTables[node->parentPosition].size]=(*node);
   stack->hashTables[node->parentPosition].size++;
   return EXIT_SUCCESS;
}
   



   
   






      
   





