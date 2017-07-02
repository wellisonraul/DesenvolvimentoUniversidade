#include <stdio.h>
#define TAM 200
main(){
	int v[TAM],i,menor=0;
	
	for(i=0;i<TAM;i++){
		printf("Inf. os valores para o indice %d. do vetor? ",i+1);
		scanf("%d",&v[i]);
	}
	menor=v[TAM-1];
	for(i=0;i<TAM;i++){
		if(v[i]<menor){
			menor = v[i];
		}
	}
	printf("Menor valor eh: %d",menor);
	
}
