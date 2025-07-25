#include "minha_pilha_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha_enc
{
    celula* prim;
};

struct celula
{
    Item valor;
    celula* prox;
};

static celula* criar_celula(Item it){
    celula* nova = (celula*) calloc(1, sizeof(celula));
    if (nova == NULL)
    {
        return NULL;
    }
    nova->valor = it; 
    return nova;
}

bool esvaziar(pilha_enc* P_enc){
    if (P_enc == NULL || vazia(P_enc))
    {
        return false;
    }
    
    while (P_enc->prim != NULL)
    {
        remover(P_enc);
    }
    return true;
}

pilha_enc* iniciar(){
    pilha_enc* P_enc = (pilha_enc*) calloc(1, sizeof(pilha_enc)); 
    if (P_enc == NULL)
    {
        return NULL;
    }
    return P_enc;
}

bool inserir(pilha_enc* P_enc, Item it){
    if (P_enc == NULL)
    {
        return false;
    }
    
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }

    nova_celula->prox = P_enc->prim;
    P_enc->prim = nova_celula;
    return true;
}

pilha_enc* liberar(pilha_enc* P_enc){
    if (P_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(P_enc);
    free(P_enc);
    return NULL;
}

bool remover(pilha_enc* P_enc){
    if (P_enc == NULL)
    {
        return false;
    }
    
    celula* aux = P_enc->prim; 
    P_enc->prim = aux->prox;
    free(aux);
    return true;
}

int tamanho(pilha_enc* P_enc){
    if (P_enc == NULL || vazia(P_enc))
    {
        return 0;
    }

    celula* cel_aux = P_enc->prim;
    int quant = 1;
    while (cel_aux->prox != NULL)
    {
        quant++;
        cel_aux = cel_aux->prox;
    }

    return quant;
}

int top(pilha_enc* P_enc){
    if (P_enc == NULL || vazia(P_enc))
    {
        return 0;
    }

    return P_enc->prim->valor;
}

bool vazia(pilha_enc* P_enc){
    if (P_enc->prim == NULL)
    {
        return true;
    }
    
    return false;
}