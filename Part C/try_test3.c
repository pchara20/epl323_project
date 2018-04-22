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
		
