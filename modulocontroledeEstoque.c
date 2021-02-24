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

			case '4':relatorioProdutos();
						break;
		}
	}while(opcao!='0');
}
