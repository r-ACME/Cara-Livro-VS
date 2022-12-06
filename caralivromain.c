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
#include "caralivroverusuarios.h"
#include "caralivroveramigos.h"
#include "caralivropostagens.h"

void mainpage(graph_t *graph, pointer_t *loged_user){
    int opcao = -1, indice = 0, item = 0;

    while (opcao != 0){
        clearscreen();
        header(loged_user);

        printf("\n1 - Fazer uma Postagem");
        printf("\n2 - Minhas Postagens");
        printf("\n3 - Lista de Amigos");
        printf("\n8 - Ver usuarios");
        printf("\n9 - Apagar a conta");
        printf("\n\n0 - Sair");
        printf("\n---> ");

        scanf("%i", &opcao);
        getchar();

        switch(opcao){
            case 1:
                criar_postagem(loged_user);
                break;
            case 2:

                break;
            case 3:
                ver_amigos(graph, loged_user, loged_user);
                break;
            case 8:
                lista_usuarios(graph, loged_user);
                break;
            case 9:
                if ( (*loged_user).person->deleted == FALSO)
                    (*loged_user).person->deleted = VERDADEIRO;
                return;

            default:
                printf("Opção invalida!!");
                break;
        }

    }
}
