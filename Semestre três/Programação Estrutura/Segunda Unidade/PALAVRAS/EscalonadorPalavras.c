#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(){
	char String1[50],String2[50],String3[100];	
	int i,cont = 0,aux=0,aux2=0,aux3=0;
	fgets(String1,50,stdin);
	fgets(String2,50,stdin);
	String1[strlen(String1)-1]='\0';
	String2[strlen(String2)-1]='\0';
	aux = (strlen(String1)  + strlen(String2));
	for(i=0;i<aux;i++){
		if(String1[i]!='\0' && aux2==0) String3[cont++] = String1[i];
		else aux2++;
		if(String2[i]!='\0' && aux3==0) String3[cont++] = String2[i];
		else aux3++;
	}
	
	printf("%s",String3);
}
