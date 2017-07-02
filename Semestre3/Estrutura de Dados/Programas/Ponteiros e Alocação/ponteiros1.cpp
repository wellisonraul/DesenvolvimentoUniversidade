#include <stdio.h>
#include <conio.h>

int main(void) {
   long a=5;  
   long *aPrt = &a; //variavel a armazenada no ponteiro
   printf("Conteudo do ponteiro: %ld\n",*aPrt);
   printf("Endereco de memoria do conteudo do ponteiro: %p\n",&aPrt);
   printf("Endereco de memoria do ponteiro: %p\n",aPrt);
   
   getche();
}
