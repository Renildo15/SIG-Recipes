/// adaptado de @flgorgoni,2021
int bissexto(int ano) {
  if ((ano % 4 == 0) && (ano % 100 != 0)) {
    return 1;
  } else if (ano % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}
int validacao (int dia, int mes, int ano){
	int maiorDia;
// Recebe uma data no formato (dia, mes, ano) e valida a mesma
// Retorna 1 se a data é válida ou 0 caso contrário
/// Como é uma data de validade, o programa não aceita anos anteriores
	if (ano < 2021 || mes < 1 || mes > 12)
		return 0;
	if (mes == 2) {
		if (bissexto(ano)) 
		maiorDia = 29;
		else
		maiorDia = 28;
	} else if (mes == 4 || mes == 6 || 
				mes == 9 || mes == 11) {
				maiorDia = 30;
	} else
		maiorDia = 31;

	if (dia < 1 || dia > maiorDia)
		return 0;

	return 1;
}


// Codigo baseado e modificado a partir do codigo do Prof.Flavius.
#include <string.h>
int validaNome(char nome[]){
	int tam;
	tam = strlen(nome);
	if(tam == 0){
		return 0;
	}
	for(int i = 0;i < tam; i++){
		if(nome[i] >= 'A'  && nome[i] <= 'Z'){
			continue;
		}else if(nome[i] >= 'a' && nome[i] <= 'z'){
			continue;
		}else if(nome[i]== ' '){
			continue;
		}else if(nome[i] >= ',' && nome [i] <= '.'){
			continue;
		}else{
			return 0;
		}
	}
	return 1;
}
///Feita por mim mesmo
float ValidaQuant(float quant){
	if (quant < 0){
		return 0;
	}else if (quant == 0.000){
		return 0;
	}else{
		return 1;
	}
	return 1;
}

///Funções de validaçaõ feita por mim mesmo
#include <stdio.h>
float validaPreco(float pre[]){
	float preco[1];

	for(int i = 0; i<1;i++){
		if(pre[i] < 0 || pre[i] == 0){
		printf("///             Invalido                                                  ///\n");
		printf("///             Tente novamente!                                          ///\n");
			return 0;
		}else{
			for(int i = 0;i < 1;i++){
			//printf("///             R$ %.2f                                                ///\n", pre[i]);
			return 1;
		  }	
	
		}
  }
	return 1;
}
