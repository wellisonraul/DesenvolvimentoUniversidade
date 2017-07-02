#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    unsigned long int numero1[4294967294],numero2[4294967294],numero[4294967294],aux,teste,aux2,aux3;
    int n,i;
    while(scanf("%d",&n)!=EOF){
       for(i=0;i<n;i++){
            scanf("%lu %lu",&numero1[i],&numero2[i]);
            aux2 = numero1[i];
            aux3 = numero2[i];

            teste=0;
            while(aux2!=0){
                aux2 /= 10;
                aux=aux3%10;
                aux3/=10;
                numero[i] += aux * pow(10,teste);
                teste++;
            }
        }
        for(i=0;i<n;i++){
            if(numero[i]==numero2[i]){
                printf("encaixa\n");
            }else{
                printf("nao encaixa\n");
            }
        }


    }
    return 0;
}
