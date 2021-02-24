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