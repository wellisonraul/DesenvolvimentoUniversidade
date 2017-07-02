#include <stdio.h>
#include <conio.h>

int main(void)
{
   int num,*p;
   num=55;
   p=&num; /* Pega o endereco de num */
   printf("Valor inicial: %d\n",num);
   printf("Endereco de memoria do ponteiro: %p",p);
   *p=100; /* Muda o valor de num de uma maneira indireta */
   printf ("\nValor final: %d\n",num); //note que num foi alterado,mesmo nao sendo referenciado diretamente
   printf("Endereco de memoria do ponteiro: %p",p);
   getch();
}
