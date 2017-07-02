/*Scrip de manipulação de FILA ou FIFO First In First Out*/
/*Mofificado por Denis, Felipe*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int dado[MAX];
int topo;
char op;

//declarando o escopo dos procedimentos, para poderem ser usadas abaixo do main()
void exibir(void);
void inserir(void);
void remover();
void menu(void);
//--------------------------------------

//Módulo principal
int main(){
    topo=0;
    while (op!='4'){
          system("cls");
          menu();
          }
    return 0;          
}
//-------------------------

void exibir(void){  //procedimento de exibicao da fila
    int temp;
    if (topo == 0 ){  //verifica se a fila está vazia
      printf("\n\nA Fila esta vazia\n");
    }
    else{
         for(temp=0;topo-1 >= temp ;temp++){  //lista os elementos da fila
              printf("Na posicao %d temos %d\n",temp,dado[temp]);
         }
    }
    system("PAUSE");
}

void inserir(void){ //procedimento de inserção (queue)
    if (topo==MAX){  //verifica se fila cheia
          printf("\nA Fila esta cheia, OverFlow\n");
      }
      else {  
           printf("\n\nDigite um numero inteiro para entrar na Fila: ");
           scanf("%d",&dado[topo]); //elemento ocupa posicao vazia do fim da fila
           topo++;  //desloca apontador diminuindo posicao livre na fila
           }
     exibir(); //mostra os elementos
}

void remover(int x[]){ //prodedimento de remoção (dequeue)  
    int i;
    if (topo==0){  //testa se existe elementos na fila
           printf("\nA Fila esta vazia\n");    
                }
    else {printf("\nElemento %d removido\n",dado[0]); //sempre retira o primeiro elemento da fila
         for (i=0;i<=topo-1;i++){
             dado[i] = x[i+1];  //desloca todos os elementos 1 posição à frente na fila
         }                
    }    
    topo--; //desloca apontador liberando posicao da fila    
    exibir();
}

void menu(){
    printf("-= Programa Fila Estatica em C =-\n\n");
    printf("   Para inserir digite      1\n");
    printf("   Para remover digite      2\n");
    printf("   Para exibir digite       3\n\n");
    printf("   Para sair                4\n");
    printf("\n\n\nEscolha uma opcao (1-4): ");
    op=getche();
    printf("\n");
    switch (op){
        case '1' : inserir();
             break;
        case '2' : remover(dado);
             break;
        case '3' : exibir();  
             break;
           }
    
}  
