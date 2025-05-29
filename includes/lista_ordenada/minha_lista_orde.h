#ifndef MINHA_lista_ORDE
#define MINHA_lista_ORDE

/*
gcc -c nome_arquivo_biblioteca.c : pra executar o arquivo c da biblioteca
gcc nome_do_arquivo.c pasta/nome_arquivo_biblioteca.o -o noome_que_vc_quer : pra executar o arquivo com a biblioteca

*/

#include <stdbool.h>

/*
Use ponteiro pra criar uma lista_orde
*/
typedef struct lista_orde lista_orde;

/*
O que faz: Retorna a posicao do elemento dado.
Entrada: Uma lista_orde e um elemento.
Saida: Posicao do elemento na lista_orde.
*/
int busca(lista_orde *L, int item);
/*
O que faz: Fala a capacidade total da lista_orde.
Entrada: Uma lista_orde.
Saida: A capacidade total da lista_orde.
*/
int capacidade(lista_orde *L);
/*
O que faz: Fala se a lista_orde esta cheio.
Entrada: Uma lista_orde.
Saida: Um valor boleano (sim/nao). 
*/
bool cheia(lista_orde *L);
/*
O que faz: Exibi todos os elementos da lista_orde.
Entrada: Uma lista_orde.
Saida: Nao tem
*/
void exibir(lista_orde *L);
/*
O que faz: Inicializa a sua lista_orde.
Entrada: Uma lista_orde.
Saida: Nao tem
*/
lista_orde * iniciar(int cap);
/*
O que faz: cria uma nova lista_orde so com os valores impares.
Entrada: Uma lista_orde.
saida: Uma nova lista_orde so com os valores impares da lista_orde passada como parametro.
*/
lista_orde *impares(lista_orde *L);
/*
O que faz: Inseri um elemento no fim da lista_orde.
Entrada: Uma lista_orde e um elemento.
saida: Uma lista_orde atualizada e um valor boleano pra dizer se o insersao deu certo ou nao.
*/
bool inserir(lista_orde *L, int item);
/*
O que faz: Libera o espaço alocado e da um valor NULL para o ponteiro da lista_orde.
Entrada: Uma lista_orde.
saida: Nao tem.
*/
void liberar(lista_orde** L);
/*
O que faz: Da a quantidade de valores na lista_orde menores que v.
Entrada: Uma lista_orde, um elemento que vai ser comparedo.
saida: Um valor inteiro representando a quantidade de numeros menores que v.
*/
int menores(lista_orde *L, int v);
/*
O que faz: cria uma nova lista_orde so com os valores pares.
Entrada: Uma lista_orde.
saida: Uma nova lista_orde so com os valores pares da lista_orde passada como parametro.
*/
lista_orde *pares(lista_orde *L);
/*
O que faz: Remove o elemento que esta no final da lista_orde.
Entrada: Uma lista_orde.
Saida: A lista_orde atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_final(lista_orde *L);
/*
O que faz: Remove o elemento que esta no inicio da lista_orde.
Entrada: Uma lista_orde.
Saida: A lista_orde atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_inicio(lista_orde *L);
/*
O que faz: Remove o elemento que esta na posicao desejada da lista_orde.
Entrada: Uma lista_orde e uma posicao.
Saida: A lista_orde atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_meio(lista_orde *L, int posicao);
/*
O que faz: Fala o tamanho atual da lista_orde.
Entrada: Uma lista_orde.
Saida: O tamanho da lista_orde.
*/
int tamanho(lista_orde *L);
/*
O que faz: Fala se a lista_orde esta vazia.
Entrada: Uma lista_orde.
Saida: Um valor boleano (sim/nao).
*/
bool vazia(lista_orde *L);

#endif