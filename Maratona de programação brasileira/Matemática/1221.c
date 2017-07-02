#include<stdio.h>
#include<stdlib.h>

int main(){
    double valor;
    int n,i,teste,valor2;
    unsigned long int primos[200],j;
    while(scanf("%d",&n)!=EOF){

        for(i=0;i<n;i++){
            scanf("%lu",&primos[i]);
        }

        for(i=0;i<n;i++){
            teste=0;
            valor = sqrt(primos[i]);
            valor = ceil(valor);
            for(j=3;j<=valor;j++){
                if( (primos[i]%j)==0){
                        teste++;
                }
            }
            if(teste==0) printf("Prime\n"); else printf("Not Prime\n");
        }
    }
    return 0;
}
