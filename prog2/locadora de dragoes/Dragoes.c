#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Dragoes.h"

Dragao *Dragoes;

int MAX_DRAGOES = 3;
int TAM_REALLOC_DRAGOES = 3;

int qtdDragoes=0;

int CodigoAtualDoDragao = 1;

int InicializarDragoes(){

	Dragoes = (Dragao*)malloc(MAX_DRAGOES * sizeof(Dragao));
    if (Dragoes==NULL)
        return 0;
        
	int i;
	for (i=0; i< MAX_DRAGOES; i++) {
		
	if( qtdDragoes < MAX_DRAGOES) {
		strcpy (Dragoes[i].Nome, " ");
		Dragoes[i].UnidadeEmEstoque = 0;
		Dragoes[i].preco = 0;
		Dragoes[i].codigo = CodigoAtualDoDragao;
		}	
	}
	 
   	Dragoes[0].codigo = CodigoAtualDoDragao++;
	strcpy(Dragoes[0].Nome,"Dragao1");
	Dragoes[0].preco = 1;
	Dragoes[0].UnidadeEmEstoque = 1;
	
    Dragoes[qtdDragoes];
	qtdDragoes++;
	
	Dragoes[1].codigo = CodigoAtualDoDragao++;
	strcpy(Dragoes[1].Nome,"Dragao2");
	Dragoes[1].preco = 1;
	Dragoes[1].UnidadeEmEstoque = 1;
	
    Dragoes[qtdDragoes];
	qtdDragoes++;
}


Dragao ObterDragoesPeloIndice(int indice) {
	return Dragoes[indice];
}

int QuantidadesDragoes() {
	return qtdDragoes;
}


int SalvarDragao( Dragao NovoDragao ) {
	int i;
	if( qtdDragoes < MAX_DRAGOES) {
		NovoDragao.codigo = CodigoAtualDoDragao++;
		Dragoes[qtdDragoes] = NovoDragao;
		qtdDragoes++;
		return 1;
	} 
	
	if (qtdDragoes > MAX_DRAGOES-1 ) {
		Dragao* DragoesRealloc = (Dragao*) realloc(Dragoes, (MAX_DRAGOES+1) * sizeof(Dragao)); 		if (DragoesRealloc != NULL){
 
    		MAX_DRAGOES++;
	     	Dragoes = DragoesRealloc;
	        NovoDragao.codigo = CodigoAtualDoDragao++;
            Dragoes[qtdDragoes] = NovoDragao;
            qtdDragoes++;
       	    return 1;
	}
}
	else
		return 0;
}

int obterDragaoPeloNome (char* nome, Dragao* d){
	int i;
	for(i=0;i<MAX_DRAGOES;i++){
		if(strcmp(Dragoes[i].Nome,nome)==0){
			(*d) = Dragoes[i];						
			return 0;
		}
	}
}
int VerificaDragao(int codigo) { 
	int i;
	
	for (i=0; i< MAX_DRAGOES;i++) {
		
			
				return Dragoes[i].UnidadeEmEstoque;
		}		
}


int MudarEstoqueDragao(int CodigoDragao, int qtdDragaoLocados) {
int i;
			for ( i=0; i < MAX_DRAGOES; i++) {
	
		
		    if ( Dragoes[i].codigo == CodigoDragao) {
		   	    Dragoes[i].UnidadeEmEstoque -=	qtdDragaoLocados;
			return 1;
		}
	}
}

int ApagarDragoesPeloCodigo( int codigo) {
	int i;

	for (i=0; i < qtdDragoes; i++) {
		if ( Dragoes[i].codigo == codigo) {
			Dragoes[i] = Dragoes[qtdDragoes-1];
			Dragoes[qtdDragoes-1].codigo = 0;
			qtdDragoes--;
			return 1;
		}
	} 
	if (qtdDragoes < 0.4 * MAX_DRAGOES){
            
    	Dragao* DragoesRealloc = (Dragao*) realloc(Dragoes, TAM_REALLOC_DRAGOES * sizeof(Dragoes));
        if (DragoesRealloc != NULL){
            
        MAX_DRAGOES--;
        Dragoes = DragoesRealloc;
        }
           
        }else 
			return 0;
} 

int AumentaDragaoEstoque(int qtdDragao){
    
    int i;
    for (i = 0; i < MAX_DRAGOES; i++){
        
        Dragoes[i].UnidadeEmEstoque += qtdDragao;
    
    }
    
}

int alterarDragao(int codigo, char* novoNome, int* novoEstoque, int* novoPreco){
        int i;
        for (i = 0; i < MAX_DRAGOES; i++){
        if (codigo == Dragoes[i].codigo){
            
            strcpy(Dragoes[i].Nome, novoNome);
//    		Dragao[i].UnidadeEmEstoque = novoEstoque;
//    		Dragao[i].preco = novoPreco;
            
            return 1; 
        }  
    }
}


int DiminuiDragaoEstoque(int qtdDragaoLocados){
    int i;
    for (i = 0; i < MAX_DRAGOES; i++){
    
    Dragoes[i].UnidadeEmEstoque -= qtdDragaoLocados;
    
    }
    
}

int VerificaCodigoDragao(int codigo){
	
	int i;
	for(i = 0; i < MAX_DRAGOES; i++){
		
		if (codigo == Dragoes[i].codigo){
			
			return 1;
		}
	}
}


int encerraDragoes() {
   free(Dragoes);
   return 1;
}



