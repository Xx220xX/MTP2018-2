/*P7.c*/
/*Henrique*/
/*11811ETE016*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *x, *y;
} Pont;

int main() {
    FILE *file;
    char buf[50] = {0};
    int n = 0, i;
    Pont p;
    scanf("%d", &i);
    if (i == 1) {
        scanf("%d", &n);
        fflush(stdin);
        p.x = calloc(n, sizeof(double));
        p.y = calloc(n, sizeof(double));
        for (i = 0; i < n; i++) {
            p.x[i] = cos(i * 2.0 * M_PI / (n - 1));
            p.y[i] = sin(i * 2.0 * M_PI / (n - 1));
        }
        file = fopen("pontos.dat", "w");
        for (i = 0; i < n; i++) {
            fprintf(file, "%.3lf,%.3lf\n", p.x[i], p.y[i]);
        }

        fclose(file);
        free(p.x);
        free(p.y);
    } else if (i == 2) {
        file = fopen("pontos.dat", "r");
        while (!feof(file)) {
            fgets(buf, 49, file);
            printf("%s", buf);
        }
        fclose(file);
    }
    return 0;
}
