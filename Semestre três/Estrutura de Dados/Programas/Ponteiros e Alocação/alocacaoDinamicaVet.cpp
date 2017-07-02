#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){
  int *vet, cont=0, num;
  vet = (int *) malloc(sizeof(int));  //cria o vetor dinamico vazio
  while(num!=-1 && vet !=NULL){ //aceita valores no vetor diferentes de -1 e enquanto houver memoria disponível no vetor dinamico
  
     printf("Digite um numero inteiro para compor o vetor dinamico. -1 encerra a digitacao ");
     scanf("%d", &num); // le num
     if(num!=-1){ //testa o numero digitado. Se for igual a -1, desconsidera o numero.  Senão, aceita e aloca o numero no vetor e incrementa o contador
	    vet[cont] = num;  //o numero digitado eh atribuido a uma posicao livre no vetor dinamico
	    vet=(int *) realloc(vet,sizeof(int)*(cont+2)); //aloca o elemento no vetor e abre uma posicao a mais no vetor, permitindo a entrada de novo elemento
        cont++;
 	 }
     
  }
  //Exibe os elementos que foram digitados no vetor dinamico
  for (int cont2 = 0; cont2 < cont; cont2++){
     printf("%d\t",vet[cont2]);
  }
  //fim da exibicao
   
  // libera os n elementos de vet, consequentemente, a memoria alocada para ele
  free(vet);
  

  //getch();
}
