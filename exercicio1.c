#include<stdio.h>

int main(){
    int i;

    printf("Um inteiro tem %lu bytes\n",sizeof(i));

    scanf("%d", &i);
    printf("Escrevendo: %d\n",i);

    return 0;
}