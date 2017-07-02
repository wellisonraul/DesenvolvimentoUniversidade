#include <stdio.h>
#include <conio.h>

int main(void){
  int x,*p;
  x=13;
  *p=x; //posição de memória de p é indefinida, podendo subscrever um apontador cujo endereco já esteja sendo utilizado!!!
  printf("%d",*p);
  getch();
}
