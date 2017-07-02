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
	int i;
	for(i=4;i>=1;i--){
		printf("%d|",v[i]);
	}
	return v[0];
}
