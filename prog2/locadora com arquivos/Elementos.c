#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Elementos.h"

int MAX_ELEMENTOS =5;

Elemento* Elementos;

FILE *arq_elementos;

int CodigoElementoAtual = 1; 

int qtdElementos = 0;

int InicializaElementos(){ 
    
    Elemento e;
    
    arq_elementos = fopen("elementos.txt", "r+b");
    if ( arq_elementos== NULL){
        
        printf ("Erro no arquivo\n");
        system("pause");
        return 0;
    }
    
    fseek(arq_elementos, 0, SEEK_END);
    
    int tam_bytes = ftell(arq_elementos); 
    
    qtdElementos = (tam_bytes/sizeof(Elementos));
    
    fseek(arq_elementos, 0, SEEK_SET);
     
    int i;
    for (i = 0; i < qtdElementos; i++){
        
        fread(&e, sizeof(Elemento), 1, arq_elementos);
        if(e.codigoElemento > CodigoElementoAtual){
            
            CodigoElementoAtual = e.codigoElemento;
        }
    }
    
    CodigoElementoAtual++;
}


Elemento ObterElementosPeloIndice(int indice ) {
	return Elementos[indice];
}

int QuantidadesElementos() {
		return qtdElementos;
}

int SalvarElemento(Elemento e){
    
    if (qtdElementos < MAX_ELEMENTOS){
        
        e.codigoElemento = CodigoElementoAtual++;
    
        fseek(arq_elementos, 0, SEEK_END);
        fwrite(&e, sizeof(Elementos), 1, arq_elementos);
        
        qtdElementos++;

       	return 1;
    
    }
	
        else{
	        return 0;
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
			
			
			}else 
				return 0;
		}

}

int encerraElementos() {
   free(Elementos);
   return 1;
}


