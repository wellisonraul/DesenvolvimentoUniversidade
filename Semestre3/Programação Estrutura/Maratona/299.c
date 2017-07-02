#include <stdio.h>

int main(){
	int qtdv,trem,i,j,v[100],aux,qtd,cont;
	
	while(scanf("%d",&qtdv)!=EOF){
  		for(cont=0;cont<qtdv;cont++){
			scanf("%d",&trem);
			qtd=0;
			for(i=0;i<trem;i++){
  				scanf("%d",&v[i]);
  			}
			for(i=trem-1;i>=0;i--){
				for(j=0;j<i;j++){
					if(v[j]>v[j+1]){
						qtd++;
						aux = v[j];
						v[j] = v[j+1];
						v[j+1] = aux;
					}
				}
			}
			printf("Optimal train swapping takes %d swaps.\n",qtd);
		}
    }
  	
	return 0;
}
