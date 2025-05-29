#ifndef SET
#define SET

/*
gcc -c nome_arquivo_biblioteca.c : pra executar o arquivo c da biblioteca
gcc nome_do_arquivo.c pasta/nome_arquivo_biblioteca.o -o noome_que_vc_quer : pra executar o arquivo com a biblioteca

*/

#include <stdbool.h>

/*
Use ponteiro pra criar uma set
*/
typedef struct set set;

/*
O que faz: Retorna a posicao do elemento dado.
Entrada: Uma set e um elemento.
Saida: Posicao do elemento na set.
*/
bool busca(set *L, int item);
/*
O que faz: Fala a capacidade total da set.
Entrada: Uma set.
Saida: A capacidade total da set.
*/
int capacidade(set *L);
/*
O que faz: Fala se a set esta cheio.
Entrada: Uma set.
Saida: Um valor boleano (sim/nao). 
*/
bool cheia(set *L);
/*
O que faz: Exibi todos os elementos da set.
Entrada: Uma set.
Saida: Nao tem
*/
void exibir(set *L);
/*
O que faz: Inicializa a sua set.
Entrada: Uma set.
Saida: Nao tem
*/
set * iniciar(int cap);
/*
O que faz: cria uma nova set so com os valores impares.
Entrada: Uma set.
saida: Uma nova set so com os valores impares da set passada como parametro.
*/
set *impares(set *L);
/*
O que faz: Inseri um elemento no fim da set.
Entrada: Uma set e um elemento.
saida: Uma set atualizada e um valor boleano pra dizer se o insersao deu certo ou nao.
*/
bool inserir(set *L, int item);
/*
O que faz: Libera o espaço alocado e da um valor NULL para o ponteiro da set.
Entrada: Uma set.
saida: Nao tem.
*/
void liberar(set** L);
/*
O que faz: Da a quantidade de valores na set menores que v.
Entrada: Uma set, um elemento que vai ser comparedo.
saida: Um valor inteiro representando a quantidade de numeros menores que v.
*/
int menores(set *L, int v);
/*
O que faz: cria uma nova set so com os valores pares.
Entrada: Uma set.
saida: Uma nova set so com os valores pares da set passada como parametro.
*/
set *pares(set *L);
/*
O que faz: Remove o elemento que esta no final da set.
Entrada: Uma set.
Saida: A set atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_final(set *L);
/*
O que faz: Remove o elemento que esta no inicio da set.
Entrada: Uma set.
Saida: A set atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_inicio(set *L);
/*
O que faz: Remove o elemento que esta na posicao desejada da set.
Entrada: Uma set e uma posicao.
Saida: A set atualizada e um valor boleano pra dizer se a remocao deu certo ou nao.
*/
bool remov_meio(set *L, int posicao);
/*
O que faz: Fala o tamanho atual da set.
Entrada: Uma set.
Saida: O tamanho da set.
*/
int tamanho(set *L);
/*
O que faz: Fala se a set esta vazia.
Entrada: Uma set.
Saida: Um valor boleano (sim/nao).
*/
bool vazia(set *L);

#endif