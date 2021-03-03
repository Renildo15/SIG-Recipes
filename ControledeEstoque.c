#include <stdio.h>
#include "ControledeEstoque.h"
#include "Data.h"
#include "Preco.h"

void cadastrarProduto(void){
	char produto[20];
	int  dia;
	int  mes;
	int  ano;
	int  dataValida;
	int  real;
	int  centavo;
	int  precoReal;
	int  precoCentavo;
	char quantidade[101];
	
	system("clear");
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
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", produto);
	getchar();
	printf("///             Data de Validade: \n");
	printf("///             Dia: ");
	scanf("%d", &dia);
	printf("///             Mês: ");
	scanf("%d", &mes);
	printf("///             Ano: ");
	scanf("%d", &ano);
	dataValida = validacao (dia,ano, mes);
	while(!dataValida){
		printf("///                           invalido                               ///\n");	
		printf("///                          Tente novamente                         ///\n");	
		printf("///             Dia: ");
		scanf("%d", &dia);
		printf("///             Mês: ");
		scanf("%d", &mes);
		printf("///             Ano: ");
		scanf("%d", &ano);
		dataValida = validacao (dia,ano, mes);

	}
	printf("///             %02d/%02d/%d                                               ///\n", dia, mes, ano);
	printf("///             Valido                                                     ///\n");
	getchar();
	printf("///             Valor Pago: \n");
	printf("///             Reais: ");
	scanf("%d", &real);
	printf("///             Centavos: ");
	scanf("%d", &centavo);
	precoReal = validaReal(real);
	precoCentavo =validaCentavo(centavo);
	while(!precoReal || !precoCentavo){

		
		printf("///             Invalido\n");
		printf("///             Tente novamente!                                          ///\n");
		printf("///             Valor Pago:                                               ///\n");
		printf("///             Reais: ");
		scanf("%d", &real);
		printf("///             Centavos: ");
		scanf("%d", &centavo);
		precoReal = validaReal(real);
		precoCentavo =validaCentavo(centavo);
	}
	
	printf("///              R$ %i.%02i                                                  ///\n", real, centavo);
	printf("///              Valido                                                      ///\n");

	getchar();
	printf("///             Quantidade: ");
	scanf("%[0-9,.]", quantidade);
	getchar();
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void analisarEstoque(void){
	system("clear");
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
	system("clear");
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

void relatorioProdutos(void){
	system("clear");
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
	printf("///           = = = = =    Relatorio dos Produtos   = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Nome do produto:                                            ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}