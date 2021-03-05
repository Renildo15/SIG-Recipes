///Funções de validaçaõ feita por mim mesmo
float validaPreco(float preco){
	if (preco < 0){
	// printf("Falso\n");
		return 0;
	}else if(preco == 0.00){	
	// printf("Falso\n");
		return 0;
	}else{
	// printf("Verdadeiro\n");
		return 1;
	}
	return 1;
}

