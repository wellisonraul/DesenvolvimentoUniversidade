/* Faça um algoritmo que leia nome, idade, e sexo de N pessoas. Após a leitura faça:
A) Imprima o nome, idade e sexo das pessoas cuja a idade seja maior que a idade da primeira pessoa.
B) Imprima nome e idade de todas as mulheres.
C) Imprima o nome de todos os homens menores de 21 anos */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct dados{
	char nome[60], genero;
	int idade;
};

//declaração do escopo das funções

void todos(struct dados [], int);
void maior(struct dados [], int);
void impressaoMulheres(struct dados [], int);
void menor (struct dados [], int);

main(){
	int i=0, n=0;
	printf("Com quantas pessoas vamos trabalhar? ");
	scanf("%d", &n);
	
	struct dados p[n];
	for(i=0; i<n; i++){
		printf("----- FORMULARIO DE INSCRICAO -----\n\n");
		printf("-> Dados da pessoa %d <-\n", i+1);
		printf("Informe seu nome: ");
		scanf("%s", &p[i].nome);
		printf("Informe seu genero (M/F): ");
		p[i].genero = getche();
		printf("\nInforme sua idade: ");
		scanf("%d", &p[i].idade);
		system("CLS");
	}
	//chama os procedimentos
	printf("\n\nMostrando todos os dados digitados:\n");
	todos(p,n);
	printf("\n\nMostrando o nome a idade e o sexo de todas as pessoas de idade > 1a. pessoa:\n");
	maior(p,n);
	printf("\n\nMostrando os dados de todas as mulheres:\n");
	impressaoMulheres(p,n);  
	printf("\n\nMostrando todos os homens menores que 21 anos:\n");
	menor(p,n);
}

void todos(struct dados p[], int n){
	
	for(int i=0; i<n; i++){
		printf("%s, %c, %d ano(s) de idade.\n", p[i].nome, p[i].genero, p[i].idade);
	}
}
void maior (struct dados p[], int n){
	
	for(int i=0; i<n; i++){
		if(p[i].idade>p[0].idade){
			printf("%s, %c, %d ano(s) de idade.\n", p[i].nome, p[i].genero, p[i].idade);
		}
	}
}

void impressaoMulheres(struct dados p[], int n){
	
	for(int i=0; i< n; i++){
		if(p[i].genero=='f' || p[i].genero=='F'){
			printf("%s, %c, tem %d ano(s) de idade.\n", p[i].nome, p[i].genero, p[i].idade);
		}
	}
}

void menor (struct dados p[], int n){
	
	for(int i=0; i< n; i++){
		if(p[i].genero=='m' || p[i].genero=='M'){
			if(p[i].idade<21){
				printf("%s, %c, tem %d ano(s).\n", p[i].nome, p[i].genero, p[i].idade);
			}
		}
	}
}
