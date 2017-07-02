#include <stdio.h>
#include <stdlib.h>

int main(){
	const int tam = 10;
	int m[tam][tam],i,j,aux;
	
	printf("Preencha a Matriz!");
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			printf("%d |",m[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(i%2==0){
				aux = m[i][j];
				m[i][j] = m[i+1][j];
				m[i+1][j] = aux;
			}
		}
	}
	printf("\n");
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			printf("%d |",m[i][j]);
		}
		printf("\n");
	}

}
