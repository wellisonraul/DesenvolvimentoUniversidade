#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	int id;
	char nome[50];
};
const int tam = 3 ;
main(){
	struct pessoa v[tam],aux;
	int i,j;
	
	for(i=0;i<tam;i++){
		printf("Inf. %d Nome: ",i+1);
		scanf("%s",v[i].nome);
		printf("Inf. %d Idade: ",i+1);
		scanf("%d",&v[i].id);
	}
	for(i=tam;i>=0;i--){
		for(j=0;j<i;j++){
			if(v[j].id<v[j+1].id){
				aux = v[j];
				v[j]=v[j+1];
				v[j+1] = aux;
			}
		}
	}
	printf("\nPessoas Ordenadas de forma Decrescente de Idade\n");
	for(i=0;i<tam;i++){
		printf("Nome: %s Idade: %d\n",v[i].nome,v[i].id);
	}
	
}
