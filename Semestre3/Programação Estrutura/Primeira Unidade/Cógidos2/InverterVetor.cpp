#include <stdio.h>
#include <stdlib.h>

int main(){
	int v[10],i;
	printf("Inf os valores do vetor !");
	for(i=0;i<10;i++){
		scanf("%d",&v[i]);
	}
	for(i=10;i>-1;i--){
		printf(" %d |",v[i]);
	}
	return 0;
}
