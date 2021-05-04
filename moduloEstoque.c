#include <stdio.h>
#include <stdlib.h>
#include "moduloEstoque.h"
#include "Relatorios.h"
#include "valid.h"
#include "string.h"


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
	char status[1];
	struct produto* prox;
};

void moduloEstoque(Produto* nom){
	char opcao;
	Produto* lista;
	lista = NULL;
	do{
		opcao = menuEstoque();
		switch (opcao)
		{
			case '1':cadastrarProduto();
						break;
		
			case '2':RelaProdutos();
						break;

			case '3': RelatorioSaida();
			
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
	printf("///           3. Relatorio de saida                                       ///\n");
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

//===============================================================================================================================================================================================================================================================================================================================================================================================///

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


Produto* PesquisaProd(char* nom){
	FILE* fp;
	Produto* nomIng;

	nomIng = (Produto*) malloc(sizeof(Produto));
	fp = fopen("Produtos.dat","rb");
	if(fp == NULL){
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
	}
	while(!feof(fp)){
		fread(nomIng,sizeof(Produto),1,fp);
		if(strcmp(nomIng->Nomeproduto,nom) == 0){
			fclose(fp);
			return nomIng;
		}
	}
	fclose(fp);
	return NULL;
}
//===============================================================================================================================================================================================================================================================//APAGAR SE DE ERRADO
void exibeRelProd(Produto* pro){
  	printf("/// # Nome:%s                                                             ///\n",pro->Nomeproduto);
		printf("/// # Data de validade: %02d/%02d/%d                                      ///\n",pro->vali.dia,pro->vali.mes,pro->vali.ano);
		// printf("/// # Valor pago:R$ %.2f                                                  ///\n",pro->preco);
		// printf("/// # Kg/gramas: %.3f                                                     ///\n",pro->Kg);
}

void RelSaida(Produto* pro){
  	printf("/// # Nome:%s                                                             ///\n",pro->Nomeproduto);
		printf("/// # Valor pago:R$ %.2f                                                  ///\n",pro->preco);
}





void apagarLista(Produto **lista){
    Produto *pro;
    
    while (*lista != NULL){
   	    pro = *lista;
        *lista = (*lista)->prox;
        free(pro);
    }   
}
void RelaProdutos(void){
	FILE *fp;
  Produto* pro;
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

	pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("Produtos.dat", "rb");

    if (fp == NULL) {
        printf("ERRO");
    }else{
        while(fread(pro, sizeof(Produto), 1, fp)) {
            if(strcmp(pro->status,"x") != 0){
                exibeRelProd(pro);
            }
        }
        printf("\n");
        printf("////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}

void RelatorioSaida(void){
	FILE* fp;
	Produto* pro;
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
		printf("///-----------------------------------------------------------------------///\n");	
		pro = (Produto*) malloc(sizeof(Produto));
    fp = fopen("Produtos.dat", "rb");

    if (fp == NULL) {
        printf("ERRO");
    }else{
        while(fread(pro, sizeof(Produto), 1, fp)) {
            if(strcmp(pro->status,"x") != 0){
                RelSaida(pro);
            }
        }
        printf("\n");
        printf("////////////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(fp);
}


