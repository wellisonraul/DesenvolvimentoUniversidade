/* Programa FilaCircular.cpp - modificado por Denis, Felipe */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TamanhoFila  5 //numero de elementos da fila

int PU_PosIni = 0;  //indica o início da fila circular
int PU_QtdElementos = 0;  //indica o final da fila circular

int PU_Fila[TamanhoFila]; //vetor usado na fila circular

char op;

//declara o escopo dos procedimentos e funções e , para poderem ser usadas abaixo do main()
void insere(int);
int remover();
void menu(void);
void mostra(void);
//----------------------------------------------------------------------



int main(void) {
    while (op!='4'){
          system("cls");
          menu();
          system("pause");
    }
   
}

void insere( int PA_Valor )
{
   
   if( PU_QtdElementos < TamanhoFila ){
      //// converte os valores virtuais (tamanho e comeco) para o valor real utilizando o operador %(modulo) //// 
      int L_PosReal = (PU_PosIni+PU_QtdElementos)%TamanhoFila; 
      //------------------------------------------------------------
      
      PU_Fila[L_PosReal] = PA_Valor;  //insere o elemento na fila circular
      printf ("Adicionou[%d] = %d \n", L_PosReal, PU_Fila[L_PosReal]);
      PU_QtdElementos++;

   }else printf ("Fila cheia!!! \n");
   printf("\n\n");
   mostra();  //exibe os elementos da fila circular

}

int remover(void)
{
   if( PU_QtdElementos > 0 ){
      printf ("Removeu[%d] = %d \n", PU_PosIni, PU_Fila[PU_PosIni]);
      PU_Fila[PU_PosIni] = 0;
      //// apaga o primeiro elemento da fila deslocando o ponteiro do comeco para proximo elemento ////
      PU_PosIni = (PU_PosIni+1)%TamanhoFila; 
      //// decrementa o contador de tamanho (um valor foi removido) ////
      PU_QtdElementos--;
      printf("\n\n");
      mostra();
   }
   printf ("Fila vazia!! \n");
   mostra();
 
}

void mostra (void)
{
   printf("\nListando os elementos da fila circular...\n\n");  
   for( int con = 0; con < TamanhoFila; con++){
      printf ("Elemento[%d] = %d \n", con, PU_Fila[con]);
   }
   printf ("\n");
}

void menu(){
    int num;
    printf("-= Programa Fila Ciruclar em C =-\n\n");
    printf("   Para inserir digite      1\n");
    printf("   Para remover digite      2\n");
    printf("   Para exibir digite       3\n\n");
    printf("   Para sair                4\n");
    printf("\n\n\nEscolha uma opcao (1-4): ");
    op=getche();
    printf("\n");
    switch (op){
        case '1' :{
              printf("\n\nDigite um numero inteiro para entrar na Fila: ");
              scanf("%d",&num); //elemento ocupa posicao vazia do fim da fila
              printf("\n\n");
              insere(num);
             }break;
        case '2' : remover();
             break;
        case '3' : mostra();  
             break;
           }
}
