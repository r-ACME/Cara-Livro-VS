#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "caralivropattern.h"
#include "caralivromain.h"
#include "graph.h"
#include "data.h"
#include "util.h"
#include "lista.h"





void ver_amigos(graph_t* graph, pointer_t* loged_user, pointer_t* current_friend) {

	int opcao = -2, indice = 0, item = 0, subopcao = 0;

	while (opcao != -1) {
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
			if (busca_amigo(loged_user->friends_list, opcao)) {
				printf("\n\nO que deseja ver de %s", (*current_friend).person->name);
				printf("\n1 - Lista de amigos");
				printf("\n2 - Postagens");

				if ((*current_friend).person->id == (*loged_user).person->id)
					printf("\n3 - Remover amigo");

				printf("\n\n-1 - Voltar");
				printf("\n---> ");
				scanf("%i", &subopcao);
				getchar();

				if (subopcao == -1) {
					continue;
				}
				if (subopcao == 1) {
					ver_amigos(graph, loged_user, busca_pointer(graph, opcao));
				}
				if (subopcao == 2) {
					lista_imprime_posts((*current_friend).person->posts);
				}
				if (subopcao == 3 && (*current_friend).person->id == (*loged_user).person->id) {
					if (remove_profile_list(current_friend->friends_list, subopcao)) {
						(*current_friend).qtd_friends--;
						printf("\nUsuario removido com sucesso!");
					}
				}
				else {
					printf("\nEste usuario nao e amigo de %s", (*current_friend).person->name);
					getchar();
				}
				break;
			}

		}

	}
}


