#include <stdio.h>
#include <conio.h>

int main(void){
   int num,*p1, *p2;
   num=55;
   p1=&num; /* Pega o endereco de num */
   p2=p1; /*p2 passa a apontar para o mesmo endereço apontado por p1 */
   printf("Endereco de p1: %p\n",p1);;
   printf("Valor apontado por p1: %d\n",*p1);
   printf("Endereco de p2: %p\n",p2);
   printf("Valor apontado por p2: %d\n",*p2);
   getch();
}
