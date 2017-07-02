#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
	char str[100];
	int cont = 0,i;
	fgets(str,100,stdin);
	str[strlen(str)-1]='\0';
	for(i=0;i<strlen(str);i++){
		if(str[i]>='A' && str[i]<='Z') cont++;
	}
	
	printf("%d",cont);
	return 0;
}
