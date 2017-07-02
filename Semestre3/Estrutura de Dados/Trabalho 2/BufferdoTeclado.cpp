#include <stdio.h>
#include <string.h>

main(){
	char v[50];
	int tam,indice;
	printf("Digite o nome: ");
	fflush(stdin); // limpa o buffer do teclado
	gets(v);
	tam = strlen(v);
	
	for(indice=tam;indice>=0;indice--){
		printf("%c",v[indice]);
	}
}
