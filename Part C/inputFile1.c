/******************************************************************
 Panayiotis Charalambous - pchara20 ID: 952304                    ***
 Andreas Costi            - acosti01 ID: 1003060                    ***
 Stephanie Nicolaou        - snikol07 ID: 932787                    ***
 ***
 Part C - Compilers                                                ***
 bison -d parser_952304_1003060_932787.y                            ***
 flex preprocessor_952304_1003060_932787.fl                        ***
 gcc parser_952304_1003060_932787.tab.c lex.yy.c -lfl -o a.out    ***
 ./a.out inputFile.c outputFile.c                                ***
 *******************************************************************/
int main(void){
	int i;
	int j;
	int k;
	i=0;
	j=0;
	k=0;
	while(i<=10){
		i++;
		println(i);
		if(j<=0){
			j++;
			for(k=0;k<=3;k++){
				j++;
				println(j);
			}
		}
	}
}
		
