#include <stdio.h>

main(){
	int v[10],i,menor,soma,tmaior,maior,ql=0;
	printf("Inf o vetor\n");

	for(i=0;i<10;i++){
		scanf("%d",&v[i]);
		soma = soma + v[i];
	}
	printf("Vetor Normal: ");
	for(i=0;i<10;i++){
		printf("%d|",v[i]);
	}
	for(i=0;i<10;i++){
		if(v[i]<soma){
			menor = v[i];
			soma = v[i];
		}
	}
	tmaior = menor;
	for(i=0;i<10;i++){
		if(v[i]>tmaior){
			
			maior = v[i];
			tmaior = v[i];
			ql = 0;
			ql = ql + i; 
		}
	}
	v[ql]= v[9];
	v[9] = maior;
	printf("\nVetor modificado: ");
	for(i=0;i<10;i++){
		printf("%d|",v[i]);
	}
}
