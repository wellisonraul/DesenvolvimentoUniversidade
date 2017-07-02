#include<stdio.h>
#include<stdlib.h>

	int main(){
		char **caminho;
		int n=5,m=30,i,j;

		caminho = (char **) malloc(n*sizeof(char *));
		if(M1 == NULL){
			printf("Nao foi possivel alocar a memoria!");
			return 0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				caminho[i]= (char *) malloc (m*sizeof(char));
				if(M1[i]==NULL){
					printf("Nao foi possivel alocar a memoria!");
					return 0;
				}
			}
		}
		return 0;
	}
	
	for(i=0;i<n;i++){
			free(M1[i]);
			free(M2[i]);
			free(M3[i]);
	}
	free(M1);
	free(M2);
	free(M3);
		
	
	return 0;
}
