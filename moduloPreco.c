#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "valid.h"
#include "Struct.h"
#include "moduloReceita.h"

void moduloPrecos(void){
	char opcao;
	do{
		opcao = menuPreco();
		switch(opcao)
		{
			case '1':exibirTabela();
						break;

			case '2':precoporPrato();
						break;

			case '3':precoCategoria();
						break;
		}
	}while(opcao!='0');

}

void precoporPrato(void){
	Prato* prato;
	char* prec;

	prec = TelaprecoporPrato();

	prato = pesquisaPre(prec);

	exibirTudo(prato);

}
void exibirTabela(void){
	Prato* prato;
	TelaexibirTabela(prato);
///// em desenvolvimento
}


char menuPreco(void){
	limpaTela();
	char op;
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
	printf("///           = = = = =         Menu Preços         = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Exibir tabela de preços                                  ///\n");
	printf("///           2. Buscar preços por prato                                  ///\n");
	printf("///           3. Buscar preços por categoria                              ///\n");
	printf("///           0. Sair                                                     ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}

void relatorioPrecos(Prato* pre){
	if( pre == NULL){
		printf("///                        Nao existe esse preco!                         ///\n");
	}else{
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
		printf("///           = = = = =     Relatorio de Precos     = = = = =             ///\n");
		printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
		printf("///                                                                       ///\n");
		printf("///                                                                       ///\n");
		printf("///                         Precos dos Pratos                             ///\n");
		printf("///-----------------------------------------------------------------------///\n");
		printf("///   %s: R$%.2f                                                          ///\n",pre->nomePrato,pre->preco);
		printf("///                                                                       ///\n");
		printf("///                                                                       ///\n");
		printf("/////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		getchar();
		////// em desenvolvimento
	}
}

void TelaexibirTabela(Prato* preco ){
	char situacao [11];
	if(preco == NULL){
		printf("///                     Não existe esse dado                               ///\n");
	}else{
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
		printf("///           = = = = =   Exibir tabela de preços   = = = = =             ///\n");
		printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
		printf("///                                                                       ///\n");
		printf("///                               TABELA                                  ///\n");
		printf("///                                                                       ///\n");
		printf("///  Nome do prato: %s                                                    ///\n",preco->nomePrato);
		printf("///  Praço: %.2f                                                          ///\n",preco->preco);
		if(preco->status == 'D'){
			strcpy(situacao,"Disponivel");
		}else if(preco->status == 'I'){
			strcpy(situacao, "Indisponivel");
		}else{
			strcpy(situacao,"Não informado");
		}
		printf("///  Status: %s                                                           ///\n",situacao);
		printf("///                                                                       ///\n");
		printf("/////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		getchar();
	}
}

char* TelaprecoporPrato(void){
	char* prec;
	prec = (char*) malloc(sizeof(char));
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
	printf("///           = = = = =        Preço por prato      = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Nome do prato: ");
	scanf("%20[^\n]",prec);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return prec;
}


Prato* pesquisaPre(char* nom){
	FILE* fp;
	Prato* nomPre;

	nomPre = (Prato*) malloc(sizeof(Prato));
	fp = fopen("Receitas.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(nomPre,sizeof(Prato),1,fp);
		if(strcmp(nomPre->nomePrato, nom) == 0){
			fclose(fp);
			return nomPre;
		}
	}

	fclose(fp);
	return NULL;
}