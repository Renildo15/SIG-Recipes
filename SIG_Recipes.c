#include <stdio.h>
#include <stdlib.h>

char menuPrincipal (void);
void cadastrarReceita (void);
char consultarReceita (void);
char consultarPreco (void);
char controleEstoque (void);
void menuSobre (void);
void prepararReceita (void);
void fimProg (void);

void moduloConsultarReceita(void);
void buscarReceita (void);
void buscarporCategoria (void);
void buscaporIngrediente (void);

void moduloconsultarPreco(void);
void exibirTabela (void);
void precoporPrato (void);
void precoCategoria (void);

void modulocontroledeEstoque(void);
void cadastrarProduto (void);
void analisarEstoque (void);
void reabastecerEstoque (void);
void relatorioProdutos (void);

int main(void) {
	char opcao;

    menuSobre();
	do{
		opcao = menuPrincipal();
		switch (opcao)
		{
		case '1':cadastrarReceita();
			break;
		
		case '2':moduloConsultarReceita();
			break;

		case '3':moduloconsultarPreco();
		    break;

		case '4':modulocontroledeEstoque();
			break;

		case '5':prepararReceita();
			break;

		case '6':menuSobre();
			break;
		}
	}while(opcao != '0');
	fimProg();
	return 0;
}