#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char nome[100];
	int i;
	fgets(nome,100,stdin);
	nome[strlen(nome)-1]='\0';
	for(i=0;i<100;i++){
		if(i==0){
			printf("%c",nome[i]);
		}
		if(nome[i]==' '){
			printf("%c",nome[i+1]);
		}
	}
	
	return 0;
}
