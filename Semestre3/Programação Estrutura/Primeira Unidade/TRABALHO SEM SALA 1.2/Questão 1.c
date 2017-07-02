#include <stdio.h>
#include <stdlib.h>

main(){
	float vetor[100],aux;
	int n,i,j,contq=0;
	//Ler o tamanho do vetor
	printf("Inf. tamanho do vetor");
	scanf("%d",&n);
	//Ler o vetor
	for(i=0;i<n;i++){
		scanf("%f",&vetor[i]);
	}
	// Ordenar o vetor
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(vetor[j]>vetor[j+1]){
				aux = vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]= aux;
			}
		}
	}
	// Contando números iguais
	for(i=0;i<n;i+=contq){
		contq=0;
		for(j=i;j<n;j++){
			if(vetor[i]==vetor[j]){
				contq++;
			}
		}
		
		printf("%.2f -> %d vezes\n",vetor[i],contq);
	}
}
