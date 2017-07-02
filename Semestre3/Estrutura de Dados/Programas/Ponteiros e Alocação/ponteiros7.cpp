#include <stdio.h>
#include <conio.h>

int main(void){
  int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p;
  p=vet;  //o ponteiro aponta para a posicao 0 do vetor vet
  printf("O terceiro elemento do vetor e: %d",p[2]);
  getch();
}
