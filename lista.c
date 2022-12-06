/**
 * @file   lista.c
 * @author Raphael Menezes
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "define.h"
#include "lista.h"

/* Constantes */

/* Tipos */

/**
 * Função de criação.
 * @param lista Pointer pointer da lista a ser criada
 * @return Lista vazia.
 */
bool_t lista_cria(my_posts_t **lista) {
    (*lista) = malloc(sizeof(my_posts_t));

    (*lista)->prev_post = NULL;
    (*lista)->my_post = NULL;
    (*lista)->next_post = NULL;
    (*lista)->qtd_posts = 0;
}

/**
 * Função de criação.
 * @param lista Pointer pointer da lista de likes a ser criada
 * @return Lista vazia.
 */
bool_t lista_cria_like(lista_likes_t **lista) {
    (*lista) = malloc(sizeof(lista_likes_t));

    (*lista)->user.id_user = 0;
    (*lista)->user.like = FALSO;
    (*lista)->next_like = NULL;
}

/**
 * Função que verifica se a lista está vazia.
 * @param lista Lista a ser verificada.
 * @return VERDADEIRO caso a lista esteja vazia ou, caso contrário,
 * retorna FALSO.
 */
bool_t lista_estaVazia(my_posts_t posts) {
  return posts.my_post == NULL;
}


/**
 *Função que imprime item da lista
 * @param my_post Endereço de dado de uma publicação
 */
bool_t imprime_post_ativo(post_t *publish){
    if(publish == NULL){
        return FALSO;
    }
    if(publish->active == VERDADEIRO){
        printf("\nPost number %i", (*publish).id);
        printf("\nContent \n%s", (*publish).info);
        printf("\n\nPublish at ", imprime_data_post(&(*publish).publish_at));
        printf("\nLikes %i", publish->post_likes->qtd_likes);
    }
    return VERDADEIRO;
}

/**
 *Função que imprime itens desativados
 * @param my_post Endereço de dado de uma publicação
 */
bool_t imprime_post_desativado(post_t *publish){
    if(publish == NULL){
        return FALSO;
    }
    if(publish->active == FALSO){
        printf("\nPost number %i", (*publish).id);
        printf("\nContent \n%s", (*publish).info);
        printf("\n\nPublish at ", imprime_data_post(&(*publish).publish_at));
        printf("\nLikes %i", publish->post_likes->qtd_likes);
    }
    return VERDADEIRO;
}

/**
 * Função que imprime todas publicações
 * @param user Lista de postagens
 */
bool_t lista_imprime_posts(my_posts_t *user) {

    if(lista_estaVazia(*user)){
        return VERDADEIRO;
    }
    my_posts_t *atual = user;

    for(atual = user; atual->my_post != NULL; atual = atual->next_post){
        imprime_data_post(atual->my_post);
        printf("\n\n");
    }

    return VERDADEIRO;
}

/**
 * Função que verifica se usuário deu like
 * @param user Lista de postagens
 */
bool_t lista_confere_user(lista_likes_t *lista, likes_t user) {

    lista_likes_t *current = lista;

    while ((current != NULL) && (current->user).id_user != user.id_user) {
        current = current->next_like;
    }

    if(current->user.id_user == user.id_user){
        return VERDADEIRO;
    }
    return FALSO;
}


/**
 * Função que procura e desativa um item da lista caso o item esteja presente.
 * @param posts Lista ontem o item ser procurado.
 * @param id Id do item a ser procurado e desativado.
 * @return Verdadeiro para conseguir desativar.
 */
bool_t lista_desativa_post(my_posts_t *posts, int id) {

  my_posts_t * anterior = NULL;
  my_posts_t * atual = posts;

  // Busca pelo item até encontrá-lo ou a lista chegar no final
  while ((atual != NULL) && (*atual->my_post).id != id) {
    anterior = atual;
    atual = atual->next_post;
  }

  // Se chegou no final e não encontrou, retorna a lista original
  if (atual == NULL) {
        return FALSO;
  }
  // Se chegou até aqui é porque encontrou e está em <atual>
  posts->my_post->active = FALSO;

  return VERDADEIRO;
}

