#include <iostream>
#include <conio.h>
#include <stdio.h>

//declarando o escopo da funcao
int entrada();
//--------------------------------------------------------------
//m�dulo principal
int main(void){
   // chama a funcao entrada()
   printf("A idade digitada foi %d",entrada()); 
   //getch();
}

//criando a fun��o entrada()
int entrada(){
   int idade;
   printf("Digite a idade de uma pessoa: ");
   scanf("%d",&idade);
   return(idade);
}
