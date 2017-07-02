#include <iostream>
#include <conio.h>
#include <stdio.h>

int fat(int);
int main(void){
	int n;
	printf("\n\nDigite um valor inteiro para n: ");
	scanf("%d", &n);
	printf("\nO fatorial de %d e' %d", n, fat(n));
	getch();
}

int fat(int n){
	if(n!=0) {
  	  return(n*fat(n-1));
	}else{
      return(1);
    }
}
