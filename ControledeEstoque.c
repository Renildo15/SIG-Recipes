#include <stdio.h>
#include <stdlib.h>
#include "ControledeEstoque.h"
#include "Data.h"
#include "ValidaQuant.h"
#include "validaNome.h"
#include "Preco.h"
#include "limpaTela.h"

typedef struct data Data;
typedef struct produto Produto;

struct data{
	int  dia;
	int  mes;
	int  ano;
};

struct produto{
	char produto[21];
	char pre[11];
	float preco;
	char quant[11];
	float Kg;
};

void cadastrarProduto(void){
	Data data;
	Produto prod;
	int dataValida;
	float valPre;
	
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
	printf("///           = = = = =      Cadastrar produto      = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///             Nome do produto: ");
	scanf("%20[^\n]", prod.produto);
	getchar();

	while(!validaNome(prod.produto)){
		printf("///             Nome do produto: Invalido                                 ///\n");	
		printf("///             Nome do produto: ");
		scanf("%20[^\n]", prod.produto);
		getchar();
	}
	printf("///             Data de Validade: \n");
	printf("///             Dia: ");
	scanf("%d", &data.dia);
	printf("///             Mês: ");
	scanf("%d", &data.mes);
	printf("///             Ano: ");
	scanf("%d", &data.ano);
	setbuf(stdin,NULL);
	dataValida = validacao (data.dia,data.mes,data.ano);
	
	while(!dataValida){
		
		printf("///             Data de Validade: invalido                                ///\n");	
		printf("///             Dia: ");
		scanf("%d", &data.dia);
		printf("///             Mês: ");
		scanf("%d", &data.mes);
		printf("///             Ano: ");
		scanf("%d", &data.ano);
		setbuf(stdin,NULL);
		data.dia = (int)data.dia ;data.mes=(int)data.mes; data.ano = (int)data.ano;
		dataValida = validacao (data.dia,data.mes,data.ano);
	}
	// printf("///             %02d/%02d/%d                                               ///\n", data.dia, data.mes, data.ano);
	// printf("///             Valido                                                     ///\n");
	printf("///             Valor Pago: ");
	scanf("%10[^\n]",prod.pre);
	setbuf(stdin,NULL);
	prod.preco = atof(prod.pre);
	valPre = validaPreco(&prod.preco);

	while(!valPre){
		printf("///             Valor Pago: ");
		scanf("%f",&prod.preco);
		setbuf(stdin,NULL);
		valPre = validaPreco(&prod.preco);

	}

	// printf("///             R$ %.2f                                                   ///\n",prod.preco);
	printf("///             Kg/Gramas: ");
	scanf("%10[^\n]",prod.quant);
	setbuf(stdin,NULL);
	prod.Kg = atof(prod.quant);
	ValidaQuant(prod.Kg);
	while (!prod.Kg){
				printf("///             Kg/Gramas: Invalido                                      ///\n");
				printf("///             Kg/Gramas: ");
				scanf("%10[^\n]",prod.quant);
				setbuf(stdin,NULL);
				prod.Kg = atof(prod.quant);
				ValidaQuant(prod.Kg);

	}
	// printf("///             %.3f Kg                                                  ///\n",prod.Kg);
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void analisarEstoque(void){
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
	printf("///           = = = = =      Analisar estoque       = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                        Produtos estocados                             ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();

}

void reabastecerEstoque(void){
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
	printf("///           = = = = =     Reabastecer estoque     = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Nome do produto que está em falta:                          ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void relatorioSaida(void){
	char nome[101] = "#Feijoada";
	char nome1[101] = "#Lasanha";
	char nome2[101] = "#Yakisoba";

	char pr[101] = "R$ 10.00";
	char pr1[101] = "R$ 12.50";
	char pr2[101] = "R$ 20.00";

	char kg[101] = "2.900 Kg";
	char kg1[101] = "2.000 Kg";
	char kg2[101] = "1.000 Kg";
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
	printf("///           = = = = =     Relatorio das Saidas     = = = = =            ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("///                   Valores gastos por ingrediente                      ///\n");
	printf("///-----------------------------------------------------------------------///\n");
	for(int i = 0;i <1;i++){
		
		printf("///    %s- ", nome);
		printf("%s por ",pr);
		printf("%s                                   ///\n",kg);
		printf("///    %s- ", nome1);
		printf("%s por ",pr1);
		printf("%s                                    ///\n",kg1);
		printf("///    %s- ", nome2);
		printf("%s por ",pr2);
		printf("%s                                   ///\n",kg2);
	}
	printf("///                                                                       ///\n");
	printf("///    Apenas um exemplo de como funcionara a funcao.                     ///\n");
	printf("///                  Em desenvolvimento.                                  ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	getchar();
}

