#include <stdio.h>
#include <stdlib.h>

#define  N 8
typedef struct {
	char i,j;
}Pontos;
int possibilidades=0;
int jaEstive(Pontos	*p0, int i,int j){
	int k=0;
		for(;(p0+k)->i!='@' && (p0+k)->j!='@';k--){
		if((p0+k)->i==i && (p0+k)->j==j){
			return 1;
		}
	}
	return 0;
}
char mat[N][N]={{0,0,1,0,0,0,1,1},
                                   {1,0,0,0,0,0,1,1},
                                   {0,0,0,1,1,0,1,1},
                                    {0,0,0,1,1,0,1,1},
                                      {0,0,0,1,1,0,1,1},
                                    {0,0,0,1,1,0,1,1},
                                   {0,1,0,0,1,1,1,0},
                                   {0,1,0,0,0,0,0,0}};
  int achei=0;     
int resolve(char m[][N],int i,int j,Pontos *p){
	if(i==N-1&&j==N-1){
		printf("achei");
		achei=1;
		p->i=i;
		p->j=j;
		p[1].i='#';
		p[1].j='#';
		return 1;
	}
	if(i+1<N && mat[i+1][j]!=1 && !jaEstive(p-1, i+1,j)&& achei==0  && possibilidades<64){
			p->i=i;
			p->j=j;
			possibilidades++;
		    resolve(m, i+1, j,p+1);
		}	
if(i-1>=0&& mat[i-1][j]!=1 && !jaEstive(p-1, i-1,j)&& achei==0 && possibilidades<64){
			p->i=i;
			p->j=j;
			possibilidades++;
		    resolve(m, i-1, j,p+1);
		}
	
		if(j+1<N && mat[i][j+1]!=1 && !jaEstive(p-1, i,j+1)&&achei==0  && possibilidades<64){
			p->i=i;
			p->j=j;
			possibilidades++;
		    resolve(m, i, j+1,p+1);
		}
		if(j-1>=0&& mat[i][j-1]!=1 && !jaEstive(p-1, i,j-1)&&achei==0 && possibilidades<64 ){
			p->i=i;
			p->j=j;
			possibilidades++;
		    resolve(m, i, j-1,p+1);
		}
	
	if(achei==1){
		return 1;
	}
		return 2;
}

		void printaM(char mat[][N){
			int i,j;
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
	  	if(mat[i][j]=='X'){
	  		printf("%c   ",'X');
	  		continue;
	  	}
	  	printf("%d   ",mat[i][j]);
	  }
	  printf("\n");
	}
		}

int main(){
	Pontos p[25];
	p[0].i='@';	
	p[0].j='@';
	
	
	printaM(mat);
	
//	printf("%d",jaEstive(p+1, 1, 3));
	printf("%d\n\n",resolve(mat,0,0,p+1));
	
	int k=0;
		for(;(p+k)->i!='#' && (p+k)->j!='#'&& achei !=0;k++){
		printf(" ps %d %d\n",(p+k)->i,(p+k)->j );
			if((p+k)->i!='@' && (p+k)->j!='@')
			mat[(p+k)->i][(p+k)->j] ='X';
	}
	printaM(mat);
	
	return 0;
}
