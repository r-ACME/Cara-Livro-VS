#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "define.h"
#include "data.h"

#pragma once

typedef unsigned char bool_t;

typedef struct likes_s likes_t;
struct likes_s{ //Estrutura para armazenar se 1 usuário curtiu o post
    int id_user;
    bool_t like;
};

//Lista do Hash
typedef struct lista_likes_s lista_likes_t;
struct lista_likes_s{ //Estrutura para armazenar a relação de varias curtidas em 1 post
    likes_t user;
    lista_likes_t *next_like;
    int qtd_likes;
};

//Hash
typedef struct hash_likes_s hash_likes_t;
struct hash_likes_s{ //Estrutura para armazenar a relação de varias curtidas em 1 post
    int size_pattern;
    int pattern;
    lista_likes_t *likes;
    hash_likes_t *next_pattern;
    int qtd_likes;
};

struct date_s{ //Estrutura para armazenar e preencher uma data para as publicações
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
}; typedef struct date_s date_t;

typedef struct post_s post_t;
struct post_s{ //Estrutura para armazenar uma publicação
    int id;
    date_t publish_at;
    char info[TAM_MAX_POST];
    hash_likes_t *post_likes;
    bool_t active;
};

//lista
typedef struct my_posts_s my_posts_t;
struct my_posts_s{ //Estrutura para relacionar as publicações com um usuário
    my_posts_t *prev_post;
    post_t *my_post;
    my_posts_t *next_post;
};

typedef struct profile_s profile_t;
typedef struct profile_list_s profile_list_t;
typedef struct pointer_s pointer_t;
typedef struct graph_s graph_t;


struct profile_s{ //Estrutura para armazenar um usuário
    int id;
    char name[TAM_MAX];
    char login[TAM_MAX];
    char password[TAM_MAX_SENHA];
    my_posts_t *posts;
    int qtd_posts;
    bool_t deleted;
};

//grafo

struct profile_list_s{ //Estrutura para armazenar a lista de amigos do usuários
    pointer_t *my_friend;
    profile_list_t *next_friend;
};

struct pointer_s{ //Vertice
    profile_t *person;
    profile_list_t *friends_list;
    int qtd_friends;
};

struct graph_s{
    int qtd_profiles; ///4int
    pointer_t *profiles[MAX_SIZE];
};


//Functions

int last_valid_id(graph_t *graph);
bool_t valida_senha(profile_t *login, char *user[TAM_MAX], char *password[TAM_MAX_SENHA]);
bool_t preenche_perfil(profile_t* profile, profile_t new_profile);
bool_t cria_perfil(profile_t** profile);
bool_t preenche_profile_list(profile_list_t **profile_list, pointer_t *new_profile_list);
bool_t remove_profile_list(profile_list_t** profile_list, int id);
bool_t cria_profile_list(profile_list_t **profile_list);
bool_t preenche_pointer(pointer_t* pointer[], profile_t new_pointer);
bool_t cria_pointer(pointer_t** pointer);
bool_t realoca_pointer(pointer_t* pointer[], int qtd_profiles);
bool_t preenche_grafo(pointer_t* pointer[], int qtd_profiles, profile_t* new_profile);
bool_t cria_grafo(graph_t** graph);
int last_valid_id_post(profile_t* profile);
bool_t cria_posts_list(my_posts_t** my_posts);
bool_t cria_post(post_t** post);
bool_t grava_new_post(my_posts_t** my_posts, post_t* new_post);
bool_t grava_post(post_t **novo, post_t *new_post);
bool_t grava_like(likes_t *novo, likes_t new_like);
bool_t preenche_data(date_t * date, date_t new_date);
bool_t preenche_data_post(date_t *date);
bool_t imprime_data_post(date_t *date);
bool_t deleta_perfil(profile_t** profile);

#endif // DATA_H_INCLUDED
