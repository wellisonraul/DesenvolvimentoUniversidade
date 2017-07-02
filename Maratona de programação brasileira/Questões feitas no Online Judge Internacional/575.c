/* Wellison Raul Mariz Santos 
   Questão 575 da uva 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int decimal=0,i=0,cont=0;
	char binario[1000];
	while(scanf("%s",binario)!=EOF){
		cont = strlen(binario);
		decimal =0;
		for(i=0;i<strlen(binario);i++){
			decimal += (binario[i]-'0')*(pow(2,cont)-1);
			cont--;
		}
		if(decimal!=0){
			printf("%d\n",decimal);	
		}
	}
	return 0;
}
