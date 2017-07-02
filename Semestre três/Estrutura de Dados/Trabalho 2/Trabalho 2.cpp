#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(){
	int i,j,ii,jj,cont=0,DeterminanteA=0,DeterminanteB=0,aux=1;
	float MatrizInversa[3][3],a[3][3],b[3][3],VetorAuxiliar[4],MatrizCofatora[3][3],MatrizAdjunta[3][3];
	
	// Inserindo valores na Matriz A
	printf("Preencha a Matriz com obs: DIGITAR VALORES NUMERICOS DO TIPO REAL \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Inf. o valor M[%d][%d] da matriz: ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
	// Questão A
	printf("\n\nMatriz A: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			//Questão B
			b[i][j]=a[j][i];
			printf(" %.2f|",a[i][j]);
		}
		printf("\n");
	}
	//Questão C
	printf("\n\nMatriz B: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.2f|",b[i][j]);
		}
		printf("\n");
	}
	//Determinante A 
	for(i=0;i<3;i++){
		aux = 1;
		for(j=0;j<3;j++){ 
			
			aux *= a[j][(j+i)%3];
			
		}
		DeterminanteA += aux;
	}
	for(i=0;i<3;i++){
		aux = 1;
		for(j=0;j<3;j++){ 
			
			aux *= a[j][(2-j+i)%3];
			
		}
		DeterminanteA = DeterminanteA - aux ;
	}
	printf("\nDeterminante A: %d",DeterminanteA);
	//Determinante B
	for(i=0;i<3;i++){
		aux = 1;
		for(j=0;j<3;j++){ 
			
			aux *= a[j][(j+i)%3];
			
		}
		DeterminanteB += aux;
	}
	for(i=0;i<3;i++){
		aux = 1;
		for(j=0;j<3;j++){ 
			
			aux *= a[j][(2-j+i)%3];
			
		}
		DeterminanteB = DeterminanteB - aux ;
	}
	//Matriz Cofatora
	if(DeterminanteB!=0){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cont=0;
				for(ii=0;ii<3;ii++){
					for(jj=0;jj<3;jj++){
						if(i!=ii && j!=jj){
							VetorAuxiliar[cont] = a[ii][jj];
							cont++;
						}
					}	
				}
				//Matriz Cofatora
				MatrizCofatora[i][j]= ((pow((-1),i+j)) * ((VetorAuxiliar[0]*VetorAuxiliar[3]) - (VetorAuxiliar[1]*VetorAuxiliar[2])));
			}
		}
		//Matriz Adjunta
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				MatrizAdjunta[i][j]=MatrizCofatora[j][i];
			}
		}
		//Matriz Inversa
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
		  		MatrizInversa[i][j]=MatrizAdjunta[i][j]/(float)DeterminanteB;
		  	}
		}
		printf("\n\nMatriz Inversa B:\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%.2f|",MatrizInversa[i][j]);
			}
			printf("\n");
		}	
	}else{
		printf("\n\nDeterminante = 0 logo nao possui inversa !");
	}
	return 0;
}
