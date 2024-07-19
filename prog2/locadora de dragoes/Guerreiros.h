//#define MAX_GUERREIROS 5
#define TAM_STRING 20

struct tp_guerreiro {
	char Nome[TAM_STRING];
	int CodigoDoGuerreiro;
	char Titulo[TAM_STRING];
	char Reino[TAM_STRING];
}; 

typedef struct tp_guerreiro Guerreiro;

// funcao iniciazliar
int inicializarGuerreiros();

// funcoes listar 
int QuantidadesGuerreiros();
Guerreiro ObterGuerreiroPeloIndice(int indice);
int inicializarGuerreiros();
int obterGuerreiroPeloNome (char* nome, Guerreiro* g);
int obterGuerreiroPeloCodigo(int codigo, Guerreiro* g);
// funcoes cadastrar 
void CadastrarGuerreiro();
int SalvarGuerreiro (Guerreiro NovoGuerreiro);
void GravarDados();
//int SalvarCliente( Cliente a );

// funcoes pesquisar
void PesquisarGuerreiro ();
void PesquisarNome();
int obterGuerreiroPeloNome(char* nomeBusca, Guerreiro* s);
    
// funcoes apagar
void ApagarGuerreiro();
int ApagarGuerreiroPeloCodigo(int codigo);

// Alterar
int alterarGuerreiro(int codigo, char* novoNome, char* novoTitulo, char* novoReino);
int AlterarNomeGuerreiro(int codigo, char* novoNome);
int AlterarReinoGuerreiro(int codigo, char* novoNome);
int AlterarTituloGuerreiro(int codigo, char* novoNome);
int alocarGuerreiros();
int encerraGuerreiros();

int Cadastrar_Teste_Guerreiros();
int VerificaCodigoGuerreiro(int CodigoDoGuerreiro);


int obterGuerreiroPeloNome (char* nome, Guerreiro* g);
