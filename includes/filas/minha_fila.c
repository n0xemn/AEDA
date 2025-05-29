#include <stdio.h>
#include <stdlib.h>
#include "minha_fila.h"

struct fila
{
    int cap, qtde;
    int* elementos;    
};

int capacidade(fila *L){
    return L->cap;
}

bool cheia(fila *L){
    if (L->qtde >= L->cap)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int front(fila *L){
    if (!vazia(L))
    {
        return L->elementos[0];
    }
    printf("Fila Vazia");
    printf("\n");
    return 0;
}

fila * iniciar(int cap){
    fila* fil_aux = (fila*) malloc(sizeof(fila));
    if (fil_aux != NULL)
    {
        fil_aux->elementos = (int*) malloc(cap * (sizeof(int)));
        if (fil_aux->elementos == NULL)
        {
            free(fil_aux);
            return NULL;
        }
        fil_aux->cap = cap;
        fil_aux->qtde = 0;
    }
    return fil_aux;
}

bool inserir(fila *L, int item){
    if (!cheia(L))
    {
        L->elementos[L->qtde] = item;
        L->qtde++;
        return true;
    }
    return false;
}

void liberar(fila** L){
    free((*L)->elementos);
    free(*L);
    *L = NULL;
}

bool remover(fila *L){
    if (!vazia(L))
    {
        for (int i = 0; i < L->qtde - 1; i++)
        {
            L->elementos[i] = L->elementos[i + 1];
        }
        L->qtde--;
        return true;
    }
    return false;
}

int tamanho(fila *L){
    return L->qtde + 1;
}

bool vazia(fila *L){
    if (L->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}