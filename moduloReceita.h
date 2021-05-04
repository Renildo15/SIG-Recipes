typedef struct prato Prato;
void moduloReceitas(void);
Prato* preencherTelareceitas (void);
void cadastrarReceita(void);
char menuReceitas (void);
char menuPreco (void);
void gravarReceita(Prato* Rec);
void exibirTudo(Prato* Re);
void deletarReceita (Prato* Rec);
char relatorios(void);

typedef struct prato Prato;
void moduloPrecos(void);
void TelaexibirTabela (void);
void exibirTabela(void);
char* TelaprecoporPrato (void);
void precoporPrato(void);
Prato* pesquisaPre(char* nom);
Prato* pesquisarIngre(char* nom);
void precoCategoria(void);
char* TelaprecoCategoria (void);
void TeladeAviso(void);

typedef struct prato Prato;
char* telabuscarReceita(void);
Prato* pesquisarReceita(char* nom);
void buscarporCategoria(void);
void buscarReceita(void);
Prato* pesquisarCate(char* nom);
char* TelabuscarporCategoria(void);
char* TelabuscaporIngrediente(void);
void buscaporIngrediente(void);
Prato* PesquisaIng(char* nom);
void deletar(void);
void exibirTudo(Prato* Re);



void apagarListaPra(Prato** lista);