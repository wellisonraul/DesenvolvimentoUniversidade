#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[3][3],i,j;
	
	printf("Preencha a Matriz!");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			m[i][j]=  i+j;
		}
	}
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d |",m[j][i]);
		}
		printf("\n");
	}
}
