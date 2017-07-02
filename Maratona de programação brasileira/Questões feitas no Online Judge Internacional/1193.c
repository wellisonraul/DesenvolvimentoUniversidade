#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int valorInf,n,i,j,x=0,t=0,op[3],dadosBin[100000],dadosHexInt[100000],resul,hex[10000],bin,bina[10000],dec,aux;
	char recebeDados[10000],s[4],dadosHex[100000],teste[1000];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			t=0;
			valorInf =0;
			scanf("%s",recebeDados);
			for(i=0;i<strlen(recebeDados);i++){
				if(recebeDados[i]==32){
					t++;
				}else{
					if(t==0){
						valorInf += (recebeDados[i] - '0')*(pow(10,strlen(recebeDados)));
						printf("|%d|",strlen(recebeDados));
					}else{
						strncat(s,recebeDados,3);
						break;
					}
				}
			}
			if ((strcmp(s,"bin") == 0)) {
				op[i] = 1;
				x=0;
				while(valorInf!=0){
					aux=valorInf%10;
        			valorInf/=10;
        			dadosBin[x++] = aux;
				}
			}else{
				if(strcmp(s,"dec")==0){
					op[i] = 2;
					dec = valorInf;
					bin = valorInf;
				}else{
					x=0;
					op[i] = 3;
					for(j=strlen(dadosHex)-1;j>=0;j--){
						if(dadosHex[j]>=87 && dadosHex[j]<=102){
							dadosHexInt[x++] = 87 - dadosHex[j];
						}else{
							dadosHexInt[x++] = dadosHex[j] - '0';
						}
						printf("|%d|",dadosHexInt[x-1]);
					}
				}
			}
		}
		switch(op[0]){
			case 1:
				printf("Case %d:\n",x);
				resul=0;
				for(i=x-1;i>=0;i--){
					resul += dadosBin[i]*pow(2,i);
				}
				printf("%d dec\n",resul);
				i=0;
				while(resul>16){
					hex[i++]= resul%16;
					resul = resul/16;
				}
				printf("%d",resul);
				for(i=i-1;i>=0;i--){
						switch(hex[i]){
							case 10:
								printf("a");
								break;
							case 11:
								printf("b");
								break;
							case 12:
								printf("c");
								break;
							case 13:
								printf("d");
								break;
							case 14:
								printf("e");
								break;
							case 15:
								printf("f");
								break;
							default:
								printf("%d",hex[i]);
						}
				}

				printf(" hex\n\n");

				break;
			case 2:
				i=0;
				j=0;

				while(dec>=16){
					hex[i++]= dec%16;
					dec = dec/16;
				}

				while(bin>=2){
					bina[j++]= bin%2;
					bin = bin/2;
				}
				i--;
				printf("%d",dec);
				for(i;i>=0;i--){
						switch(hex[i]){
							case 10:
								printf("a");
								break;
							case 11:
								printf("b");
								break;
							case 12:
								printf("c");
								break;
							case 13:
								printf("d");
								break;
							case 14:
								printf("e");
								break;
							case 15:
								printf("f");
								break;
							default:
								printf("%d",hex[i]);
						}

					}
					printf(" hex\n%d",bin);
					for(i=j-1;i>=0;i--){
						printf("%d",bina[i]);
					}
					printf(" bin\n\n",bin);
				break;
			case 3:
				return 0;
		}
	}
	return 0;
}

