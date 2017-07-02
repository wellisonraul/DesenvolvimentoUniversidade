#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

/* Método de busca binária aplicado à strings
 * by Denis, Felipe
 * ATENÇÃO!!! Esse método só funciona quando os dados estão devidamente
 * ordenados, sejam eles de que tipos forem*/
 
 
//cria a estrutura chamada listaTel
struct listaTel { 
   char nome[60]; 
   char telefone[15]; 
}; 

int buscaBinStr(char nome[], struct listaTel agenda[], int n){
   int comp;  // variavel que guardará o resultado da comparacao
   int esq, dir, indiceMeio;
  
   esq = 0;
   dir = n - 1;
   while (esq <= dir){
      indiceMeio = (esq + dir) / 2;
      comp = strcmp(strupr(nome), strupr(agenda[indiceMeio].nome));
      if(comp < 0){
         dir = indiceMeio - 1;
      }else if(comp > 0){
         esq = indiceMeio + 1;
      }else{ 
         return indiceMeio;  
      }
   }
   return -1; /* nao achou ! */
}

int main(void){
   struct  listaTel agendaTel[10];
   int tamanhoLista = sizeof(agendaTel)/sizeof(*agendaTel);  //guarda o tamanho da lista
   char nome_pesq[60],temp[60], op='s';
   int esq, dir, valorMeio, cond, achou, indice;
   for(int cont=0;cont<tamanhoLista;cont++){
      printf("Digite o nome da %da. pessoa: ",cont+1);
      fflush(stdin);
      gets(agendaTel[cont].nome);   
      printf("Digite o telefone: ");
      fflush(stdin);
      gets(agendaTel[cont].telefone);   
   }
   printf("\n\nOs dados presentes na lista telefonica sao:\n");
   
   //ordenacao bouble sort
    for(int cont1=0;cont1<tamanhoLista-1;cont1++){  //laço da bolha
      for(int cont2=cont1+1;cont2<tamanhoLista;cont2++){ //laço de comparação 
            if(strcmp(strupr(agendaTel[cont1].nome), strupr(agendaTel[cont2].nome))>0){  //compara bolha com próximo elemento
               //ordena o nome
               strcpy(temp,agendaTel[cont2].nome);       // temp guarda menor elemento da comparação
               strcpy(agendaTel[cont2].nome,agendaTel[cont1].nome);   // copia maior elemento para proxima posicao
               strcpy(agendaTel[cont1].nome,temp);         // menor elemento vai para a posição menor
               
               //copia o telefone para a nova posicao, mantendo a integridade dos dados
               strcpy(temp,agendaTel[cont2].telefone);       // temp guarda menor elemento da comparação
               strcpy(agendaTel[cont2].telefone,agendaTel[cont1].telefone);   // copia maior elemento para proxima posicao
               strcpy(agendaTel[cont1].telefone,temp);         // menor elemento vai para a posição menor

            }
       }
    } 
   //exibindo os dados dos registros
   printf("#\tNome\t\tTelefone\n");
   for(int cont=0;cont<tamanhoLista;cont++){
      printf("%d\t%s\t", cont+1, agendaTel[cont].nome);   
      printf("%s\n",agendaTel[cont].telefone);   
   }
 
   //realizando a pesquisa binária
   while(op=='s'){
      printf("\n\nDigite o nome a ser pesquisado: ");
      fflush(stdin);
      gets(nome_pesq);
      indice = buscaBinStr(nome_pesq,agendaTel,tamanhoLista);
      if(indice == -1){
         printf("\n\nNao foi encontrado nenhuma ocorrencia para %s\n",nome_pesq);
      }else{
         printf("\n\nEncontrada ocorrencia no registro %d",indice+1);
      }
      printf("\n\nContinua pesquisa (s/n)? ");
         op=getche();
   }
   
} 

