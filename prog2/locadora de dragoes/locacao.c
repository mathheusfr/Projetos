#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Guerreiros.h"
#include "Dragoes.h"
#include "Elementos.h"
#include "Locacao.h"


int MAX_LOCACOES = 5;
int TAM_REALLOC_LOCACOES = 2;


Locar* Locacao;

int codLocacaoAtual = 1;


int qtdLocacao = 0;

int inicializarLocacao() {
	int i;
	Locacao = (Locar*)malloc(MAX_LOCACOES * sizeof(Locar));
    if (Locacao==NULL)
        return 0;
	
	for (i=0; i<MAX_LOCACOES; i++) {
		Locacao[i].codigoLocacao = 0;
		strcpy (Locacao[i].DataFimLocacao, " ");
		strcpy (Locacao[i].DataInicioLocacao, " ");
		Locacao[i].LocacaoCodigoDragao = 0;
		Locacao[i].LocacaoCodigoGuerreiro = 0;
		Locacao[i].qtdDragaoLocados = 0;
	}
}

Locar ObterLocacaoPeloIndice(int indice ) {
	return Locacao[indice];
}

int QuantidadesLocacoes() {
		return qtdLocacao;
}


int obterLocacaoPeloCodigo(int codigoLocacao, Locar* l){
	int i;
	for(i=0;i<codLocacaoAtual;i++){
		if(Locacao[i].codigoLocacao==codigoLocacao){
			(*l) = Locacao[i];
		}
	}
	if(qtdLocacao<=(MAX_LOCACOES*0.4)){
			if(qtdLocacao<=5){
				Locacao = (Locar*)malloc(MAX_LOCACOES * sizeof(Locar));
				if(Locacao != NULL){
		}
			else{
					MAX_LOCACOES = 5;
			}
				Locacao = (Locar*) realloc(Locacao,qtdLocacao*sizeof(Locar));
				if(Locacao != NULL){
					MAX_LOCACOES = qtdLocacao;
				}
			}

		}
	return 0;
}

int verificarCodigos(int codigoGuerreiro, int CodigoDragao){
	
	if( (VerificaCodigoGuerreiro(codigoGuerreiro) == 1 && VerificaCodigoDragao(CodigoDragao) == 1) ){
		
		return 1;
		
	}
	else{
		return 0;
	}
}


int Alugar(Locar l) {
	int i;
	for (i=0; i< QuantidadesLocacoes(); i++) {
		
		if (VerificaDragao() >= Locacao[i].qtdDragaoLocados) { 
		
			l.codigoLocacao = codLocacaoAtual++;
			Locacao[qtdLocacao] = l;	
			Locacao[i].pago = 0;		
			MudarEstoqueDragao(l.CodigoDragao, l.qtdDragaoLocados);
			Locacao[i].pago = 0; 
		    qtdLocacao++;
		    return 1; 
		}
	 	if (qtdLocacao > MAX_LOCACOES-1){
	    
        	    Locar* locacaoRealloc = (Locar*) realloc(Locacao, (MAX_LOCACOES+1) * sizeof(Locacao));
        	    if (locacaoRealloc != NULL){
    	        
    	        MAX_LOCACOES++;
    	        Locacao = locacaoRealloc;
    	        l.codigoLocacao = codLocacaoAtual++;
                Locacao[qtdLocacao] = l;
                DiminuiDragaoEstoque(l.qtdDragaoLocados);
                Locacao[i].pago = 0; 
                qtdLocacao++;
                
                return 1;
    	   }
    	   
    	    else{
	            return 0;
	        }
		}	
	}
}

int RealizarDevolucao( Locar l) {

    int i; 
    for (i = 0; i < MAX_LOCACOES; i++){
        
        if (l.codigoLocacao == Locacao[i].codigoLocacao){
            if (Locacao[i].pago == 0){
                
                strcpy(Locacao[i].DataInicioLocacao, l.DataFimLocacao);
                Locacao[i].pago = 1;
                int qtdLocacao = Locacao[i].qtdDragaoLocados;
                AumentaDragaoEstoque(qtdLocacao);
                return 0;
		}
		
		if (qtdLocacao <= 0.4 * MAX_LOCACOES){
                
        	    Locar* locacaoRealloc = (Locar*) realloc(Locacao, (MAX_LOCACOES-1) * sizeof(Locar));
                if (locacaoRealloc != NULL){
            }
                MAX_LOCACOES--;
                Locacao = locacaoRealloc;
                strcpy(Locacao[i].DataFimLocacao, l.DataFimLocacao);
                Locacao[i].pago = 1;
                int qtdDragao = Locacao[i].qtdDragaoLocados;
                DiminuiDragaoEstoque(qtdDragao);
                qtdLocacao--;
                return 0;
                
            }
        }
            else{
                
                return 1;
            }
      
        }    
    }   
	

int ApagarLocacaoPeloCodigo( int codigo) {
	int i;

	for (i=0; i < QuantidadesLocacoes(); i++) {
		if ( Locacao[i].codigoLocacao == codigo) {
			Locacao[i] = Locacao[qtdLocacao-1];
			Locacao[qtdLocacao-1].codigoLocacao = 0;
			qtdLocacao--;
			return 1;
		}else 
				return 0;

	}
}


int encerrarLocacoes(){
	 free(Locacao);
   return 1;
}


