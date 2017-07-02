#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct ponto{
	float x,y;
}; 


float VerificaCirculo(struct ponto p, struct ponto c, float r){
	if((sqrt(((p.x-c.x)*(p.x-c.x))+((p.y-c.y)*(p.y-c.y))))<=r) return 1; else return 0 ;
}


main(){
	struct ponto P,C;
	float r;
	
	scanf("%f",&C.x);
	scanf("%f",&C.y);
	scanf("%f",&P.x);
	scanf("%f",&P.y);
	scanf("%f",&r);
	
	
	printf("%f",VerificaCirculo(P,C,r));
	

	return 0;
}
