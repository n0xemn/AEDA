#include <stdio.h>
#include <stdlib.h>
#include "minha_lista_orde.h"

struct lista_orde
{
    int cap, qtde;
    int* elementos;    
};

int busca(lista_orde *L, int item){
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
            return k + 1;
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
    return 0;
}

int capacidade(lista_orde *L){
    return L->cap;
}

bool cheia(lista_orde *L){
    if (L->qtde >= L->cap)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void exibir(lista_orde *L){
    for (int i = 0; i < L->qtde; i++)
    {
        printf("%d ", L->elementos[i]);
    }
    printf("\n");
}

lista_orde * iniciar(int cap){
    lista_orde* list_aux = (lista_orde*) malloc(sizeof(lista_orde));
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

lista_orde * impares(lista_orde *L){
    lista_orde* impar = iniciar(L->cap);
    
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i]%2 == 1)
        {
            inserir(impar, L->elementos[i]);
        }
    }
    return impar;
}

bool inserir(lista_orde *L, int item){
    if (vazia(L))
    {
        L->elementos[L->qtde] = item;
        L->qtde++;
        return true;
    }
    
    if (!cheia(L))
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
    return false;
}

void liberar(lista_orde** L){
    free((*L)->elementos);
    free(*L);
    *L = NULL;
}

int menores(lista_orde *L, int v){
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

lista_orde *pares(lista_orde *L){
    lista_orde* par = iniciar(L->cap);
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i]%2 == 0)
        {
            inserir(par, L->elementos[i]);
        }
    }
    return par;
}

bool remov_final(lista_orde *L){
    if (!vazia(L))
    {
        L->qtde--;
        return true;
    }
    return false;
}

bool remov_inicio(lista_orde *L){
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

bool remov_meio(lista_orde *L, int posicao){
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

int tamanho(lista_orde *L){
    return L->qtde + 1;
}

bool vazia(lista_orde *L){
    if (L->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}