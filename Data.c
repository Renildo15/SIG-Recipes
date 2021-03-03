/// Função BASEADA e não copiada na do Professor Flavius
#include <stdio.h>
int validacao (int dia, int ano, int mes){
	int maiorDia;

	if( ano >= 2021){
		if ((ano % 4 == 0) && (ano % 100 != 0)){
				return 1;
				if ((mes == 2) && (dia == 29)){
					maiorDia = 29;
					return 1;
					if (dia > maiorDia)	{
						printf("///                          Data invalida                               ///\n");
						return 0;	
					}else{
						return 1;
					}
				}	
		}else if ((ano % 400 == 0)){
				if ((mes == 2) && (dia == 29)){
					maiorDia = 29;
					return 1;	
					if (dia > maiorDia)	{
							printf("///                          Data invalida                               ///\n");	
							return 0;
					}else{
						return 1;
					}
				}
		}else{
				if ((mes == 2) && (dia >= 29)){
					maiorDia = 28;
					printf("///                           invalido                                ///\n");
					printf("///                          Nao e ano bissexto                               ///\n");
					return 0;
					if (dia > maiorDia)	{
							printf("///                          Data invalida                               ///\n");	
							return 0;
				}else{
						return 1;
					}

				
				}	
		}		
	}else{
		printf("///                           invalido                                                     ///\n");
		printf("///                          Anos anteriores nao sao permitidos                            ///\n");
		return 0;
	}

	if (mes == 4 || mes == 6 || mes == 9 || mes ==11){
		maiorDia = 30;

	}else{
		maiorDia = 31;
	}

	if(mes < 0 || mes > 12){
		printf("///                          Data invalida                               ///\n");
		return 0;
	}

	if (dia < 1 || dia > maiorDia){
		printf("///                          Data invalida                               ///\n");
		return 0;
	}else{
		return 1;
	}
	return 0;
}