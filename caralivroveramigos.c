#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "caralivropattern.h"
#include "caralivromain.h"
#include "caralivropostagens.h"
#include "graph.h"
#include "data.h"
#include "util.h"
#include "lista.h"


void ver_amigos(graph_t* graph, pointer_t* loged_user, pointer_t* current_friend) {

	int opcao = -2, indice = 0, item = 0, subopcao = 0;

	while (opcao != -1) {

		opcao = -2, indice = 0, item = 0, subopcao = 0;

		clearscreen();
		header(loged_user);

		printf("%s - Lista de amigos", (*current_friend).person->name);

		lista_amigos(current_friend->friends_list);

		printf("\n\nPara ver o usuario da lista, informe seu ID:\n");

		printf("\n\n-1 - Voltar");
		printf("\n---> ");

		scanf("%i", &opcao);
		getchar();

		switch (opcao) {
		case -1:
			return;
		default:
			if (opcao == (*loged_user).person->id ) {
				printf("\nEste e voce");
				getchar();
			}
			else if (busca_amigo(current_friend->friends_list, opcao)) {
				pointer_t* new_friend = busca_pointer(graph, opcao);

				printf("\n\n%s", (*new_friend).person->name);
				printf("\n1 - Lista de amigos");
				printf("\n2 - Postagens");

				if (busca_amigo(loged_user->friends_list, opcao)) {
					printf("\n3 - Remover amigo");
				}
				else {
					printf("\n3 - Adiciona amigo");
				}

				printf("\n\n-1 - Voltar");
				printf("\n---> ");
				scanf("%i", &subopcao);
				getchar();

				if (subopcao == -1) {
					continue;
				}
				if (subopcao == 1) {
					ver_amigos(graph, loged_user, new_friend);
				}
				if (subopcao == 2) {
					lista_imprime_posts((*current_friend).person->posts);
				}
				if (subopcao == 3){
					if ((*current_friend).person->id == (*loged_user).person->id) {
						remove_profile_list(&loged_user->friends_list, opcao);
						(*loged_user).qtd_friends--;
						printf("\nUsuario removido com sucesso!");
					}
					else {
						preenche_profile_list(&(loged_user->friends_list), new_friend);
						(*loged_user).qtd_friends++;
					}
				}
				else {
					printf("\nEste usuario nao e amigo de %s", (*current_friend).person->name);
				}
				getchar();
				break;
			}
			else {
				printf("\nAmigo invalido!");
				getchar();
			}

		}

	}
}



