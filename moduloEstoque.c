#include <stdio.h>
#include <stdlib.h>
#include "moduloEstoque.h"
#include "Relatorios.h"
#include "valid.h"


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
};

void moduloEstoque(Produto* nom){
	char opcao;
	do{
		opcao = menuEstoque();
		switch (opcao)
		{
			case '1':cadastrarProduto();
						break;
		
			case '2':analisarEstoque();
						break;

			case '3':reabastecerEstoque();
							
						break;

			case '4': relatorioSaida(nom);
				break;
		}
	}while(opcao!='0');
}


void cadastrarProduto(void){
	Produto* prod;
	
	prod = TelacadastrarProduto();

	gravarProduto(prod);

	free(prod);
}

void analisarEstoque(void){
	Produto* prod;

	TelaanalisarEstoque(prod);
}

void reabastecerEstoque(void){
	cadastrarProduto();
}

char menuEstoque(void) {
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
	printf("///           = = = = =        Menu Estoque         = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Cadastrar produto                                        ///\n");
	printf("///           2. Analisar estoque                                         ///\n");
	printf("///           3. Reabastecer o estoque                                    ///\n");
	printf("///           4. Relatorio de saida                                       ///\n");
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

Produto* TelacadastrarProduto(void){
	Produto* prod;
	int dataValida;
	float valPre;
	prod = (Produto*) malloc(sizeof(Produto));
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
	printf("///             Nome do Produto: ");
	scanf("%20[^\n]", prod->Nomeproduto);
	getchar();

	while (!validaNome(prod->Nomeproduto)){
		printf("///             Nome do produto: Invalido                                  ///\n");	
		printf("///             Nome do produto: ");
		scanf("%20[^\n]", prod->Nomeproduto);
		getchar();
	}
	printf("///             Data de Validade: \n");
	printf("///             Dia: ");
	scanf("%d", &prod->vali.dia);
	getchar();
	printf("///             Mês: ");
	scanf("%d", &prod->vali.mes);
	getchar();
	printf("///             Ano: ");
	scanf("%d", &prod->vali.ano);
	getchar();
	dataValida = validacao (prod->vali.dia,prod->vali.mes,prod->vali.ano);
	
	while(!dataValida){
		
		printf("///             Data de Validade: invalido                                ///\n");	
		printf("///             Dia: ");
		scanf("%d",  &prod->vali.dia);
		getchar();
		printf("///             Mês: ");
		scanf("%d",&prod->vali.mes);
		getchar();
		printf("///             Ano: ");
		scanf("%d", &prod->vali.ano);
		getchar();
		prod->vali.dia = (int)prod->vali.dia ;prod->vali.mes=(int)prod->vali.mes; prod->vali.ano = (int)prod->vali.ano;
		dataValida = validacao (prod->vali.dia,prod->vali.mes,prod->vali.ano);
	}
	printf("///             Valor Pago: ");
	scanf("%10[^\n]",prod->pre);
	getchar();
	prod->preco = atof(prod->pre);
	valPre = validaPreco(&prod->preco);

	while(!valPre){
		printf("///             Valor Pago: ");
		scanf("%f",&prod->preco);
		getchar();
		valPre = validaPreco(&prod->preco);

	}

	printf("///             Kg/Gramas: ");
	scanf("%10[^\n]",prod->quant);
	getchar();
	prod->Kg = atof(prod->quant);
	ValidaQuant(prod->Kg);
	while (!prod->Kg){
				printf("///             Kg/Gramas: Invalido                                      ///\n");
				printf("///             Kg/Gramas: ");
				scanf("%10[^\n]",prod->quant);
				getchar();
				prod->Kg = atof(prod->quant);
				ValidaQuant(prod->Kg);

	}
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();

	return prod;
}



void TelaanalisarEstoque(Produto* est){
	if(est == NULL){
			printf("///                     Não existe esse dado                               ///\n");
	}
	char situacao [11];
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
	printf("///                                                                       ///\n");
	printf("/// # Nome:%s                                                             ///\n",est->Nomeproduto);
	printf("/// # Data de validade: %02d/%02d/%d                                      ///\n",est->vali.dia,est->vali.mes,est->vali.ano);
	printf("/// # Valor pago:R$ %.2f                                                  ///\n",est->preco);
	printf("/// # Kg/gramas: %.3f                                                     ///\n",est->Kg);
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	////// em desenvolvimento

}



void relatorioSaida(Produto* sai){
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
	printf("///  # Saida:%s -> ", sai->Nomeproduto);
	printf("%.3f Kg/gramas por ",sai->Kg);
	printf("R$%.2f                             ///\n",sai->preco);
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	getchar();
	////// em desenvolvimento
}

void gravarProduto(Produto* pro){
	FILE* fp;
	fp = fopen("Produtos.dat","ab");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
		exit(1);
	}

	fwrite(pro, sizeof(Produto),1,fp);
	fclose(fp);
}
