#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int i,j,cont=0,n;
	float m[3][4],multiplicadordopivo=0,x1=0,x2=0,x3=0,multiplicadordopivo2=0,multiplicadordopivo3=0,aux=0;
	printf("Informe o numeros de incognitas ?");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			printf("Informe o valor da Matriz Ampliada m[%d][%d]: ",i,j);
			scanf("%f",&m[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			// 1º Pivo 
			if(i==j && m[i][j]==0 && i==0){
				if(m[i+1][j]!=0){
					for(i=0;i<1;i++){
						for(j=0;j<4;j++){
							aux = m[i][j];
							m[i][j]= m[i+1][j];
							m[i+1][j]=aux;	
						}
					}
				}else{
				if(m[i+2][j]!=0){
						for(i=0;i<1;i++){
							for(j=0;j<4;j++){
								aux = m[i][j];
								m[i][j]= m[i+2][j];
								m[i+2][j]=aux;	
							}
						}
					}
				}
			}
			// 2º Pivo !
			if(i==j && m[i][j]==0 && i==1){
				if(m[i+1][j]!=0){
					for(i=1;i<2;i++){
						for(j=0;j<4;j++){
							aux = m[i][j];
							m[i][j]= m[i+1][j];
							m[i+1][j]=aux;	
						}
					}
				}else{
				if(m[i-1][j]!=0){
						for(i=1;i<1;i++){
							for(j=0;j<4;j++){
								aux = m[i][j];
								m[i][j]= m[i-1][j];
								m[i-1][j]=aux;	
							}
						}
					}
				}
			}
			// 3 º Pivo
			if(i==j && m[i][j]==0 && i==2){
				if(m[i-1][j]!=0){
					for(i=2;i<3;i++){
						for(j=0;j<4;j++){
							aux = m[i][j];
							m[i][j]= m[i-1][j];
							m[i-1][j]=aux;	
						}
					}
				}else{
				if(m[i-2][j]!=0){
						for(i=2;i<3;i++){
							for(j=0;j<4;j++){
								aux = m[i][j];
								m[i][j]= m[i-2][j];
								m[i-2][j]=aux;	
							}
						}
					}
				}
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if((i==1 && j==0) || (i==2 && j==0)){
				multiplicadordopivo = m[i][j]/m[i-i][j-j];
			}
			// Zerando primeira e segunda linha
			if(i>0){
				m[i][j]=( (m[i][j]) - (multiplicadordopivo*m[i-i][j]));	
			}
		}
 }

	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if(i==2 && j==1) multiplicadordopivo = m[i][j]/m[j][j];
			// Zerando segunda linha
			if(i>=2){
				m[i][j]=( (m[i][j]) - (multiplicadordopivo*m[i-1][j]));		
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if(i==2 && j==2){
				multiplicadordopivo = m[0][2]/m[j][j];
			}
			if(i==2 && j==2){
				multiplicadordopivo2 = m[1][2]/m[j][j];
			}
			if(i==1 && j==1){
				multiplicadordopivo3 = m[0][1]/m[j][j];
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			if(i==0){
				m[i][j]=( (m[i][j]) - (multiplicadordopivo*m[i+2][j]));		
			}
			if(i==1){
				m[i][j]=( (m[i][j]) - (multiplicadordopivo2*m[i+1][j]));
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
				if(i==0){
					m[i][j]=( (m[i][j]) - (multiplicadordopivo3*m[i+1][j]));
				}
		}
	}
	for(i=3;i>=0;i--){
		for(j=4;j>=0;j--){			
				m[i][j]=m[i][j]/m[i][i];
		}
	}
		
	//Terminando a Matriz 
	for(i=2;i>=0;i--){
		for(j=3;j>=0;j--){
			if(i==j && cont!=1){
				x3 = m[i][j+1]/m[i][j];
				x2 = (m[i-1][j+1] - ((x3)*m[i-1][j]))/m[i-1][j-1];
				x1 =  (m[i-2][j+1] + (-(m[i-2][j-1]*x2)) + (-((x3)*m[i-2][j])))/m[i-2][j-2];
				cont ++;
			}
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%.2f|",m[i][j]);
		}
		printf("\n");
	}
	printf("\n\nX1: %.2f X2: %.2f X3: %.2f",x1,x2,x3);
	
	return 0;
}
