#include <iostream>
#include <conio.h>
#include <stdio.h>
int cont=0;

//declara o escopo da funcao
char *nomes(char nome[60]);
//--------------------------------------------------------------
//m�dulo principal
int main(void){
   // chama a funcao nomes(nome)
   char nome[60];
   printf("Digite um nome: ");
   fflush(stdin);
   gets(nome);
   printf("O nome digitado foi %s",nomes(nome)); 
   getch();
}

//criando a fun��o recursiva nomes(nome)
char *nomes(char nome[60]){
   cont++;
   printf("%s %d\t", nome, cont);
   return(nomes(nome));  //autochama a fun��o
}
