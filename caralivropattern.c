/**
 * @file   caralivropattern.c
 * @brief  Prints repetitivos do sistema
 * @author Raphael Menezes
 * @date   2022-11-10
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caralivropattern.h"
#include "data.h"


/*
 * Função para imprimir cabeçalho
 */
void header(pointer_t *logged_user){

    if(logged_user == NULL)
        printf("\n\nBem Vindo ao\n\n");
    else
        printf("\n\nSeja Bem Vindo %s\n\n", logged_user->person->name);
    printf("+-----------------------+\n");
    printf("|       Cara-Livro      |\n");
    printf("+-----------------------+\n");
    printf("\nSeu twittagram pessoal!\n");
}

