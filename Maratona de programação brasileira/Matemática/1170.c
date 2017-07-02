#include<stdio.h>
#include<stdlib.h>

int main(){
    int nCasos,i,j,nResp[1000],contaC;
    float nValores[1000];
    while(scanf("%d",&nCasos)!=EOF){
        for(i=0;i<nCasos;i++){
            scanf("%f",&nValores[i]);
        }
        for(i=0;i<nCasos;i++){
        contaC =0;
          while(nValores[i]>1){
            nValores[i] /= 2;
            contaC++;
          }
          nResp[i]=contaC;
        }

        for(i=0;i<nCasos;i++){
            printf("%d dias\n",nResp[i]);
        }
    }
    return 0;
}
