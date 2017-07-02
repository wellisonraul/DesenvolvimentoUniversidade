#include<stdlib.h>
#include<stdio.h>
int main(){
	int MatrizD[100][100],i,j,n,k,teste;
	char MatrizP[100][100];
	printf("Inf. a quantidade de Vertices?");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Inf. o vertice %d?",i+1);
		fflush(stdin);
		scanf("%c",&MatrizP[0][i]);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			MatrizP[j][i] = MatrizP[0][i];
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				printf("Inf. o valor entre o vertice %c para o %c! Obs: -1 para infinito!",MatrizP[0][i],MatrizP[0][j]);
				scanf("%d",&teste);
				if(teste==-1){
					MatrizD[i][j]=2147483647;
				}else{
					MatrizD[i][j]= teste;
					MatrizP[i][j]= MatrizP[i][i]; 			
				}
			}
		}
	}
	printf("\n");
	

	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((MatrizD[i][k]!=2147483647 ) && (MatrizD[k][j]!=2147483647) && i!=j){
					if((MatrizD[i][k] + MatrizD[k][j]) < MatrizD[i][j]){
						MatrizD[i][j] = MatrizD[i][k] + MatrizD[k][j];
						MatrizP[i][j] = MatrizP[k][k];
					}
				}
			}	
		}
	}
	
		
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("|%d|",MatrizD[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("|%c|",MatrizP[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
