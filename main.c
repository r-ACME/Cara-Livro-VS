#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "caralivropattern.h"
#include "caralivromain.h"
#include "graph.h"
#include "data.h"

int main()
{
    printf("Abriu");
    time_t t;
    srand((unsigned)time(&t));

    int opcao = -1, indice = 0, item = 0;

    char login[TAM_MAX], password[TAM_MAX];

    graph_t graph;
    graph.qtd_profiles = 0;
    aloca_vetor_grafo(&graph, MAX_SIZE);

    profile_t admin;

    admin.id = 0;
    strcpy(admin.name, "admin");
    strcpy(admin.login, "admin");
    strcpy(admin.password, "admin");
    admin.deleted = FALSO;
    admin.posts = NULL;

    //cria_grafo(&graph);

    grafo_insere_ordenado( &graph, &admin);

    while (opcao != 0){
        clearscreen();

        /*for (int i = 0; i < graph.qtd_profiles; i++)
            printf("\n\nCadastro %i: %s\n", i + 1, graph.profiles[i]->person->name);*/

        header(NULL);

        printf("\n1 - Entrar");
        printf("\n2 - Cadastrar");
        printf("\n\n0 - Sair");
        printf("\n---> ");

        scanf("%i", &opcao);
        getchar();

        switch(opcao){
            case 0: break;
            case 2:
                if(!signin(&graph))
                    printf("\nNao foi possivel cadastrar este usuario! Verifique seus dados e tente novamente!");
                else{
                    printf("\nPerfil cadastrado com sucesso!");
                    getchar();
                }
                break;
            case 1:
                fflush(stdin);
                printf("\nInforme o login: ");
                fgets(login,TAM_MAX,stdin);
                uteis_removeQuebraLinhaFinal(login);

                fflush(stdin);
                printf("\nDigite sua senha: ");
                fgets(password,TAM_MAX,stdin);
                uteis_removeQuebraLinhaFinal(password);

                fflush(stdin);
                profile_t *user = busca_perfil(&graph, &login);

                if(valida_senha(user, login, password)){
                    mainpage(&graph, user);
                }
                else{
                    printf("\nLogin ou senha invalida!!");
                    getchar();
                }
                break;
            default:
                printf("Opção invalida!!");
                break;
        }
    }
    return SUCESSO;
}
