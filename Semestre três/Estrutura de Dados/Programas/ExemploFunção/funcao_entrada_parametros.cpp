#include <iostream>
#include <conio.h>
#include <stdio.h>

//declara o escopo da funcao
char *entrada(char[]);
//--------------------------------------------------------------
//m�dulo principal
int main(void){
   char nome[60];
   printf("Digite seu nome: ");
   fflush(stdin);
   gets(nome);
   printf("O nome digitado foi %s",entrada(nome));
   //getch();
}

//criando a fun��o entrada(nome)
char *entrada(char nome[60]){
   return(nome);
}
