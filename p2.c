/*p2.c*/
/*Henrique*/
/*11811ETE016*/
#include <stdio.h>
char dicionario[64];
int length(char str[]) {
    int i;for (i = 0; str[i]; ++i);
    return i - 1;
}
int potencia(int base,int e){
    int i=0,j=1;
    for(;i<e;j=j*base,i++);
    return j;
}
void remove0(char bin[]) {
    int i, j = 0, grava = 0;
    for (i = 0; bin[i]; ++i) {
        if (bin[i] != '0') {
            grava = 1;
        }
        if (grava) {
            bin[j++] = bin[i];
        }
    }
    bin[j] = 0;
}
char numToApar(int num) {
    if (num > 63) { num = 1; };
    return dicionario[num];
}
void decTo(int dec, char bin[], int base, int bits) {
    bin[bits--] = 0;
    while (bits >= 0) {
        bin[bits] = numToApar(dec % base);
        bits--;
        dec = dec / base;
    }
    if (base != 2) {
        remove0(bin);
    }
}
int aprToNum(char num, int base) {
    if (base == 16) {
        if (num <= 'z' && num >= 'a') {
            num -= ('a' - 'A');
        }
    }
    int j;
    for (j = 0; j <= base; ++j) {
        if (num == dicionario[j]) {
            return j;
        }
    }
return 1;
}

int baseToDec(char bin[], int actualBase) {
    int i = length(bin);
    int soma = 0;
    int j = 0;
    for (; i >= 0; i--) {
        int num = aprToNum(bin[i], actualBase);
        soma += num * potencia(actualBase,j++);
    }
    return soma;
}
void brincar() {
    char bin[128];
    char nome[] = "ELA E LINDA";
    printf("%s\n", nome);
    int base = 64;
    int i;
    for (i = 0; nome[i]; ++i) {
        decTo(nome[i], bin, base, 8);
        printf("%s ", bin);
    }
}

void criarDicionario() {
    int j;
    int n = '0';
    for (j = 0; j <= 61; ++j) {

        dicionario[j] = n;
        if (n == '9') {
            n = 'A';
        } else if (n == 'Z') {
            n = 'a';
        } else if (n == 'z') {
            break;
        } else {
            n++;
        }
    }
    dicionario[62] = '/';
    dicionario[63] = '+';
}
int main() {
    criarDicionario();
    int escolha = 0;
    char str[650] = {0};

    scanf("%d", &escolha);
    getchar();
    switch (escolha) {
        case 1://bin to dec
            scanf("%s", str);
            printf("%d", baseToDec(str, 2));
            break;
        case 2://bin to Hex
            scanf("%s", str);
            decTo(baseToDec(str, 2), str, 16, 8);
            printf("%s", str);
            break;
        case 3://hex to dec
            scanf("%s", str);
            printf("%d", baseToDec(str, 16));
            break;
        case 4://hex to bin
            scanf("%s", str);
            decTo(baseToDec(str, 16), str, 2, 15);
            printf("%s", str);
            break;
        case 5:
            scanf("%d", &escolha);
            decTo(escolha, str, 2, 10);
            printf("%s", str);
            break;
        case 6:
            scanf("%d", &escolha);
            decTo(escolha, str, 16, 16);
            printf("%s", str);
            break;
        case 7://oct to dec
            scanf("%s", str);
            printf("%d", baseToDec(str, 8));
            break;
        case 8://dec to oct
            scanf("%d", &escolha);
            decTo(escolha, str, 8, 16);
            printf("%s", str);

    }
    printf("\n");
    return 0;
}
