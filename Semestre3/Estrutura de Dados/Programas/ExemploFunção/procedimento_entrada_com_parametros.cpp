#include <iostream>
#include <conio.h>
#include <stdio.h>

//declarar o escopo do procedimento
void entrada(char nome[60],int idade);
//--------------------------------------------------------------
//módulo principal
int main(void){
   char nome[60];  
   int idade;
   printf("Digite seu nome: ");
   fflush(stdin);
   gets(nome);
   printf("Digite sua idade: ");
   scanf("%d",&idade);
   entrada(nome,idade); // chama o procedimento entrada, passando o nome digitado como argumento
   //getch();
}

//criando o procedimento entrada(nome)
void entrada(char nome[60],int idade){
   printf("O nome digitado foi %s",nome);
   printf("\nA idade digitada foi %d",idade);   

}
