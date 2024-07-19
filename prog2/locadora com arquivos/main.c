#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>
#include <conio.h>


#include "guerreiro.h"
#include "Dragoes.h"
#include "Elementos.h"
#include "Locacao.h"

void imprimeMenu() {
  		printf ("________________________________________\n \n ");
	    printf ("  \t            MENU             		 \n");
	    printf ("  \t                             		 \n");
	    printf ("  \t '0' - PARA ENCERRAR OPERACAO 	   	 \n");
	    printf ("  \t                             		 \n");
	    printf ("  \t '1' - GUERREIROS			     	 \n");
	    printf ("  \t                             		 \n");
	    printf ("  \t '2' - DRAGOES			    	 	 \n");
		printf ("  \t                               	 \n");
		printf ("  \t '3' - ELEMENTO DE DRAGOES     	 \n");
		printf ("  \t                               	 \n");
		printf ("  \t '4' - LOCACOES                     \n");
	    printf ("_______________________________________ \n");
}

void Sub_Menu() {
    printf ("________________________________________ \n ");
    printf ("            SUB MENU             		  \n");
    printf ("                               		  \n");
    printf ("   '1' - LISTAR      			  		  \n");
    printf ("                               		  \n");
    printf ("   '2' - CADASTRAR 		      		  \n");
    printf ("                               		  \n"); 
    printf ("   '3' - ALTERAR		     	    	  \n");
    printf ("                                		  \n"); 
    printf ("   '4' - PESQUISAR		     		  	  \n");
    printf ("                                		  \n");
    printf ("   '5' - EXCLUIR			   	          \n");
	printf ("                                   	  \n");
    printf ("   '0' - RETORNAR					 	  \n");
    printf ("________________________________________ \n ");
}


void Sub_locar() {
    printf (" _______________________________________\n");
    printf ("            SUB MENU LOCAR              \n");
    printf ("                               		 \n");
    printf ("   '1' - LISTAR      			  		 \n");
    printf ("                               		 \n");
    printf ("   '2' - LOCAR DRAGAO 		      	     \n");
    printf ("                                		 \n"); 
    printf ("   '3' - ALTERAR LOCACAO	  	 	     \n");
    printf ("                                		 \n");
    printf ("   '4' - PESQUISAR LOCACAO			   	 \n");
	printf ("                                   	 \n");
    printf ("   '5' - DEVOLVER DRAGAO				 \n");
    printf ("										 \n");
    printf ("   '0' - RETORNAR					 	 \n");
    printf ("________________________________________\n");
}

void Sub_AlterarGuerreiro() {
    printf (" _____________________________________________	\n");
    printf ("        SUB MENU LOCAR   GUERREIRO      		\n");
    printf ("                               		 		\n");
    printf ("   '1' - ALTERAR TODOS OS DADOS DO GUERREIROS	\n");
    printf ("                               		 		\n");
    printf ("   '2' - ALTERAR REINO	      	         		\n");
    printf ("                         	       		 		\n"); 
    printf ("   '3' - ALTERAR TITULO	  	 	     		\n");
    printf ("										 		\n");
    printf ("   '0' - SAIR					 	 	 		\n");
    printf ("										 		\n");
    printf (" _____________________________________________	\n");

}

