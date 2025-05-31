#include <stdio.h>
#include <stdlib.h>
#include "../includes/fila_encadeada/minha_fila_encadeada.h"

int main(){
    fila_enc* F = iniciar();
    inserir(F, 2);
    printf("%d", front(F));
    remover(L);
    printf("%d", front(F));

    F = liberar(F);

    return 0;
}