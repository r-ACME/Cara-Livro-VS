/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "define.h"
#include "data.h"
#include "graph.h"
/* Constantes */

/* Códigos de Erros */

/* Tipos */




/* Funções Exportadas */

bool_t grafo_insere_ordenado ( graph_t *graph, profile_t *new_user ){

    graph_t *current = graph;
    profile_t current_user;

    /*if (current->qtd_profiles == 0)
        cria_pointer(current->profiles);
    else
        realoca_pointer(&current->profiles, (*current).qtd_profiles);*/

    preenche_grafo(graph->profiles, (*current).qtd_profiles, new_user);

    (*current).qtd_profiles++;
    return VERDADEIRO;
}

profile_t * busca_perfil(graph_t *graph, char *login[TAM_MAX]){

    int i = 0;

    for(; i < graph->qtd_profiles; i++){

        if(strcmp( (*graph).profiles[i]->person->login, login) == 0) {
            return ((*graph).profiles[i]->person);
        }
    }
    return NULL;
}

bool_t aloca_vetor_grafo(graph_t* graph, int size) {

    if (graph == NULL)
        return FALSO;

    for (int i = 0; i < size; i++) {
        graph->profiles[i] = malloc(sizeof(pointer_t));
        graph->profiles[i]->friends_list = NULL;
        graph->profiles[i]->qtd_friends = 0;
        cria_perfil(&graph->profiles[i]->person);
    }

    return VERDADEIRO;
}


pointer_t* busca_pointer(graph_t* graph, int id) {

    if((*graph).profiles[id]->person->deleted)
        return NULL;
        
    return ( (*graph).profiles[id] );
}


bool_t* busca_amigo(profile_list_t *amigos, int id) {

    profile_list_t* current = amigos;

    while (current != NULL) {
        if (current->my_friend->person->id == id)
            return VERDADEIRO;
        current = current->next_friend;
    }
    return FALSO;
}







