#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "guerreiro.h"
#include "Dragoes.h"
#include "Elementos.h"
#include "Locacao.h"


int MAX_LOCACOES = 5;

FILE *arq_locacoes;

Locar* Locacao;

int CodigoLocacaoAtual = 1;


int qtdLocacao = 0;


int InicializarLocacao(){ 
    
   arq_locacoes = fopen("locacao.dat", "a+b");
    if (arq_locacoes == NULL){
        
        printf ("Erro no arquivo\n");
        system("pause");
        exit(1);
    }
    
    fseek(arq_locacoes, 0, SEEK_END);
    
    int tam_bytes = ftell(arq_locacoes); 
    
    qtdLocacao = ((tam_bytes/sizeof(Locar)));
    
    fseek(arq_locacoes, 0, SEEK_SET);
    
    MAX_LOCACAO = qtdLocacao;
    
 
    
    int lido = fread(locacao, sizeof(Locar), qtdLocacao, arq_locacoes);
   
     if(lido != qtdLocacao){
         
         printf ("erro na leitura do arquivo \n");
         system ("pause");
         exit(1);
     }
    
    return 1;
}

int obterLocacaoPeloIndice(int indice, Locar* l){
    Locar Locacao; 
    rewind(arq_locacoes);
    fseek(arq_locacoes, indice* sizeof(Locar), SEEK_SET);
    
    fread(&Locar, sizeof(Locar), 1, arq_locacoes);
    
    *l = Locar;
    
    return 1;
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
		
		if (VerificaDragao(l.CodigoDragao) >= Locacao[i].qtdDragaoLocados) { 
		
			l.codigoLocacao = codLocacaoAtual++;
			Locacao[qtdLocacao] = l;	
			Locacao[i].pago = 0;		
			MudarEstoqueDragao(l.CodigoDragao, l.qtdDragaoLocados);
			Locacao[i].pago = 0; 
		    qtdLocacao++;
		    return 1; 
		}
	 	if (qtdLocacao > MAX_LOCACOES-1){
	    
        	     fseek(arq_guerreiros, 0, SEEK_END);
    				fwrite(&g, sizeof(Guerreiro), 1, arq_guerreiros);
                
                return 1;
    	   }
    	   
    	    else{
	            return 0;
	        }
		}	
	
}

int RealizarDevolucao(Locar l) {

    int i; 
    for (i = 0; i < MAX_LOCACOES; i++){
        
        if (l.codigoLocacao == Locacao[i].codigoLocacao){
            if (Locacao[i].pago == 0){
                
                strcpy(Locacao[i].DataFimLocacao, l.DataFimLocacao);
                Locacao[i].pago = 1;
                int qtdLocacao = Locacao[i].qtdDragaoLocados;
                AumentaDragaoEstoque(l.CodigoDragao, qtdLocacao);
                return 0;
		}else{
                
                return 1;
        	}
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


int AlterarCadastroLocacao(int codigo, int novoCodGuerreiro, int novoCodDragao, char* novaDataInicio, int novoQtdLocado){
    
    int i;
    for (i = 0; i < MAX_LOCACOES; i++){

        if ((codigo == Locacao[i].codigoLocacao) && (Locacao[i].pago == 0)){
            
            Locacao[i].codigoLocacao = novoCodGuerreiro;
            Locacao[i].codigoGuerreiro = novoCodDragao;
            Locacao[i].qtdDragaoLocados = novoQtdLocado;
            strcpy(Locacao[i].DataInicioLocacao, novaDataInicio);
            
            return 1;
        }
    }
    
}


int AlterarGuerreiroLocacao(int codigo, int novoCodGuerreiro){
    
    int i;
    for (i = 0; i < MAX_LOCACOES; i++){

        if ((codigo == Locacao[i].codigoLocacao) && (Locacao[i].pago == 0)){
            
            Locacao[i].codigoGuerreiro = novoCodGuerreiro;
            
            return 1;
        }
    }
}

int AlterarDragaoLocacao(int codigo, int novoCodDragao){
    
    int i;
    for (i = 0; i < MAX_LOCACOES; i++){

        if ((codigo == Locacao[i].codigoGuerreiro) && (Locacao[i].pago == 0)){
            
            Locacao[i].CodigoDragao = novoCodDragao;
            
            return 1;
        }
    }
    
}

int AlterarDataLocacao(int codigo, char* novaDataInicio){
    
    int i;
    for (i = 0; i < MAX_LOCACOES; i++){

        if (codigo == Locacao[i].codigoLocacao){
            
            strcpy(Locacao[i].DataInicioLocacao, novaDataInicio);
            
            return 1;
        }
    }
}

int AlterarQtdLocacao(int codigo, int novoQtdLocado){
    int i;
    for (i = 0; i < MAX_LOCACOES; i++){

        if (codigo == Locacao[i].codigoLocacao){
            
            Locacao[i].qtdDragaoLocados = novoQtdLocado;
            
            return 1;
        }
    }
    
}

int encerraLocacao() {
    
   fseek(arq_locacoes, 0, SEEK_SET);
    int gravado = fwrite(locacao, sizeof(Locar), qtdLocacao, arq_locacoes);
    if (gravado != qtdLocacao){
        printf ("erro não escrita do arquivo \n");
        system("pause");
        exit(1);
    }   
   fclose(arq_locacoes);
   return 1;
}


