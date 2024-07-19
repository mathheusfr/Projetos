#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h>
#include <conio.h>

#include "Guerreiros.h"
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

void ListarGuerreiros() {
	printf (" \n  Lista de Guerreiros ");
	int i;
	
		for (i=0; i < QuantidadesGuerreiros(); i++)  {
		Guerreiro Guerreiro_Atual;
		Guerreiro_Atual = ObterGuerreiroPeloIndice(i);

		printf (" \t \n \n  Codigo   %d ", Guerreiro_Atual.CodigoDoGuerreiro);
		printf (" \t   Nomes    %s ", Guerreiro_Atual.Nome);
		printf (" \t   Reino    %s", Guerreiro_Atual.Reino);
		printf (" \t   Titulo   %s ", Guerreiro_Atual.Titulo);
		printf (" \t  \n \n \n ");

	}	
		if (QuantidadesGuerreiros()==0){
		printf (" \n \n nenhum Guerreiro encontrado\n");
	}
}

void CadastrarGuerreiro() {
	system("cls");
	
	Guerreiro NovoGuerreiro; 

	printf (" \n  \n Cadastrar Guerreiros ");

    fflush(stdin);
	printf (" \n \n \n  Nome do Guerreiro "); 
    scanf("%s[^\n]",NovoGuerreiro.Nome);
    
    fflush (stdin);
    printf (" \n \n Reino do Guerreiro ");
    scanf("%s[^\n]", NovoGuerreiro.Reino);
    
    fflush(stdin);
    printf (" \n \n Titulo do Guerreiro ");
    scanf("%s[^\n]",NovoGuerreiro.Titulo);
    
    
	if 	(SalvarGuerreiro (NovoGuerreiro)== 1 ){
		printf (" \n \n O Guerreiro foi Cadastrado com sucesso  ");
	} else
		printf (" \n \n O Nao foi possivel Cadastrar o Guerreiro ");
	
}

