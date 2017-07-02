#include<stdio.h>
#include<stdlib.h>

int inverte(int []);

int main(){
	int v[5],i;
	for(i=0;i<5;i++){
		scanf("%d",&v[i]);
	}
	
	printf("%d",inverte(v));
	
	
	return 0;
}

int inverte(int v[]){
	int i,soma=0;
	for(i=0;i<5;i++){
		soma+= v[i];
	}
	return v[0];
}
