/* Usando Equações de Pell para achar raiz quadrada dos números */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// Esse algoritmo pode ser reduzido apenas usando pow(1,1/n); onde n é a raiz;.

long double retorno=0; 
double RaizDec(long double recebeDecimal, long double recebeSegundaParte){
	long double cont=1;
	while(recebeDecimal>recebeSegundaParte){
		/*  resultado do último passo * 100 e número de passos da sequência anterior * 20 + 1 */
		if(recebeDecimal>recebeSegundaParte){
			recebeDecimal -= recebeSegundaParte;
			recebeSegundaParte+=2;
			retorno = recebeDecimal;	
		}
		cont++;
	}
	retorno = recebeDecimal;
	return cont;
}
double Raiz(int vRaiz){
	 long double impares=1,recebeDecimal=0,recebeSegundaParte,x=0,decimais,cont=0;	
	
	/*Função para calcular a parte inteira do número da Raiz*/
	while(vRaiz>=0){
		vRaiz -= impares; 
		
		if(vRaiz<0){
			vRaiz += impares;
			break;	
		}
		
		impares += 2;
		cont++;
	}
	if(vRaiz==0){
		return cont;
	}else{
			/* Inicia segunda parte */
		retorno = vRaiz;
		decimais = cont;
	
		while(x<30){
			cont=0;
			recebeSegundaParte =((decimais*pow(10,x) ) * 20) + 1 ;
			recebeDecimal = retorno*100;
			if(recebeDecimal>recebeSegundaParte){
				recebeDecimal -= recebeSegundaParte;
				recebeSegundaParte += 2;
				cont = (RaizDec(recebeDecimal,recebeSegundaParte));
			}else{
				retorno = recebeDecimal;
			}	
			decimais += cont/pow(10,x+1); 
			x++;
		}	
		return decimais;
	}

}

int main(){
	int numero;
	while(scanf("%d",&numero)!=EOF){
		printf("%.30lf\n",Raiz(numero));
	}
	
	return 0;
}
