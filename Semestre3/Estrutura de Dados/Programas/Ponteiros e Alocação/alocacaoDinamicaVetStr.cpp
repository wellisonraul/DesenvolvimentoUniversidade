#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int  cont=0;
  char **vet, nom[255];
  vet = (char **) malloc(sizeof(char[255]));  //cria o vetor dinamico vazio de strings
  while(strcmp(strupr(nom),"FIM")!=0 && vet !=NULL){ //aceita valores no vetor diferentes de "FIM" e enquanto houver memoria disponível no vetor dinamico
  
     printf("Digite um nome para compor o vetor dinamico. 'FIM' encerra a digitacao ");
     fflush(stdin);
     gets(nom); // le o nome digitado
     if(strcmp(strupr(nom),"FIM")!=0){ //testa o nome digitado. Se for igual a "FIM", desconsidera o nome.  Senão, aceita e aloca o nome no vetor e incrementa o contador
	    vet[cont] = strdup(nom);  //o nome digitado eh atribuido a uma posicao livre no vetor dinamico - strdup() deve ser utilizado apenas em vetores dinamicos de strings
	    vet=(char **) realloc(vet,sizeof(char[255])*(cont+2)); //aloca o elemento no vetor e abre uma posicao a mais no vetor, permitindo a entrada de novo elemento
        cont++;
 	 }
     
  }
  //Exibe os elementos que foram digitados no vetor dinamico
  for (int cont2 = 0; cont2 < cont; cont2++){
     printf("%s\t",vet[cont2]);
  }
  //fim da exibicao
   
  // libera os n elementos de vet, consequentemente, a memoria alocada para ele
  free(vet);
  

  //getch();
}
