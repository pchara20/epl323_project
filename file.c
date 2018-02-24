#include <stdio.h>

int kokos ( int sasa,int asd,int asd,int asd,int asd,int asd,int asd,int asd,int asd,int asd,int asd,int asd ){}


int foo (int a){
 return a;
}
int foo (int a, int b){
 return a+b;
}
int foo (int a, int b, int c){
 return a+b+c;
}
void main(){
 printf("Calling foo: %d\n",
foo(10));
 printf("Calling foo: %d\n",
foo(10, 10));
 printf("Calling foo: %d\n",
foo(10, 10, 10));
} 
