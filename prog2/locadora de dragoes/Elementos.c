#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Elementos.h"

int MAX_ELEMENTOS =5;
int TAM_REALLOC_ELEMENTOS = 2;

Elemento* Elementos;

int CodigoElementoAtual = 1; 

int qtdElementos = 0;

int inicializarElementos() {
	
	Elementos = (Elemento*)malloc(MAX_ELEMENTOS * sizeof(Elemento));
    if (Elementos==NULL)
        return 0;
	
	int i;
	for (i=0; i<MAX_ELEMENTOS; i++) {
		
		if( qtdElementos < MAX_ELEMENTOS) {
		Elementos[i].codigoElemento = CodigoElementoAtual;
		strcpy (Elementos[i].nome, " ");
		strcpy (Elementos[i].vunerabilidade, "");
   		}			
   }
	Elementos[0].codigoElemento = CodigoElementoAtual++;
	strcpy(Elementos[0].nome,   "Fogo");
	strcpy(Elementos[0].vunerabilidade,  "Agua ");

	Elementos[qtdElementos];
	qtdElementos++;	
}



Elemento ObterElementosPeloIndice(int indice ) {
	return Elementos[indice];
}

int QuantidadesElementos() {
		return qtdElementos;
}

int SalvarElemento( Elemento NovoElemento ) {
	int i;
	if( qtdElementos < MAX_ELEMENTOS) {
		NovoElemento.codigoElemento = CodigoElementoAtual++;
		Elementos[qtdElementos] = NovoElemento;
		qtdElementos++;
		return 1;
		
	}
	if (qtdElementos > MAX_ELEMENTOS-1 ) {
		Elemento* ElementoRealloc = (Elemento*) realloc(Elementos, (MAX_ELEMENTOS+1) * sizeof(Elemento));
 		if (ElementoRealloc != NULL){
 
    		MAX_ELEMENTOS++;
    		Elementos = ElementoRealloc;
	        NovoElemento.codigoElemento = CodigoElementoAtual++;
            Elementos[qtdElementos] = NovoElemento;
            qtdElementos++;
       	    return 1;
		}
	}
}


int obterElementoPeloNome (char* nomeElemento, Elemento* e) {
	int i;
	for(i=0;i<MAX_ELEMENTOS;i++){
		if(strcmp(Elementos[i].nome,nomeElemento)==0){
			(*e) = Elementos[i];						
			return 0;
		}
	}
}





int AlterarCadastroElemento(int codigo, char* novoNome, char* novaVulnerabilidade){
    
    int i;
    for (i = 0; i < MAX_ELEMENTOS; i++){
     
        if (codigo == Elementos[i].codigoElemento){
            
            strcpy(Elementos[i].nome, novoNome);
            strcpy(Elementos[i].vunerabilidade, novaVulnerabilidade);
            
            return 1;
        }
        
    }

}

int VerificaElemento(){
    
    int i;
    for (i = 0; i < MAX_ELEMENTOS; i++){
        
        return Elementos[i].codigoElemento;
    }
}


int ApagarElementosPeloCodigo( int codigo) {
	int i;

	for (i=0; i < qtdElementos; i++) {
		if ( Elementos[i].codigoElemento == codigo) {
			Elementos[i] = Elementos[qtdElementos-1];
			Elementos[qtdElementos-1].codigoElemento = 0;
			qtdElementos--;
			return 1;
		}
		
		if (qtdElementos < 0.4 * MAX_ELEMENTOS){
            
    	Elemento* ElementoRealloc = (Elemento*) realloc(Elementos, TAM_REALLOC_ELEMENTOS * sizeof(Elementos));
        if (ElementoRealloc != NULL){
            
        MAX_ELEMENTOS--;
        Elementos = ElementoRealloc;
        }
           
        }
			else 
				return 0;

	}
}

int encerraElementos() {
   free(Elementos);
   return 1;
}

