#include <stdio.h>

//zera todos os bits
unsigned int clear(unsigned int val)
{
}

//seta um único bit
unsigned int setbit(unsigned int x, int bit)
{
    //marcar como 1(ligado) o bit em questão
    unsigned mask = (1 << bit);
    return x | mask;
}

//resseta um único bit
unsigned int clearbit(unsigned int x, int bit)
{
    //zera um único bit
    unsigned mask = ~(1 << bit);
    return x & mask;
}

//inverte o valor de um único bit
unsigned int invertBit(unsigned int x, int bit)
{
}

//retorna o estado de um determinado bit
int testBit(unsigned int x, int bit)
{
}

int main()
{
    unsigned int x = 0xF0F0;
    printf("Binario: %b\n, x");
    printf("Decimal: %u\n, x");

    unsigned int var2;

    var2 = clear(x);
    printf("Clear: %0x\n", var2);

    var2 = setbit(x);
    printf("Clear: %0x\n", var2);

    var2 = clearbit(x);
    printf("Clear: %0x\n", var2);

    var2 = invertBit(x);
    printf("Clear: %0x\n", var2);

    var2 = testBit(x);
    printf("Clear: %0x\n", var2);
}