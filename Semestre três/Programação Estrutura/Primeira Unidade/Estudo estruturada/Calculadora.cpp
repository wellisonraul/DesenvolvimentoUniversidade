#include<stdio.h>
#include<stdlib.h>

float calc(float num1,float num2, char operador){
	if(operador=='+') return num1+num2;
	if(operador=='*') return num1*num2;
	if(operador=='/') return num1/num2;
	if(operador=='-') return num1-num2;
	
	return 0;
}

main(){
	float num1,num2;
	char operador;
	
	printf("Inf. dois numeros ?\n");
	scanf("%f%f",&num1,&num2);
	printf("Inf. o operador ?\n");
	fflush(stdin);
	scanf("%c",&operador);
	printf("%.2f %c %.2f = %.2f",num1,operador,num2,calc(num1,num2,operador));
}
