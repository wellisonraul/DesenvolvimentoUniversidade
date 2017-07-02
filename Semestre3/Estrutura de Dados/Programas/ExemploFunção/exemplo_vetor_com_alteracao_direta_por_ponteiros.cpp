/*Exemplo de vetor com alteracao direta, via procedimento*/
  
#include <conio.h>
#include <stdio.h>

void alteraVetor(float [3]);  //declara o escopo da funcao

int main(void){
 	float vet[3];  //declara o vetor como local do modulo principal (main())
    
    for(int cont=0;cont<=2;cont++){
       printf("Digite o %d numero :",cont+1);
       scanf("%f",&vet[cont]);
       
    }
	printf("\n\nImprimindo os elementos antes da alteracao:\n\n");
    for(int cont=0;cont<=2;cont++){
       printf("%.2f\t",vet[cont]);
    }
    printf("\n\n");
    //chama a função (procedimento) alteraVetor(), passando o vetor para dentro da funcao
    alteraVetor(vet);
    //-----------------------------------------------------------------------------------
    printf("\n\nNovos elementos apos a alteracao direta via procedimento alteraVetor(vet):\n\n");
    for(int cont=0;cont<=2;cont++){
       printf("%.2f\t",vet[cont]);
    }
    getch();
}

/*Note que, mesmo o vetor sendo declarado com nome diferente, 
  a alteracao se dá (in)diretamente no vetor vet[],
  que foi declarado localmente no main().  Essa alteração
  ocorre via endereçamento por ponteiros, ou seja, o vetor vet[]
  receberá os valores digitados no vetor v[], referenciadas
  via ponteiros de memória*/
void alteraVetor(float v[3]){
 for(int cont=0;cont<=2;cont++){
	printf("Digite o %d numero: ",cont+1);
    scanf("%f",&v[cont]);
 }
}
