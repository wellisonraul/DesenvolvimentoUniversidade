#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,vValores[101],i,j;
    unsigned long long int resposta,aux;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&vValores[i]);
        }
        for(i=0;i<n;i++){
        resposta=1;
        aux=0;
            for(j=1;j<vValores[i];j++){
                resposta *= 2;
                aux += resposta;
            }
            printf("%llu kg\n",(aux/12)/1000);
        }
    }
    return 0;
}
