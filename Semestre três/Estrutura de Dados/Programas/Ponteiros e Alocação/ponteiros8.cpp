#include <stdio.h>
#include <conio.h>

int main(void){
  int x,*p;
  x=13;
  *p=x; //posi��o de mem�ria de p � indefinida, podendo subscrever um apontador cujo endereco j� esteja sendo utilizado!!!
  printf("%d",*p);
  getch();
}
