#ifndef MINHA_FILA_ENCADEADA
#define MINHA_FILA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct fila_enc fila_enc;
typedef struct celula celula;

// a ideia vai ser, colocar no começo e tirar no final (parece mais facil)

/*

*/
bool esvaziar(fila_enc* L_enc);
/*

*/
int front(fila_enc* L_enc);
/*

*/
fila_enc* iniciar();
/*

*/
bool inserir(fila_enc* L_enc, Item it);
/*

*/
fila_enc* liberar(fila_enc* L_enc);
/*

*/
bool remover(fila_enc* L_enc);
/*

*/
int tamanho(fila_enc* L_enc);
/*

*/
bool vazia(fila_enc* L_enc);

#endif