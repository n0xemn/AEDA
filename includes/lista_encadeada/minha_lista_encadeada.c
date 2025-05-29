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

int busca(lista_enc* L_enc, Item it){
    if (L_enc ==NULL)
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

static celula* criar_celula(Item it){
    // pra deixar funcoes fazendo uma coisa especifica. toda vez que precisar criar uma celula nova eh soh chamar essa funcao
    // e "static" quer dizer que a funcao soh pode ser usada no arquivo em que ela ta.
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
    if (L_enc == NULL)
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
    lista_enc * L_enc = (lista_enc*) calloc(1, sizeof(lista_enc)); // mudei pra calloc pra nao te que colocar que qtde e prim recebem 0 ou null 
    if (L_enc == NULL)
    {
        return NULL;
    }
    return L_enc;
}

bool inserir_fim(lista_enc* L_enc, Item it){
    if (!L_enc)
    {
        return false;
    }
                     
    //celula* celula_nova = (celula*) malloc(sizeof(celula));
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
    L_enc->prim = nova_celula; // poderia usar a funcao de inserir no inicio, mas eu teria que medar mais coisae o com preguica
    L_enc->qtde++;
    return true;
}

bool inserir_inicio(lista_enc* L_enc, Item it){
    //celula* nova_celula = (celula*) malloc(sizeof(celula)); //mudar
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    //nova_celula->valor = it;
    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    return true;
}

bool inserir_meio(lista_enc* L_enc, Item it, int posicao){
    if (L_enc || !vazia(L_enc) || posicao <= L_enc->qtde || posicao > 0)
    {
        celula* aux_prox = L_enc->prim;
        celula* aux_ant;
        celula* cel_aux = criar_celula(it);
        if (cel_aux == NULL)
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
            cel_aux->prox = aux_prox;
            aux_ant->prox = cel_aux;
            L_enc->qtde++;
            return true;
        } 
        cel_aux->prox = L_enc->prim;
        L_enc->prim = cel_aux;
        L_enc->qtde++;
        return true;
    }
    return false;
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

bool remover_comeco(lista_enc* L_enc){
    celula* aux = L_enc->prim; // a logica estava errada
    if (aux != NULL)
    {
        L_enc->prim = aux->prox;
        L_enc->qtde--;
        free(aux);
        return true;
    }
    return false;
}

bool remover_meio(lista_enc* L_enc, int posicao){
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
            return true;
        }
        L_enc->prim = aux_prox->prox;
        free(aux_prox);
        L_enc->qtde--;
        return true;
    }
    return false;
}

bool remover_fim(lista_enc* L_enc){
    if (L_enc == NULL)
    {
        return false;
    }
    
    celula* aux = L_enc->prim;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    free(aux);
    L_enc->qtde--;
    return true;
}

int tamanho(lista_enc* L_enc){
    if (L_enc == NULL) // perguntar ele se eu devia dar um exit aqui se nao tiver uma lista iniciada
    {
        return NULL;
    }
    return L_enc->qtde;
}

bool vazia(lista_enc* L_enc){
    if (L_enc->qtde == 0) // perguntar ele se eu devia dar um exit aqui se nao tiver uma lista iniciada
    {
        return true;
    }
    return false;
}