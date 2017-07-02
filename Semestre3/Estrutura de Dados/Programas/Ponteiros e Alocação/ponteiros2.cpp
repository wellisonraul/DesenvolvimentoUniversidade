#include <stdio.h>
#include <conio.h>

#include <stdio.h>
int main(void)
{
   int num,valor;
   int *p=5;
   num=55;
   p=&num; /* Pega o endereco de num */
   valor=*p; /* Valor é igualado a num de uma maneira indireta */
   printf ("%d\n",valor);
   printf ("Endereco para onde o ponteiro aponta: %p\n",p);
   printf ("Valor da variavel apontada: %d\n",*p);
   getch();
}

