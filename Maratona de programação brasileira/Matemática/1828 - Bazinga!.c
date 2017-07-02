#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n,i,j;
    char cResp[202][50];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            fgets(cResp[i],50,stdin);
            cResp[i][strlen(cResp[i]-1)]='\0';
        }
        for(i=0;i<n*2;i++){
            for(j=0;j<strlen(cResp[i]);j++){
                if(cResp[i][j]==32){
                    strncat(cResp[++i],cResp[i-1],j);
                }
            }
        }
        for(i=0;i<n;i++){
            printf("%s\n",cResp[i]);
        }

    }
    return 0;
}
