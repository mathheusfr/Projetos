#define TAM_STRING 20

struct tp_guerreiro {
	char Nome[TAM_STRING];
	int CodigoDoGuerreiro;
	char Titulo[TAM_STRING];
	char Reino[TAM_STRING];
}; 

typedef struct tp_guerreiro Guerreiro;


// funcao iniciazliar
int InicializarGuerreiros();

// funcoes listar 
int QuantidadeGuerreiros();
int obterGuerreiroPeloIndice(int indice, Guerreiro* g);
int obterGuerreiroPeloCodigo(int codigo, Guerreiro* g);
Guerreiro ObterGuerreiroPeloIndicee(int indice);


void ListarGuerreiros();
int obterGuerreiroPeloNomee (char* nome, Guerreiro* g);


// funcoes cadastrar 
int SalvarGuerreiro();
void CadastrarGuerreiro();
//int alterarGuerreiro(int codigo, char* novoNome, char* novoTitulo, char* novoReino);
int alterarGuerreiro(int codigo, Guerreiro g)
int SalvaArquivos(Guerreiro g);

//int inicializarGuerreiros();
int encerraGuerreiros();
int salvarGuerreiro(Guerreiro g);

// funcoes pesquisar



//Guerreiro obterGuerreiroPeloCodigo(int codigo);
/*Guerreiro obterGuerreiroPeloNome (char* nome);*/
//int obterGuerreiroPeloNome(char* nomeBusca, Guerreiro* g);

int ApagarGuerreiroPeloCodigo(int codigo);
int verificarCodGuerreiro(int codGuerreiro);
int obterGuerreiroParaLocacao();


int AlterarGuerreiro(int codigo, Guerreiro g);
int AlterarNomeGuerreiro(int codigo, char* novoNome);
int AlterarReinoGuerreiro(int codigo, char* novoNome);
int AlterarTituloGuerreiro(int codigo, char* novoNome);

int MostrarGuerreirosSalvosNoArquivo(Guerreiro g);
int guerreiroCod();

int Verificacao(int codigo);
