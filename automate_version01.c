#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
	puts("NOME DA EMPRESA");
	putchar(10);
	puts("1 - Atualizar sistema");
	puts("2 - Baixar pacote");
	puts("3 - Baixar programa/aplicativo");
	puts("4 - Verificar versão de pacote/aplicativo");
	puts("0 - Sair do programa");
	putchar(10);
	printf("OPÇÃO: ");
}

int main() {

	system("clear");

	int contador = 0;
	while (contador == 0) {

		menu();
		int opcao;
		scanf("%d", &opcao);

		if (opcao == 0) {
			contador = 1;
			system("clear");
		}
		else {

			char comando[45] = "sudo apt-get install ", comando_aplicativo[45] = "snap install ", comando_versao[35] = "apt-show-versions ", recurso[20];

			switch(opcao) {

				case 1:
					putchar(10);

					system("sudo apt-get update");
					break;

				case 2:
					putchar(10);

					printf("Digite o nome do pacote que deseja baixar: ");
					scanf("%s", recurso);
					putchar(10);

					system(strcat(comando, recurso));

					break;

				case 3:
					putchar(10);

					printf("Digite o nome do programa/aplicativo que deseja baixar: ");
					scanf("%s", recurso);
					putchar(10);

					system(strcat(comando_aplicativo, recurso));

					break;

				case 4:
					putchar(10);

					printf("Digite o nome do pacote/aplicativo que deseja verificar a versão: ");
					scanf("%s", recurso);
					putchar(10);

					system(strcat(comando_versao, recurso));

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

	return 0;

}
