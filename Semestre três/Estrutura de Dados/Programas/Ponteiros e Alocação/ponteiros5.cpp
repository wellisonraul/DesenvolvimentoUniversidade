#include <stdio.h>
#include <conio.h>

int main(void){
   int a,b,*aPtr;
   a=5;
   b=6;
   aPtr=&a;
   printf("Endereco do apontador: %p\n",aPtr);
   printf("Valor apontado pelo apontador: %d\n",*aPtr);
   aPtr++;
   aPtr=&b;
   printf("Endereco do apontador: %p\n",aPtr);
   printf("Valor apontado pelo apontador: %d\n",*aPtr);
 
   aPtr--;
   aPtr=&b;
   printf("Endereco do apontador: %p\n",aPtr);
   printf("Valor apontado pelo apontador: %d\n",*aPtr);
   getch();
}
