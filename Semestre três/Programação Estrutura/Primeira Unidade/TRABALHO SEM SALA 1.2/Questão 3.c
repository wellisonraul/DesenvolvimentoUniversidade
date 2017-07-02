#include <stdio.h>
#include <stdlib.h>

struct Dados{
	char nome[15];
	int ano;
	float preco;
};

main(){
	struct Dados vetor[100];
	int n,i;
	float p;
	printf("Quantos carros deseja cadastrar ?");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("informe nome do carro !");
		scanf("%s",vetor[i].nome);
		printf("informe ano do carro !");
		scanf("%d",&vetor[i].ano);
		printf("informe preco do carro !");
		scanf("%f",&vetor[i].preco);
	}
	printf("Informe o preco ?");
	scanf("%f",&p);
	for(i=0;i<n;i++){
		if(vetor[i].preco<p){
			printf("Nome: %s Ano: %d Preco: %.2f \n",vetor[i].nome,vetor[i].ano,vetor[i].preco);
		}
	}
}
