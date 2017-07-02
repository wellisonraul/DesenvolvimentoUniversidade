#include "mystring.h"
#include <stdlib.h>
#include <ctype.h>

/* Retorna o tamanho da String */
int mystrlen(char *s){
	int cont=0,i;
	if(s == NULL){
		return 0;
	}
	for(i=0;s[i]!='\0';i++){
		cont++;
	}
	return cont;
}

/* Compara duas strings s1 e s2 e retorna um valor menor que zero, igual a
zero ou maior que zero caso a string s1 seja, respectivamente, maior, igual
ou maior que a string s2. */

int mystrcmp(char *s1, char *s2){
	int i = 0;
	if(s1 == NULL || s2==NULL){
		return 0;
	}else{
		while((toupper(s1[i])==toupper(s2[i])) && s1[i] != '\0'){
			i++;
		}
		if(s1[i] < s2[i]){
			 return -1;
		}else{
			if(s1[i] > s2[i]){
				return 1;
			} 
		}
		return 0;
	}	
}

/*Equivalente a função anterior, exceto que realiza a comparação apenas dos
n primeiros caracteres das duas strings.*/

int mystrncmp(char *s1, char *s2, int n){
		int i = 0;
	if(s1 == NULL || s2==NULL){
		return 0;
	}else{
		while((toupper(s1[i])==toupper(s2[i])) && s1[i] != '\0' && n!=0){
			i++;
			n--;
		}
		if(s1[i] < s2[i]){
			 return -1;
		}else{
			if(s1[i] > s2[i]){
				return 1;
			} 
		}
		return 0;
	}
}
/* Concatena a strings s2 ao final de s1. */
char *mystrcat(char *s1, char *s2){
	if(s1 == NULL || s2==NULL){
		return 0;
	}
	int i=0,j=0,k=0,cont=0;
	while(s1[i]!='\0'){
		i++;
	}
	while(s2[j]!='\0'){
		j++;
	}
	k=i;
	for(k;k<=(i+j);k++){
		s1[k]=s2[cont++];
	}
	return s1;
}
char *mystrncat(char *s1,  char *s2, int n){
	if(s1 == NULL || s2==NULL){
		return 0;
	}
	int i=0,j=0,k=0,cont=0;
	while(s1[i]!='\0'){
		i++;
	}
	while(s2[j]!='\0'){
		j++;
	}
	k=i;
	for(k;k<(i+n);k++){
		s1[k]=s2[cont++];
	}
	s1[(i+n)]='\0';
	return s1;
}
/*Copia o conteúdo da string s2 para a string s1.*/
char *mystrcpy(char *s1, char *s2){
	if(s1 == NULL || s2==NULL){
		return 0;
	}
	int i=0,j=0;
	while(s2[j]!='\0'){
		j++;
	}
	for(i=0;i<j;i++){
		s1[i]=s2[i];
	}
	s1[i]='\0';
	return s1;
}
/*Copia os n primeiros caracteres de s2 para a string s1.*/
char *mystrncpy(char *s1, char *s2, int n){
	int i=0;
	for(i=0;i<n;i++){
		s1[i]=s2[i];
	}
	s1[i]='\0';
	return s1;
}
/*Aloca memória e retorna uma nova string que é a cópia da string s.*/
char *mystrdup(char *s){
	char *s1;
	int j=0,i=0,cont=0;
	if(s == NULL){
		return 0;
	}
	for(i=0;s[i]!='\0';i++){
		cont++;
	}
	s1=(char*) malloc(sizeof(char)*cont);
	if(s1!=NULL){
	int i=0,j=0;
		while(s[j]!='\0'){
			j++;
		}
		for(i=0;i<j;i++){
			s1[i]=s[i];
		}
		s1[i]='\0';
	} 
	return s1;
	free(s1);
}
