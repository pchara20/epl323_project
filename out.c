#include <stdio.h>


int foo1(int a){
 return a;
}
int foo2(int a, int b){
 return a+b;
}
int foo3(int a, int b, int c){
 return a+b+c;
}
void main(){
 printf("Calling foo: %d\n",
foo1(10));
 printf("Calling foo: %d\n",
foo2(10, 10));
 printf("Calling foo: %d\n",
foo3(10, 10, 10));
} 
