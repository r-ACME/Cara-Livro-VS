/**
 * @file   caralivromain.c
 * @brief  Arquivo para a tela inicial do aplicativo
 * @author Raphael Menezes
 * @date   2022-11-10
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "define.h"
#include "caralivropattern.h"
#include "caralivrocadastro.h"

void mainpage(graph_t *graph, profile_t *loged_user){
    int opcao = -1, indice = 0, item = 0;

    while (opcao != 0){
        clearscreen();
        header(loged_user);

        printf("\n1 - Pagina Inicial");
        printf("\n2 - Meu Perfil");
        printf("\n3 - Lista de Amigos");
        printf("\n\n0 - Sair");
        printf("\n---> ");

        scanf("%i", &opcao);
        getchar();

        switch(opcao){
            case 1:

                break;
            case 2:

                break;
            default:
                printf("Opção invalida!!");
                break;
        }
    }
}
