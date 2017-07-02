/* Programa listaEncadeada.cpp
  Modificado por Denis, Felipe */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//estrutura da fila encadeada
struct lista { 
  int elemento; //campo elemento da lista
  struct lista *prox; //campo que apontará para o proximo elemento da lista
};
typedef struct lista Lista;

//escopo das funcoes
void menu();
Lista *inicializa(void);
Lista *insere(Lista *, int);
void imprime(Lista *);
Lista *retira(Lista *, int);
//------------------------------


//***  módulo principal ****
int main (void) {
    char op; //utilizada para escolha de opcoes no menu
    int elemento;  //elemento a ser utilizado nas tarefas de insercao e remocao
    Lista *l; /* declara uma lista não iniciada */
    l = inicializa(); // inicia lista vazia 
    while (op!='4'){
          system("cls");
          printf("-= Programa Lista Encadeada em C =-\n\n");
          printf("   Para inserir digite      1\n");
          printf("   Para remover digite      2\n");
          printf("   Para exibir digite       3\n\n");
          printf("   Para sair                4\n");
          printf("\n\n\nEscolha uma opcao (1-4): ");
          op=getche();
          printf("\n");
          switch (op){
             case '1' : {
                  printf("\n\nDigite o numero inteiro a ser inserido: ");
                  scanf("%d",&elemento);
                  l=insere(l,elemento); 
                  imprime(l);
             }
             break;
             case '2' : {
                  printf("\n\nDigite o numero inteiro a ser removido: ");
                  scanf("%d",&elemento);
                  l=retira(l,elemento); 
                  imprime(l);
             }
             break;
             case '3' : imprime(l);  
                break;
           }
    }
    
}
//*******************************************************


/* função de inicialização: retorna uma lista vazia */
Lista *inicializa (void)
{
   return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista *insere (Lista *l, int i)
{
    Lista *novo = (Lista *) malloc(sizeof(Lista));  //cria vetor dinamico baseado na estrutura Lista
    novo->elemento = i; //insere novo elemento na lista temporária
    novo->prox = l; //aponta para o proximo elemento vazio na lista
    return novo; //atualiza a lista real
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista *l)
{
    Lista *p; /* variável auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
       printf("elemento = %d\n", p->elemento);
    getch();
}

/* função retira: retira elemento da lista */
Lista *retira (Lista *l, int v) {
     Lista *ant = NULL; /* ponteiro para elemento anterior */
     Lista *p = l; /* ponteiro para percorrer a lista*/
     /* procura elemento na lista, guardando anterior */
     while (p != NULL && p->elemento != v) {
        ant = p;  //guarda o indice anterior de p
        p = p->prox; //pesquisa o proximo elemento da lista
     }
     /* verifica se achou elemento */
     if (p == NULL)
         return l; /* não achou: retorna lista original */
     /* retira elemento */
     if (ant == NULL) {
        /* retira elemento do inicio */
        l = p->prox; //faz a lista apontar para o proximo elemento
     } else {
        /* retira elemento do interior da lista */
        //faz com que o elemento anterior aponte para o proximo, excluindo a referencia do elemento a ser deletado
        ant->prox = p->prox; 
     }
     free(p);  //libera a memória do vetor temporário
     return l;  //retorna a lista atualizada
}
