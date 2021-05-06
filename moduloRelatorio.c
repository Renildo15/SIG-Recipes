#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloReceita.h"
#include "moduloEstoque.h"
#include "Relatorios.h"
#include "valid.h"
#include "Struct.h"

void moduloRelatorios(void){
	char opcao;
	do{
		opcao = menuRelatorio();
		switch (opcao)
		{
			case '1': relatorioPratos();

				break;

			case '2':relatorioPrecos();
				        
				break;

			case '3':relatorioIngredientes();
								
				break;

			case '4':relatorioCategoria();
								
				break;
		}
	}while(opcao!='0');
}






char menuRelatorio(void){
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
	printf("///           1. Relatorio dos pratos                                     ///\n");
	printf("///           2. Relatorio dos precos                                     ///\n");
	printf("///           3. Relatorio dos ingredientes                               ///\n");
	printf("///           4. Relatorio das categorias                                 ///\n");
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
	FILE* fp;
	Prato* prato;
	limpaTela();
	printf("\n\n");
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
		prato = (Prato*) malloc(sizeof(Prato));
		fp = fopen("Receitas.dat","rb");
		
		if(fp == NULL){
			printf("ERRO!");
		}else{
			while(fread(prato,sizeof(Prato),1,fp)){
				if(strcmp(&prato->status,"x") != 0){
					ExibiPrato(prato);
				}
			}
			printf("///                                                                       ///\n");
			printf("/////////////////////////////////////////////////////////////////////////////\n");
			printf("\n");
			getchar();
		}
		fclose(fp);
		
	
}

void ExibiPrato(Prato* pro){
  	printf("/// # Nome:%s                                                             ///\n",pro->nomePrato);
}
		

void apagarListaRe(Prato** lista){
    Prato* pra;
    
    while (*lista != NULL){
   	    pra = *lista;
        *lista = (*lista)->prox;
        free(pra);
    }   
}

//------------------------------------------------------------------------------------------------------------///
//-----------------------------------------------------------------------------------------------------------///



void relatorioPrecos(void){
	FILE* fp;
	Prato* pre;
	limpaTela();
	printf("\n\n");
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
	printf("///           = = = = =     Relatorio dos Preços    = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
		pre = (Prato*) malloc(sizeof(Prato));
		fp = fopen("Receitas.dat","rb");
		
		if(fp == NULL){
			printf("ERRO!");
		}else{
			while(fread(pre,sizeof(Prato),1,fp)){
				if(strcmp(&pre->status,"x") != 0){
					ExibiPre(pre);
				}
			}
			printf("///                                                                       ///\n");
			printf("/////////////////////////////////////////////////////////////////////////////\n");
			printf("\n");
			getchar();
		}
		fclose(fp);
		
	
}

void ExibiPre(Prato* pro){
	printf("/// # Nome:  %s                                                              ///\n",pro->nomePrato);
  	printf("/// # Preço: R$%0.2f                                                        ///\n",pro->preco);
}
		

void apagarListaPre(Prato** lista){
    Prato* pra;
    
    while (*lista != NULL){
   	    pra = *lista;
        *lista = (*lista)->prox;
        free(pra);
    }   
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


void relatorioIngredientes(void){
		FILE* fp;
		Prato* ing;
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
		ing = (Prato*) malloc(sizeof(Prato));
		fp = fopen("Receitas.dat","rb");
		
		if(fp == NULL){
			printf("ERRO!");
		}else{
			while(fread(ing,sizeof(Prato),1,fp)){
				if(strcmp(&ing->status,"x") != 0){
					Exibiingr(ing);
				}
			}
			printf("///                                                                       ///\n");
			printf("/////////////////////////////////////////////////////////////////////////////\n");
			printf("\n");
			getchar();
		}
		fclose(fp);
		
	
}

void Exibiingr(Prato* ingr){
  	printf("/// # Ingredientes: %s                                               ///\n",ingr->ingredientes);
}
		

void apagarListaIng(Prato** lista){
    Prato* pra;
    
    while (*lista != NULL){
   	    pra = *lista;
        *lista = (*lista)->prox;
        free(pra);
    }   
}



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------///
void relatorioCategoria(void){
			FILE* fp;
			Prato* cat;
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
			printf("///                                                                       ///\n");
			cat = (Prato*) malloc(sizeof(Prato));
			fp = fopen("Receitas.dat","rb");
		
			if(fp == NULL){
			printf("ERRO!");
			}else{
				while(fread(cat,sizeof(Prato),1,fp)){
					if(strcmp(&cat->status,"x") != 0){
						ExibiCat(cat);
					}
				}
			printf("///                                                                       ///\n");
			printf("/////////////////////////////////////////////////////////////////////////////\n");
			printf("\n");
			getchar();
		}
		fclose(fp);
		
	
}
		

void ExibiCat(Prato* cat){
  	printf("/// # Categoria: %s                                                       ///\n",cat->categoria);
}
		

void apagarListaCat(Prato** lista){
    Prato* pra;
    
    while (*lista != NULL){
   	    pra = *lista;
        *lista = (*lista)->prox;
        free(pra);
    }   
}
