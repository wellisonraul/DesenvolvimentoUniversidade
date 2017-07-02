#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,m, matriz[100][100],matriz1[100][100],i,j,matriz2[100][100];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&matriz1[i][j]);
			matriz2[i][j] = matriz[i][j] + matriz1[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d|",matriz2[i][j]);
		}
		printf("\n");
	}
	return 0;
}
