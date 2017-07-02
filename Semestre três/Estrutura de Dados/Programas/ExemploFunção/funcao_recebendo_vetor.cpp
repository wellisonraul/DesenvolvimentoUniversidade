#include <iostream>
#include <conio.h>
#include <stdio.h>
/*CONSTRUIR UM PROGRAMA QUE PECA AO USUARIO PARA DIGITAR 5 NUMEROS E, ATRAVES DA
FUNCAO EXIBE(NUM), MOSTRE OS NUMEROS DIGITADOS*/

char *exibe(char*);

int main(void){
    
    char nomes[5][60];
    
    for(int cont=0;cont<=4;cont++){
       printf("Digite o %do. nome: ",cont+1);
       scanf("%s",&nomes[cont]);
    }
    printf("Os elementos digitados sao:\n\n");
    for(int cont=0;cont<=4;cont++){
       printf("%s\t",exibe(nomes[cont]));
    }
    
    getch();
  
}

char *exibe(char nome[]){
   return(nome);
}
   
   
