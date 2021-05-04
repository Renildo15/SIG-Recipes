#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "valid.h"
#include "Struct.h"
#include "moduloReceita.h"

void buscaporIngrediente(void){
	Prato* prato;
	char* nomIng;
	nomIng = TelabuscaporIngrediente();

	prato = PesquisaIng(nomIng);

	exibirTudo(prato);

	free(prato);

}

char* TelabuscaporIngrediente(void){
	char* ing;
	ing = (char*) malloc(sizeof(char));
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =         Receitas Culinárias         = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @R.Rabi - Jan, 2021                      ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =    Buscar por Ingrediente   = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Nome do ingrediente: ");
	scanf("%20[^\n]",ing);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();

	return ing;

}


Prato* PesquisaIng(char* nom){
	FILE* fp;
	Prato* nomIng;

	nomIng = (Prato*) malloc(sizeof(Prato));
	fp = fopen("Receitas.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}
	while(!feof(fp)){
		fread(nomIng,sizeof(Prato),1,fp);
		if(strcmp(nomIng->ingredientes,nom) == 0){
			fclose(fp);
			return nomIng;
		}
	}
	fclose(fp);
	return NULL;
}