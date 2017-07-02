#include <stdio.h>
#include <stdlib.h>

int main(){
	int l,c,i,j,soma=0,somatorio=0,ii=0,jj=0;
	char m[200][200];
	while(scanf("%d%d",&l,&c)!=EOF){
		if(l==0 || c==0) continue;
		for(i=0;i<l;i++){
			scanf("%s",m[i]);
		}
		for(i=0;i<l;i++){
			for(j=0;j<c;j++){
				   soma=0;
				 if( m[i][j]!='*'){
                       for(ii=i-1;ii<i+2;ii++){
                       		for(jj=j-1;jj<j+2;jj++){
                       			if(m[ii][jj]=='*' && (ii>=0 && jj>=0 ) ){
                       				soma++;
                       			}
                       		}
                       }
                    m[i][j] = '0' + soma;
				   }
			}
		}
		printf("Field #%d:\n",++somatorio);
		for(i=0;i<l;i++){
			printf("%s\n",m[i]);
		}
		for(i=0;i<103;i++){
			for(j=0;j<103;j++){
				m[i][j]='0';
			}
		}
	}
	return 0;
}
