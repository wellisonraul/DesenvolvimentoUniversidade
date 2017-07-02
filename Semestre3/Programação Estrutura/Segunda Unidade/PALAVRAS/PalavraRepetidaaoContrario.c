#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char String[100],String2[50];
	int i,cont=0;
	
	fgets(String,50,stdin);
	String[strlen(String)-1]='\0';
	cont = strlen(String)-1;
	for(i=0;String[i]!='\0';i++){
		String2[cont]=String[i];
		cont--;
	}
	strcat(String,String2);
	printf("%s",String);
	return 0;
}
