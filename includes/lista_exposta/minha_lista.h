#ifndef MINHA_LISTA
#define MINHA_LISTA

/*
gcc -c nome_arquivo_biblioteca.c : pra executar o arquivo c da biblioteca
gcc nome_do_arquivo.c pasta/nome_arquivo_biblioteca.o -o nome_que_vc_quer : pra executar o arquivo com a biblioteca

*/

#include <stdbool.h>

typedef struct lista lista;

struct lista
{
    int cap, qtde;
    int elementos[10];    
};

/*
O que faz: Retorna a posicao do elemento dado.
Entrada: Uma lista e um elemento.
Saida: Posicao do elemento na lista.
*/
int busca(lista *L, int item);
/*
O que faz: Fala a capacidade total da lista.
Entrada: Uma lista.
Saida: A capacidade total da lista.
*/
int capacidade(lista *L);
/*
O que faz: Fala se a lista esta cheia.
Entrada: Uma lista.
Saida: Um valor boleano (true ou false). 
*/
bool cheia(lista *L);
/*
O que faz: Exibi todos os elementos da lista.
Entrada: Uma lista.
Saida: Nao tem
*/
void exibir(lista *L);
/*
O que faz: Inicializa a sua lista.
Entrada: Uma lista.
Saida: Nao tem
*/
void iniciar(lista *L);
/*
O que faz: cria uma nova lista so com os valores impares.
Entrada: Uma lista.
saida: Uma nova lista so com os valores impares da lista passada como parametro.
*/
lista impares(lista *L);
/*
O que faz: Inseri um elemento no fim da lista.
Entrada: Uma lista e um elemento.
saida: Uma lista atualizada e um valor boleano pra dizer se a insersao deu certo ou nao.
*/
bool inserir_final(lista *L, int item);
/*
O que faz: Inseri um elemento no começo da lista.
Entrada: Uma lista e um elemento.
saida: Uma lista atualizada e um valor boleano pra dizer se a insersao deu certo ou nao.
*/
bool inserir_inicio(lista *L, int item);
/*
O que faz: Inseri um elemento na posicao desejada da lista.
Entrada: Uma lista, um elemento e uma posicao.
saida: Uma lista atualizada e um valor boleano pra dizer se a insersao deu certo ou nao.
*/
bool inserir_meio(lista *L, int item, int posicao);
/*
O que faz: Da a quantidade de valores na lista menores que o item escolhido.
Entrada: Uma lista, um elemento a ser comparado.
saida: Um valor inteiro representando a quantidade de numeros menores que o item escolhido.
*/
int menores(lista *L, int v);
/*
O que faz: Ordena a lista em ordem crescente.
Entrada: Uma lista.
saida: Uma lista ordenada em ordem crescente.
*/
void ordenar_cresc(lista *L);
/*
O que faz: Ordena a lista em ordem decrescente.
Entrada: Uma lista.
saida: Uma lista ordenada em ordem decrescente.
*/
void ordenar_decresc(lista *L);
/*
O que faz: cria uma nova lista so com os valores pares.
Entrada: Uma lista.
saida: Uma nova lista so com os valores pares da lista passada como parametro.
*/
lista pares(lista *L);
/*
O que faz: Remove o elemento que esta no final da lista.
Entrada: Uma lista.
Saida: A lista atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_final(lista *L);
/*
O que faz: Remove o elemento que esta no inicio da lista.
Entrada: Uma lista.
Saida: A lista atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_inicio(lista *L);
/*
O que faz: Remove o elemento que esta na posicao desejada da lista.
Entrada: Uma lista e uma posicao.
Saida: A lista atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_meio(lista *L, int posicao);
/*
O que faz: Fala o tamanho atual da lista.
Entrada: Uma lista.
Saida: O tamanho da lista.
*/
int tamanho(lista *L);
/*
O que faz: Fala se a lista esta vazia.
Entrada: Uma lista.
Saida: Um valor boleano (true ou false).
*/
bool vazia(lista *L);

#endif