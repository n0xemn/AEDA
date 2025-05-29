#include "minha_lista_ancadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct lista_enc
{
    int qtde;
    celula* prim;
};

struct celula
{
    int valor;
    celula* prox;
};

lista_enc* iniciar(){
    lista_enc * L_enc = (lista_enc*) malloc(sizeof(lista_enc));
    if (L_enc != NULL)
    {
        L_enc->qtde = 0;
        L_enc->prim = NULL;
    }
    return L_enc;
}

bool inserir_inicio(lista_enc* L_enc, Item dado){
    celula* nova_celula = (celula*) malloc(sizeof(celula));
    if (nova_celula == NULL)
    {
        return false;
    }
    nova_celula->valor = dado;
    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    return true;
}

bool inserir_fim(lista_enc* L_enc){
    if (!L_enc)
    {
        return false;
    }
                     
    celula* celula_nova = (celula*) malloc(sizeof(celula));
    if (celula_nova ==NULL)
    {
        return false;
    }
    
    celula* celula_auxiliar = L_enc->prim;
    for (int i = 1; i <= L_enc->qtde; i++)
    {
        if (celula_auxiliar->prox == NULL)
        {
            celula_auxiliar->prox = celula_nova;
            L_enc->qtde++;
            return true;
        }
        celula_auxiliar = celula_auxiliar->prox;
    }
    L_enc->prim = celula_nova;
    L_enc->qtde++;
    return true;
}

void remover_comeco(lista_enc* L_enc){
    celula* aux = L_enc->prim;
    if (aux != NULL)
    {
        L_enc->prim = aux->prox;
        L_enc->qtde--;
    }
    free(aux);
}

int tamanho(lista_enc* L_enc){
    return L_enc->qtde;
}

bool vazia(lista_enc* L_enc){
    if (L_enc->qtde == 0)
    {
        return true;
    }
    return false;
}

void remover_meio(lista_enc* L_enc, int posicao){
    if (L_enc || !vazia(L_enc) || posicao <= L_enc->qtde || posicao > 0)
    {
        celula* aux_prox = L_enc->prim;
        celula* aux_ant;
        if (posicao > 1)
        {
            for (int i = 1; i < posicao; i++)
            {
                aux_ant = aux_prox;
                aux_prox = aux_prox->prox;
            }
            aux_ant->prox = aux_prox->prox;
            free(aux_prox);
            L_enc->qtde--;
            return;
        }
        L_enc->prim = aux_prox->prox;
        free(aux_prox);
        L_enc->qtde--;
    }
}