#include <stdio.h>
#include <stdlib.h>
#include "includes/lista_n_exposta/minha_lista.h"

int main(){
    lista *L = iniciar(10);
    int i = 0;
    while (!cheia(L))
    {
        inserir_final(L, i);
        i++;
    }
    exibir(L);

    liberar(&L);
    return 0;
}