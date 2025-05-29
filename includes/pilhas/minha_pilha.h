#ifndef MINHA_PILHA
#define MINHA_PILHA

/*
gcc -c nome_arquivo_biblioteca.c : pra executar o arquivo c da biblioteca
gcc nome_do_arquivo.c pasta/nome_arquivo_biblioteca.o -o noome_que_vc_quer : pra executar o arquivo com a biblioteca

*/

#include <stdbool.h>

/*
Use ponteiro pra criar uma pilha
*/
typedef struct pilha pilha;

/*
O que faz: Fala a capacidade total da pilha.
Entrada: Uma pilha.
Saida: A capacidade total da pilha.
*/
int capacidade(pilha *L);
/*
O que faz: Fala se a pilha esta cheio.
Entrada: Uma pilha.
Saida: Um valor boleano (sim/nao). 
*/
bool cheia(pilha *L);
/*
O que faz: Inicializa a sua pilha.
Entrada: Uma pilha.
Saida: Nao tem
*/
pilha * iniciar(int cap);
/*
O que faz: Inseri um elemento no fim da pilha.
Entrada: Uma pilha e um elemento.
saida: Uma pilha atualizada e um valor boleano pra dizer se o insersao deu certo ou nao.
*/
bool inserir(pilha *L, int item);
/*
O que faz: Libera o espaço alocado e da um valor NULL para o ponteiro da pilha.
Entrada: Uma pilha.
saida: Nao tem.
*/
void liberar(pilha** L);
/*
O que faz: Remove o elemento que esta no final da pilha.
Entrada: Uma pilha.
Saida: A pilha atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remover(pilha *L);
/*
O que faz: Fala o tamanho atual da pilha.
Entrada: Uma pilha.
Saida: O tamanho da pilha.
*/
int tamanho(pilha *L);
/*
O que faz: Da o valor do topo da pilha.
Entrada: Uma pilha.
Saida: Um valor inteiro.
*/
int top(pilha * P);
/*
O que faz: Fala se a pilha esta vazia.
Entrada: Uma pilha.
Saida: Um valor boleano (sim/nao).
*/
bool vazia(pilha *L);

#endif