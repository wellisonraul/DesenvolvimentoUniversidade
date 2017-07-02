//questão 7
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

main(){
	int qtp;
	printf("Inf a quantidade de pessoas para o cadastro ?");
	scanf("%d",&qtp);
	
	char nome[qtp][50],sexo[qtp][1],idade[qtp][3],gam[qtp][50];
	int i=0;
	for(i=0;i<qtp;i++){
		if(i==0){
			gets(gam[i]);
		}
		printf("Informe seu Nome: ");
		gets(nome[i]);
		printf("Informe sua idade: ");
		gets(idade[i]);
		printf("Informe seu sexo: M para homens ou F para mulheres ");
		gets(sexo[i]);
	}
	printf("Pessoas com idades maiores do que a primeira pessoa cadastrada \n");
	for(i=0;i<qtp;i++){
		if( (int)atoi(idade[0])<(int)atoi(idade[i])){
			printf("Nome: %s Idade: %s Sexo: %c \n",nome[i],idade[i],sexo[i][0]);
		}
	}
	printf("\nMulheres cadastradas \n");
	for(i=0;i<qtp;i++){
		if((sexo[i][0]=='F') || sexo[i][0]=='f'){
			printf("Nome: %s Idade: %s\n",nome[i],idade[i]);
		}
	}
	printf("\nHomens com menos de 21 anos \n");
	for(i=0;i<qtp;i++){
		if(((sexo[i][0]=='M') || (sexo[i][0]=='m')) && ((int)atoi(idade[i])<21)){
			printf("Nome: %s \n",nome[i]);
		}
	}
	
}
