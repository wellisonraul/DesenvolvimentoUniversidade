#include<stdio.h>
#include<stdlib.h>

int main(){
    unsigned long long int numero1,numero2,i,fat1,fat2;
    while(scanf("%llu %llu",&numero1,&numero2)!=EOF){
        fat1=1;
        fat2=1;
        for(i=numero1;i>=1;i--){
            fat1 *= i;
        }
        for(i=numero2;i>=1;i--){
            fat2 *= i;
        }
        printf("%llu\n",fat1+fat2);
    }
    return 0;
}
