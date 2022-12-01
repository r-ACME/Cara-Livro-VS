/**
 * @file   caralivromain.c
 * @brief  Arquivo para a tela inicial do aplicativo
 * @author Raphael Menezes
 * @date   2022-11-30
 */

 /* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "define.h"
#include "graph.h"
#include "caralivropattern.h"
#include "caralivrocadastro.h"


void lista_usuarios(graph_t* graph, pointer_t* loged_user) {

	int opcao = -2, indice = 0, item = 0, i = 0;
	int limite = 10;
	int quantidade = 0;

	while (opcao != -1) {
		clearscreen();
		header(loged_user);

		printf("\n\nPara adicionar algum usuário, informe seu numero:\n");

		for (i = 0; i < limite; i++) {
			if (quantidade * limite + i < (*graph).qtd_profiles) {
				if((*graph).profiles[quantidade * limite + i]->person->id != (*loged_user).person->id)
					if( (*graph).profiles[quantidade * limite + i]->person->deleted == FALSO)
						if( !busca_amigo(loged_user->friends_list, quantidade * limite + i))
							printf("\n%i - %s", i, (*graph).profiles[quantidade * limite + i]->person->name);
			}
		}
		if ((quantidade + 1) * limite < (*graph).qtd_profiles)
			printf("\n\n11 - Proxima pagina");
		if ((quantidade - 1) * limite >= 0)
			printf("\n\n12 - Pagina anterior");
		printf("\n\n-1 - Sair");
		printf("\n---> ");

		scanf("%i", &opcao);
		getchar();

		switch (opcao) {
		case -1: 
			return;
		case 11:
			if ( (quantidade + 1) * limite < (*graph).qtd_profiles)
				quantidade++;
			break;
		case 12: 
			if ((quantidade - 1) * limite > -1)
				quantidade = quantidade - 1;
			break;
		default:
			if ((*graph).profiles[quantidade * limite + opcao]->person != NULL) {
				if ((*graph).profiles[quantidade * limite + opcao]->person->deleted == FALSO) {
					pointer_t *new_friend = busca_pointer(graph, (quantidade * limite + opcao) );

					/*if ((*loged_user).friends_list == NULL)
						cria_profile_list(&(*loged_user).friends_list);//*/
					preenche_profile_list( &(loged_user->friends_list) , new_friend);
					(*loged_user).qtd_friends++;
				}
 			}
			else {
				printf("\nUsuario não encontrado!\n");
			}
			break;
		}

	}
	
	

}