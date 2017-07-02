#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
	char nome[50];
	float nota[3];
};
main(){
	struct Aluno cadastro[2];
	char nome[50];
	int i,j,quantidadedenomes=0;
	for(i=0;i<5;i++){
		printf("Informe o nome do %do aluno: ",i+1);
		scanf("%s",cadastro[i].nome);
		fflush(stdin);
		/*for(j=0;j<3;j++){
			printf("Informe a %o  nota aluno: ",j+1);
			scanf("%f",&cadastro[i].nota[j]);	
		}*/
	}
	for(i=0;i<5;i++){
			printf("Nome %d: %s\t",i+1,cadastro[i].nome);
		for(j=0;j<3;j++){
			printf("Nota %d: %.2f\t",j+1,cadastro[i].nota[j]);
		}
		printf("\n");
	}
	printf("\n\n Digite um nome a ser pesquisado ? \n");
   fflush(stdin);
   gets(nome);
   fflush(stdin);
   printf("\nNome que deve ser encontrado: %s !",nome);
   for(int cont=0;cont<=4;cont++){
   		if(strcmp(strupr(nome),strupr(cadastro[cont].nome)) == 0){
   			quantidadedenomes=cont;
   		}
   }
   printf("\nSendo Encontrado %d Nomes nesse registro",quantidadedenomes+1);
}
