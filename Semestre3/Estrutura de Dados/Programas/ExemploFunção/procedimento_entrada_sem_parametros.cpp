#include <iostream>
#include <conio.h>
#include <stdio.h>

//declarar o escopo do procedimento
void entrada();
//--------------------------------------------------------------
//módulo principal
int main(void){
   entrada(); // chama o procedimento entrada()
}

//criando o procedimento entrada()
void entrada(){
   char nome[60];  // variavel local
   printf("Digite seu nome: ");
   fflush(stdin);
   gets(nome);
   printf("O nome digitado foi %s",nome);
   getch();
}
