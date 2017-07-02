/* Wellison Raul Mariz Santos 
   Questão 100 da uva 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,aux,cont=0,cont2=0;
	while(scanf("%d %d",&i,&j)!=EOF){
		printf("%d %d",i,j);
		cont=0;
		cont2=0;
		if(i>j){
			aux = i;
			i = j;
			j = aux;
		}
		for(i;i<=j;i++){
			cont=1;
			aux = i;
			while(aux!=1){
				if(aux%2!=0){
			     	aux=((3*aux) + 1);
					cont++;
				}else{
					aux/=2;
					cont++;
				}	
			}
			if(cont>cont2) cont2=cont;
		}
		printf(" %d\n",cont2);
	}
	return 0;
}
