#include <stdio.h>
#include <stdlib.h>
#include "ModulosAssinaturas.h"

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