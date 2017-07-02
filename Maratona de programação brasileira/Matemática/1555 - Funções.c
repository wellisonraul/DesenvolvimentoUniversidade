#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    long long int beto,rafael,carlos;
    int nCasos,x,y,i;
    char vResp[10000][15];
    while(scanf("%d",&nCasos)!=EOF){
        for(i=0;i<nCasos;i++){
            scanf("%d %d",&x,&y);

            rafael = pow((3*x),2) + pow(y,2);
            beto = (2*pow(x,2)) + pow(5*y,2);
            carlos = -100*x + pow(y,3);

            if(rafael>carlos && rafael>beto){
                    strcpy(vResp[i],"Rafael ganhou");
            }else{
                if(carlos>rafael && carlos>beto){
                    strcpy(vResp[i],"Carlos ganhou");
                }else{
                    strcpy(vResp[i],"Beto ganhou");
                }
            }
        }
        for(i=0;i<nCasos;i++){
            printf("%s\n",vResp[i]);
        }
    }
    return 0;
}
