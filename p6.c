/*P6.c*/
/*Henrique*/
/*11811ETE016*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
 	double *x,*y;
 }Pont;
int main(){
	
	int n,i;
	Pont p;
	scanf("%d",&n);
	fflush(stdin);
	p.x = calloc(n,sizeof(double ) );
	p.y= calloc(n,sizeof(double ) );
	for(i=0;i<n;i++){
		p.x [i]= cos(i*2.0*M_PI/(n-1));
        p.y[i] = sin(i*2.0*M_PI/(n-1));
        
	}
	for(i=0;i<n;i++){
	printf("(%.3lf,%.3lf)\n",p.x[i],p.y[i]);
	}
	free(p.x);
	free(p.y);
}
