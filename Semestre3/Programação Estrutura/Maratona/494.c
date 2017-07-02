/* Wellison Raul Mariz Santos
 Questão 454 UVA */
#include <stdio.h>
#include <stdlib.h>

int main(){
	char frase;
	int cont=0;
	int palavra=0;
	
	while(scanf("%c",&frase)!=EOF){
		if(((frase>='a' && frase<='z')) || ((frase>='A' && frase<='Z'))){
			if(cont==0){
				palavra++;
				cont++;
			}
		}else{
			cont=0;
			if(frase=='\n'){
				printf("%d\n",palavra);
				palavra=0;
			}
		}
	}
	return 0;
}
