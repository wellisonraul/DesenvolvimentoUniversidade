#include<stdio.h>
#include<stdlib.h>
struct Dados{
	char nome[60];
	float v[2],soma;
};

void Ler(struct Dados []);
char *media(char[],float);
int main(){
	struct Dados alunos[5];
	int i;
	Ler(alunos);
	for(i=0;i<5;i++){
		printf("%s",media(alunos[i].nome, alunos[i].soma));	
	}
	
	return 0;
}


void Ler(struct Dados alunos[]){
	int i,j;
	
	for(i=0;i<5;i++){
		printf("Inf o nome do %d aluno ?",i+1);
		scanf("%s",alunos[i].nome);
		for(j=0;j<2;j++){
			printf("Inf a %d nota do %d aluno ?",j+1,i+1);
			scanf("%f",&alunos[i].v[j]);
			alunos[i].soma += alunos[i].v[j]; 	
		}
		alunos[i].soma/= 2;
	}
	
	
	
}
char *media(char nome[],float soma){
		printf("Aluno: %s está ",nome);
		if(soma<5) return "media inferior a 5 reprovado";
		if(soma>5 && soma<=6.9) return "media entre 5 e 6,9 recuperacao";
		if(soma>=7) return "media superior ou igual a 7 aprovado";
		return "Null";
}