/**
 * Função que procura e remove um item da lista caso o item esteja presente.
 * @param posts Lista ontem o item ser procurado.
 * @param id Id do item a ser procurado e deletado.
 * @return Verdadeiro se conseguir deletar.
 */
bool_t lista_deleta_post(my_posts_t *posts, int id) {

  my_posts_t * anterior = NULL;
  my_posts_t * atual = posts;

  // Busca pelo item até encontrá-lo ou a lista chegar no final
  while ((atual != NULL) && (*atual->my_post).id != id) {
    anterior = atual;
    atual = atual->next_post;
  }

  // Se chegou no final e não encontrou, retorna a lista original
  if (atual == NULL) {
        return FALSO;
  }
  // Se chegou até aqui é porque encontrou e está em <atual>

  // Verifica se é o primeiro
  if (anterior == NULL) {
    posts->my_post = posts->next_post->my_post;
  }
  else {
    anterior->next_post = atual->next_post;
  }

  posts->qtd_posts--;
  // Libera o espaço alocado pelo atual
  free(atual);

  return VERDADEIRO;
}

/**
 * Função que libera a memória utilizada pela lista.
 * @param lista Lista a ter a memória liberada.
 */
bool_t lista_libera(my_posts_t *lista) {

  my_posts_t *current = lista;
  post_t *atual = lista->my_post;

  while (atual != NULL) {
    current = current->next_post;
    free(atual);
    atual = current->my_post;
  }
  return VERDADEIRO;
}


/**
 * Função que insere um item em ordem.
 * @param lista Lista onde o item será inserido.
 * @param item Item a ser inserido na lista.
 * @return Lista atualizada com o novo item.
 */
bool_t lista_insere_inicio_post(my_posts_t *posts, post_t* new_post) {

    my_posts_t *novo;
    my_posts_t *current = posts;

    novo = (my_posts_t *) malloc(sizeof(my_posts_t));
    if (grava_post(novo, new_post) == FALSO){
        free(novo);
        return FALSO;
    }
    (*posts).qtd_posts += 1;
    return VERDADEIRO;
}


/**
 * Função que insere um item em ordem na lista de likes.
 * @return Lista atualizada com o novo item.
 */
bool_t lista_insere_ordenado_like(lista_likes_t *likes, likes_t new_like) {

    lista_likes_t *novo;
    lista_likes_t *previous = NULL;
    lista_likes_t *current = likes;

    while( (current->user).id_user >= new_like.id_user && current != NULL){
        previous = current;
        current = current->next_like;
    }

    novo = (lista_likes_t *) malloc(sizeof(lista_likes_t));
    grava_like( &novo->user, new_like );

    if(current->user.id_user == new_like.id_user){
        return FALSO;
    }

    if(previous == NULL){
       novo->next_like = likes->next_like;
       likes = novo;
    }
    else{
        previous->next_like = novo;
        novo->next_like = current;
    }

    (*likes).qtd_likes++;

    return VERDADEIRO;
}


/**
 * Função que remove um item da lista de likes.
 * @return Lista atualizada com o novo item.
 */
bool_t lista_remove_like(lista_likes_t *likes, likes_t like_to_remove) {

    lista_likes_t *previous = NULL;
    lista_likes_t *current = likes;

    while( (current->user).id_user >= like_to_remove.id_user && current != NULL){
        previous = current;
        current = current->next_like;
    }

    if(current->user.id_user == like_to_remove.id_user){
        previous->next_like = current->next_like;
        free(current);
        (*likes).qtd_likes--;
        return VERDADEIRO;
    }
    return FALSO;
}



bool_t lista_adiciona_amigo(profile_list_t* profile_list, pointer_t *new_friend) {

    (*profile_list).my_friend = new_friend;
    (*profile_list).next_friend = NULL;
}


bool_t lista_amigos(profile_list_t* friends_list) {

    profile_list_t* current = friends_list;
    while (current != NULL) {
        if(current->my_friend->person->deleted == FALSO)
            printf("\n%i - %s", current->my_friend->person->id, current->my_friend->person->name);
        current = current->next_friend;
    }

}