#include <stdio.h>
#include <stdlib.h>
struct Dados{
	char nome[60];
	int idade;
	char sexo;
};

void todos(struct Dados [],int);
void maior(struct Dados [],int);
void impressaoMulheres(struct Dados [],int);
void menor(struct Dados [],int);


int main(){
	struct Dados Pessoas[100];
	int n,i;
	printf("Inf. quantidade de pessoas a serem cadastradas !");
	scanf("%d",&n);
	system("cls");
	for(i=0;i<n;i++){
		printf("-----FORMULARIO DE CADASTRAMENTO-----\n");
		printf("Inf. seu nome: ");
		fflush(stdin);
		gets(Pessoas[i].nome);
		fflush(stdin);
		printf("Inf. sua idade: ");
		scanf("%d",&Pessoas[i].idade);
		fflush(stdin);
		printf("Inf. seu sexo: ");
		Pessoas[i].sexo = getchar();
		system("cls");
	}
	todos(Pessoas, n);
	maior(Pessoas, n);
	impressaoMulheres(Pessoas, n);
	menor(Pessoas, n);
	
	
	return 0;
}

void todos(struct Dados Pessoas[],int n){
	int i;
	printf("-----TODAS AS PESSOAS CADASTRADAS-----\n");
	for(i=0;i<n;i++){
		printf("%s possui %d anos, sexo %c\n",Pessoas[i].nome,Pessoas[i].idade,Pessoas[i].sexo);
	}
	printf("\n");
}
void maior(struct Dados Pessoas[],int n){
	int i;
	printf("\n----TODAS AS PESSOAS CADASTRADAS QUE POSSUEM IDADE SUPERIOR A PRIMEIRA PESSOA----\n");
	for(i=1;i<n;i++){
		if(Pessoas[i].idade>Pessoas[0].idade) printf("%s possui %d anos, sexo %c\n",Pessoas[i].nome,Pessoas[i].idade,Pessoas[i].sexo);
	}
	printf("\n");
}
void impressaoMulheres(struct Dados Pessoas[],int n){
	int i;
	printf("\n----TODAS AS PESSOAS CADASTRADAS DO SEXO FEMININO----\n");
	for(i=0;i<n;i++){
		if(Pessoas[i].sexo=='F' || Pessoas[i].sexo=='f' ) printf("%s possui %d anos \n",Pessoas[i].nome,Pessoas[i].idade);
	}
	printf("\n");
}

void menor(struct Dados Pessoas[],int n){
	int i;
	printf("\n----TODAS AS PESSOAS CADASTRADAS DO SEXO MASCULINO COM MENOS DE 21 ANOS----\n");
	for(i=0;i<n;i++){
		if((Pessoas[i].sexo=='m' || Pessoas[i].sexo=='M') &&( Pessoas[i].idade<21) ) printf("%s\n",Pessoas[i].nome);
	}
	printf("\n");
}
