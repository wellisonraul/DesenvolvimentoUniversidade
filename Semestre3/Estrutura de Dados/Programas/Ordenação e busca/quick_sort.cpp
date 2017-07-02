//Método de ordenação quick_sort - by Denis, Felipe

#include<conio.h>
#include <iostream>  //fundamental, devido a funcao rand()
#include <stdlib.h>
#include <stdio.h>


void troca(int x[], int i, int j){ //função de troca
   int temp;
   temp = x[i];
   x[i] = x[j];
   x[j] = temp;
}

int random(int min, int max){  //localiza elemento aleatorio no vetor
   return (int)((max - min) * rand()/(float)RAND_MAX + min);
}

void QuickSort(int x[], int limiteInferior, int limiteSuperior){ 
   int i, m;
   if(limiteInferior >= limiteSuperior){  //indica que estou fora da particao atual
      return;   //retorno vazio (null)
   }
   troca(x, limiteInferior, random(limiteInferior, limiteSuperior)); //faz a troca do elemento maior pelo menor
   m = limiteInferior;
   for(i=limiteInferior+1; i<=limiteSuperior; i++){
      if(x[i] < x[limiteInferior]){ //faz a troca do proximo elemento da partição
         troca(x, ++m, i);
      }
   }
   troca(x, limiteInferior, m);
   QuickSort(x, limiteInferior, m-1);  //particiona e ondena elementos da partição anterior à atual
   QuickSort(x, m+1, limiteSuperior);  //particiona e ordena elementos da proxima particao à atual
}

int main (void){

   int x[500];
   int tamanhoVetor = sizeof(x)/sizeof(*x);  //determina o tamanho do vetor
   for(int i=0;i<tamanhoVetor;i++){ //preenchendo o vetor
       x[i] = rand() % 500;  //gera numeros aleatórios, de 0 a 500 e os armazena nas posicoes do vetor
   }
   
   for(int i=0;i<tamanhoVetor;i++){  //exibe vetor atual
      printf("%d\t", x[i] );
   }
   
   QuickSort(x, 0,tamanhoVetor-1);  //passa os elementos do vetor, o tamenho incial e tamanho final-1 (ex: 0 a 9,para um vetor de 10 posicoes)
   
   printf("\n");
   for(int i=0;i<tamanhoVetor;i++){ //exibe vetor ordenado
      printf("%d\t", x[i] );
   }
   getch();
}
