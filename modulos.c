#include <stdio.h>
#include "modulos.h"
#include "menuPrincipal.h"
#include "ConsultarReceitas.h"
#include "ConsultarPrecos.h"
#include "ControledeEstoque.h"
#include "Relatorios.h"

void moduloConsultarReceita(void){
	char opcao;
	do{
    opcao = consultarReceita();
		switch (opcao)
		{
			case '1':buscarReceita();
						break;
		
			case '2':buscarporCategoria();
						break;
		
			case '3':buscaporIngrediente();
						break;
		}

	}while(opcao!= '0');

}
void moduloconsultarPreco(void){
	char opcao;
	do{
		opcao = consultarPreco();
		switch(opcao)
		{
			case '1':exibirTabela();
						break;

			case '2':precoporPrato();
						break;

			case '3':precoCategoria();
						break;
		}
	}while(opcao!='0');

}

void modulocontroledeEstoque(void){
	char opcao;
	do{
		opcao = controleEstoque();
		switch (opcao)
		{
			case '1':cadastrarProduto();
						break;
		
			case '2':analisarEstoque();
						break;

			case '3':reabastecerEstoque();
						break;
		}
	}while(opcao!='0');
}

void moduloRelatorios(void){
	char opcao;
	do{
		opcao = relatorios();
		switch (opcao)
		{
			case '1': relatorioPratos();
				break;

			case '2': relatorioPrecos();
				break;

			case '3': relatorioSaida();
				break;

			case '4': relatorioIngredientes();
				break;

			case '5': relatorioCategoria();
				break;
		}
	}while(opcao!='0');
}
