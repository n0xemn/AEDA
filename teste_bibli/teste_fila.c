#include <stdio.h>
#include <stdlib.h>
#include "includes/filas/minha_fila.h"

int main(){
    fila *F = iniciar(10);
    int i = 1;
    while (!cheia(F))
    {
        inserir(F, i);
        i++;
    }
    while (!vazia(F))
    {
        printf("%d ", front(F));
        remover(F);
    }
    
    
    liberar(&F);
    return 0;
}