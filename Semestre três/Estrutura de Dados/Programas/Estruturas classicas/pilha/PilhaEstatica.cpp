/* Programa PihaEstatica.cpp
 modificado por Denis, Felipe*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> //necessario para a funcao tupper()


#define MAX_ELEMENTOS 5 //tamanho da pilha

//*variaveis globais

int pilha[MAX_ELEMENTOS];
int topo=0;

/*prototipos
============*/
void push(int);
int pop(void);
void inserir(void);
void listar(void);
void remover(void);

 /*principal
 ============*/
int main(void){
     char opcao;
     int i;
     
     
     for(int cont=0;cont<MAX_ELEMENTOS;cont++)
          pilha[cont]=0;/*inicializa a matriz com nulos, evitando sujeira*/
	   
     //system("pause");
     while(1){ //laco infinito
              system("cls");
              printf("\n\n\nEscolha uma opcao:\n\n\n   Inserir(i)\n\n   Listar(l)\n\n   Remover(r)\n\n   Sair(s)");
              printf("\n\n\n Escolha a opcao desejada --->> ");
              opcao=toupper(opcao=getche());  //recebe a opcao desejada e converte para maiusculo
	          switch(opcao){
	                case 'I':inserir();
		                break;
	                case 'L':listar();
		                break;
                    case 'R':remover();
	                    break;
                    case 'S':printf("\n\n\n Fim do programa!");
                        getch();
		                exit(0); //negativa o while (sai do laco)
              }
     }/*fim while*/
 }
 
 /* poe um elemento na pilha*/
void inserir(void){
    int elemento;
    printf("\n\nDigite o numero inteiro a ser inserido na pilha -->>  ");
    scanf("%d",&elemento);
    fflush(stdin);
    push(elemento);  //chama o procedimento push(), para inserir o elemento desejado
}

 /* remove um elemento na pilha*/
void remover(void){
    int remove=pop();  //chama a função pop(), para retirar o elemento desejado
    if(remove!=-1)  //se o retorno da função for negativo, indica que removi o elemento
       printf("\n\nElemento removido da pilha: %d",remove);
}

 /* lista os elementos na pilha*/ 
void listar(void){
   int i;
   printf("\n topo(%d)\n\n",topo);
   for(i=topo-1;i>=0;i--)  //lista os elementos da pilha (vetor - listagem invertida)
      printf("\n%d) %d ",i,pilha[i]);
   printf("\n\n");
   system("pause");
 }

 /* procedimento push()*/ 
void push(int i)
{
   if(topo>=MAX_ELEMENTOS){ //se o tamanho máximo da pilha foi atingido...
      printf("\n\n\t\t______________________\n");
      printf("\n\n\t\tOVERFLOW!!! PILHA CHEIA\n");
      printf("\t\t______________________\n");
      getch();
	  return; //encerra a execucao do procedimento
   }
   pilha[topo]=i;  //novo elemento inserido no inicio da pilha
   topo++; //desloca o apontador do topo da pilha uma posicao acima
   listar(); //lista os elementos da pilha
}

/*funcao pop()*/
int pop(void){
   topo--; //move o apontador de inicio da pilha uma posicao "acima"
   if(topo<0){
      printf("\n\n\t\t______________________\n");
      printf("\n\t\tUNDERFLOW!!! PILHA vazia\n");
      printf("\t\t______________________\n");
      topo++; //retorna o valor original do apontador de inicio de pilha
      getch();
      return -1;  //indica que nao removi o elemento
   }
   listar(); //lista os elementos da pilha
   return pilha[topo];
}

