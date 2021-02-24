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