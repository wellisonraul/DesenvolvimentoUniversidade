#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void){
  int *v, i, n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n); // le n
  //aloca n elementos para v
  v = (int *) malloc(n*sizeof(int));
  // zera o vetor v com n elementos
  for (i = 0; i < n; i++){
     v[i] = i;
  }
  for (i = 0; i < n; i++){
     printf("%d\t",v[i]);
  }
  // libera os n elementos de v
  free(v);
  

  //getch();
}
