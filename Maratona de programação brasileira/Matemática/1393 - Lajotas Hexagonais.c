#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,resp,i,aux[40];
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            continue;
        }
        aux[1]=1;
        aux[2]=2;
        aux[3]=3;

        if(n<=3){
            printf("%d\n",aux[n]);
        }else{
            for(i=4;i<=n;i++){
                aux[i] = aux[i-1] + aux[i-2];
            }
            printf("%d\n",aux[i-1]);
        }

    }
    return 0;
}
