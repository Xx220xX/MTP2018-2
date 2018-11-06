#include<stdio.h>
void printa(char **mat,int n,int m int x0, int y0) {
    int i, j, x = x0, y = y0,yat;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            textbackground(mat[i][j]?BLUE:BLACK);
            gotoxy(x++, y);
            printf(" ");
        }
        y ++;
        x = x0;
    }
}
char **  alocarMatriz(int m,int n){
	char **mat;
	int i;
	mat=(char **)malloc(m*sizeof(char *)) ;
	for(i=0;i<n;i++)
		mat[i]= (char *)malloc(n*sizeof(char));
	return mat;
}
void liberar(char **m, int colunas){
	int i;
	for(i=0;i<colunas;i++)
	free(m[i]);
	free(M);
}
void virar(char **mat,int m, int m) {
    char **aux= alocarMatriz(n,m);
    int i0, j0, j1 = m - 1, i1 = 0, i, j;
    for (i0 = 0; i0 < m; i0++) {
        for (j0 = 0; j0 < n; ++j0) {
            aux[i0][j0] = mat[i1][j1];
            i1++;
            if (i1 == n) {
                j1--;
                i1 = 0;
            }
        }
    }
	for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            mat[i][j] = aux[i][j];
        }
    }
    liberar(aux,m);
}
