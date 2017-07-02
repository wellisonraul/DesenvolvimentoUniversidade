#include <stdio.h>

int main(){
	int qtd,v[100],soma=0,tijolos,aux=0,cont=0,i;
	
	
	while(scanf("%d",&qtd)!=EOF){
  		  if(qtd==0) continue;
		  cont++;
		  soma=0;
  		  aux=0;
  		  tijolos=0;
		  for(i=0;i<qtd;i++){
  			scanf("%d",&v[i]);
  			soma+= v[i];
  		  }
  		  tijolos = soma/qtd;
  		  for(i=0;i<qtd;i++){
  		  	if(v[i]>tijolos){
  		  		aux+= v[i]-tijolos;
  		  	}
  		  }
  		  
  		  printf("Set #%d\nThe minimum number of moves is %d.\n\n",cont,aux);
	}
	return 0;
}
