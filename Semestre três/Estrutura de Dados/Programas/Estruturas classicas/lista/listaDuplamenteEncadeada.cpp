/* Programa listaDuplamenteEncadeada.cpp
 modificado por Denis, Felipe*/

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

// crio a estrutura
struct lista {
  int elemento;
  struct lista *ant;
  struct lista *prox;
};
typedef struct lista Lista;

//escopo das funcoes
Lista *inicializa(void);
Lista *insere(Lista *, int);
void imprime(Lista *);
Lista *busca(Lista *, int);
Lista *retira(Lista *, int);
//---------------------------


int main (void) {
    char op; //utilizada para escolha de opcoes no menu
    int elemento;  //elemento a ser utilizado nas tarefas de insercao e remocao
    Lista *l; /* declara uma lista não iniciada */
    l = inicializa(); // inicia lista vazia 
    while (op!='4'){
          system("cls");
          printf("-= Programa Lista Duplamente Encadeada em C =-\n\n");
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


/* função de inicialização: retorna uma lista vazia */
Lista *inicializa (void)
{
   return NULL;
}

/* inserção no início */
Lista *insere (Lista *l, int v)
{
      Lista *novo = (Lista *) malloc(sizeof(Lista)); //cria vetor dinamico baseado na estrutura Lista
      novo->elemento = v; //insere o novo elemento na lista temporária
      novo->prox = l; //aponta para o proximo elemento vazio na lista
      novo->ant = NULL; //aponta para o elemento anterior vazio na lista
      /* verifica se lista não está vazia */
      if (l != NULL)
         l->ant = novo;  //faz o elemento anterior apontar para o novo, inserindo o elemento à lista
      return novo;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista *l)
{
    Lista *p; /* variável auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
       printf("elemento = %d\n", p->elemento);
    getche();
}

/* função busca: busca um elemento na lista */
Lista *busca (Lista *l, int v)
{
      Lista *p;
      for (p=l; p!=NULL; p=p->prox)
         if (p->elemento == v)
            return p;
      return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista *retira (Lista *l, int v) {
      Lista *p = busca(l,v);  //busca o elemento na lista
      if (p == NULL)
         return l; /* não achou o elemento: retorna lista inalterada */
      /* retira elemento do encadeamento */
      if (l == p) //se o elemento a ser removido for localizado na lista real
         l = p->prox; //faz a lista real apontar para o proximo elemento da lista
      else
          p->ant->prox = p->prox; //faz o elemento anterior apontar para o proximo elemento
      if (p->prox != NULL)  //se o proximo elemento nao for nulo
         p->prox->ant = p->ant; //faz o próximo elemento apontar para o elemento anterior
      free(p); //libera a memória do vetor temporário
      return l; //retorna a lista atualizada
}
