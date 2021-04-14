typedef struct prato Prato;

struct prato{
	char nomePrato[21];
	char ingredientes[101];
	char pre[11];
	float preco;
	char categoria[21];
	int quant;
	char preparo[101];
	char quan[11];
	float Kg;
	char status;
};


void exibirTudo(Prato* Re);