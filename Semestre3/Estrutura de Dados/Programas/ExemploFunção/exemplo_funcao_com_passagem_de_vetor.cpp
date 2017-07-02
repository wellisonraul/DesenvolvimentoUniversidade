#include <conio.h>
#include <stdio.h>

int soma(int []);

int main(void){
    int vet[5];
     
    for(int cont=0;cont<=4;cont++){
          printf("Digite o %do. numero: ",cont+1);
          scanf("%d",&vet[cont]);
    }
    printf("\n\nA soma dois numeros eh: %d",soma(vet));
    getch();
}

int soma(int v[]){
    int soma_vet=0;
    for(int cont=0;cont<=4;cont++){
        soma_vet+=v[cont];
    }
    return(soma_vet);
}
