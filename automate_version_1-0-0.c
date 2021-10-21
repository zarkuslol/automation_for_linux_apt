/*

	Automate version 1.0

	Author: zarkus

	Software that simplifies some tasks on Linux to buy time or for begginers

	Written specifically for Ubuntu and Debian (that uses apt-get), but you can modify
	this code to make it run on other OS

	Only available in Portuguese, the English version will be launched soon

	It can be used and modified for everybody... Enjoy it :) !

	Changes: Modularization of the entire code, it's as clean as possible, but need some changes
	regarding the names of the modules

*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menus
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

// Options 
void option1() {

	system("clear");
	system("sudo apt-get update");

}

void option2() {

	system("clear");

	printf("Digite o nome do pacote que deseja baixar: ");
	scanf("%s", resource);
	putchar(10);

	system(strcat(command, resource));

}

void option3() {

	system("clear");

	printf("Digite o nome do pacote que deseja baixar: ");
	scanf("%s", recurso);
	putchar(10);

	system(strcat(comando, recurso));

}

void option4() {

	system("clear");

	printf("Digite o nome do pacote/aplicativo que deseja verificar a versão: ");
	scanf("%s", recurso);
	putchar(10);

	system(strcat(comando_versao, recurso));

}

void option5() {

	system("clear");

	system("sudo apt-get autoclean");
	system("sudo apt-get clean");

}

// Modules
void validation(int *n, int *i, int *array[], int *option) {

	for (int j = 0; j < n; j++) {
		if (valores_aceitos[j] == opcao) {
			i = 1;
			break;
		}
	}

}

void options() {

	char comando[45] = "sudo apt-get install ",
         comando_aplicativo[45] = "snap install ",
         comando_versao[35] = "apt-show-versions ",
         recurso[20];

	switch(opcao) {
		case 1:
			option1();
			break;
		case 2:
			option2();
			break;
		case 3:
			option3();
			break;
		case 4:
			option4();
			break;
		case 5:
			option5();
			break;
	}

}

void loop_control(int *contador) {

	int continuar;
	printf("Deseja continuar rodando o programa? (1 - sim / 2 - não): ");
	scanf("%d", &continuar);

	if (continuar == 1) {
		system("clear");
	}
	else {
		system("clear");
		contador = 1;
	}

}

void test1(int *opcao) {

	menu();
	scanf("%d", &opcao);

	validation(&n, &i, &valores_aceitos, &opcao);

}

void test2(int *opcao) {

	system("clear");

	menu_error();
	scanf("%d", &opcao);

	validation(&n, &i, &valores_aceitos, &opcao);

}

void verification(int *opcao, int *contador) {

	if (opcao == 0) {
		contador = 1;
		system("clear");
	}
	else {
		options();
	}
	putchar(10);
	loop_control(&contador);

}

void inside_loop(int *opcao, int *i) {

	test1(&opcao);

	while (i == 0) {
		test2(&opcao);
	}
		
	if (i == 1) {	
		verification(&opcao, &contador);
	}

}

// Main function
int main() {

	system("clear");

	int valores_aceitos[6] = {0, 1, 2, 3, 4, 5},
	    i = 0, 
	    n = 6, 
	    x = 0;

	int contador = 0;
	while (contador == 0) {

		int opcao;
		inside_loop(&opcao, &i);

	}

	return 0;

}
