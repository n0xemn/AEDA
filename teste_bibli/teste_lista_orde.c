#include <stdio.h>
#include <stdlib.h>
#include "includes/lista_ordenada/minha_lista_orde.h"

int main(){
    lista_orde *L_o = iniciar(10);
    int i = 20;
    while (!cheia(L_o))
    {
        inserir(L_o, i);
        exibir(L_o);
        i--;
    }
    i = busca(L_o, 14);
    printf("%d", i);
    
    liberar(&L_o);
    return 0;
}