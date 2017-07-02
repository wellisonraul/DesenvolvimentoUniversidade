#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>

//cria a estrutura chamada listaTel
struct listaTel { 
   char nome[60]; 
   char telefone[15]; 
}; 

int main(void){
   //referencia um alias para a estrutura
   struct  listaTel agendaTel[10];
   char nome_pesq[60];
   int achou;
   for(int cont=0;cont<=9;cont++){
      printf("Digite o nome da %da. pessoa: ",cont+1);
      fflush(stdin);
      gets(agendaTel[cont].nome);   
      printf("Digite o telefone: ");
      fflush(stdin);
      gets(agendaTel[cont].telefone);   
   }
   printf("\n\nOs dados presentes na lista telefonica sao:\n");
   
   //exibindo os dados dos registros
   printf("#\tNome\t\tTelefone\n");
   for(int cont=0;cont<=9;cont++){
      printf("%d\t%s\t", cont+1, agendaTel[cont].nome);   
      printf("%s\n",agendaTel[cont].telefone);   
   }
 
   //realizando a pesquisa sequencial
   printf("\n\nDigite o nome a ser pesquisado: ");
   fflush(stdin);
   gets(nome_pesq);
   
   achou=0;  //inicializa a flag achou como falso
   for(int cont=0;cont<=9;cont++){
      
      if(strcmp(strupr(agendaTel[cont].nome), strupr(nome_pesq))==0){
         achou=1; //modifica a flag, indicando que foi encontrado o valor pesquisado
         printf("\n%s\t\t%s - posicao %d\n",agendaTel[cont].nome, agendaTel[cont].telefone, cont+1);
      }
   }
   if(achou==0){ //indica que nao foi encontrada nenhuma ocorrencia para a pesquisa
      printf("\n\nNao foi encontrado nenhuma ocorrencia para %s\n",nome_pesq);
   }
   getch();
}
