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
		estado=estado==0?n:estado==1?n==0?2:0:n==1?2:1;
		}
		 printf("%s %s",numero,estado==0?"e multiplo de 3":"nao e");
	return 0;
	}
 
