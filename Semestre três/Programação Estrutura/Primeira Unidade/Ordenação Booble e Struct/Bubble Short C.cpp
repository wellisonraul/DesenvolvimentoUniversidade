#include <stdio.h>
#include <stdlib.h>

main(){
	int v[10] = {2,3,1,5,10,7,8,9,6,4},i,j,aux;
	
	//Ordenar
	
	for(i=9;i>=0;i--){
		for(j=0;j<i;j++){
			if(v[j]>v[j+1]){
				aux = v[j];
				v[j]=v[j+1];
				v[j+1]= aux;
			}
		}
	}
	
	for(i=0;i<10;i++){
		printf("%d|",v[i]);
	}
}