void Sub_AlterarDragoes() {
    printf (" _____________________________________________	\n");
    printf ("        SUB MENU LOCAR  DRAGOES	      		\n");
    printf ("                               		 		\n");
    printf ("   '1' - ALTERAR TODOS OS DADOS DO DRAGAO		\n");
    printf ("                               		 		\n");
    printf ("   '2' - ALTERAR NOME DO DRAGAO         		\n");
    printf ("                         	       		 		\n"); 
    printf ("   '3' - ALTERAR UNIDADE DOS DRAGOES     		\n");
    printf ("										 		\n");
    printf ("   '4' - ALTERAR PRECO DOS DRAGOES     		\n");
    printf ("										 		\n");
    printf ("   '5' - ALTERAR IDADE DOS DRAGOES     		\n");
    printf ("										 		\n");
    printf ("   '0' - SAIR					 	 	 		\n");
    printf (" _____________________________________________	\n");

}
void ListarGuerreiros(){

	printf("\n ");
	Guerreiro g;
    	int i;
    	for(i = 0; i < QuantidadeGuerreiros(); i++)	{
    	int retorno = obterGuerreiroPeloIndice(i, &g);
    	if ((retorno == 1 && g.CodigoDoGuerreiro > 0 ))
    		
		printf (" \t \n \n  Codigo   %d ", g.CodigoDoGuerreiro);
		printf (" \t   Nomes    %s ", g.Nome);
		printf (" \t   Reino    %s", g.Reino);
		printf (" \t   Titulo   %s ", g.Titulo);
		printf (" \t  \n \n \n ");

    	}
		
		if (QuantidadeGuerreiros()==0)
    		printf("Nenhum guerreiro cadastrado\n");
    	
		printf("\n");
}

void CadastrarGuerreiro(){ 
    Guerreiro g; 
    printf (" \n  \n Cadastrar Guerreiros ");

    fflush(stdin);
	printf (" \n \n \n  Nome do Guerreiro "); 
    scanf("%s[^\n]",g.Nome);
    
    fflush (stdin);
    printf (" \n \n Reino do Guerreiro ");
    scanf("%s[^\n]", g.Reino);
    
    fflush(stdin);
    printf (" \n \n Titulo do Guerreiro ");
    scanf("%s[^\n]",g.Titulo); 
    
    if 	(SalvarGuerreiro (g)== 1 ){
		printf (" \n \n O Guerreiro foi Cadastrado com sucesso  ");
	} else
		printf (" \n \n O Nao foi possivel Cadastrar o Guerreiro ");
}

void PesquisarGuerreiro(){

	printf("\n Pesquisar Guerreiro ");


	int opcaoPesquisa;
	Guerreiro* g;
	g = malloc(sizeof(Guerreiro));
	scanf("%d", &opcaoPesquisa);
	
		printf("Digite o nome do guerreiro: ");
		char nomeGuer[30];
		scanf("%s",nomeGuer);
		
		obterGuerreiroPeloNomee(nomeGuer,g);
		if(strlen((*g).Nome) == 0){
			printf("__________________________________\n");
			printf("Guerreiro nao encontrado\n\n");
		}
			else{
				printf("\n----------------------------\n");
				printf("Codigo: %d",(*g).CodigoDoGuerreiro);
				printf("\nNome: %s",(*g).Nome);
				printf("\nTitulo: %s",(*g).Titulo);
				printf("\nReino: %s",(*g).Reino);
				printf("\n----------------------------\n");
			}

}

void ApagarGuerreiro() {
	system("pause");
	int i;
	
	ListarGuerreiros();
	int codigo;

	printf (" Digite o codigo do Guerreiro a ser apagado ");
 	scanf("%d", &codigo);

	if (ApagarGuerreiroPeloCodigo(codigo)==1) { 
		printf ("\n  guerreiro apagado com sucesso ");
	}else 
		printf (" Falha ao apagar o guerreiro \n ");
}

void AlterarRegistroGuerreiro(){
    
    int codigo;
    int opcao;
    Guerreiro g; 
    
    ListarGuerreiros();
    
    printf("Informe o codigo do guerreiro a ser alterado: \n");
    scanf ("%d", &codigo);
    
    printf ("Informe o que deseja ser alterado: 1 - Nome, 2 - Reino, 3 - Titulo\n");
    scanf ("%d", &opcao);
    
    switch(opcao){
        
        case 1: 
            printf ("Informe o novo nome do guerreiro: "); 
            scanf ("%s", g.Nome);
        break;
        
        case 2:
            printf ("Digite o novo reino do guerreiro: \n");
            scanf ("%s", g.Reino);
        break;
        
        case 3:
            printf ("Digite o novo titulo do guerreiro: \n");
            scanf ("%s", g.Titulo);
        break;
    }

    if(AlterarGuerreiro(codigo, g) == 1){
        printf ("Guerreiro alterado\n");
    }
    else{
        printf ("Falha ao alterar\n");
    }
}

