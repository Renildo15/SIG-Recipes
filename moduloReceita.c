#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "valid.h"
#include "Struct.h"
#include "moduloReceita.h"
#include "moduloEstoque.h"


void moduloReceitas(void){
	char opcao;
	do{
    opcao = menuReceitas();
		switch (opcao)
		{

			case '1':cadastrarReceita();
						break;

			case '2':buscarReceita();	 
						break;
		
			case '3':buscarporCategoria();
						break;
		
			case '4':buscaporIngrediente();
						break;

			case '5':deletar();
		}

	}while(opcao!= '0');

}

void cadastrarReceita(void){
	Prato* prato;

	prato = preencherTelareceitas();

	gravarReceita(prato);

	free(prato);
}


void buscarReceita(void){
	Prato* prato;
	char* nom;

	nom = telabuscarReceita();

	prato = pesquisarReceita(nom);

	exibirTudo(prato);

	free(prato);

}


void deletar(void){
	Prato* prato;
	char* nom;

	nom = telabuscarReceita();
	prato = pesquisarReceita(nom);

	deletarReceita(prato);

	free(prato);
}

Prato* preencherTelareceitas(void){
	Prato* prato;
	limpaTela();
	float valPre;
	int op;
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =         Receitas Culinárias        = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @R.Rabi - Jan, 2021                      ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =      Cadastrar Receitas     = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");

	prato = (Prato*) malloc(sizeof(Prato));
	printf("///             Nome do prato: ");
	scanf("%20[^\n]", prato->nomePrato);
	getchar();

	while (!validaNome(prato->nomePrato)){
		printf("///             Nome do prato: Invalido                                   ///\n");	
		printf("///             Nome do prato: ");
		scanf("%20[^\n]", prato->nomePrato);
		getchar();
	}
	printf("///             Quantidade de ingredientes:");
	scanf("%i",&prato->quant);
	getchar();
	valQuant(prato->quant);
	while(!valQuant(prato->quant)){
			printf("///             Quantidade de ingredientes:Invalido!                     ///\n");
			printf("///             Quantidade de ingredientes:");
			scanf("%i",&prato->quant);
			getchar();
			valQuant(prato->quant);
			
	}
	for(int i = 0; i < prato->quant;++i){
		printf("///             Ingredientes: ");
		scanf("%10[^\n]", prato->ingredientes);
		PesquisaProd(prato->ingredientes);
		getchar();
			if(!PesquisaProd(prato->ingredientes)){
				TeladeAviso();
				return 0;
			}else{
					while (!validaNome(prato->ingredientes)){
						printf("///             Ingredientes: Invalido                                    ///\n");	
						printf("///             Ingredientes: ");
						scanf("%[^\n]", prato->ingredientes);
						getchar();

					}
			}
				
				
	}
		
					
	printf("///             Kg/Gramas: ");
	scanf("%10[^\n]",prato->quan);
	getchar();
	prato->Kg = atof(prato->quan);
	ValidaQuant(prato->Kg);
	while (!prato->Kg){
			printf("///             Kg/Gramas: Invalido                                      ///\n");
			printf("///             Kg/Gramas: ");
			scanf("%10[^\n]",prato->quan);
			getchar();
			prato->Kg = atof(prato->quan);
			ValidaQuant(prato->Kg);
	}
	printf("///             Modo de preparo: ");
	scanf("%100[^\n]",prato->preparo);
	getchar();
	while(!validaNome(prato->preparo)){
		printf("///             Modo de preparo: Invalido                                 ///\n");	
				
		printf("///             Modo de preparo: ");
		scanf("%100[^\n]",prato->preparo);
		getchar();

	}
	printf("///             Preco: ");
	scanf("%s",prato->pre);
	getchar();
	prato->preco = atof(prato->pre);
	valPre = validaPreco(&prato->preco);

	while(!valPre){
		printf("///             Preco: ");
		scanf("%f",&prato->preco);
		getchar();
		valPre = validaPreco(&prato->preco);

	}
	printf("///             Categoria: ");
	scanf("%20[^\n]", prato->categoria);
	getchar();
	while(!validaNome(prato->categoria)){
		printf("\n///             Preco: Invalido                                           ///\n");	
		printf("\n///             Tente novamente!                                          ///\n");
		printf("///             Categoria: ");
		scanf("%20[^\n]", prato->categoria);
		getchar();
	}
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	prato->status = 'D';
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();

	return prato;
}




