#include <stdio.h>
#include <stdlib.h>

int main(){
	int v[10],i,aux,n=9;
	printf("Inf os valores do vetor !");
	for(i=0;i<10;i++){
		scanf("%d",&v[i]);
	}
	for(i=0;i<5;i++){
		aux = v[i];
		v[i] = v[n];
		v[n] = aux;
		n--;
	}
	for(i=0;i<10;i++){
		printf("%d |",v[i]);
	}
	return 0;
}
