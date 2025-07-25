#ifndef ARV_BI_BU
#define ARV_BI_BU
#include <stdbool.h>

typedef int Item_arv;

typedef struct arvore_bin arvore_bin;

/*
oq faz: cria uma arvore;
entrada: um elemento.
saida: uma arvore;
*/
arvore_bin* criar_arv(Item_arv it);
/*
oq faz: faz uma busca em em-ordem.
entrada: uma arvore.
saida: nao tem.
*/
void em_ordem(arvore_bin* arv);
/*
oq faz: faz uma busca em pre-ordem.
entrada: uma arvore.
saida: nao tem.
*/
void pre_ordem(arvore_bin* arv);
/*
oq faz: faz uma busca em pos-ordem.
entrada: uma arvore.
saida: nao tem.
*/
void pos_ordem(arvore_bin* arv);
/*
oq faz: faz uma busca em largura.
entrada: uma arvore.
saida: nao tem.
*/
void largura(arvore_bin* arv);
/*
oq faz: Insere um elemento.
entrada: uma arvore e um item.
saida: nao tem.
*/
arvore_bin* inserir_arv(arvore_bin* arv, Item_arv it);
/*
oq faz: remove um item da arvore.
entrada: uma arvore e um item.
saida: um ponteiro pra arvore modificada, nao precisa fazer sua arvore receber o return dessa funcao.
*/
arvore_bin* remover_arv(arvore_bin* arv, Item_arv it);
/*
oq faz: verifica se o numero dado esta na arvore.
entrada: uma arvore e um item.
saida: uma resposta boleana, true se esta e false se nao esta.
*/
bool busca_arv(arvore_bin* arv, Item_arv it);

arvore_bin* liberar_arv(arvore_bin* arv);


int qtde_folhas(arvore_bin* arv);
int qtde_pares(arvore_bin* arv);
int qtde_internos(arvore_bin* arv); //usar maximo menos 1. pq ra iz nao e
void exibir_inverso(arvore_bin* arv);

#endif