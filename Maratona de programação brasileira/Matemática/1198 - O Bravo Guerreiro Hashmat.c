#include<stdio.h>
#include<stdlib.h>

int main(){
    unsigned long long int exercito1,exercito2;
    while(scanf("%llu %llu",&exercito1,&exercito2)!=EOF){
        printf("%llu\n",abs(exercito1-exercito2));
    }
    return 0;
}
