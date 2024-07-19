// #define MAX_LOCACOES 5

struct tp_locacao{
	int codigoLocacao;
	int LocacaoCodigoDragao;
	int LocacaoCodigoGuerreiro;
	
	char DataInicioLocacao[20];
	char DataFimLocacao[20];
	//float ValorLocacao;
	int pago;	
	int CodigoDragao;
	int codigoGuerreiro;
	
	 int qtdDragaoLocados; 
};
	
typedef struct tp_locacao Locar;


int ExisteGuerreiro();
// Inicializar
int inicializarLocacao();
void CadastrarLocacoes();

// listar
void ListarLocacoes();
int QuantidadesLocacoes();

// cadastro

// locar
void LocarDragao();
int Alugar(Locar l);
int verificarCodigos(int codigoGuerreiro, int CodigoDragao);

// alterar
void AlterarLocacao();


// devolucao
void EfetuarDevolucao();
void VerificaDevolucao();
int RealizarDevolucao( Locar l);


// pesquisar
void pesquisaLocacao();
int obterLocacaoPeloCodigo(int codigoLocacao, Locar* l);

// Apagar 
void ApagarLocacao();
Locar ObterLocacaoPeloIndice(int indice );
void ApagarLocacao();

int encerrarLocacoes();





