/* Wellison Raul Mariz Santos 
   Questão 10035 da uva 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int numero1,numero2,uns,cont,aux=0,aux2=0;
    while(scanf("%d %d",&numero1,&numero2)!=EOF){
    
    	while(numero1 || numero2){
    	cont=0;
    	uns=0;
    	   while(numero1||numero2){
		   		aux=numero1%10;
    			aux2=numero2%10;
    			if((aux+aux2+uns)>9)cont++;
    			uns=(aux+aux2+uns)/10;
    			numero1=numero1/10;
    			numero2=numero2/10;
    		}
    	if(cont==0) printf("No carry operation.\n");
    	else if(cont==1) printf("1 carry operation.\n");
    	else printf ("%d carry operations.\n",cont);
    	}
	}
	return 0;
}
