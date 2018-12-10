/*p4.c*/
/*Henrique*/
/*11811ETE016*/
#include<stdio.h>
int ackermann (int m, int n);
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d\n",ackermann(m,n));
}
 int ackermann (int m, int n){
	if(m==0){return n+1;}
  if(m>0 && n==0){return ackermann(m-1,1);}
	if(m>0 && n>0){return ackermann(m-1,ackermann(m,n-1)); }
}
