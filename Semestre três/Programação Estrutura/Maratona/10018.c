/*Wellison Raul Mariz Santos
Questão 10018 da uva*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	long  long int numero,aux,SomaComReverso,cont=0,Reverso=0,recebe,termos,i;
	while(scanf("%lld",&termos)!=EOF){
		for(i=0;i<termos;i++){
			scanf("%lld",&numero);
			cont=0;
			Reverso=0;
			while(Reverso==0){
				aux=0;
				recebe = numero;
    			while(numero!=0){
        			aux=aux*10+numero%10;
        			numero/=10;
        		}
        		SomaComReverso = aux + recebe;
        		aux=0;
        		if(aux==recebe){
        			printf("%lld %lld\n",cont,recebe);
        			Reverso++;
					continue;
        		}
        		cont++;
        		recebe=SomaComReverso;
    			while(SomaComReverso!=0){
        			aux=aux*10+SomaComReverso%10;
        			SomaComReverso/=10;
        		}
        		if(recebe==aux){
        			Reverso++;
        			printf("%lld %lld\n",cont,recebe);
        			continue;
        		}else{
        			numero = recebe;
        		}
			}
	    }
	}
	
	return 0;
}
