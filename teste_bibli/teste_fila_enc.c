#include <stdio.h>
#include <stdlib.h>
#include "../includes/fila_encadeada/minha_fila_encadeada.h"

int main(){
    fila_enc* F = iniciar();
    int a =  4;
    inserir(F, a);
    inserir(F, 78);
    printf("%d ", front(F));

    F = liberar(F);

    return 0;
}