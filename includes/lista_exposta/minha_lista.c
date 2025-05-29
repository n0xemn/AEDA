#include <stdio.h>
#include <stdlib.h>
#include "minha_lista.h"


int busca(lista *L, int item){
    if (vazia(L))
    {
        return 0;
    }
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i] == item)
        {
            return i+1;
        }
    }
}

int capacidade(lista *L){
    return L->cap;
}

bool cheia(lista *L){
    if (L->qtde >= L->cap)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void exibir(lista *L){
    for (int i = 0; i < L->qtde; i++)
    {
        printf("%d ", L->elementos[i]);
    }
    printf("\n");
}

void iniciar(lista *L){
    L->cap = 10;
    L->qtde = 0;
}

lista impares(lista *L){
    lista impar;
    iniciar(&impar);
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i]%2 == 1)
        {
            inserir_inicio(&impar, L->elementos[i]);
        }
    }
    return impar;
}

bool inserir_final(lista *L, int item){
    if (!cheia(L))
    {
        L->elementos[L->qtde] = item;
        L->qtde++;
        return true;
    }
    return false;
}

bool inserir_inicio(lista *L, int item){
    if (!cheia(L))
    {
        for (int i = L->qtde; i > 0; i--)
        {
            L->elementos[i] = L->elementos[i - 1];
        }
        L->elementos[0] = item;
        L->qtde++;
        return true;
    }
    return false;
}

bool inserir_meio(lista *L, int item, int posicao){
    if (!cheia(L))
    {
        for (int i = L->qtde; i > posicao - 1; i--)
        {
            L->elementos[i] = L->elementos[i - 1];
        }
        L->elementos[posicao - 1] = item;
        L->qtde++;
        return true;
    }
    return false;
}

int menores(lista *L, int v){
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

void ordenar_cresc(lista *L){
    for (int i = 0; i < L->qtde - 1; i++)
    {
        for (int j = 0; j < L->qtde -1 - i; j++)
        {
            if (L->elementos[j] > L->elementos[j + 1])
            {
                int aux = L->elementos[j];
                L->elementos[j] = L->elementos[j + 1];
                L->elementos[j + 1] = aux;
            }
        }
    }
}

void ordenar_decresc(lista *L){
    for (int i = 0; i < L->qtde - 1; i++)
    {
        for (int j = 0; j < L->qtde -1 - i; j++)
        {
            if (L->elementos[j] < L->elementos[j + 1])
            {
                int aux = L->elementos[j];
                L->elementos[j] = L->elementos[j + 1];
                L->elementos[j + 1] = aux;
            }
        }
    }
}

lista pares(lista *L){
    lista par;
    iniciar(&par);
    for (int i = 0; i < L->qtde; i++)
    {
        if (L->elementos[i]%2 == 0)
        {
            inserir_inicio(&par, L->elementos[i]);
        }
    }
    return par;
}

bool remov_final(lista *L){
    if (!vazia(L))
    {
        L->qtde--;
        return true;
    }
    return false;
}

bool remov_inicio(lista *L){
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

bool remov_meio(lista *L, int posicao){
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

int tamanho(lista *L){
    return L->qtde + 1;
}

bool vazia(lista *L){
    if (L->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}