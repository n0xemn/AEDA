#include <stdio.h>
#include <stdlib.h>
#include "arv-bi-bu.h"
#include "minha_fila_encadeada.h"

struct arvore_bin{
    Item_arv valor;
    arvore_bin* SAE;
    arvore_bin* SAD;
};

Item_arv maior_esquerda(arvore_bin* arv);

arvore_bin* criar_arv(Item_arv it){
    arvore_bin* aux = (arvore_bin*) calloc(1, sizeof(arvore_bin));
    if (aux != NULL)
    {
        aux->valor= it;
    }
    return aux;
}

void pre_ordem(arvore_bin* arv){
    if (arv == NULL)
    { 
        return;
    }
    printf("%d ", arv->valor);
    pre_ordem(arv->SAE);
    pre_ordem(arv->SAD);
}

void em_ordem(arvore_bin* arv){
    if (arv == NULL)
    { 
        return;
    }
    em_ordem(arv->SAE);
    printf("%d ", arv->valor);
    em_ordem(arv->SAD);
}

void pos_ordem(arvore_bin* arv){
    if (arv == NULL)
    { 
        return;
    }
    pos_ordem(arv->SAE);
    pos_ordem(arv->SAD);
    printf("%d ", arv->valor);
}

void largura(arvore_bin* arv){
    fila_enc* fila = iniciar();
    if (fila == NULL){
        return;
    }
    if (arv == NULL)
    {
        free(fila);
        return;
    }
    inserir(fila, arv);
    arvore_bin* aux;  
    while (tamanho(fila) != 0)
    {
        aux = front(fila);
        remover(fila);
        printf("%d ", aux->valor);
        if (aux->SAE != NULL)
        {
            inserir(fila, aux->SAE);
        }
        if (aux->SAD != NULL)
        {
            inserir(fila, aux->SAD);
        }
    }
}

arvore_bin* inserir_arv(arvore_bin* arv, Item_arv it){
    if (arv == NULL)
    {
        return NULL;
    }
    else if (it <= arv->valor)
    {
        if (arv->SAE == NULL)
        {
            arv->SAE = criar_arv(it);
        }
        else
        {
            inserir_arv(arv->SAE, it);
        }
    }
    else
    {
        if (arv->SAD == NULL)
        {
            arv->SAD = criar_arv(it);
        }
        else
        {
            inserir_arv(arv->SAD, it);
        }
    }
}

arvore_bin* remover_arv(arvore_bin* arv, Item_arv it){
    if (arv == NULL)
    {
        return NULL;
    }
    else if (it < arv->valor)
    {
        arv->SAE = remover_arv(arv->SAE, it);
    }
    else if (it > arv->valor)
    {
        arv->SAD = remover_arv(arv->SAD, it);
    }
    else
    {
        if (arv->SAE == NULL && arv->SAD == NULL)
        {
            free(arv);
            return NULL;
        }
        else if (arv->SAE == NULL)
        {
            arvore_bin* aux = arv->SAD;
            free(arv);
            return aux;
        }
        else if(arv->SAD == NULL)
        {
            arvore_bin* aux = arv->SAD;
            free(arv);
            return aux;
        }
        else
        {
            arv->valor = maior_esquerda(arv->SAE);
            return arv;
        }
    }
}

Item_arv maior_esquerda(arvore_bin* arv){
    if (arv->SAD != NULL)
    {
        return maior_esquerda(arv->SAD);
    }
    else
    {
        Item_arv aux = arv->valor;
        remover_arv(arv, aux);
        return aux;
    }
}

bool busca_arv(arvore_bin* arv, Item_arv it){
    if (arv == NULL)
    {
        return false;
    }
    else if (it <= arv->valor)
    {
        return busca_arv(arv->SAE, it);
    }
    else
    {
        return busca_arv(arv->SAD, it);
    }
}

int qtde_folhas(arvore_bin* arv){
    int qtde = 0;
    fila_enc* fila = iniciar();
    if (fila == NULL){
        return 0;
    }
    if (arv == NULL)
    {
        free(fila);
        return 0;
    }
    inserir(fila, arv);
    arvore_bin* aux;  
    while (tamanho(fila) != 0)
    {
        aux = front(fila);
        remover(fila);
        if (aux->SAE == NULL && aux->SAD == NULL)
        {
            qtde++;
        }
        if (aux->SAE != NULL)
        {
            inserir(fila, aux->SAE);
        }
        if (aux->SAD != NULL)
        {
            inserir(fila, aux->SAD);
        }
    }
    return qtde;
}

int qtde_pares(arvore_bin* arv){
    int qtde = 0;
    if (arv == NULL)
    { 
        return 0;
    }

    qtde += qtde_pares(arv->SAE);
    qtde += qtde_pares(arv->SAD);
    
    if (arv->valor%2 == 0)
    {
        qtde++;
    }
    return qtde;
}

int qtde_internos_aux(arvore_bin* arv){
    int qtde = 0;
    if (arv == NULL)
    { 
        return 0;
    }

    if (arv->SAE != NULL || arv->SAD != NULL)
    {
        qtde++;
    }

    qtde += qtde_internos_aux(arv->SAE);
    qtde += qtde_internos_aux(arv->SAD);
    
    return qtde;
}

int qtde_internos(arvore_bin* arv){
    return qtde_internos_aux(arv) - 1;
}

void exibir_inverso(arvore_bin* arv){
    if (arv == NULL)
    { 
        return;
    }
    exibir_inverso(arv->SAD);
    printf("%d ", arv->valor);
    exibir_inverso(arv->SAE);
}

arvore_bin* liberar_arv(arvore_bin* arv){
    fila_enc* fila = iniciar();
    if (fila == NULL){
        return NULL;
    }
    if (arv == NULL)
    {
        free(fila);
        return NULL;
    }
    inserir(fila, arv);
    arvore_bin* aux;  
    while (tamanho(fila) != 0)
    {
        aux = front(fila);
        remover(fila);
        if (aux->SAE != NULL)
        {
            inserir(fila, aux->SAE);
        }
        if (aux->SAD != NULL)
        {
            inserir(fila, aux->SAD);
        }
        free(aux);
    }
    return NULL;
}