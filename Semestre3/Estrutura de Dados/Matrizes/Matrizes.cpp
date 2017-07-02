#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[3][3],i,j,somaI=0,contI=0,sub2=0,multD=1,somaS=0,soma1=0,multC=1;
	//Preenchendo a Matriz
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			m[i][j] = i*3 + j;
		}
	}
	//Mostrando a Matriz
	printf("Matriz Preenchida!\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d |",m[i][j]);
		}
		printf("\n");
	}
	//Valores pares da Matriz
	printf("\nValores Pares!\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(m[i][j]%2==0) printf("%d |",m[i][j]); else printf("  |");
		}
		printf("\n");
	}
	//Média dos Impares
	printf("\n\nMedia dos Impares!\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(m[i][j]%2==1){
				somaI+= m[i][j];
				contI++;
			}
		}
	}
	//Subtraindo Elementos
	printf("%d",somaI/contI);
	printf("\n\nSubtraindo Elementos da Linha 2!\n");
	for(i=1;i<=1;i++){
		for(j=0;j<=2;j++){
			sub2 = sub2-m[i][j];
			if(j==0) sub2 = sub2 * -1;
		}
	}
	
	printf("%d",sub2);
	//Diagonal Principal
	printf("\n\nElementos da Diagonal Principal e sua Multiplicação!\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j){
				printf("%d |",m[i][j]);
				multD*= m[i][j];
			}else{
				printf("  |");
			}
		}
		printf("\n");
	}
	printf("Multiplicacao: %d\n",multD);
	//Diagonal Secundaria
	printf("\n\nElementos da Diagonal Secundaria e sua Soma!\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i+j==2){
				printf("%d |",m[i][j]);
				somaS += m[i][j];
			}else{
				printf("  |");
			}
		}
		printf("\n");
	}
	printf("Soma: %d\n",somaS);
	// Soma da primeira linha
	printf("\n\nSoma dos Elementos da 1 linha e sua Soma!\n");
	for(i=0;i<1;i++){
		for(j=0;j<3;j++){
				soma1+= m[i][j];
			}
		printf("\n");
	}
	printf("Soma: %d\n",soma1);
	//Multiplicar os Elementos
	printf("\n\nMultiplicar dos Elementos da 2 coluna !\n");
	for(i=0;i<3;i++){
		for(j=1;j<2;j++){
				multC*= m[i][j];
			}
		printf("\n");
	}
	printf("Multiplicacao: %d\n",multC);
}
