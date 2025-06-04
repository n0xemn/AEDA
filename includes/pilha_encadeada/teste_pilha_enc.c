#include <stdio.h>
#include <stdlib.h>
#include "minha_pilha_encadeada.h"

int main(){
    pilha_enc* P = iniciar();
    for (int i = 0; i < 10; i++)
    {
        inserir(P, i);
        printf("%d ", top(P));
    }
    printf("Tamanho da pilha: %d. ", tamanho(P));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", top(P));
        remover(P);
    }
    printf("Tamanho da pilha: %d", tamanho(P));

    P = liberar(P);

    return 0;
}