void MudarNomeDoGuerreiro(){
     
    ListarGuerreiros();
    int codigo;
    char novoNome[50], novoTitulo[50], novoReino[50];
    
    printf ("Informe o codigo do guerreiro para atualizar o cadastro: \n");
    scanf ("%d", &codigo);
    
    printf ("Informe o novo nome do guerreiro: "); 
     scanf("%s[^\n]", novoNome);
    
   if (alteraNomeGuerreiro(codigo, novoNome)==1)
		printf(" Nome do Guerreiro alterado \n");
	else
		printf("Falha ao alterar cadastro \n");   
  
}

void MudarReinoDoGuerreiro(){
    
    ListarGuerreiros();
    int codigo;
    char novoNome[50], novoTitulo[50], novoReino[50];
    
      printf ("Informe o codigo do guerreiro para atualizar o cadastro: \n");
    scanf ("%d", &codigo);
    
    printf ("Informe o novo nome do guerreiro: "); 
     scanf("%s[^\n]", novoNome);
  
   if (alteraReinoGuerreiro(codigo, novoReino)==1)
		printf(" Reino do guerreiro alterado \n");
	else
		printf("Falha ao alterar cadastro \n");     
}

void MudartituloDoGuerreiro(){
    
    ListarGuerreiros();
    int codigo;
    char novoNome[50], novoTitulo[50], novoReino[50];
    
     printf ("Informe o codigo do guerreiro para atualizar o cadastro: \n");
    scanf ("%d", &codigo);
    
    printf ("Informe o novo titulo do guerreiro: "); 
     scanf("%s[^\n]", novoNome);
    
   if (alteraTituloGuerreiro(codigo, novoTitulo)==1)
		printf("Titulo do guereiro alterado \n");
	else
		printf("Falha ao alterar cadastro \n");   			
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListarDragoes(){

		Dragao d;
    	int i;
    	for(i = 0; i < QuantidadeDragoes(); i++)	{
    	int retorno = obterDragaoPeloIndice(i, &d);
    	if ((retorno == 1 && d.codigo > 0 ))
    	
   		printf (" \t \t  \n \n  Codigo  %d ", d.codigo);
		printf (" \t \t  Nomes   %s ", d.Nome);
		printf (" \t \t  Idade   %d ", d.idade);
		printf (" \t \t  Preco   %d ", d.preco);
		printf (" \t \t  Unidade em estoque   %d ", d.UnidadeEmEstoque);
		printf (" \t  \n \n \n ");

    	}
		
		if (QuantidadeDragoes()==0)
    		printf("Nenhum Dragao cadastrado\n");
    	
		printf("\n");
}


void CadastrarDragao() {
	system("cls");
	
	Dragao d; 

	printf (" \n Cadastrar Dragao ");

    fflush(stdin);
	printf (" \n \n Digite o Nome do Dragao "); 
    scanf("%s[^\n]", d.Nome);
  
  	fflush(stdin);
  	printf (" \n \n  Digite o preco do Dragao ");
  	scanf ("%d", &d.preco);

	fflush(stdin);
	printf (" \n  Digite a unidade em estoque ");
	scanf ("%d", &d.UnidadeEmEstoque);
	
	fflush(stdin);
	printf (" \n  Digite a idade do Dragao ");
	scanf ("%d", &d.idade);
//	
//	ListarElementos();
//	
//	printf ("Informe o elemento do dragao\n");
//    scanf ("%d", &d.CodigoElemento);
	
	if ( (SalvarDragao(d)== 1) && (VerificaElemento(d)== 1) ) {
		printf (" \n \n O Dragao foi Cadastrado com sucesso  ");
	} else
		printf (" \n \n O Nao foi possivel Cadastrar o Dragao ");
}

void AlterarCadastroDragao(){
    
    ListarDragoes();
    int codigo;
    char novoNome[50];
	int novoEstoque; 
	int novoPreco;
	
	ListarElementos();
    
    printf (" \n \n Informe o codigo do Dragao para atualizar o cadastro: \n");
    scanf ("%d", &codigo);
    
    printf (" \n \n Informe o novo nome do Dragao: "); 
    scanf("%s[^\n]", novoNome);
    
    printf (" \n \n Informe a nova unidade de estoque do Dragao ");
    scanf ("%d", &novoEstoque);
    
    printf (" \n \n Informe o novo preco do Dragao: ");
    scanf ("%d", &novoPreco);
    
    if (alterarDragao(codigo, novoNome, novoEstoque, novoPreco)==1)
		printf("Dragao alterado \n");
	else
		printf("Falha ao alterar cadastro \n");   
}

void MudarNomeDoDragao(){
     
   
    ListarDragoes();
    char novoNome[50];
	
	ListarElementos();
	
	int codigo;
    
    printf (" \n \n Informe o codigo do Dragao para atualizar o cadastro: \n");
    scanf ("%d", &codigo);
    
     
    printf (" \n \n Informe o novo nome do Dragao: "); 
    scanf("%s[^\n]", novoNome);
    
   if (alteraNomeDragao(codigo, novoNome)==1)
		printf("Nome Dragao alterado \n");
	else
		printf("Falha ao alterar cadastro \n");   
    
}

void MudarUnidadeDragoes(){
    
   ListarDragoes();
    int codigo;
    char novoNome[50];
	int novoEstoque; 
	int novoPreco;
	
	ListarDragoes();
   
    printf (" \n \n Informe a nova unidade de estoque do Dragao ");
    scanf ("%d", &novoEstoque);
   
   if (alterarUnidadeDragao(codigo, novoEstoque)==1)
		printf("Noma unidade alterada \n");
	else
		printf("Falha ao alterar cadastro \n");   
    
}

void MudarPrecoDragao(){
	ListarDragoes();
    int codigo;
 
	int novoPreco;

	ListarDragoes();
  
    printf (" \n \n Informe o novo preco do Dragao: ");
    scanf ("%d", &novoPreco);
      
    if (alterarPrecoDragao(codigo, novoPreco)==1)
		printf("Preco do Dragao alterado \n");
	else
		printf("Falha ao alterar cadastro \n"); 
}

void MudarIdadeDragao(){
    
    ListarDragoes();
    int codigo;
	int novaIdade;
	
	ListarDragoes();
 
    printf (" \n \n Informe a nova idade do Dragao: ");
    scanf ("%d", &novaIdade);
    
    if (alterarIdadeDragao(codigo,novaIdade)==1)
		printf("Dragao alterado \n");
	else
		printf("Falha ao alterar cadastro \n");   
}


void PesquisarDragao(){

	printf("\n Pesquisar Guerreiro ");
	int opcaoPesquisa;
	Dragao* d;
	d = malloc(sizeof(Dragao));
	scanf("%d", &opcaoPesquisa);
	
		printf("Digite o nome do Dragao: ");
		char nomeDragao[30];
		scanf("%s",nomeDragao);
		
		obterDragaoPeloNomee(nomeDragao,d);
		if(strlen((*d).Nome) == 0){
		
			printf("Dragao nao encontrado\n\n");
		}
			else{
				printf("Codigo: %d",(*d).codigo);
				printf("\n Nome do Dragao : %s",(*d).Nome);
				printf("\n preco: %d",(*d).preco);
				printf("\n Unidade de estoque: %d",(*d).UnidadeEmEstoque);
				printf("\n----------------------------\n");
			}
}


void ApagarDragao() {
	system("pause");
	int i;
	
	ListarDragoes();
	int codigo;

	printf (" Digite o codigo do dragao a ser apagado ");
	scanf("%d", &codigo);

	if (ApagarDragoesPeloCodigo(codigo)==1) 
		printf ("\n  Dragao apagado com sucesso ");
	else 
		printf (" Falha ao apagar o dragao \n ");
}

///////////////////////


void ListarElementos() {
	system("cls");
	printf (" \n Lista de Elementos ");
	int i;
	
		for (i=0; i < QuantidadesElementos(); i++)  {
		Elemento Elemento_Atual;
		Elemento_Atual = ObterElementosPeloIndice(i);

		printf (" \n \n  Codigo do Elemento %d ", Elemento_Atual.codigoElemento);
		printf (" \n \n  Nomes do Elemento   %s ", Elemento_Atual.nome);
		printf (" \n \n  Vunerabilidade    %s ", Elemento_Atual.vunerabilidade);
		printf (" \t  \n \n \n ");
	}	
	
	if (QuantidadesElementos()==0){
		printf ("nenhuma Elemento encontradd\n");
	}
}

void CadastrarElemento() {
	system("cls");
	
	Elemento e; 

	printf (" \n Cadastrar Elemento ");

    fflush(stdin);
	printf (" \n Nome do Elemento "); 
 	scanf("%s[^\n]", e.nome);
    
    fflush(stdin);
	printf (" \n Vunerabilidade  "); 
    scanf("%s[^\n]", e.vunerabilidade);
    
   
	if 	(SalvarElemento(e)== 1 ){
		printf (" \n \n O Elemento foi Cadastrado com sucesso  ");
		printf (" \n \n -------------------------------------------	");
	} else
		printf (" \n \n O Nao foi possivel Cadastrar o Elemento ");
	
}

void AlterarCadastroDoElemento(){
        
    int codigo; 
    char novoNome[50];
    char novaVulnerabilidade[50];
    
    ListarElementos();
    
    printf ("Informe o codigo do elemento para alterar o cadastro: \n");
    scanf ("%d", &codigo);
    printf ("Informe o novo nome do elemento:\n");
    scanf("%s[^\n]", novoNome);
    printf ("Informe a nova vulnerabilidade do elemento:\n");
    scanf("%s[^\n]", novaVulnerabilidade);
    
    if(AlterarCadastroElemento(codigo, novoNome, novaVulnerabilidade)==1)
        printf ("cadastro alterado\n");
    else
        printf ("Falha ao alterar\n");
    
}

void PesquisarElemento(){

	printf("\n Pesquisar Elemento ");


	int opcaoPesquisa;
	Elemento* e;
	e = malloc(sizeof(Elemento));
	scanf("%d", &opcaoPesquisa);
	
		printf("Digite o nome do Elemento: ");
		char nomeElemento[30];
		scanf("%s[^\n]",nomeElemento);
		
		obterElementoPeloNome(nomeElemento,e);
		if(strlen((*e).nome) == 0){
			printf("__________________________________\n");
			printf("Elemento nao encontrado\n\n");
		}
			else{
				printf("\n Nome do Elemento : %s",(*e).nome);
				printf("\n Vunerabilidae  : %s",(*e).nome);
				printf (" \n Codigo do Elemento : %d",(*e).codigoElemento);
			}			
}


void ApagarElemento() {
	system("pause");
	int i;
	
	ListarElementos();
	int codigo;

	printf (" Digite o codigo do Elemento a ser apagado ");
 	scanf("%d", &codigo);

	if (ApagarElementosPeloCodigo(codigo)==1) {
		printf ("\n  Elemento apagado com sucesso ");
	 }else 
		printf (" Falha ao apagar o Elemento \n ");
}


///////////////////////////////////

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");

InicializarGuerreiros();
InicializarDragoes();



int opcao;   
int opcao_sub_menu;

do{ 

imprimeMenu();

printf (" \n \n \n 		INFORME A OPCAO DESEJADA 	 	  \n");
scanf ("%d", &opcao);

switch(opcao){
		 case 0:
       		 printf (" Operacao Encerrada \n"); 
    	break;

case 1:  // Guerreiros
	system("cls");
	printf ("  \t '1' - GUERREIROS			     	  \n");
 	do{ 
	Sub_Menu();
		scanf ("%d", &opcao_sub_menu);

    switch(opcao_sub_menu) {
		case 0:
			printf (" \n \n  Operacao Encerrada \n"); 
		break;

		case 1:
			printf (" \n Listar Guerreiros  "); 
			ListarGuerreiros();
		break;

		case 2:
			printf (" \n Cadastrar Guerreiro  "); 
			CadastrarGuerreiro();
		break;

					
case 3:  // ALTERAR
system("cls");
printf ("  \t '3' - ALTERAR GUERREIROS	\n");
 		do{ 
		Sub_AlterarGuerreiro();
		scanf ("%d", &opcao_sub_menu);

    	switch(opcao_sub_menu) {
		case 1:
			printf (" \n \n  Alterar todas informacoes \n"); 
			AlterarCadastroGuerreiro();
		break;

		case 2:
			printf (" \n \n  Alterar nome Guerreiro \n"); 
			MudarNomeDoGuerreiro();
		break;

		case 3:
			printf (" \n	Alterar reino do Guerreiro  "); 
			MudarReinoDoGuerreiro();
		break;

		case 4:
			printf (" \n	 Alterar titulo do Guerreiro	"); 
			MudartituloDoGuerreiro();
		break;
				
		default:
			printf (" \n erro ");
		} break;// fim do swith Mudar Guerreiros			
}while(opcao_sub_menu != 0); // fim do sub menu
break; 


		case 4:
			printf (" \n Pesquisa Guerreiro  "); 
			PesquisarGuerreiro();
		break;

		case 5:
			printf (" \n Apagar Guerreiro pelo nome "); 
			ApagarGuerreiro();
		break;
									
		default:
			printf (" \n erro ");
		} break;// fim do swith guerreiros				
}while(opcao_sub_menu != 0); // fim do sub menu
break;


case 2:  // Dragoes
	system("cls");
	printf ("  \t  -	 Dragoes	\n");
 	do{ 
	Sub_Menu();
		scanf ("%d", &opcao_sub_menu);

    switch(opcao_sub_menu) {
		case 0:
			printf (" \n \n		Operacao Encerrada \n"); 
		break;

		case 1:
			printf (" \n 	Listar Dragoes  "); 
			ListarDragoes();
		break;

		case 2:
			printf (" \n 	Cadastrar Dragoes  "); 
			CadastrarDragao();
		break;

		case 3:  // ALTERAR
		system("cls");
		printf ("  \t '3' - ALTERAR DRAGAO	\n");
		 		do{ 
				Sub_Menu();
				scanf ("%d", &opcao_sub_menu);
		
		    	switch(opcao_sub_menu) {
				case 0:
					printf (" \n \n  Alterar todas informacoes \n"); 
					AlterarCadastroDragao();
				break;
		
				case 1:
					printf (" \n \n  Alterar nome dos Dragoes \n"); 
					MudarNomeDoDragao();
				break;
		
				case 2:
					printf (" \n	Alterar unidade dos Dragoes  "); 
					MudarUnidadeDragoes();
				break;
		
				case 3:
					printf (" \n	 Alterar preco do Dragao	"); 
					MudarPrecoDragao();
				break;
		
				case 4:
					printf (" \n	Alterar idade do Dragao  "); 
					MudarIdadeDragao();
				break;
		
								
				default:
					printf (" \n erro ");
				} break;// fim do swith Mudar Guerreiros			
		}while(opcao_sub_menu != 0); // fim do sub menu
		break; 
		
		case 4:
			printf (" \n 	Pesquisa Dragoes  "); 
			PesquisarDragao();
		break;

		case 5:
			printf (" \n 	Apagar Dragao "); 
			ApagarDragao();
		break;
									
		default:
			printf (" \n erro ");
		} break;// fim do swith Dragoes				
}while(opcao_sub_menu != 0); // fim do sub menu
break;	
			

	} // fim do switch principal
}while(opcao != 0); // fim do while principal 

	encerraGuerreiros();
	encerraDragoes();

	
	return (0);
} //  fim da main 



