#ifndef MINHA_LISTA_ENCADEADA
#define MINHA_LISTA_ENCADEADA

#include <stdbool.h>

typedef int Item;

typedef struct lista_enc lista_enc;
typedef struct celula celula;

/*
O que faz: Busca a posicao em que o item desejado esta.
Entrada: Uma lista e o item.
Saida: A posicao na lista do item escolhido.
*/
int busca_por_item(lista_enc* L_enc, Item it);
/*
O que faz: Busca o item da posicao idicada.
Entrada: Uma lista e a posicao do item
Saida: O item na posicao indicada
*/
Item busca_por_posicao(lista_enc* L_enc, int posi);
/*
O que faz: Remove todos os elementos da lista.
Entrada: Uma lista.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool esvaziar(lista_enc* L_enc);
/*
O que faz: Exibe todos os elementos da lista.
Entrada: Uma lista.
Saida: Nao tem.
*/
void exibir(lista_enc* L_enc);
/*
O que faz: Inicia sua lista.
Entrada: Nao tem.
Saida: Uma lista criada (use ponteiro)
*/
lista_enc* iniciar();
/*
O que faz: Insere um item no final da lista.
Entrada: Uma lista e um item.
Saida: Um valor boleano que indica se deu certo ou nao.
*/
bool inserir_fim(lista_enc* L_enc, Item it);
/*
O que faz: Insere um item no comeco da lista.
Entrada: Uma lista e um item.
Saida: Um valor boleano que indica se deu certo ou nao.
*/
bool inserir_inicio(lista_enc* L_enc, Item it);
/*
O que faz: Insere um item na posicao da lista escolhida.
Entrada: Uma lista, um item e uma posicao.
Saida: Um valor boleano que indica se deu certo ou nao.
*/
bool inserir_meio(lista_enc* L_enc, Item it, int posicao);
/*
O que faz: Libera a sua lista.
Entrada: Uma lista.
Saida: NULL.
*/
lista_enc* liberar(lista_enc* L_enc);
/*
O que faz: Ordena sua lista em ordem crescente.
Entrada: Uma lista.
Saida: Nao tem.
*/
void ordenar(lista_enc* L_enc);
/*
O que faz: Remove o item do comeco da lista.
Entrada: Uma lista.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool remover_comeco(lista_enc* L_enc);
/*
O que faz: Remove o item da posicao da lista escolhida.
Entrada: Uma lista e uma posicao.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool remover_meio(lista_enc* L_enc, int posicao);
/*
O que faz: Remove o item do fim da lista.
Entrada: Uma lista.
Saida: Um valor boleano indicando se deu certo ou nao.
*/
bool remover_fim(lista_enc* L_enc);
/*
O que faz: Da o tamano da lista.
Entrada: Uma lista.
Saida: O tamano da lista.
*/
int tamanho(lista_enc* L_enc);
/*
O que faz: Verifica se a lista esta vazia ou nao.
Entrada: Uma lista.
Saida: Um valor boleano indicando se esta vazia ou nao.
*/
bool vazia(lista_enc* L_enc);

#endif
