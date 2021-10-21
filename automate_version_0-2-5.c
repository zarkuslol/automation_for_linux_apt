/*
Automate version 0.2

Author: zarkus

Software that simplifies some tasks on Linux to buy time or for begginers

Written specifically for Ubuntu and Debian (that uses apt-get), but you can modify
this code to make it run on other OS

Only available in Portuguese, the English version will be launched soon

It can be used and modified for everybody... Enjoy it :) !
*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions / Menus
void menu() {
	puts("NOME DA EMPRESA");
	putchar(10);
	puts("1 - Atualizar sistema");
	puts("2 - Baixar pacote");
	puts("3 - Baixar programa/aplicativo");
	puts("4 - Verificar versão de pacote/aplicativo");
	puts("5 - Limpar sistema");
	puts("0 - Sair do programa");
	putchar(10);
	printf("OPÇÃO: ");
}

void menu_error() {
	puts("NOME DA EMPRESA");
	putchar(10);
	puts("Opção inválida, tente novamente");
	putchar(10);
	puts("1 - Atualizar sistema");
	puts("2 - Baixar pacote");
	puts("3 - Baixar programa/aplicativo");
	puts("4 - Verificar versão de pacote/aplicativo");
	puts("5 - Limpar sistema");
	puts("0 - Sair do programa");
	putchar(10);
	printf("OPÇÃO: ");
}

// Main function
int main() {

	system("clear");

	int valores_aceitos[6] = {0, 1, 2, 3, 4, 5}, i = 0, n = 6, x = 0;

	int contador = 0;
	while (contador == 0) {

		menu();
		int opcao;
		scanf("%d", &opcao);

		for (int j = 0; j < n; j++) {
			if (valores_aceitos[j] == opcao) {
				i = 1;
				break;
			}
		}

		while (i == 0) {

			system("clear");

			menu_error();
			scanf("%d", &opcao);

			for (int j = 0; j < n; j++) {
				if (valores_aceitos[j] == opcao) {
					i = 1;
					break;
				}
			}

		}
		
		if (i == 1) {
			
			if (opcao == 0) {

				contador = 1;
				system("clear");

			}

			else {

				char comando[45] = "sudo apt-get install ", comando_aplicativo[45] = "snap install ", comando_versao[35] = "apt-show-versions ", recurso[20];

				switch(opcao) {

					case 1:
						system("clear");

						system("sudo apt-get update");
						break;

					case 2:
						system("clear");

						printf("Digite o nome do pacote que deseja baixar: ");
						scanf("%s", recurso);
						putchar(10);

						system(strcat(comando, recurso));

						break;

					case 3:
						system("clear");

						printf("Digite o nome do programa/aplicativo que deseja baixar: ");
						scanf("%s", recurso);
						putchar(10);

						system(strcat(comando_aplicativo, recurso));

						break;

					case 4:
						system("clear");

						printf("Digite o nome do pacote/aplicativo que deseja verificar a versão: ");
						scanf("%s", recurso);
						putchar(10);

						system(strcat(comando_versao, recurso));

						break;

					case 5:
						system("clear");

						system("sudo apt-get autoclean");
						system("sudo apt-get clean");

						break;

				}

				putchar(10);

				int continuar;
				printf("Deseja continuar rodando o programa? (1 - sim / 2 - não): ");
				scanf("%d", &continuar);

				if (continuar == 1) {
					system("clear");
					continue;
				}
				else {
					system("clear");
					contador = 1;
				}

			}
		}


	}

	return 0;

}
