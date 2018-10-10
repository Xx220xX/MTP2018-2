#include <stdio.h>
void integerValueOf(char *str,int *n){
		if(*str){
			if(*str>='0'&&*str<='9')
				*n=*n*10+((*str-'0'));
	    integerValueOf((str+1), n);
    }
}
int main(){
	char str[256]="";
	int n;
	scanf("%s",str);
	integerValueOf(&str[0], &n);
	printf("%d",n);
	return 0;
}
