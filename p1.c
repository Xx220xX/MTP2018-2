/*p1.c*/
/*Henrique*/
/*11811ETE016*/

#include <stdio.h>
int main(){
	char numero[250];
	scanf("%s",numero);
	int estado=0,n=0,i;
	for(i=0;numero[i];i++){
		n=numero[i]-48;
		if(estado==0)
			estado=n;
		else if(estado==1){
			estado=n==0?2:0;
		else if(estado==2)
			estado=n==1?2:1;
		}   printf("%s %s",numero,estado==0?"e multiplo de 3":"nao e");
			return 0;
	}
