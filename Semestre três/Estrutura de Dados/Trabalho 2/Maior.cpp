#include <stdio.h>
#define TAM 3
main(){
	int v[TAM],i,maior=0;
	
	for(i=0;i<TAM;i++){
		printf("Inf. os valores para o indice %d. do vetor? ",i+1);
		scanf("%d",&v[i]);
	}
	maior=v[TAM-1];
	for(i=0;i<TAM;i++){
		if(v[i]>maior){
			maior = v[i];
		}
	}
	printf("Maior valor eh: %d",maior);
	
}
