#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
	char str[100];
	int i;
	fgets(str,100,stdin);
	
	for(i=0;i<strlen(str);i++){
		if(str[i]>='A' && str[i]<='Z'){
			str[i] = tolower(str[i]);
		}else{
			str[i] = toupper(str[i]); 
		}
	}
	str[strlen(str)-1]='\0';
	
	printf("%s",str);
	return 0;
}
