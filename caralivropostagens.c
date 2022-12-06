/**
 * @file   data.c
 * @brief  Arquivo com as implementações das funções de manuseio de dados
 * @author Raphael Menezes
 * @date   2022-12-05
 */

 /* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "define.h"
#include "data.h"
#include "lista.h"
#include "graph.h"
#include "hash.h"
#include "caralivropattern.h"
#include "caralivrocadastro.h"
#include "caralivroverusuarios.h"
#include "caralivroveramigos.h"
#include "caralivropostagens.h"



bool_t criar_postagem(pointer_t * current_user) {

    clearscreen();
    header(current_user);
    char post[TAM_MAX_POST];

    printf("\nDiga o que está pensando: ");
    fgets(post, TAM_MAX_POST, stdin);
    uteis_removeQuebraLinhaFinal(post);

    post_t new_post;

    if (current_user->person->posts == NULL)
        cria_posts_list(&current_user->person->posts);

    new_post.active = VERDADEIRO;
    preenche_data_post(&new_post.publish_at);
    new_post.id = last_valid_id_post(current_user->person->posts);
    hash_cria(&new_post.post_likes, HASH_PATTERN);
    strcpy(&new_post.info, post);

    grava_new_post(&current_user->person->posts, &new_post);


	return VERDADEIRO;
}










