#include "helper.h"
int temp = 0;
int label = 0;
int flag = 0;

char *createTemp(){
	char * str = (char *) malloc(5);
	temp = temp % 8 + 1;
	if (temp == 1)
		flag = !flag;
	if (flag)
		sprintf(str, "$t%d", temp);
	else
		sprintf(str, "$s%d", temp);
	return str;
}

char *createLabel(){
	char * str = (char *) malloc(4);
	sprintf(str, "L%d", (++label));
	return str;
}

char *mergeStrings(int count, ...){
	char buf[10000] = { };
	va_list args;
	
	va_start(args, count);
	int x;
	for (x = 0; x < count; x++) {
		strcat(buf, va_arg(args, char *));
		//printf("buf = %s \n",buf);
	}
	va_end(args);
	//printf("count = %d \n",count);
	char *str = malloc(strlen(buf) + 1);
	strcpy(str, buf);
	return str;

}

char * insert(Array *array, char *name){
	int i;
	for(i=0;i<100;i++){
		if(array->info[i]==NULL){
			array->info[i] = (Node *) malloc(sizeof(Node));
			array->info[i]->key=name;
			array->info[i]->value= createTemp();
			return array->info[i]->value;
		}
	}
}

void clearArray(Array *array){
	int i;
	for(i=0;i<100;i++)
		array->info[i]=NULL;
}

char *findInTheArray(Array *array,char *key){
	int i;
	for(i=0;i<100;i++){
		if(array->info[i]==NULL)
			continue;	
		if(strcmp(key,array->info[i]->key)==0){
			return array->info[i]->value;
		}
	}
	return NULL;
}
