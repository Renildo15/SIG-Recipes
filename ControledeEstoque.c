#include <stdio.h>
#include <stdlib.h>
#include "ControledeEstoque.h"
#include "Data.h"
#include "ValidaQuant.h"
#include "validaNome.h"
#include "Preco.h"
#include "limpaTela.h"

void cadastrarProduto(void){
	char produto[20];
	int  dia;
	int  mes;
	int  ano;
	int  dataValida;
	char pre[11];
	float preco;
	float valPre;
	char quant[11];
	float Kg;
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
	scanf("%[^\n]", produto);
	getchar();
	while(!validaNome(produto)){
		printf("\n///             Invalido                                                  ///\n");	
		printf("\n///             Tente novamente!                                          ///\n");
		printf("///             Nome do produto: ");
		scanf("%[^\n]", produto);
		getchar();
	}
	printf("///             Data de Validade: \n");
	printf("///             Dia: ");
	scanf("%d", &dia);
	printf("///             Mês: ");
	scanf("%d", &mes);
	printf("///             Ano: ");
	scanf("%d", &ano);
	setbuf(stdin,NULL);
	dataValida = validacao (dia,mes,ano);
	
	while(!dataValida){
		
		printf("///                           invalido                               ///\n");	
		printf("///                          Tente novamente                         ///\n");	
		printf("///             Dia: ");
		scanf("%d", &dia);
		printf("///             Mês: ");
		scanf("%d", &mes);
		printf("///             Ano: ");
		scanf("%d", &ano);
		setbuf(stdin,NULL);
		dia = (int)dia ;mes=(int)mes; ano = (int)ano;
		dataValida = validacao (dia,mes,ano);
	}
	printf("///             %02d/%02d/%d                                               ///\n", dia, mes, ano);
	printf("///             Valido                                                     ///\n");
	getchar();
	printf("///             Valor Pago: ");
	scanf("%s",pre);
	setbuf(stdin,NULL);
	preco = atof(pre);
	valPre = validaPreco(&preco);

	while(!valPre){
		printf("///             Valor Pago: ");
		scanf("%f",&preco);
		setbuf(stdin,NULL);
		valPre = validaPreco(&preco);

	}

	printf("///             R$ %.2f                                                   ///\n",preco);
	getchar();
	printf("///             Kg/Gramas: ");
	scanf("%s",quant);
	setbuf(stdin,NULL);
	Kg = atof(quant);
	ValidaQuant(Kg);
	while (!Kg){
				printf("///             Invalido                                                  ///\n");
				printf("///             Kg/Gramas: ");
				scanf("%s",quant);
				setbuf(stdin,NULL);
				Kg = atof(quant);
				ValidaQuant(Kg);

	}
	printf("///             %.3f Kg                                                  ///\n",Kg);
	getchar();
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
