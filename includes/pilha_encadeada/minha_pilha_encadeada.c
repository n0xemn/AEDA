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

bool esvaziar(pilha_enc* P_enc){
    if (P_enc == NULL || P_enc->prim == NULL)
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
    pilha_enc * P_enc = (pilha_enc*) calloc(1, sizeof(pilha_enc)); // mudei pra calloc pra nao te que colocar que qtde e prim recebem 0 ou null 
    if (P_enc == NULL)
    {
        return NULL;
    }
    return P_enc;
}

bool inserir(pilha_enc* P_enc, Item it){
    //celula* nova_celula = (celula*) malloc(sizeof(celula)); //mudar
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    //nova_celula->valor = it;
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
    celula* aux = P_enc->prim; // a logica estava errada
    if (aux != NULL)
    {
        P_enc->prim = aux->prox;
        free(aux);
        return true;
    }
    return false;
}

int tamanho(pilha_enc* P_enc){
    if (P_enc == NULL || P_enc->prim == NULL)
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
    if (P_enc == NULL)
    {
        printf("Pilha nao iniciada.");
        return 0;
    }
    if (P_enc->prim == NULL)
    {
        printf("Pilha vazia.");
        return 0;
    }
    return P_enc->prim->valor;
}

bool vazia(pilha_enc* P_enc){
    if (P_enc->prim == NULL) // perguntar ele se eu devia dar um exit aqui se nao tiver uma lista iniciada
    {
        return true;
    }
    return false;
}