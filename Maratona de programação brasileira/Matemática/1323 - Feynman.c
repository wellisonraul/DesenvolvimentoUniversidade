#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,resp,i;
    while(scanf("%d",&n)!=EOF){
        if(n==0) continue;
        resp = 0;
        for(i=1;i<=n;i++){
            resp += i * i;
        }
        printf("%d\n",resp);
    }
    return 0;
}
