#include <conio.h>
#include <stdio.h>

int main(void){
    int vet[3]={12,8,3};  //armazendo dados no vetor vet
    int temp;

    printf("Vetor antes da ordenacao:\n\n");
    for(int cont1=0;cont1<=2;cont1++){  //exibindo os dados originais
        printf("%d\t", vet[cont1]);
    }
  
    //****** M�todo de ordena��o Bouble Sort ******** 
    for(int cont1=0;cont1<=1;cont1++){  //la�o da bolha
      for(int cont2=cont1+1;cont2<=2;cont2++){ //la�o de compara��o 
            if(vet[cont1]>vet[cont2]){  //compara bolha com pr�ximo elemento
               temp = vet[cont2];       // temp guarda menor elemento da compara��o
               vet[cont2]=vet[cont1];   // copia maior elemento para proxima posicao
               vet[cont1]=temp;         // menor elemento vai para a posi��o menor
            }
       }
    }
    
    printf("\n\n\nVetor depois da ordenacao:\n\n");
    for(int cont1=0;cont1<=2;cont1++){   // exibe vetor ordenado
        printf("%d\t", vet[cont1]);
    }
    
    getch();
}
