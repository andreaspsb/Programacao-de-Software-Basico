#include<stdio.h>

int multiplicaPorValor (int x) {
    x = x * x;
    return x;
}

int multiplicaPorReferencia (int* x) {
    *x = *x * *x;
}

void swap(int *var1, int *var2) {
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void caixaDeBanco(int* r, int* um, int* cinco, int* dez, int* cinquenta, int* cem) {
    int resto = *r % 100;
    *cem = *r / 100;

    int resto2 = resto % 50;
    *cinquenta = resto / 50;
    
    int resto3 = resto2 % 10;
    *dez = resto2 / 10;
    
    int resto4 = resto3 % 5;
    *cinco = resto3 / 5;

    //int resto5 = resto4 % 1;
    *um = resto4;
}


int main() {
    int t = 10;
    printf("%d - %d\n", multiplicaPorValor(t), t);

    multiplicaPorReferencia(&t);
    printf("%d\n", t);

    int* b;
    printf("Endereco t: %p\n", &b);

    int x = 10, y = 5;
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);

    int um, cinco, dez, cinquenta, cem;
    int r = 599;

    caixaDeBanco(&r, &um, &cinco, &dez, &cinquenta, &cem);
    printf("um: %d, cinco: %d, dez: %d, cinquenta: %d, cem: %d\n", um, cinco, dez, cinquenta, cem);

}
