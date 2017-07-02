#include <stdio.h>
#include <string.h>

int main(){
	int b1,b2,b3,g1,g2,g3,c1,c2,c3,Minimos[6],i,menorval=0,cont;
	while(scanf("%d%d%d%d%d%d%d%d%d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)!=EOF){
		 Minimos[0]=b2+b3+c1+c3+g1+g2;
    	 Minimos[1]=b2+b3+c1+c2+g1+g3;
      	 Minimos[2]=b1+b3+c2+c3+g1+g2;
    	 Minimos[3]=b1+b2+c2+c3+g1+g3;
    	 Minimos[4]=b1+b3+c1+c2+g3+g2;
    	 Minimos[5]=b2+b1+c1+c3+g3+g2;
    	
    	menorval= Minimos[0];
    	cont=0;
    	for(i=1;i<6;i++){
    		if(Minimos[i]<menorval){
    			menorval = Minimos[i];
    			cont= i;
    		} 
    	}
    	
    	if(cont==0) printf("BCG ");
        if(cont==1) printf("BGC ");
        if(cont==2) printf("CBG ");
        if(cont==3) printf("CGB ");
    	if(cont==4) printf("GBC ");
    	if(cont==5) printf("GCB ");
    	
    	printf("%d\n",menorval);
	}
	return 0;
}
