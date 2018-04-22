void gcd (int y,int z) {
	int x;
	x=y+z;
	println(x);
	return;
}
int main(void){
	int i;
	int j;
	int k;
	j=input();
	i=input();
	k=i+j;
	output(k);
	println();
	gcd(j,i);
	for(i=0;i<=10;i++){
		j++;
		println(j);
	}
}
