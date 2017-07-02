/*Exemplo de matriz com alteracao direta, via procedimento alteraTabela([][])*/
  
#include <conio.h>
#include <stdio.h>

void alteraTabela(float [3][3]);  //declara o escopo da funcao

int main(void){
 	float mat[3][3];  //declara a matriz como local do modulo principal (main())
    
    for(int linha=0;linha<=2;linha++){
       for(int coluna=0;coluna<=2;coluna++){
          printf("Digite o numero correspondente a posicao %dx%d da tabela: ",linha+1,coluna+1);
          scanf("%f",&mat[linha][coluna]);
       }
    }
	printf("\n\nImprimindo os elementos da tabela antes da alteracao:\n\n");
    for(int linha=0;linha<=2;linha++){
       for(int coluna=0;coluna<=2;coluna++){
          printf("%.2f\t",mat[linha][coluna]);
       }
       printf("\n");
    }

    //chama a função (procedimento) alteraTabela(), passando a matriz para dentro da funcao
    alteraTabela(mat);
    //-----------------------------------------------------------------------------------
    printf("\n\nNovos elementos da tabela apos a alteracao direta via procedimento alteraTabela(mat):\n\n");
    for(int linha=0;linha<=2;linha++){
       for(int coluna=0;coluna<=2;coluna++){
          printf("%.2f\t",mat[linha][coluna]);
       }
       printf("\n");
    }
    getch();
}

/*Note que, mesmo a matriz sendo declarada com nome diferente, 
  a alteracao se dá (in)diretamente na matriz mat[][],
  que foi declarada localmente no main().  Essa alteração
  ocorre via endereçamento por ponteiros, ou seja, a matriz mat[][]
  receberá os valores digitados na matriz m[][], referenciadas
  via ponteiros de memória*/
void alteraTabela(float m[3][3]){
 for(int linha=0;linha<=2;linha++){
	for(int coluna=0;coluna<=2;coluna++){
          printf("Digite o numero correspondente a posicao %dx%d da tabela: ",linha+1,coluna+1);
          scanf("%f",&m[linha][coluna]);
    }
 }
}
