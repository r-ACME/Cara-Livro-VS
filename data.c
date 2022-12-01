/**
 * @file   data.c
 * @brief  Arquivo com as implementações das funções de manuseio de dados
 * @author Raphael Menezes
 * @date   2022-11-10
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "lista.h"


/*
 * Funções para struct de profile
 */


int last_valid_id(graph_t *graph){
    return graph->qtd_profiles;
}

bool_t valida_senha(profile_t *login, char *user[TAM_MAX], char *password[TAM_MAX_SENHA]){
    if(login == NULL){
        return FALSO;
    }

    if (login->deleted == VERDADEIRO)
        return FALSO;

    if(strcmp(login->login, user) == 0){
        if(strcmp(login->password, password) == 0){
            return VERDADEIRO;
        }
    }
    return FALSO;
}



bool_t preenche_perfil(profile_t *profile, profile_t new_profile){

    profile_t * profilenew = profile;

    (*profilenew).id = new_profile.id;
    strcpy((*profilenew).name, new_profile.name );
    strcpy((*profilenew).login, new_profile.login );
    strcpy((*profilenew).password, new_profile.password);
    (*profilenew).posts = NULL;
    (*profilenew).deleted = FALSO;

    return VERDADEIRO;
}


bool_t cria_perfil(profile_t **profile){

    (*profile) = (profile_t *) malloc(sizeof(profile_t));

    return VERDADEIRO;
}

bool_t deleta_perfil(profile_t** profile) {

    (*profile)->deleted = VERDADEIRO;
    strcpy((*profile)->login, "");
}

bool_t preenche_profile_list(profile_list_t **profile_list, pointer_t *new_profile_list){
    
    profile_list_t* current = (*profile_list);
    profile_list_t* previous = NULL;

    while (current != NULL && current->my_friend->person->id > new_profile_list->person->id) {
        previous = current;
        current = current->next_friend;
    }

    profile_list_t* new;
    cria_profile_list(&new);
    lista_adiciona_amigo(new, new_profile_list);

    if (current != NULL) {
        if (current->my_friend->person->id == new_profile_list->person->id) {
            printf("Usuario ja adicionado!");
            return FALSO;
        }
    }

    if (previous == NULL) {
        new->next_friend = (*profile_list);
        (*profile_list) = new;
    }
    else {
        previous->next_friend = new;
        new->next_friend = current;
    }

    return VERDADEIRO;
    
}

bool_t cria_profile_list(profile_list_t **profile_list){

    (*profile_list) = (profile_list_t *) malloc(sizeof(profile_list_t));

    return VERDADEIRO;
}

bool_t preenche_pointer(pointer_t *pointer[], profile_t new_pointer) {

    profile_t* new_profile = (*pointer[0]).person;

    //cria_perfil(&new_profile);

    preenche_perfil( new_profile, new_pointer);

    (pointer[0])->friends_list = NULL;
    (pointer[0])->qtd_friends = 0;
}

bool_t cria_pointer(pointer_t **pointer){

    (*pointer) = (pointer_t*) malloc(sizeof(pointer_t));
    
    cria_perfil(pointer[0]->person);

    return VERDADEIRO;
}

bool_t realoca_pointer(pointer_t *pointer[], int qtd_profiles) {

    int size = qtd_profiles + 2;
    
    (pointer) = (pointer_t*) realloc( pointer , sizeof(pointer_t*) * size);

    if (pointer == NULL)
        return FALSO;

    cria_perfil((*pointer[qtd_profiles]).person);

    return VERDADEIRO;
}

bool_t preenche_grafo(pointer_t *pointer[], int qtd_profiles, profile_t* new_profile) {

    preenche_pointer( &pointer[qtd_profiles], *new_profile);
    return VERDADEIRO;
}


bool_t cria_grafo(graph_t **graph){

    (*graph) = (graph_t *) malloc(sizeof(graph_t));
    cria_pointer( &(*graph)->profiles);
    (*graph)->qtd_profiles = 0;


    return VERDADEIRO;
}




/*
 * Funções para struct de postagem
 */

 /* Função não será mais utilizada pois será utilizado um campo para contar as curtidas
int conta_likes(hash_likes_t *recived){
    likes_t *current = recived->user;
    hash_likes_t *next = recived->next_like;

    if(current == NULL){
        return 0;
    }
    int count = 0;

    while(next != NULL){
        if( (*current).like)
            count++;
        current = (*next).user;
        next = (*next).next_like;
    }
    return count;
}*/

bool_t grava_post(post_t *novo, post_t *new_post){

    novo->id = new_post->id;
    strcpy(&novo->info, new_post->info);
    novo->post_likes = (hash_likes_t *) malloc(sizeof(hash_likes_t));
    if(preenche_data_post(&novo->publish_at) == FALSO)
        return FALSO;
    novo->active = VERDADEIRO;

    return VERDADEIRO;
}


bool_t grava_like(likes_t *novo, likes_t new_like){

    novo->id_user = new_like.id_user;
    novo->like = new_like.like;

    return VERDADEIRO;
}












/*
 * Funções para struct de datas
 */



bool_t preenche_data(date_t * date, date_t new_date){

    //preencher com data especifica
    (*date).year = new_date.year;
    (*date).month = new_date.month;
    (*date).day = new_date.day;
    (*date).hour = new_date.hour;
    (*date).minutes = new_date.minutes;
    (*date).seconds = new_date.seconds;

    return VERDADEIRO;
}

bool_t preenche_data_post(date_t *date){

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //preencher com data da gravação
    (*date).year = tm.tm_year;
    (*date).month = tm.tm_mon;
    (*date).day = tm.tm_mday;
    (*date).hour = tm.tm_hour;
    (*date).minutes = tm.tm_min;
    (*date).seconds = tm.tm_sec;

    return VERDADEIRO;
}

bool_t imprime_data_post(date_t *date){
    if(date == NULL)
        return FALSO;
    printf("%i/%i/%i - %i:%i:%i", (*date).month, (*date).day, (*date).year, (*date).hour, (*date).minutes, (*date).seconds);
}














