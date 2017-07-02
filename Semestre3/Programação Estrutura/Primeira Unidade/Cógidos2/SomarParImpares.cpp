#include <stdio.h>
#include <stdlib.h>

int main(){
	int v[10],i,somaP=0,somaI=0;
	printf("Inf os valores do vetor !");
	for(i=0;i<10;i++){
		scanf("%d",&v[i]);
	}
	for(i=0;i<10;i++){
		if(i%2==0) somaP+= v[i]; else somaI += v[i];
	}
	printf("Soma dos Indices Pares: %d\nSoma dos Indices Impares: %d",somaP,somaI);
	
	return 0;
}
