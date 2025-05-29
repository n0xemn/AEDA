#include <stdio.h>
#include <stdlib.h>
#include "minha_pilha.h"

struct pilha
{
    int cap, qtde;
    int* elementos;    
};

int capacidade(pilha *L){
    return L->cap;
}

bool cheia(pilha *L){
    if (L->qtde >= L->cap)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pilha * iniciar(int cap){
    pilha* list_aux = (pilha*) malloc(sizeof(pilha));
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

bool inserir(pilha *L, int item){
    if (!cheia(L))
    {
        L->elementos[L->qtde] = item;
        L->qtde++;
        return true;
    }
    return false;
}

void liberar(pilha** L){
    free((*L)->elementos);
    free(*L);
    *L = NULL;
}

bool remover(pilha *L){
    if (!vazia(L))
    {
        L->qtde--;
        return true;
    }
    return false;
}

int tamanho(pilha *L){
    return L->qtde + 1;
}

int top(pilha * P){
    return P->elementos[P->qtde -1];
}

bool vazia(pilha *L){
    if (L->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}