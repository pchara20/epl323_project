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
int createHashTable(hashtable ** hashTable, char *name,char *type, int isFunc);
char * searchNodes(hashtable *table,char * var);
int initStack(STACK**stack);
void push(hashtable *newHash, STACK *stack);
hashtable* pop(STACK *stack);
char * searchHash(char * variable, STACK *stack);

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

hashtable* pop(STACK *stack){
   hashtable *temp=NULL;
   if (stack->size==0){
      printf("Stack is empty\n");
      return NULL;
   }       
   stack->size--;
   temp=&stack->hashTables[stack->size];
   return temp;   
}

void printStack(STACK *stack){
   int i=0;
   for (i=0;i<stack->size;i++){
      printf("HashTable Position %d \n",i);
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
   printf("----------------- PRINTING HASHTABLE ----------\n");
   printf("Name: %s\n",hashTable->namefunction);
   printf("Type: %s\n",hashTable->typefunction);
   printf("Is function (1 for yes, else no): %d\n",hashTable->isFunction);
   printf("Variables in this hashTable %d\n",hashTable->size);
   printf("Parameters %d\n",hashTable->countparamfunc);
   int i;
   for (i=0;i<hashTable->size;i++)
      printNode(&hashTable->node[i]);
   printf("----------------- END HASHTABLE ----------\n");
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
      printf("----------------- PRINTING NODE ----------\n");
       printf("name: %s \n", node->name);
       printf("type: %s \n", node->type);
       printf("whatfunction: %d\n", node->parentPosition);
       printf("line number %d\n",node->lineNumber);
       printf("type %d\n",node->varType);                    
       printf("----------------- END NODE ----------\n");         
}        

int insertNode(NODE* node,STACK *stack){
   stack->hashTables[node->parentPosition].node[stack->hashTables[node->parentPosition].size]=(*node);
   stack->hashTables[node->parentPosition].size++;
   return EXIT_SUCCESS;
}

int findScope ( STACK *stack){
   int num;
   num=stack->size-1;
   while (stack->hashTables[num].isFunction!=1)
      num--;
   return num;
   }

char * searchHash(char * variable, STACK *stack){
   int scopeMax=findScope(stack);
   printf("To scope in %d\n",scopeMax);
   int tableIndex=stack->size-1;
   char *temp;
   if (searchNodes(&stack->hashTables[tableIndex],variable)!=NULL)
      return searchNodes(&stack->hashTables[tableIndex],variable);
   
   while (tableIndex>=scopeMax){
      if ((searchNodes(&stack->hashTables[tableIndex],variable))!=NULL)
         return searchNodes(&stack->hashTables[tableIndex],variable);
      else
         tableIndex--;
   }
   if ((strcmp(stack->hashTables[0].namefunction,"global")==0)&&(searchNodes(&stack->hashTables[0],variable)!=NULL))
      return searchNodes(&stack->hashTables[0],variable);
   return "NULL";
} 

int searchPosition(char * variable, STACK *stack){
   int scopeMax=findScope(stack);
   int tableIndex=stack->size-1;
   char *temp;
   if (searchNodes(&stack->hashTables[tableIndex],variable)!=NULL)
      return tableIndex;
   
   while (tableIndex>scopeMax){
      if ((searchNodes(&stack->hashTables[tableIndex],variable))!=NULL)
         return tableIndex;
      else
         tableIndex--;
   }
   return -1;
} 

char * searchNodes(hashtable *table,char * var){
   int i;
   for ( i=0;i<table->size;i++){
      if (strcmp(table->node[i].name,var)==0){         
         char * result = malloc(sizeof(strlen(table->node[i].type)));
         strcpy(result,table->node[i].type);
         return result;
         }
      }
      return "NULL";
}
   

   int compareArgs(STACK *stack, char *typeofarg,int position,int varType){  
    /*int i;
    hashtable *hash=(*stack)->hashTables[position];
    NODE *node=hash->node;
    NODE *help=hash->node;
    
    for (i=0;i<hash->size;i++){
        if(strcmp(node->type,typeofarg)==0 && node->varType==varType){
            while(strcmp(help->name,node->name)!=0){
                if(help->isclosed==0 && help->isarg==1)
                    return 2;
                    help=help->next;
            }
            node->isclosed=1;
            return 1;
        }
         node=node->next;
    }*/
    return 0;
}
           
         
         
   

   



   
   






      
   





