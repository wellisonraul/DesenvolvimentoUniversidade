#include<stdio.h>
#include<stdlib.h>
struct Dados{
	char nome[16];
	int ano;
	float preco;
};

int main(){
	struct Dados *v ;
	int n,i;
	float p;
	
	scanf("%d",&n);
	
	v=(struct Dados *) malloc(sizeof(struct Dados)*n);
	if(v==NULL){
		printf("Não foi possivel alocar a memoria"); 
		return 0;	
	} 
	
	for(i=0;i<n;i++){
		scanf("%s",v[i].nome);
		scanf("%d",&v[i].ano);
		scanf("%f",&v[i].preco);
	}
	
	scanf("%f",&p);
	
	for(i=0;i<n;i++){
		if(p>v[i].preco){
			printf("Carro: %s Ano: %d Preco: %.2f\n",v[i].nome,v[i].ano,v[i].preco);
		}
	}
	free(v);
	return 0;
}
