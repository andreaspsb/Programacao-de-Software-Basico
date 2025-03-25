//Faça um programa em c, com duas funções
//uma função chamada imprime e outra preenche.
//A função imprime deve imprimir um vetor de 0 a 10.
// void imprime(int vet[], int tam);
//A função preenche deve preencher um vetor com tamanho tam.
// void preenche(int vet[], int tam);
//por fim, faça um main, com um vetor de 10 inteiros.
//Chame a função preenche, printe os valores preenchidos.
//por fim, chame a função imprime.

#include<stdio.h>

void imprime(int vet[], int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void preenche(int vet[], int tam) {
    for(int i = 0; i < tam; i++) {
        vet[i] = i;
    }
}

int main() {
    int vet[10];
    preenche(vet, 10);
    imprime(vet, 10);
}