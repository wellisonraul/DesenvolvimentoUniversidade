#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
	char dic[10][100],aux[100];
	int i,j;
	
	for(i=0;i<10;i++){
		fgets(dic[i],100,stdin);
	}
	for(i=9;i>=0;i--){
		for(j=0;j<i;j++){
			if(strcmp(dic[j],dic[j+1])>0){
				strcpy(aux,dic[j]);
				strcpy(dic[j],dic[j+1]);
				strcpy(dic[j+1],aux);
			}
		}
	}
	for(i=0;i<10;i++){
		printf("\n%s",dic[i]);
	}
	
	return 0;
}
