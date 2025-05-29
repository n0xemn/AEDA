#ifndef MINHA_FILA
#define MINHA_FILA

/*
gcc -c nome_arquivo_biblioteca.c : pra executar o arquivo c da biblioteca
gcc nome_do_arquivo.c pasta/nome_arquivo_biblioteca.o -o noome_que_vc_quer : pra executar o arquivo com a biblioteca

*/

#include <stdbool.h>

/*
Use ponteiro pra criar uma fila
*/
typedef struct fila fila;

/*
O que faz: Fala a capacidade total da fila.
Entrada: Uma fila.
Saida: A capacidade total da fila.
*/
int capacidade(fila *L);
/*
O que faz: Fala se a fila esta cheio.
Entrada: Uma fila.
Saida: Um valor boleano (sim/nao). 
*/
bool cheia(fila *L);
/*
O que faz: Retorna o o primero elemento da fila.
Entrada: Uma fila.
Saida: Uma valor inteiro (primeiro elemento da fila).
*/
int front(fila *L);
/*
O que faz: Inicializa a sua fila.
Entrada: Uma fila.
Saida: Nao tem
*/
fila * iniciar(int cap);
/*
O que faz: Inseri um elemento na fila.
Entrada: Uma fila e um elemento.
saida: Uma fila atualizada e um valor boleano pra dizer se o insersao deu certo ou nao.
*/
bool inserir(fila *L, int item);
/*
O que faz: Libera o espaço alocado e da um valor NULL para o ponteiro da fila.
Entrada: Uma fila.
saida: Nao tem.
*/
void liberar(fila** L);
/*
O que faz: Remove o elemento que esta na frente naa fila.
Entrada: Uma fila.
Saida: uma valor boleano sim/nao (se removeu ou nao).
*/
bool remover(fila *L);
/*
O que faz: Fala o tamanho atual da fila.
Entrada: Uma fila.
Saida: O tamanho da fila.
*/
int tamanho(fila *L);
/*
O que faz: Fala se a fila esta vazia.
Entrada: Uma fila.
Saida: Um valor boleano (sim/nao).
*/
bool vazia(fila *L);

#endif