#include <stdio.h>
#include <conio.h>

int main(void){
  int vet[4];
  int *p;
  p=vet; //referencia o apontador p à partir da posicao 0 do vetor
  for (int count=0;count<4;count++)
  {
    *p=0;  //atribui 0 a posicao atual do apontador
    p++;  //incrementa o endereco do apontador, incrementando automaticamente a posicao do vetor
  }

  for (int i=0;i<4;i++)
    printf("%d\t",vet[i]);

 
   getch();
}
