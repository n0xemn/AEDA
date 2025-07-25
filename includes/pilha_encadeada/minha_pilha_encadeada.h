#ifndef MINHA_PILHA_ENCADEADA
#define MINHA_PILHA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct pilha_enc pilha_enc;
typedef struct celula celula;

/*
O que faz: Esvazia sua pilha.
Entrada: Uma pilha.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool esvaziar(pilha_enc* P_enc);
/*
O que faz: Inicia a pilha.
Entrada: Nao tem.
Saida: Uma pilha iniciada (usar ponteiro).
*/
pilha_enc* iniciar();
/*
O que faz: Insere o item no topo da pilha.
Entrada: Uma pilha e um item.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool inserir(pilha_enc* P_enc, Item it);
/*
O que faz: Libera a pilha.
Entrada: Uma pilha.
Saida: NULL.
*/
pilha_enc* liberar(pilha_enc* P_enc);
/*
O que faz: Remove o item do topo da pilha.
Entrada: Uma pilha.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool remover(pilha_enc* P_enc);
/*
O que faz: Da o tamanho da pilha.
Entrada: Uma pilha.
Saida: O tamanho da pilha.
*/
int tamanho(pilha_enc* P_enc);
/*
O que faz: Da o elemento do topo da pilha.
Entrada: Uma pilha.
Saida: O item que esta no topo da pilha (se a pilha estiver vazia ou se ela nao existir, vai retornar o valor 0).
*/
int top(pilha_enc* P_enc);
/*
O que faz: Indica se a pilha esta vazia.
Entrada: Uma pilha.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool vazia(pilha_enc* P_enc);

#endif