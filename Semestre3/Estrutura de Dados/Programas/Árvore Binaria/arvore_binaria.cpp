/* Exemplo de uma arvore binaria - beta 1                       *
 * by Piveta, Eduardo (modified by Denis, Felipe)               */

 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct arv {  //cria uma estrutura duplamente encadeada para a arvore
   char info;
   struct arv* esq;
   struct arv* dir;
};

typedef struct arv Arv;

//cria os protótipos das funções
Arv* criarVazia();
Arv* criar(char c, Arv* e, Arv* d);
bool vazia(Arv* a);
void imprimir(Arv* a);
//-------------------------------------

int main(void){
   
   /*criando a arvore binaria de 3 niveis, seguindo a configuração:    Ex: a((b(d))(c(e)(f)))
   OBS: Cria-se os nós, do nível maior para o menor (raiz)*/  

   
   Arv* d = criar('d', criarVazia(), criarVazia());   //nivel 3
   Arv* e = criar('e', criarVazia(), criarVazia());  //nivel 3
   Arv* f = criar('f', criarVazia(), criarVazia());  //nivel 3
   Arv* b = criar('b', criarVazia(), d);             //nivel 2
   Arv* c = criar('c', e, f);                        //nivel 2
   Arv* a = criar('a', b, c);                        //nivel 1
   
  
   imprimir(a);//imprime o nível da árvore desejado, neste caso, toda a arvore

   //getch();
}

Arv* criarVazia(){ // cria uma arvore vazia (sem galhos)
   return NULL;
}


Arv* criar(char c, Arv* sae, Arv* sad){ //cria uma arvore nao vazia (com nós)
   Arv* p = (Arv*) malloc(sizeof(Arv));
   p->info = c;
   p->esq = sae;  //faz a lista apontar para a subarvore esquerda
   p->dir = sad;  //faz a lista apontar para a subarvore direita
   return p;
}

bool vazia(Arv* a){  //testa se arvore vazia (sem nós)
   return a == NULL;
}


void imprimir(Arv* a){  //imprime a arvore, à partir da raiz
   printf("<");
   if (!vazia(a)){
      printf("%c", a->info);  //imprime o nome da raiz
      imprimir(a->esq);   //aponta para o nó esquedo e imprime
      imprimir(a->dir);   //aponta para o nó direito e imprime
    }
    printf(">");
}
