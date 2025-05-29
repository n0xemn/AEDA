#include <stdio.h>
#include <stdlib.h>
#include "includes/SET/set.h"

int main(){
    set *S = iniciar(10);
    int i = 20;
    while (!cheia(S))
    {
        inserir(S, i);
        exibir(S);
        inserir(S, i);
        exibir(S);
        i--;
    }
    
    liberar(&S);
    return 0;
}