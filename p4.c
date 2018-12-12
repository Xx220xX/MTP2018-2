/*p4.c*/
/*Henrique*/
/*11811ETE016*/

#include <stdio.h>
char A(char m, char n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return A(m - 1, 1);
    } else {
        return A(m - 1, A(m, n - 1));
    }
}

int main() {
    char m, n, r;
    int aux;
    scanf("%d", &aux);
    m = aux;
    scanf("%d", &aux);
    n = aux;
    r = A(m, n);
    printf("%d\n", r);
    return 0;
}
