#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct set
{
    int cap, qtde;
    int* elementos;    
};

bool busca(set *L, int item){
    if (vazia(L))
    {
        return 0;
    }
    int i = 0, j = L->qtde - 1, k;
    while (i <= j)
    {
        k = (j+i)/2;
        if (L->elementos[k] == item)
        {
            return true;
        }
        else if (L->elementos[k] > item)
        {
            j = k - 1;
        }
        else
        {
            i = k + 1;
        }
    }
    return false;
}

int capacidade(set *L){
    return L->cap;
}

bool cheia(set *L){
    if (L->qtde >= L->cap)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void exibir(set *L){
    for (int i = 0; i < L->qtde; i++)
    {
        printf("%d ", L->elementos[i]);
    }
    printf("\n");
}

set * iniciar(int cap){
    set* list_aux = (set*) malloc(sizeof(set));
    if (list_aux != NULL)
    {
        list_aux->elementos = (int*) malloc(cap * (sizeof(int)));
        if (list_aux->elementos == NULL)
        {
            free(list_aux);
            return NULL;
        }
        list_aux->cap = cap;
        list_aux->qtde = 0;
    }
    return list_aux;
}

set * impares(set *L){
    set* impar = iniciar(L->cap);
    
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i]%2 == 1)
        {
            inserir(impar, L->elementos[i]);
        }
    }
    return impar;
}

bool inserir(set *L, int item){
    if (vazia(L))
    {
        L->elementos[L->qtde] = item;
        L->qtde++;
        return true;
    }
    
    if (!cheia(L))
    {
        if (!busca(L, item))
        {
            for (int i = L->qtde; i > 0; i--)
            {
                if (L->elementos[i - 1] > item)
                {
                    L->elementos[i] = L->elementos[i - 1];
                    L->elementos[i - 1] = item;
                } else
                {
                    L->elementos[i] = item;
                    break;
                }
            }
            L->qtde++;
            return true;
        }
    }
    return false;
}

void liberar(set** L){
    free((*L)->elementos);
    free(*L);
    *L = NULL;
}

int menores(set *L, int v){
    int quant = 0;
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i] < v)
        {
            quant++;
        }
    }
    return quant;
}

set *pares(set *L){
    set* par = iniciar(L->cap);
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i]%2 == 0)
        {
            inserir(par, L->elementos[i]);
        }
    }
    return par;
}

bool remov_final(set *L){
    if (!vazia(L))
    {
        L->qtde--;
        return true;
    }
    return false;
}

bool remov_inicio(set *L){
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

bool remov_meio(set *L, int posicao){
    if (!vazia(L))
    {
        for (int i = posicao - 1; i < L->qtde - 1; i++)
        {
            L->elementos[i] = L->elementos[i + 1];
        }
        L->qtde--;
        return true;
    }
    return false;
}

int tamanho(set *L){
    return L->qtde + 1;
}

bool vazia(set *L){
    if (L->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}