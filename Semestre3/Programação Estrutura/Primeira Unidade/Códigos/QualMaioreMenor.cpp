#include <stdio.h>

main(){
	int n[3],i,soma,menor,maior,tmaior;
	printf("Inf. tres numeros\n");
	for(i=0; i<3;i++){
		scanf("%d",&n[i]);
		soma = soma + n[i];
	}
	for(i=0;i<3;i++){
		if(n[i]<soma){
			menor = n[i];
			soma = n[i];
		}
	}
	tmaior = menor;
	for(i=0;i<3;i++){
		if(n[i]>tmaior){
			maior = n[i];
			tmaior = n[i];
		}
	}
	printf("\nMenor: %d",menor);
	printf("\nMaior: %d",maior);
}
