#ifndef MINHA_LISTA_ENCADEADA
#define MINHA_LISTA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct lista_enc lista_enc;
typedef struct celula celula;

lista_enc* iniciar();

void inserir_inicio(lista_enc* L_enc, Item dado);
bool inserir_fim(lista_enc* L_enc);
void remover_comeco(lista_enc* L_enc);
void remover_meio(lista_enc* L_enc, int posicao);
int tamanho(lista_enc* L_enc);
bool vazia(lista_enc* L_enc);



#endif