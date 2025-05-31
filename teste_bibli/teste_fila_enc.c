#include <stdio.h>
#include <stdlib.h>
#include "../includes/fila_encadeada/minha_fila_encadeada.h"

int main(){
    fila_enc* F = iniciar();
    for (Item i = 0; i < 5; i++)
    {
        inserir(F, i);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", front(F));
        remover(F);
    }
    F = liberar(F);

    return 0;
}