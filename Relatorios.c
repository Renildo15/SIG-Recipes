#include <stdio.h>
#include <stdlib.h>
#include "Relatorios.h"
#include "limpaTela.h"
/////Exemplo de como a função funcionará
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