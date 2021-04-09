#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menuPrincipal.h"
#include "ValidaQuant.h"
#include "validaNome.h"
#include "Preco.h"
#include "limpaTela.h"
#include "valQuant.h"

typedef struct prato Prato;
typedef struct ingredientes Ingredientes;

struct prato{
	char nomePrato[21];
	char Ingredientes[101];
	char pre[11];
	float preco;
	char categoria[21];
	int quant;
};

struct ingredientes{
	char preparo[101];
	char quan[11];
	float Kg;
};

char menuPrincipal (void){
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
	printf("///           1. Cadastrar receitas                                       ///\n");
	printf("///           2. Consultar receitas                                       ///\n");
	printf("///           3. Consultar preços das comidas                             ///\n");
	printf("///           4. Controle de estoque                                      ///\n");
	printf("///           5. Deletar Receita                                          ///\n");
	printf("///           6. Relátorios                                               ///\n");
	printf("///           7. Sobre o projeto                                          ///\n");
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



void cadastrarReceita(void){
	limpaTela();
	Prato prato;
	Ingredientes ingre;
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
	printf("///             Nome do prato: ");
	scanf("%20[^\n]", prato.nomePrato);
	getchar();

	while (!validaNome(prato.nomePrato)){
		printf("///             Nome do prato: Invalido                                   ///\n");	
		printf("///             Nome do prato: ");
		scanf("%20[^\n]", prato.nomePrato);
		getchar();
	}
	printf("///             Quantidade de ingredientes:");
	scanf("%i",&prato.quant);
	getchar();
	valQuant(prato.quant);
	while(!valQuant(prato.quant)){
			printf("///             Quantidade de ingredientes:Invalido!                     ///\n");
			printf("///             Quantidade de ingredientes:");
			scanf("%i",&prato.quant);
			getchar();
			valQuant(prato.quant);
			
		}
	for(int i = 0; i < prato.quant;++i){
		printf("///             Ingredientes: ");
		scanf("%100[^\n]", prato.Ingredientes);
		getchar();
		while (!validaNome(prato.Ingredientes)){
			printf("///             Ingredientes: Invalido                                    ///\n");	
			printf("///             Ingredientes: ");
			scanf("%[^\n]", prato.Ingredientes);
			getchar();

		}
		printf("///             Kg/Gramas: ");
		scanf("%10[^\n]",ingre.quan);
		setbuf(stdin,NULL);
		ingre.Kg = atof(ingre.quan);
		ValidaQuant(ingre.Kg);
		while (!ingre.Kg){
			printf("///             Kg/Gramas: Invalido                                      ///\n");
			printf("///             Kg/Gramas: ");
			scanf("%10[^\n]",ingre.quan);
			setbuf(stdin,NULL);
			ingre.Kg = atof(ingre.quan);
			ValidaQuant(ingre.Kg);
		}
	}
	printf("///             %.3f Kg                                                  ///\n",ingre.Kg);
	printf("///             Modo de preparo: ");
	scanf("%100[^\n]",ingre.preparo);
	getchar();
	while(!validaNome(ingre.preparo)){
		printf("///             Modo de preparo: Invalido                                 ///\n");	
		
		printf("///             Modo de preparo: ");
		scanf("%100[^\n]",ingre.preparo);
		getchar();

	}
	printf("///             Preco: ");
	scanf("%s",prato.pre);
	setbuf(stdin,NULL);
	prato.preco = atof(prato.pre);
	valPre = validaPreco(&prato.preco);

	while(!valPre){
		printf("///             Preco: ");
		scanf("%f",&prato.preco);
		setbuf(stdin,NULL);
		valPre = validaPreco(&prato.preco);
		setbuf(stdin,NULL);

	}
	printf("///             R$ %.2f                                                   ///\n",prato.preco);
	getchar();
	printf("///             Categoria: ");
	scanf("%[^\n]", prato.categoria);
	getchar();
	while(!validaNome(prato.categoria)){
		printf("\n///             Preco: Invalido                                           ///\n");	
		printf("\n///             Tente novamente!                                          ///\n");
		printf("///             Categoria: ");
		scanf("%[^\n]", prato.categoria);
		getchar();
	}
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

char consultarReceita(void) {
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
	printf("///           = = = = =      Consultar Receitas     = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Buscar receita                                           ///\n");
	printf("///           2. Buscar receitas por categoria                            ///\n");
	printf("///           3. Buscar receita por ingrediente                           ///\n");
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

char consultarPreco(void){
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
	printf("///           = = = = =       Consultar Preços      = = = = =             ///\n");
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

char controleEstoque(void) {
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
	printf("///           = = = = =      Controle de Estoque    = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar produto                                        ///\n");
	printf("///           2. Analisar estoque                                         ///\n");
	printf("///           3. Reabastecer o estoque                                    ///\n");
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

void deletarReceita(void) {
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
	printf("///           = = = = =       Deletar receita       = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///             Buscar nome da receita:                                   ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();

}

char relatorios(void){
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
	printf("///           = = = = =          Relatorios         = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Relatorio das pratos                                     ///\n");
	printf("///           2. Relatorio dos precos                                     ///\n");
	printf("///           3. Relatorio de saida                                       ///\n");
	printf("///           4. Relatorio dos ingredientes                               ///\n");
	printf("///           5. Relatorio das categorias                                 ///\n");
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

void relatorioPratos(void){
	char nome[101] = "#Feijoada";
	char nome1[101] = "#Lasanha";
	char nome2[101] = "#Yakisoba";
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
	printf("///           = = = = =     Relatorio dos Pratos    = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///                         Nomes dos Pratos                              ///\n");
	printf("///-----------------------------------------------------------------------///\n");
	for(int i = 0;i <1;i++){
		
		printf("///    %s                                                          ///\n", nome);
		printf("///    %s                                                           ///\n", nome1);
		printf("///    %s                                                          ///\n", nome2);
	}
	printf("///                                                                       ///\n");
	printf("///    Apenas um exemplo de como funcionara a funcao.                     ///\n");
	printf("///                  Em desenvolvimento.                                  ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	getchar();
}

void relatorioPrecos(void){
	char pr[] = "#R$ 100.00";
	char pr2[] = "#R$ 89.90 ";
	char pr3[] = "#R$ 80.50";
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
	for(int i = 0;i <1;i++){
		
		printf("///    %s                                                         ///\n", pr);
		printf("///    %s                                                         ///\n", pr2);
		printf("///    %s                                                          ///\n", pr3);
	}
	printf("///                                                                       ///\n");
	printf("///    Apenas um exemplo de como funcionara a funcao.                     ///\n");
	printf("///                  Em desenvolvimento.                                  ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	getchar();
}

void relatorioIngredientes(void){
	char nome[101] = "#Feijão";
	char nome1[101] = "#Arroz";
	char nome2[101] = "#Carne";
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
	printf("///           = = = = =  Relatorio dos Ingredientes = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///                  Nomes dos Ingredientes                               ///\n");
	printf("///-----------------------------------------------------------------------///\n");
	for(int i = 0;i <1;i++){
		
		printf("///    %s                                                            ///\n", nome);
		printf("///    %s                                                             ///\n", nome1);
		printf("///    %s                                                             ///\n", nome2);
	}
	printf("///    Apenas um exemplo de como funcionara a funcao.                     ///\n");
	printf("///                  Em desenvolvimento.                                  ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	getchar();
}

void relatorioCategoria(void){
	char nome[101] = "#Doces";
	char nome1[101] = "#Salgados";
	char nome2[101] = "#Comida japonesa";
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
	printf("///           = = = = =   Relatorio das categorias  = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///                     Nome das Categorias                               ///\n");
	printf("///-----------------------------------------------------------------------///\n");
	for(int i = 0;i <1;i++){
		
		printf("///    %s                                                             ///\n", nome);
		printf("///    %s                                                          ///\n", nome1);
		printf("///    %s                                                   ///\n", nome2);
	}
	printf("///                                                                       ///\n");
	printf("///    Apenas um exemplo de como funcionara a funcao.                     ///\n");
	printf("///                  Em desenvolvimento.                                  ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	getchar();
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
