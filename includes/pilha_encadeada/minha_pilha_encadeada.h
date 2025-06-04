#ifndef MINHA_PILHA_ENCADEADA
#define MINHA_PILHA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct pilha_enc pilha_enc;
typedef struct celula celula;

/*

*/
bool esvaziar(pilha_enc* P_enc);
/*

*/
pilha_enc* iniciar();
/*

*/
bool inserir(pilha_enc* P_enc, Item it);
/*

*/
pilha_enc* liberar(pilha_enc* P_enc);
/*

*/
bool remover(pilha_enc* P_enc);
/*

*/
int tamanho(pilha_enc* P_enc);
/*

*/
int top(pilha_enc* P_enc);
/*

*/
bool vazia(pilha_enc* P_enc);

#endif