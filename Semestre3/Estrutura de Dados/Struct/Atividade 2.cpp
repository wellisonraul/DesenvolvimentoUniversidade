#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//cria a estrutura chamada pessoa
struct caracteristicas { 
   char nome[50]; 
   int idade; 
   char sexo; 
}; 

int main(void){
   //referencia um alias vetorial para a estrutura
   struct  caracteristicas pessoa[5];
   char nome[50];
   int quantidadedenomes=0;
   for(int cont=0;cont<=4;cont++){
      printf("\n\nDigite o nome da %da. pessoa: ",cont+1);
      fflush(stdin);
      scanf("%s",pessoa[cont].nome);   
      printf("Digite a idade: ");
      scanf("%d",&pessoa[cont].idade);
      printf("Digite o sexo: ");
      scanf("%s",pessoa[cont].sexo);
   }
   //exibindo os dados do vetor de registros
   printf("\n\nAs caracter?sticas s?o: \n");
   for(int cont=0;cont<=4;cont++){
      printf("\n\nNome: %s\n", pessoa[cont].nome);
      printf("Idade: %d\n", pessoa[cont].idade);
      printf("Sexo: %c\n", pessoa[cont].sexo);
   }
}
