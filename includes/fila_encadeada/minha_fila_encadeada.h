#ifndef MINHA_FILA_ENCADEADA
#define MINHA_FILA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct fila_enc fila_enc;
typedef struct celula celula;

// a ideia vai ser, colocar no começo e tirar no final

/*
O que faz: Esvazia a sua fila.
Entrada: Uma fila.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool esvaziar(fila_enc* F_enc);
/*
O que faz: Da o valor da frente da fila.
Entrada: Uma fila.
Saida: O valor da frente da fila.
*/
int front(fila_enc* F_enc);
/*
O que faz: Inicia sua fila.
Entrada: Nao tem.
Saida: Uma fila iniciada (use ponteiro).
*/
fila_enc* iniciar();
/*
O que faz: Insere um item no final da fila.
Entrada: Uma fila e um item.
Saida: Um valor boleano indicando se deu certo ou nao. 
*/
bool inserir(fila_enc* F_enc, Item it);
/*
O que faz: Libera a sua fila.
Entrada: Uma fila.
Saida: NULL.
*/
fila_enc* liberar(fila_enc* F_enc);
/*
O que faz: Remove o Item da frente da fila.
Entrada: Uma fila.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool remover(fila_enc* F_enc);
/*
O que faz: Da o tamanho da fila.
Entrada: Uma fila.
Saida: O tamanho da fila.
*/
int tamanho(fila_enc* F_enc);
/*
O que faz: Verifica se a fila esta vazia.
Entrada: Uma fila.
Saida: Um valor boleano indicando se a fila esta vazia ou nao.
*/
bool vazia(fila_enc* F_enc);

#endif