#include <iostream>
#include <conio.h>
#include <stdio.h>

void entrada();
//criando o procedimento entrada()

//--------------------------------------------------------------
//módulo principal
int main(void){
   entrada(); // chama o procedimento entrada()
}

void entrada(){
   char nome[60];
   printf("Digite seu nome: ");
   fflush(stdin);
   gets(nome);
   printf("O nome digitado foi %s",nome);
   //getch();
}

