#include<stdio.h>
#include<stdlib.h>

int main(){
    int nCasos,vJogadores[11],qtdEq,nResp[100],i,j;
    while(scanf("%d",&nCasos)!=EOF){
        for(i=0;i<nCasos;i++){
        vJogadores[0]=10;
            for(j=0;j<vJogadores[0];j++){
                scanf("%d",&vJogadores[i]);
            }
            nResp[i] = vJogadores[(vJogadores[0]/2)];
            printf("%d",nResp[i]);
        }
        for(i=0;i<nCasos;i++){
            printf("Case %d: %d\n",i,nResp[i]);
        }

    }
    return 0;
}
