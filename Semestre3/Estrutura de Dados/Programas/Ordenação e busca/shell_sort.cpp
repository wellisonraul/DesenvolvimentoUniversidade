#include <conio.h>
#include <stdio.h>

int main (void){
    int comp=0, troca=0, gap=0, temp=0, cont1=0, cont2=0, cont3=0;
    int vet[20];
    int tamanhoVetor = sizeof(vet)/sizeof(*vet);  //guarda o tamanho do vetor
    int i, j, incremento;
    for(cont1=0;cont1<tamanhoVetor;cont1++){
       printf("Digite o %do. elemento do vetor ",cont1+1);
       scanf("%d",&vet[cont1]);
    }
    printf("\n\nos dados do vetor digitados foram:\n\n");
    for(cont1=0;cont1<tamanhoVetor;cont1++){
       printf("%d\t",vet[cont1]);
    }     
    //ordenacao shell sort
        
     gap = tamanhoVetor/2;
     while (gap > 0){
        for (cont1=0; cont1 < tamanhoVetor; cont1++){
            cont2 = cont1;
            temp = vet[cont1];
            while ((cont2 >= gap) && (vet[cont2-gap] > temp)){
                  vet[cont2] = vet[cont2 - gap];
                  cont2 = cont2 - gap;
            }
            vet[cont2] = temp;
        }
        if (gap/2 != 0)
           gap = gap/2;
        else if (gap == 1)
             gap = 0;
        else
            gap = 1;
     }
     
     printf("\n\nos dados do vetor ordenados foram:\n\n");
     for(cont1=0;cont1<tamanhoVetor;cont1++){
        printf("%d\t",vet[cont1]);
     } 
                

    printf("\n\nFinal de programa - pressione ENTER para sair");
    getch ();	//Pausa para a execução do programa//

}