void AlterarCadastroGuerreiro(){
    
    ListarGuerreiros();
    int codigo;
    char novoNome[50], novoTitulo[50], novoReino[50];
    
    printf ("Informe o codigo do guerreiro para atualizar o cadastro: \n");
    scanf ("%d", &codigo);
    
    printf ("Informe o novo nome do guerreiro: "); 
     scanf("%s[^\n]", novoNome);
    
    printf ("Informe o novo reino do guerreiro: ");
    scanf("%s[^\n]", novoReino);
    
    printf ("Informe o novo titulo do guerreiro: ");
    scanf("%s[^\n]", novoTitulo);
    
    if (alterarGuerreiro(codigo, novoNome, novoTitulo, novoReino)==1)
		printf("Guerreiro alterado \n");
	else
		printf("Falha ao alterar cadastro \n");   
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
		
		obterGuerreiroPeloNome(nomeGuer,g);
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
	
	Elemento NovoElemento; 

	printf (" \n Cadastrar Elemento ");

    fflush(stdin);
	printf (" \n Nome do Elemento "); 
 	scanf("%s[^\n]", NovoElemento.nome);
    
    fflush(stdin);
	printf (" \n Vunerabilidade  "); 
    scanf("%s[^\n]", NovoElemento.vunerabilidade);
    
   
	if 	(SalvarElemento(NovoElemento)== 1 ){
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


void ListarDragoes() {
	system("cls");
	printf (" \n Lista de Dragoes ");
	int i;
	
		for (i=0; i < QuantidadesDragoes(); i++)  {
		Dragao Dragao_Atual;
		Dragao_Atual = ObterDragoesPeloIndice(i);
		
		Elemento Elemento_Atual;
		Elemento_Atual = ObterElementosPeloIndice(i);

		printf (" \t \t  \n \n  Codigo  %d ", Dragao_Atual.codigo);
		printf (" \t \t  Nomes   %s ", Dragao_Atual.Nome);
		printf (" \t \t  Idade   %d ", Dragao_Atual.idade);
		printf (" \t \t  Preco   %d ", Dragao_Atual.preco);
		printf (" \t \t  Unidade em estoque   %d ", Dragao_Atual.UnidadeEmEstoque);
//		printf (" \n \n  Elemento do Dragao %s ", Elemento.NomeElemento.nome);
//		printf (" \t \t  Elemento do Dragao %s ", Elemento[CodigoElemento].);
//		printf (" \t \t  Elemento do Dragao %s ", Elemento[CodigoElemento].vunerabilidade);
		printf (" \t  \n \n \n ");
	}	
	
	if (QuantidadesDragoes()==0){
		printf ("nenhuma Dragao encontrada\n");
	}
}

void CadastrarDragao() {
	system("cls");
	
	Dragao NovoDragao; 

	printf (" \n Cadastrar Dragao ");

    fflush(stdin);
	printf (" \n \n Digite o Nome do Dragao "); 
    scanf("%s[^\n]", NovoDragao.Nome);
  
  	fflush(stdin);
  	printf (" \n \n  Digite o preco do Dragao ");
  	scanf ("%d", &NovoDragao.preco);

	fflush(stdin);
	printf (" \n  Digite a unidade em estoque ");
	scanf ("%d", &NovoDragao.UnidadeEmEstoque);
	
	fflush(stdin);
	printf (" \n  Digite a idade do Dragao ");
	scanf ("%d", &NovoDragao.idade);
	
	ListarElementos();
	
	printf ("Informe o elemento do dragao\n");
    scanf ("%d", &NovoDragao.CodigoElemento);
	
	if ( (SalvarDragao(NovoDragao)== 1) && (VerificaElemento(NovoDragao)== 1) ) {
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

void PesquisarDragao(){

	printf("\n Pesquisar Guerreiro ");
	int opcaoPesquisa;
	Dragao* d;
	d = malloc(sizeof(Dragao));
	scanf("%d", &opcaoPesquisa);
	
		printf("Digite o nome do Dragao: ");
		char nomeDragao[30];
		scanf("%s",nomeDragao);
		
		obterDragaoPeloNome(nomeDragao,d);
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListarLocacoes() {
	system("cls");
	printf (" \n Lista de Locacoes ");
	int i;
	
		for (i=0; i < QuantidadesLocacoes(); i++)  {
		Locar Locacao_Atual;
		Locacao_Atual = ObterLocacaoPeloIndice(i);
		
		printf (" \n  O codigo do Dragao  e : %d ",Locacao_Atual.CodigoDragao);
		printf (" \n O codigo da Locacao e : %d", Locacao_Atual.codigoLocacao);
		
		printf (" \n A data de inicio da locacao: %s ", Locacao_Atual.DataInicioLocacao);
		printf (" \n A data do fim da locacao:  %s", Locacao_Atual.DataFimLocacao);
		printf (" \n A quantidade de Dragoes Locados: %d ", Locacao_Atual.qtdDragaoLocados);
		printf (" \n \n Valor pago para Locar o Dragao: %d", Locacao_Atual.pago);
		printf (" \t  \n \n \n ");
	}	
	if (QuantidadesLocacoes()==0){
		printf ("nenhuma locacao encontrada\n");
	}
}

void LocarDragao() {
	
	Locar l;
	
	if ( (QuantidadesGuerreiros()==0) || (QuantidadesDragoes()==0) ) {
		printf (" Impossivel Locar Dragao \n");
	} else {
	
	ListarGuerreiros();
	
	printf (" \n \n  Informe o codigo do guerreiro que deseja locar um Dragao ");
	scanf ("%d", &l.codigoGuerreiro);
	
	ListarDragoes();

	printf (" \n \n Informe o codigo do Dragao ");
	scanf ("%d", &l.CodigoDragao);
	
	printf (" \n \n  Informe a data de inicio da locacao ");
	scanf("%s", l.DataInicioLocacao);
	
	printf (" \n \n  Informe a data do fim da locacao ");
	scanf("%s", l.DataFimLocacao);

  
    int verificCod = verificarCodigos(l.codigoGuerreiro, l.CodigoDragao);
    
    int verific = Alugar(l);
    if (verific == 1 && verificCod == 1){
        printf ("Aluguel realizado\n");
    }
    else if (verific == 0 && verificCod == 1){
        printf ("Aluguel nao realizado\n");
    }
}
 
}
void AlterarLocacao(){
}

void EfetuarDevolucao(){

    Locar l;

    ListarLocacoes();

    printf (" \n \n Informe o codigo da locacao para realizar a devolu??o ");
    scanf ("%d", &l.codigoLocacao);

    printf ("Informe a data de devolu??o:\n");
    scanf("%s[^\n]", l.DataFimLocacao);

    int verificPago = RealizarDevolucao(l);

    if (verificPago == 0)
        printf ("Devolucao feita com exito! \n");
    if (verificPago == 1)
        printf ("Problema na devolucao! \n");
}

void pesquisaLocacao(){

	printf("Pesquisar Locacao :\n");
	printf("Digite o codigo da locacao: ");
		Locar* l;
		l = (Locar*) malloc(sizeof(Locar));
	
	
		int codLoca;
		scanf("%d",&codLoca);
		obterLocacaoPeloCodigo(codLoca,l);
		if((*l).codigoLocacao <= 0){
			printf("__________________________________\n");
			printf("Codigo Invalido\n");
		}
			else{
				printf("\n----------------------------\n");
				printf("Codigo: %d",(*l).codigoLocacao);
			
			}	
}
void ApagarLocacao() {
	system("pause");

	ListarLocacoes();
	Locar l;

	printf (" Digite o codigo dA locacao para devolucao ");
	scanf("%d", &l.codigoLocacao);

	if (RealizarDevolucao(l)==0) 
		printf ("\n  Locacao apagado com sucesso ");
	else 
		printf (" Falha ao apagar a Locacao \n ");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
    inicializarGuerreiros();
    InicializarDragoes();
    inicializarElementos();
    
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
	
									case 3:
										printf (" \n Alterar Guerreiro  "); 
										AlterarCadastroGuerreiro();
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
	
									case 3:
										printf (" \n 	Alterar Dragoes  "); 
										AlterarCadastroDragao();
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
							
							case 3:  // Elementos
            				system("cls");
						    printf ("  \t '3' - ELEMENTOS	\n");
							 		do{ 
									Sub_Menu();
									scanf ("%d", &opcao_sub_menu);
	
				                	switch(opcao_sub_menu) {
									case 0:
										printf (" \n \n  Operacao Encerrada \n"); 
									break;
	
									case 1:
										printf (" \n	Listar Elementos  "); 
										ListarElementos();
									break;
	
									case 2:
										printf (" \n	Cadastrar Elementos  "); 
										CadastrarElemento();
									break;
	
									case 3:
										printf (" \n	 Alterar Elementos	"); 
										//AlterarCadastroDoElemento();
									break;
		
									case 4:
										printf (" \n	Pesquisar Elementos  "); 
										PesquisarElemento();
									break;

									case 5:
										printf (" \n 	Apagar Guerreiro pelo nome "); 
										ApagarElemento();
									break;
																
									default:
										printf (" \n erro ");
									} break;// fim do swith guerreiros				
							}while(opcao_sub_menu != 0); // fim do sub menu
							break; 
		       
			        
			      		case 4:  // LOCAR
            				system("cls");
						    printf ("  \t 	 - Locacoes	\n");
							 	do{ 
								Sub_locar();
									scanf ("%d", &opcao_sub_menu);
	
				                switch(opcao_sub_menu) {
									case 0:
										printf (" \n \n Operacao Encerrada \n"); 
									break;
	
									case 1:
										printf (" \n 	Listar Locacoes  "); 
										ListarLocacoes();
									break;
	
									case 2:
										printf (" \n	Efetuar Locacao "); 
										LocarDragao();
									break;
	
									case 3:
										printf (" \n	Alterar Locacao  "); 
										AlterarLocacao();
									break;
		
									case 4:
										printf (" \n	Pesquisar Locacao  "); 
									 pesquisaLocacao();
									break;

									case 5:
										printf (" \n 	Devolver Locacao  "); 
										EfetuarDevolucao();
									break;
									
									case 6:
										printf (" \n 	Apagar Locacao  "); 
										ApagarLocacao();
									break;
																							
									default:
										printf (" \n erro ");
									} break;// fim do swith guerreiros				
							}while(opcao_sub_menu != 0); // fim do sub menu
							break;
					} // fim do switch principal
	}while(opcao != 0); // fim do while principal 
	
	encerraGuerreiros();
	encerraDragoes();
	encerraElementos();
	encerrarLocacoes();
	
	return 0;
} //  fim da main 


