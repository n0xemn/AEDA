#include "minha_fila_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct fila_enc
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

bool esvaziar(fila_enc* F_enc){ 
    if (F_enc == NULL || F_enc->prim == NULL)
    {
        return false;
    }
    
    while (F_enc->prim != NULL)
    {
        remover(F_enc);
    }
    return true;
}

int front(fila_enc* F_enc){
    if (F_enc == NULL || vazia(F_enc))
    {
        printf("Sem elemento a ser exibido");
        return 0;
    }
    celula* aux = F_enc->prim;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    return aux->valor;
}

fila_enc* iniciar(){ 
    fila_enc* F_enc = (fila_enc*) calloc(1, sizeof(fila_enc));
    if (F_enc == NULL)
    {
        return NULL;
    }

    return F_enc;
}

bool inserir(fila_enc* F_enc, Item it){
    if (F_enc == NULL)
    {
        return false;
    }
    
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }

    nova_celula->prox = F_enc->prim;
    F_enc->prim = nova_celula;
    return true;
}

fila_enc* liberar(fila_enc* F_enc){
    if (F_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(F_enc);
    
    free(F_enc);
    return NULL;
}

bool remover(fila_enc* F_enc){
    if (F_enc == NULL || vazia(F_enc))
    {
        return false;
    }
    
    celula* aux_ant = F_enc->prim;
    if (aux_ant->prox == NULL)
    {
        F_enc->prim = NULL;
        free(aux_ant);
        return true;
    }

    celula* aux_pro = aux_ant->prox;
    while (aux_pro->prox != NULL)
    {
        aux_ant = aux_pro;
        aux_pro = aux_pro->prox;
    }
    aux_ant->prox = NULL;
    free(aux_pro);
    return true;
}

int tamanho(fila_enc* F_enc){
    if (F_enc == NULL)
    {
        printf("Fila nao inciada.");
        return 0;
    }

    int quant = 0;
    celula* aux = F_enc->prim;
    while (aux != NULL)
    {
        quant++;
        aux = aux->prox;
    }
    return quant;
}

bool vazia(fila_enc* F_enc){
    if (F_enc == NULL)
    {
        printf("Fila, nao iniciada.");
        return false;
    }
    
    if (F_enc->prim == NULL)
    {
        return true;
    }

    return false;
}