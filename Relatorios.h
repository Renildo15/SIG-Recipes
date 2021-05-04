typedef struct prato Prato;
typedef struct data Data;
typedef struct produto Produto;
void moduloRelatorios(void);
char menuRelatorio(void);
void relatorioPratos(void);
void relatorioPrecos(void);
void relatorioCategoria(void);
void RelatorioSaida(void);
void relatorioIngredientes(void);


void ListaPro(char* pro);
char* TelaRelaPro(void);
void RelatProduto(void);
void exibirRela(Produto* aux);

void relProdOrdenados(Produto **lista);
void exibeRelProd(Produto* pro);
void exibirProdutos(Produto* pro);
void RelaProdutos(void);
void RelSaida(Produto* pro);

void ExibiPrato(Prato* pro);
void apagarListaRe(Prato** lista);

void ExibiPre(Prato* pro);
void apagarListaPre(Prato** lista);

void Exibiingr(Prato* ingr);
void apagarListaIng(Prato** lista);

void ExibiCat(Prato* cat);
void apagarListaCat(Prato** lista);