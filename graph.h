#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED


/* Inclusões */
#include "define.h"
#include "data.h"
/* Constantes */

/* Códigos de Erros */

/* Tipos */




/* Funções Exportadas */
bool_t grafo_insere_ordenado(graph_t* graph, profile_t* new_user);
profile_t * busca_perfil(graph_t *graph, char *login[TAM_MAX]);
bool_t aloca_vetor_grafo(graph_t* graph, int size);

#endif // GRAPH_H_INCLUDED
