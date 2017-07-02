#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[3][3],i,j=0,aux,cont=0;
	
	printf("Preencha a Matriz!");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d |",m[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++){
		cont++;
		j=cont;
		for(;j<3;j++){
				aux = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = aux;
		}
	}
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		printf("%d |",m[i][j]);
		}
		printf("\n");
	}
}
