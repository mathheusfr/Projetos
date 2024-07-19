//#define MAX_DRAGOES 20
#define TAM_STRING 20

struct tp_dragao{
	int UnidadeEmEstoque;
	char Nome[TAM_STRING];
	int preco;
	int codigo;		
	int idade;
	int CodigoElemento;
};
	
typedef struct tp_dragao Dragao;

// funcoes de inicializa??es
int InicializarDragoes();

// funcoes listar
void ListarDragoes();
int QuantidadesDragoes();
//Dragao ObterDragoesPeloIndice(int indice);
int obterDragaoPeloIndice(int indice, Dragao* d);

// funcoes cadastrar 
void CadastrarDragao();
int SalvarDragao(Dragao  d);
void GravarDados();

// funcoes pesquisar
int PesquisarNomeDragao (char Nome[], int i);
int obterDragaoPeloNome(char* nomeBusca, Dragao* s);

// funcoes apagar
void ApagarDragao();
int ApagarDragaoPeloCodigo(int codigo);
int ApagarDragaoPeloIndice(int indice); 
int ApagarDragoesPeloCodigo( int codigo);

// funcoes locar
int MudarEstoqueDragao(int codigo, int qtdDragaoLocados);
int VerificaDragao();
int VerificaCodigoDragao(int codigo);

// funcoes alterar
void AlterarCadastroDragao();
int alterarDragao();

// 
void EfetuarDevolucao();
int DiminuiDragaoEstoque(int qtdDragaoLocados);


// liberar Memoria
int	encerraDragoes();



