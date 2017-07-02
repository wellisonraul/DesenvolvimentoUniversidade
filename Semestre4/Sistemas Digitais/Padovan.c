#include<stdio.h>

int main(){
	int n,i,numero,aux1,aux2,aux3,somatorio;
	
	scanf("%d",&n);
	
	aux1 = 1;
	aux2 = 1;
	aux3 = 1;
	somatorio = 0;
	for(i=0;i<n;i++){
		if(i<=2){
			somatorio = somatorio + 1; 
		}else{
			numero = aux1 + aux2;
			aux1 = aux2;
			aux2 = aux3;
			aux3 = numero;
			somatorio = somatorio + numero; 
		}
		
	}
	printf("%d",somatorio);

	
	return 0;
	
}
