#include <stdio.h>
#include <stdlib.h>
#include "minha_lista_ancadeada.h"

int main(){
    lista_enc* L_enc = iniciar();
    for (int i = 1; i <= 10; i++)
    {
        inserir_inicio(L_enc, i);
    }
    exibir(L_enc);
    ordenar(L_enc);
    exibir(L_enc);
    L_enc = liberar(L_enc);

    return 0;
}