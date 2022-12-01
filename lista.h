#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#pragma once

/**
 * @file   lista.h
 * @brief  Arquivo com a definição dos tipos e funções de manipulação da lista
 *         utilizados na prova de AEDS.
 * @author Raphael Menezes
 * @date   2022-09-23
 */

/* Inclusões */
#include "define.h"
#include "data.h"
/* Constantes */
#define TAM_MAXIMO 20

/* Códigos de Erros */

/* Tipos */




/* Funções Exportadas */

bool_t lista_cria(my_posts_t **lista);
bool_t lista_cria_like(lista_likes_t **lista);
bool_t lista_estaVazia(my_posts_t posts);
bool_t imprime_post_ativo(post_t *publish);
bool_t imprime_post_desativado(post_t *publish);
bool_t lista_imprime_posts(my_posts_t *user);
bool_t lista_confere_user(lista_likes_t *lista, likes_t user);
bool_t lista_desativa_post(my_posts_t *posts, int id);
bool_t lista_deleta_post(my_posts_t *posts, int id);
bool_t lista_libera(my_posts_t *lista);
bool_t lista_insere_inicio_post(my_posts_t *posts, post_t* new_post);
bool_t lista_insere_ordenado_like(lista_likes_t *likes, likes_t new_like);
bool_t lista_remove_like(lista_likes_t *likes, likes_t like_to_remove);
bool_t lista_adiciona_amigo(profile_list_t* profile_list, pointer_t* new_friend);

#endif // LISTA_H_INCLUDED
