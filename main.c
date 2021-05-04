#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloReceita.h"
#include "moduloEstoque.h"
#include "Relatorios.h"
#include "valid.h"

int menuPrincipal(void);
void menuSobre(void);
void fimProg(void);



typedef struct prato Prato;
typedef struct data Data;
typedef struct produto Produto;

struct data{
	int  dia;
	int  mes;
	int  ano;
};

struct produto{
	char Nomeproduto[21];
	char pre[11];
	float preco;
	char quant[11];
	float Kg;
	Data vali;
	struct produto* prox;
};
struct prato{
	char nomePrato[21];
	char ingredientes[101];
	char pre[11];
	float preco;
	char categoria[21];
	int quant;
	char preparo[101];
	char quan[11];
	float Kg;
	char status;
};

int main(void) {
	Prato* prato;
	Produto* prod;
	prato = (Prato*) malloc(sizeof(Prato));
	prod = (Produto*) malloc(sizeof(Produto));


	char opcao;
    menuSobre();
	do{
		opcao = menuPrincipal();
		switch (opcao)
		{
		case '1':moduloEstoque(prod);
						 
			break;
		
		case '2':moduloPrecos();
					
			break;

		case '3':moduloReceitas();
		    break;

		case '4':moduloRelatorios();
			break;

		case '5':menuSobre();
			break;
	
		}
	}while(opcao != '0');
	fimProg();
	free(prato);
	free(prod);
return 0;
}

int menuPrincipal(){
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
		printf("///           = = = = = = = =  Menu Principal = = = = = = = =             ///\n");
		printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
		printf("///                                                                       ///\n");
		printf("///           1. Modulo Estoque                                           ///\n");
		printf("///           2. Modulo Preços                                            ///\n");
		printf("///           3. Modulo Receitas                                          ///\n");
		printf("///           4. Modulo Relatorio                                         ///\n");
		printf("///           5. Sobre o projeto                                          ///\n");
		printf("///           0. Encerrar o programa                                      ///\n");
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

	
void menuSobre(void) {
		limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///            Projeto Um Caderno Virtual de Receitas Culinárias            ///\n");
    printf("///              = == ==       RECIPES       = == ==                        ///\n");
    printf("///                Developed by  @Renildo Rabi - Jan, 2021                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///  = == == SIG-Recipes: Um Caderno Virtual de Receitas Culinárias == == = ///\n");
    printf("///                                                                         ///\n");
    printf("///  Fábricas de produtos alimentícios, restaurantes, lanchonetes,          ///\n");
    printf("///  padarias, ou até mesmo usuários domésticos necessitam de receita       ///\n");
    printf("///  para conduzir a preparação de determinados alimentos.                  ///\n");
    printf("///  A principio o objetivo do projeto é adicionar receitas de comidas,     ///\n");
    printf("///  procurar os tipos de pratos por ingrediente,saber os custos e          ///\n");
    printf("///  quantidades de ingredientes,a otimização do estoque e a categorização  ///\n");
    printf("///  das receitas.                                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///      Em desenvolvimento pelo aluno Renildo Rabi Vale Dos Santos         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void fimProg(void){
	limpaTela();
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =           FIM DO PROGRAMA           = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @R.Rabi - Jan, 2021                      ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	getchar();
}

void TeladeAviso(void){
	limpaTela();
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///          ===================================================          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          = = = =               AVISO!                = = = =          ///\n");
	printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
	printf("///          ===================================================          ///\n");
	printf("///                Developed by  @R.Rabi - Jan, 2021                      ///\n");
	printf("///                                                                       ///\n");
	printf("/// Esse ingrediente não está cadastardo no sistema. Para poder usar este ///\n");
	printf("/// Modulo, primeiro acesse o Modulo estoque e cadastre os ingredientes   ///\n");
	printf("/// necessários para a receita.                                           ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	getchar();
	
}