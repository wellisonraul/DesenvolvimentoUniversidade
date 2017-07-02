#include<stdlib.h>
#include<stdio.h>
int main(){
  char c;
  int h[4]={0,0, 0, 0},x=0;
  float angulo,hh,mm;
  while(scanf("%c",&c)!=EOF){
    if(c != ':' && c!=' ' && c != '\n')  h[x++]=c-'0';
    else{ 
      if(x==1){ 
        h[x++]=h[0];
        h[0]=0;
      }
    } 
    if(x==4){
      x=0;
      hh=(h[0]*10)+h[1];
      mm=(h[2]*10)+h[3];
      angulo= ((6*mm)-((30*hh)+(mm/2)));
      if(angulo<0)   angulo = -angulo;
      if(angulo>180) angulo =360-angulo;
      if(!(((h[0]*10)+h[1])<=12 && ((h[0]*10)+h[1])>=1 && ((h[2]*10)+h[3])>= 0 && ((h[2]*10)+h[3])<=59)) continue;
      printf("%.3f\n",angulo);
    }
  }
  return 0;
}
