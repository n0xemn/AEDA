#include "minha_lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct lista_enc
{
    int qtde;
    celula* prim;
};

struct celula
{
    Item valor;
    celula* prox;
};

int busca_por_item(lista_enc* L_enc, Item it){
    if (L_enc == NULL || vazia(L_enc))
    {
        return 0;
    }
    
    int i = 1;
    celula* cel_aux = L_enc->prim;
    while (cel_aux != NULL)
    {
        if (cel_aux->valor == it)
        {
            return i;
        }
        cel_aux = cel_aux->prox;
        i++;
    }
    return 0;
}

Item busca_por_posicao(lista_enc* L_enc, int posi){
    if (L_enc == NULL || vazia(L_enc))
    {
        return 0;
    }
    
    int i = 1;
    celula* cel_aux = L_enc->prim;
    while (cel_aux != NULL)
    {
        if (i == posi)
        {
            return cel_aux->valor;
        }
        cel_aux = cel_aux->prox;
        i++;
    }
    return 0;
}

static celula* criar_celula(Item it){
    // pra deixar funcoes fazendo uma coisa especifica. toda vez que precisar criar uma celula nova eh soh chamar essa funcao
    // "static" quer dizer que a funcao soh pode ser usada no arquivo em que ela ta.
    celula* nova = (celula*) calloc(1, sizeof(celula));
    if (nova == NULL)
    {
        return NULL;
    }
    nova->valor = it; 
    return nova;
}

bool esvaziar(lista_enc* L_enc){
    if (L_enc == NULL || L_enc->qtde == 0)
    {
        return false;
    }
    
    while (L_enc->qtde != 0)
    {
        remover_comeco(L_enc);
    }
    return true;
}

void exibir(lista_enc* L_enc){
    if (L_enc == NULL || vazia(L_enc))
    {
        return;
    }
    
    celula* aux = L_enc->prim;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

lista_enc* iniciar(){
    lista_enc* L_enc = (lista_enc*) calloc(1, sizeof(lista_enc));  
    if (L_enc == NULL)
    {
        return NULL;
    }
    return L_enc;
}

bool inserir_fim(lista_enc* L_enc, Item it){
    if (L_enc == NULL)
    {
        return false;
    }
                     
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    
    celula* celula_auxiliar = L_enc->prim;
    for (int i = 1; i <= L_enc->qtde; i++)
    {
        if (celula_auxiliar->prox == NULL)
        {
            celula_auxiliar->prox = nova_celula;
            L_enc->qtde++;
            return true;
        }
        celula_auxiliar = celula_auxiliar->prox;
    }
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    return true;
}

bool inserir_inicio(lista_enc* L_enc, Item it){
    if (L_enc == NULL)
    {
        return false;
    }
    
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }

    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    return true;
}

bool inserir_meio(lista_enc* L_enc, Item it, int posicao){
    if (L_enc == NULL || vazia(L_enc || posicao <= 0 || posicao > L_enc->qtde))
    {
        return false;
    }
    
    celula* aux_prox = L_enc->prim;
    celula* aux_ant;
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    
    if (posicao > 1)
    {
        for (int i = 1; i < posicao; i++)
        {
            aux_ant = aux_prox;
            aux_prox = aux_prox->prox;
        }
        nova_celula->prox = aux_prox;
        aux_ant->prox = nova_celula;
        L_enc->qtde++;
        return true;
    } 

    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    
    return true;
}

lista_enc* liberar(lista_enc* L_enc){
    if (L_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(L_enc);
    free(L_enc);
    return NULL;
}

void ordenar(lista_enc* L_enc){
    if (L_enc == NULL || vazia(L_enc))
    {
        return;
    }
    
    for (int i = 1; i < L_enc->qtde; i++)
    {
        celula* cel_aux = L_enc->prim;

        for (int j = 1; j < L_enc->qtde + 1 - i; j++)
        {
            Item valor_aux = cel_aux->valor;
            if (valor_aux > cel_aux->prox->valor)
            {
                cel_aux->valor = cel_aux->prox->valor;
                cel_aux->prox->valor = valor_aux;
            }
            cel_aux = cel_aux->prox;
        }
    }
}

bool remover_comeco(lista_enc* L_enc){
    if (L_enc == NULL || vazia(L_enc))
    {
        return false;
    }
    
    celula* aux = L_enc->prim;
    L_enc->prim = aux->prox; 
    L_enc->qtde--;
    free(aux);
    return true;
}

bool remover_meio(lista_enc* L_enc, int posicao){
    if (L_enc == NULL || vazia(L_enc) || posicao <= 0 || posicao > L_enc->qtde)
    {
        return false;
    }
    
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
        return true;
    }
    L_enc->prim = aux_prox->prox;
    free(aux_prox);
    L_enc->qtde--;
    return true; 
}

bool remover_fim(lista_enc* L_enc){
    if (L_enc == NULL || vazia(L_enc))
    {
        return false;
    }
    
    celula* aux = L_enc->prim;
    if (aux->prox == NULL)
    {
        free(aux);
        L_enc->prim == NULL;
    }
    
    while (aux->prox->prox != NULL)
    {
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox == NULL;
    L_enc->qtde--;
    return true;
}

int tamanho(lista_enc* L_enc){
    if (L_enc == NULL)
    {
        return 0;
    }
    return L_enc->qtde;
}

bool vazia(lista_enc* L_enc){    
    if (L_enc->qtde == 0)
    {
        return true;
    }
    return false;
}
