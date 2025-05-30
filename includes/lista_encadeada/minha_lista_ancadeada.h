#ifndef MINHA_LISTA_ENCADEADA
#define MINHA_LISTA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct lista_enc lista_enc;
typedef struct celula celula;

/*

*/
int busca(lista_enc* L_enc, Item it);
/*

*/
bool esvaziar(lista_enc* L_enc);
/*

*/
void exibir(lista_enc* L_enc);
/*

*/
lista_enc* iniciar();
/*

*/
bool inserir_fim(lista_enc* L_enc, Item it);
/*

*/
bool inserir_inicio(lista_enc* L_enc, Item it);
/*

*/
bool inserir_meio(lista_enc* L_enc, Item it, int posicao);
/*

*/
lista_enc* liberar(lista_enc* L_enc);
/*

*/
void ordenar(lista_enc* L_enc);
/*

*/
bool remover_comeco(lista_enc* L_enc);
/*

*/
bool remover_meio(lista_enc* L_enc, int posicao);
/*

*/
bool remover_fim(lista_enc* L_enc);
/*

*/
int tamanho(lista_enc* L_enc);
/*

*/
bool vazia(lista_enc* L_enc);

#endif
