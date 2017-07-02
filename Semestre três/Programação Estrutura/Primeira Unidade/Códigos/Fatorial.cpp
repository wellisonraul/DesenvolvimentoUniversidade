#include <stdio.h>

main(){
	int n,fat=1; 
	printf("Inf N?\n");
	scanf("%d",&n);
	if(n==0 || n==1) n = 1 ;
	for(n;n>=2;n--){
		fat = fat * n;
	}
	printf("Fatorial eh: %d",fat);

}

