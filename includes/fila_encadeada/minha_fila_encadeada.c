#include "minha_fila_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct fila_enc
{
    int qtde; // tentar fazer sem o  qtde
    celula* prim;
};

struct celula
{
    Item valor;
    celula* prox;
};

static celula* criar_celula(Item it){ // certo/pronto
    celula* nova = (celula*) calloc(1, sizeof(celula));
    if (nova == NULL)
    {
        return NULL;
    }

    nova->valor = it; 
    return nova;
}

bool esvaziar(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        return false;
    }
    
    while (L_enc->prim != NULL)
    {
        remover(L_enc);
    }
    return true;
}

int front(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        printf("Sem elemento a ser exibido");
        return 0;
    }

    return L_enc->prim->valor;
}

fila_enc* iniciar(){ // certo/pronto
    fila_enc* L_enc = (fila_enc*) calloc(1, sizeof(fila_enc));
    if (L_enc == NULL)
    {
        return NULL;
    }

    return L_enc;
}

bool inserir(fila_enc* L_enc, Item it){ // certo/pronto
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }

    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    return true;
}

fila_enc* liberar(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(L_enc);
    free(L_enc);
    return NULL;
}

bool remover(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        return false;
    }
    
    celula* aux = L_enc->prim;
    if (aux->prox == NULL)
    {
        L_enc->prim = NULL;
        free(aux);
        return true;
    }
    while (true)
    {
        if (aux->prox->prox == NULL)
        {
            free(aux->prox);
            aux->prox == NULL;
            return true;
        }
        aux = aux->prox; // ta feio, mas funciona
    }
}

int tamanho(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL)
    {
        printf("Fila nao inciada.");
        return 0;
    }
    int quant = 0;
    celula* aux = L_enc->prim;
    while (aux != NULL)
    {
        quant++;
        aux = aux->prox;
    }
    return quant;
}

bool vazia(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL)
    {
        printf("Fila, nao iniciada.");
        return false;
    }
    
    if (L_enc->prim == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// eu deveria fazer uma de verificar se estah vazia ???