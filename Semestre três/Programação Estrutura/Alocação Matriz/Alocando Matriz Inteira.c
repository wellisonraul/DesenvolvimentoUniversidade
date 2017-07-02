#include<stdio.h>
#include<stdlib.h>

int main(){
	int **M1,**M2,**M3,n,m,i,j;
	
	scanf("%d%d",&n,&m);
	
	M1 = (int **) malloc(n*sizeof(int *));
	if(M1 == NULL) return 0;
	M2 = (int **) malloc(n*sizeof(int *));
	M3 = (int **) malloc(n*sizeof(int *));
	if(M1 == NULL || M2== NULL || M3==NULL){
		printf("Nao foi possivel alocar a memoria!");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			M1[i]= (int *) malloc (m*sizeof(int));
			M2[i]= (int *) malloc (m*sizeof(int));
			M3[i]= (int *) malloc (m*sizeof(int));
			if(M1[i]==NULL || M2[i]==NULL || M3[i]==NULL  ){
				printf("Nao foi possivel alocar a memoria!");
				return 0;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&M1[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&M2[i][j]);
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d|",M3[i][j]);
		}
		printf("\n");
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
