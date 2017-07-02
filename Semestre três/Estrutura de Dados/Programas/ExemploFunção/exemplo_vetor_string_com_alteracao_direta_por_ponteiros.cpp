/*Exemplo de vetor de strings com alteracao direta, via procedimento
  esse programa d� um no��o inicial de ponteiros, ao exemplificar
  a altera��o (in)direta de valores em uma matriz, via procedimento
  alteraTabela([][])*/
  
#include <conio.h>
#include <stdio.h>

void alteraVetorStr(char [3][60]);  //declara o escopo da funcao

int main(void){
 	char vet[3][60];  //declara o vetor como local do modulo principal (main())
    
    for(int cont=0;cont<=2;cont++){
       printf("Digite o %d nome :",cont+1);
       fflush(stdin);
       gets(vet[cont]);
       
    }
	printf("\n\nImprimindo os elementos antes da alteracao:\n\n");
    for(int cont=0;cont<=2;cont++){
       printf("%s\t",vet[cont]);
    }
    printf("\n\n");
    //chama a fun��o (procedimento) alteraTabela(), passando o vetor para dentro da funcao
    alteraVetorStr(vet);
    //-----------------------------------------------------------------------------------
    printf("\n\nNovos elementos apos a alteracao (in)direta por ponteiros via funcao \n \
	alteraVetorStr(vet):\n\n");
    for(int cont=0;cont<=2;cont++){
       printf("%s\t",vet[cont]);
    }
    getch();
}

/*Note que, mesmo a matriz sendo declarada com nome diferente, 
  a alteracao se d� (in)diretamente no vetor vet[],
  que foi declarada localmente no main().  Essa altera��o
  ocorre via endere�amento por ponteiros, ou seja, o vetor vet[]
  receber� os valores digitados no vetor v[], referenciadas
  via ponteiros de mem�ria*/
void alteraVetorStr(char v[3][60]){
 for(int cont=0;cont<=2;cont++){
	printf("Digite o %d nome: ",cont+1);
	fflush(stdin);
    gets(v[cont]);
 }
}
