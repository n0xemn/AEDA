#include <stdio.h>
#include <stdlib.h>
#include "includes/pilhas/minha_pilha.h"

int main(){
    pilha *P = iniciar(10);
    int i = 1;
    while (!cheia(P))
    {
        inserir(P, i);
        i++;
    }
    while (!vazia(P))
    {
        printf("%d ", top(P));
        remover(P);
    }
    
    
    liberar(&P);
    return 0;
}