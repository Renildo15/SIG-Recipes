#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "valid.h"
#include "Str.h"
#include "moduloReceita.h"

void moduloPrecos(void){
	char opcao;
	Prato* Lista;
	Lista = NULL;

	do{
		opcao = menuPreco();
		switch(opcao)
		{
			case '1':TelaexibirTabela();
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
void precoCategoria(void){
	Prato* prato;
	char* preCat;
	preCat = TelaprecoCategoria();

	prato = pesquisarCate(preCat);

	exibirTudo(prato);
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

char* TelaprecoCategoria(void){
	char* cate;
	cate = (char*) malloc(sizeof(char));
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
	printf("///           = = = = =     Preço por Categoria     = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Nome da categoria: ");
	scanf("%20[^\n]",cate);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return cate;
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



Prato* pesquisarCate(char* nom){
	FILE* fp;
	Prato* nomCat;

	nomCat = (Prato*) malloc(sizeof(Prato));
	fp = fopen("Receitas.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(nomCat,sizeof(Prato),1,fp);
		if(strcmp(nomCat->categoria, nom) == 0){
			fclose(fp);
			return nomCat;
		}
	}

	fclose(fp);
	return NULL;
}
//===============================================================================================================================================================================================================================================================

void ExibiPreco(Prato* pro){
  	printf("/// # Nome:%s                                                             ///\n",pro->nomePrato);
		printf("/// # Preço:R$ %.2f                                                       ///\n",pro->preco);
		
		// printf("/// # Kg/gramas: %.3f                                                     ///\n",pro->Kg);
}

void apagarListaPra(Prato** lista){
    Prato* pre;
    
    while (*lista != NULL){
   	    pre = *lista;
        *lista = (*lista)->prox;
        free(pre);
    }   
}

void TelaexibirTabela(void){
	char situacao [11];
	FILE* fp;
	Prato* preco;
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
		preco = (Prato*) malloc(sizeof(Prato));
		fp = fopen("Receitas.dat","rb");
		
		if(fp == NULL){
			printf("ERRO!");
		}else{
			while(fread(preco,sizeof(Prato),1,fp)){
				if(strcmp(&preco->status,"x") != 0){
					ExibiPreco(preco);
				}
			}
			printf("///                                                                       ///\n");
			printf("/////////////////////////////////////////////////////////////////////////////\n");
			printf("\n");
			getchar();
		}
		fclose(fp);
		
	
}