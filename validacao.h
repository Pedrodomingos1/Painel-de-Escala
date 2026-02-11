#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <stdio.h>
#include <stdlib.h>

int ler_input_seguro(const char *prompt, int minimo, int maximo) {
    int valor;
    printf("%s", prompt);
    while(scanf("%d", &valor) != 1 || valor < minimo || valor > maximo) {
        while(getchar() != '\n');
        printf("Entrada invalida! Tente novamente (%d-%d): ", minimo, maximo);
    }
    while(getchar() != '\n');
    return valor;
}

#endif
