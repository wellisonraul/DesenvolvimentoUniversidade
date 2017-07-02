#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s1[10], s2[10];
	int n;
	
	fgets(s1,10,stdin);
	fgets(s2,10,stdin);
	
	s1[mystrlen(s1)-1]='\0';
	s2[mystrlen(s2)-1]='\0';
	
	
	scanf("%d",&n);
	
	/* Modifique a função e tipo do retorno para testar ! */ 
	
	printf("%d",mystrlen(s1));
	
	return 0;
}
