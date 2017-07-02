#include <stdio.h>
#define TAM 5
main(){
	float v[TAM],media,soma;
	int i;
	for(i=0;i<TAM;i++){
		printf("Inf o %d valor dos numeros: ",i+1);
		scanf("%f",&v[i]);
		soma += v[i];
	}
	media = soma/TAM;
	printf("Valores: |");
	for(i=0;i<TAM;i++){
		if(v[i]>media) printf("%.1f|",v[i]);
	}
}
