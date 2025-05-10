#include <stdio.h>
#include "mymemory.h"

int main()
{
    // aloca pool memoria
    mymemory_t *memory = mymemory_init(1000);

    // int v[32];
    //  int *v = malloc(sizeof(int)*32);
    int *v = mymemory_alloc(memory, sizeof(int) * 32);
    for (int i = 0; i < 32; i++)
        v[i] = i + 1;

    int *v2 = mymemory_alloc(memory, sizeof(int) * 16);

    // free(v);
    mymemory_free(memory, v);

    char *str = mymemory_alloc(memory, sizeof(char) * 16);
    sprintf(str, "ola mundo");

    // libera o pool de memoria
    mymemory_cleanup(memory);

    return 0;
}

mymemory_t *mymemory_init(size_t size)
{
}

void *mymemory_alloc_first(mymemory_t *memory, size_t size)
{
    allocation_t atual = *memory->head;
    allocation_t proximo = *atual.next;
    allocation_t novo;

    if (atual == NULL)
    {
        // alocar no início
        novo.start = memory->pool;
        novo.size = size;
        novo.next = NULL;
        *memory->head = novo;
        return;
    }

    if (proximo == NULL)
    {
        if ((atual.start - memory->pool) > size)
        {
            // alocar no início
            novo.start = memory->pool;
            novo.size = size;
            *novo.next = atual;
            *memory->head = novo;
            return;
        }

        return;
    }

    // percorrer a lista encadeada
    while (proximo != NULL)
    {
        if ((proximo.start - (atual.start + atual.size)) > size)
        {
            // alocar novo nodo
            novo.start = atual.start + atual.size;
            novo.size = size;
            *novo.next = proximo;
            *atual.next = novo;
            return;
        }
        atual = proximo;
        proximo = *proximo.next;
    }

    // verificar o último espaço livre
    if ((memory->pool + memory->total_size) - (atual.start + atual.size) > size)
    {
        // alocar como o último nodo
        novo.start = atual.start + atual.size;
        novo.size = size;
        novo.next = NULL;
        *atual.next = novo;
        return;
    }
}

void *mymemory_alloc_best(mymemory_t *memory, size_t size)
{
    allocation_t atual = *memory->head;
    allocation_t proximo = *atual.next;
    allocation_t novo;

    if (atual == NULL)
    {
        // alocar no início
        novo.start = memory->pool;
        novo.size = size;
        novo.next = NULL;
        *memory->head = novo;
        return;
    }

    allocation_t nodoAux;
    int anterior = 0;
    int posterior = 0;
    // percorrer a lista encadeada
    while (proximo != NULL)
    {
        posterior = proximo.start - (atual.start + atual.size);
        if (posterior > size && posterior < anterior)
        {
            anterior = posterior;
            nodoAux = atual;
        }
        atual = proximo;
        proximo = *proximo.next;
    }

    // verificar o último espaço livre
    posterior = (memory->pool + memory->total_size) - (atual.start + atual.size);
    if (posterior > size && posterior < anterior)
    {
        nodoAux = atual;
    }

    // alocar novo nodo
    if (nodoAux == NULL)
    {
        // alocar no início
        novo.start = memory->pool;
        novo.size = size;
        //*novo.next = atual;
        *memory->head = novo;
        return;
    }

    novo.start = nodoAux.start + nodoAux.size;
    novo.size = size;
    //novo.next = nodoAux.next;
    *nodoAux.next = novo;

}

void *mymemory_alloc_worst(mymemory_t *memory, size_t size)
{
    allocation_t atual = *memory->head;
    allocation_t proximo = *atual.next;
    allocation_t novo;

    if (atual == NULL)
    {
        // alocar no início
        novo.start = memory->pool;
        novo.size = size;
        novo.next = NULL;
        *memory->head = novo;
        return;
    }

    if (proximo == NULL)
    {
    }
    // percorrer a lista encadeada
}

void mymemory_free(mymemory_t *memory, void *ptr)
{
}

void mymemory_display(mymemory_t *memory)
{
}

void mymemory_stats(mymemory_t *memory)
{
}

void mymemory_cleanup(mymemory_t *memory)
{
}
