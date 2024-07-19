//#define MAX_ELEMENTOS 5
#define TAM_ELEMENTOS 20

#define TAM_STRING 20

typedef struct{
	char nome[10];
}NomesListarElementos;
	
struct tp_elemento{
//	Elemento Elementos;
	NomesListarElementos NomeElemento;
	char nome[TAM_ELEMENTOS];
	char vunerabilidade[TAM_ELEMENTOS];
	int codigoElemento;		
};
	
typedef struct tp_elemento Elemento;


// funcoes listar 
int QuantidadesElementos();
Elemento ObterElementosPeloIndice(int indice);

void ListarElementos();

// funcoes listar 

//int QuantidadesClientes( int i );
//void ListarDragoes();
int inicializarElementos();


// funcoes cadastrar 
void CadastrarElementos();
int SalvarElementos(  Elemento e);
//int SalvarClientes( Cliente NovoCliente);
void GravarDados();
int VerificaElemento();
int verificaElementoDragao();
//int SalvarCliente( Cliente a );

// funcoes pesquisar
void PesquisarElemento();
int obterElementoPeloNome (char* nomeElemento, Elemento* e);

// funcoes apagar
void ApagarElemento();

int ApagarElementosPeloCodigo(int codigo);
int ApagarElementosPeloIndice(int indice); 

// liberar Memoria

 int encerraElementos();