char menuReceitas() {
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
	printf("///           = = = = =         Menu Receitas       = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar receitas                                       ///\n");
	printf("///           2. Buscar receita                                           ///\n");
	printf("///           3. Buscar receitas por categoria                            ///\n");
	printf("///           4. Buscar receita por ingrediente                           ///\n");
	printf("///           5. Deletar Receita                                          ///\n");
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

char* telabuscarReceita(void){
	char* nom;
	nom = (char*) malloc(sizeof(char));
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
	printf("///           = = = = =       Buscar Receita        = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Nome da Receita: ");
	scanf("%20[^\n]",nom);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return nom;
}



void deletarReceita(Prato* Rec) {
	FILE* fp;
	Prato* recs;
	char nomRecei[21];
	int achou = 0;

	if(Rec == NULL){
		printf("///                       Não existe está receita                         ///\n");
	}else{
		recs = (Prato*)  malloc(sizeof(Prato));
		fp = fopen("Receitas.dat","r+b");
		if(fp == NULL){
			printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    	printf("Não é possível continuar este programa...\n");
			exit(1);
		}
		while(!feof(fp)){
			fread(recs,sizeof(Prato),1,fp);
			if(strcmp(recs->nomePrato,Rec->nomePrato)==0 && (recs->status!='x')){
				achou = 1;
				recs->status = 'x';
				fseek(fp,-1*sizeof(Prato),SEEK_CUR);
				fwrite(recs, sizeof(Prato),1,fp);
				printf("\nReceita excluida com sucesso!\n");
				getchar();

			}
		}
		if(!achou){
			printf("\nReceita não encontrada!\n");
			getchar();
		}
		fclose(fp);
	} 

}


void gravarReceita(Prato* Rec){
	FILE* fp;
	fp = fopen("Receitas.dat","ab");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	fwrite(Rec, sizeof(Prato), 1,fp);
	fclose(fp);
}



Prato* pesquisarReceita(char* nom){
	FILE* fp;
	Prato* nomRec;

	nomRec = (Prato*) malloc(sizeof(Prato));
	fp = fopen("Receitas.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}

	while(!feof(fp)){
		fread(nomRec,sizeof(Prato),1,fp);
		if(strcmp(nomRec->nomePrato, nom) == 0 && (nomRec->status != 'x')){
			fclose(fp);
			return nomRec;
		}
	}

	fclose(fp);
	return NULL;
}

Prato* pesquisarIngre(char* nom){
	FILE* fp;
	Prato* nomPro;
	nomPro = (Prato*) malloc(sizeof(Prato));

	fp = fopen("Produtos.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	while(!feof(fp)){
		fread(nomPro,sizeof(Prato),1,fp);
		if(strcmp(nomPro->nomePrato,nom) == 0 && (nomPro->status != 'x')){
			fclose(fp);
			return nomPro;
		}
	}
	fclose(fp);
	return NULL;
}

void exibirTudo(Prato* Re){
	char situacao[21];
	if(Re == NULL){
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
		printf("///           = = = = =      Exibicao completa     = = = = =              ///\n");
		printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
		printf("///                                                                       ///\n");
		printf("/// Nome do prato: %s     ///\n",Re->nomePrato);
		printf("/// Ingredientes:  %s     ///\n",Re->ingredientes);
		printf("/// Kg/gramas:     %.3f		///\n",Re->Kg);
		printf("/// Preparo:       %s			///\n",Re->preparo);
		printf("/// Preco:         R$%.2f	///\n",Re->preco);
		printf("/// Categoria:     %s			///\n",Re->categoria);
		if(Re->status == 'D'){
			strcpy(situacao,"Disponivel");
		}else if(Re->status == 'I'){
			strcpy(situacao,"Indisponivel");
		}else{
			strcpy(situacao, "Não informada");
		}
		printf("/// Status:       %s     ///\n",situacao);
		printf("///                                                                       ///\n");
		printf("/////////////////////////////////////////////////////////////////////////////\n");
		printf("\n");
		
	}

	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}








