#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
	float x,y;
}; 

float distancia(struct ponto p[],int n){
	float dca,**m;
	int i,j;

	m = (float **) malloc(n*sizeof(float *));
	if(m == NULL){
		printf("Nao foi possivel alocar a memoria!");
		return 0;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			m[i]= (float *) malloc (n*sizeof(float));
			if(m[i]==NULL){
				printf("Nao foi possivel alocar a memoria!");
				return 0;
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				m[i][j]=sqrt(((p[j].x-p[i].x)*(p[j].x-p[i].x))+((p[j].y-p[i].y)*(p[j].y-p[i].y)));
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==n-1 && i==n-1){
				break;
			} 
			printf("%.2f |",m[i][j]);
		}
		/* teste para não imprimir o ultimo numero */
		if(j==n-1 && i==n-1){
				break;
		} 
		printf("\n");
	}
	return m[i-1][j-1];
	
	for(i=0;i<n;i++){
		free(m[i]);

	}
	
	free(m);
}

main(){
	struct ponto *p;
	int i,n,m;
	printf("Inf. o tamanho ");
	scanf("%d",&n);
	
	
	p=(struct ponto *) malloc(sizeof(struct ponto)*n);
	if(p==NULL){
		printf("Não foi possivel alocar a memoria"); 
		return 0;	
	} 
	
	for(i=0;i<n;i++){
		scanf("%f",&p[i].x);
		scanf("%f",&p[i].y);
	}
	
	printf("%.2f |",distancia(p,n));
	
	return 0;
}
