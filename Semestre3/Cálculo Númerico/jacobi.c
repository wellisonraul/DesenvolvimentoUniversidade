#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int const Tmatriz;

void imprimir(float matriz[Tmatriz][Tmatriz+1],int Tmatriz){
	int i,j;
	printf("----------------Matriz Ampliada----------------\n");
	for(i=0;i<Tmatriz;i++){
		for(j=0;j<Tmatriz+1;j++){
			printf("%.2f |",matriz[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	printf("Informe quantidade de incognitas ? ");
	scanf("%d",&Tmatriz);
	system("cls");
	float matriz[Tmatriz][Tmatriz+1],XMatriz[100][Tmatriz],XmatrizP[Tmatriz];
	int i,j;
	printf("----------------Informe a Matriz----------------\n");
	for(i=0;i<Tmatriz;i++){
		for(j=0;j<Tmatriz+1;j++){
			printf("Matriz no ponto M[%d][%d]: ",i+1,j+1);
			scanf("%f",&matriz[i][j]);
		}
	}
	system("cls");
	imprimir(matriz,Tmatriz);
	getch();
	printf("\n----------------Iniciando os testes----------------\n");
	/*Váriaveis Teste */
	float cConvergencia=0, auxL;
	int teste=0;
	for(i=0;i<Tmatriz;i++){
		cConvergencia=0;
		for(j=0;j<Tmatriz;j++){
			if(i!=j){
				cConvergencia += pow((matriz[i][j]*matriz[i][j]),0.5);
			}
		}
		if(pow(pow(matriz[i][i],2),0.5)>cConvergencia){
			printf("\n|%.2f| < |%.2f|",cConvergencia,matriz[i][i]);
			
			printf("Convergencia aceita ");
		}else{
			printf("|%.2f| < |%.2f|",cConvergencia,matriz[i][i]);
			printf("\nConvergencia nao foi aceita ");
			return 0;
		}
		printf("\n");
	}
	getch();
	system("cls");
	printf("\n----------------Dividindo os Elementos pelo correspodente na diagonal principal----------------\n");
	for(i=0;i<Tmatriz;i++){
		auxL=matriz[i][i];
		for(j=0;j<Tmatriz+1;j++){
			matriz[i][j] = matriz[i][j]/auxL;
		}
	}
	
	for(i=0;i<Tmatriz;i++){
		cConvergencia=0;
		for(j=0;j<Tmatriz;j++){
			if(i!=j){
				cConvergencia += pow((matriz[i][j]*matriz[i][j]),0.5);
			}
		}
		if(pow(pow(matriz[i][i],2),0.5)>cConvergencia){
			printf("\n|%.2f| < |%.2f|",cConvergencia,matriz[i][i]);
			
			printf("Convergencia das Linhas aceita ");
		}else{
			printf("|%.2f| < |%.2f|",cConvergencia,matriz[i][i]);
			printf("\nConvergencia das Linhas nao foi aceita ");
			return 0;
		}
		printf("\n");
	}
	/* Parei aqui */
	for(j=0;j<Tmatriz;j++){
		cConvergencia=0;
		for(i=0;i<Tmatriz;i++){
			if(i!=j){
				cConvergencia += pow((matriz[j][i]*matriz[j][i]),0.5);
			}
		}
		if(matriz[j][j]>cConvergencia){
			printf("\n|%.2f| < |%.2f|",cConvergencia,matriz[j][j]);
			
			printf("Convergencia das Colunas aceita ");
		}else{
			printf("|%.2f| < |%.2f|",cConvergencia,matriz[j][j]);
			printf("\nConvergencia das Colunas nao foi aceita ");
			return 0;
		}
		printf("\n");
	}
	int cont=0;
	
	printf("----------------Informe Xo----------------\n");
	for(i=0;i<1;i++){
		for(j=0;j<Tmatriz;j++){
			scanf("%f",&XMatriz[i][j]);
		}
	}
	
	
	
	do{
	printf("Interacao %d: ",cont+1);
	for(i=0;i<Tmatriz;i++){
		XmatrizP[i]=0;
		for(j=0;j<Tmatriz;j++){
			if(i!=j){
				XmatrizP[i] += ((matriz[i][j])*(-1))*XMatriz[cont][j];
			}
		}
		XmatrizP[i] += matriz[i][j];
		printf("X%d | %.3f |",i+1,XmatrizP[i]);
	}
	printf("\n");
	cont++;
	for(i=0;i<1;i++){
		for(j=0;j<Tmatriz;j++){
			XMatriz[cont][j]=XmatrizP[j];
			if((pow(pow((XMatriz[cont][j] - XMatriz[cont-1][j] ),2),0.5)/ pow(pow(XMatriz[cont][j],2),0.5) ) < 0.01) teste++;
		}
	}
	}while(teste==0);
	
	return 0;
}
