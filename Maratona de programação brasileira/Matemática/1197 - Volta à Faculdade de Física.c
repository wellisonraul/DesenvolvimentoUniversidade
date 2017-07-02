#include<stdio.h>
#include<stdlib.h>

int main(){
    int numero1,numero2;
    while(scanf("%d %d",&numero1,&numero2)!=EOF){
        printf("%d\n",numero1*(2*numero2));
    }
    return 0;
}
