/**
 * @file   caralivrocadastro.c
 * @brief  Arquivo para tratar as funções referentes ao cadastro de novo usuário
 * @author Raphael Menezes
 * @date   2022-11-10
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "data.h"
#include "util.h"
#include "graph.h"
#include "caralivropattern.h"
#include "caralivrocadastro.h"

bool_t signin(graph_t *graph){

    clearscreen();
    header(NULL);
    char name[TAM_MAX], login[TAM_MAX], password[TAM_MAX];

    printf("\nInforme o seu nome: ");
    fgets(name,TAM_MAX,stdin);
    uteis_removeQuebraLinhaFinal(name);
    //getchar();

    printf("\nInforme o seu login: ");
    fgets(login,TAM_MAX,stdin);
    uteis_removeQuebraLinhaFinal(login);
    //getchar();

    printf("\nInforme a sua senha: ");
    fgets(password,TAM_MAX,stdin);
    uteis_removeQuebraLinhaFinal(password);
    //getchar();

    profile_t new_user;
    new_user.id = last_valid_id(graph);
    strcpy(new_user.name, name);
    strcpy(new_user.login, login);
    strcpy(new_user.password, password);
    new_user.deleted = FALSO;
    new_user.posts = NULL;

    profile_t* user = busca_perfil(graph, new_user.login);
    if (user == NULL) {
        if (grafo_insere_ordenado(graph, &new_user)) {
            return VERDADEIRO;
        }
    }
    else {
        printf("Usuario ja cadastrado!!");
        getchar();
    }
    return FALSO;
}
