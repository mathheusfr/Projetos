#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#include "Guerreiros.h"

int MAX_GUERREIROS = 3;
int TAM_REALLOC_GUERREIROS = 3;

Guerreiro* Guerreiros;

int qtdGuerreiros = 0;

int CodigoAtual = 1;

int alocarGuerreiros(){
    
}

int inicializarGuerreiros() {
	Guerreiros = (Guerreiro*)malloc(MAX_GUERREIROS * sizeof(Guerreiro));
    if (Guerreiros==NULL)
        return 0;
	
	int i;
	for (i=0; i<MAX_GUERREIROS; i++) {
		
		if( qtdGuerreiros < MAX_GUERREIROS) {
	
		Guerreiros[i].CodigoDoGuerreiro = CodigoAtual;
		strcpy (Guerreiros[i].Nome, " ");
		strcpy (Guerreiros[i].Reino, " ");
		strcpy (Guerreiros[i].Titulo, " ");
		}	
   	} 
   
   	Guerreiros[0].CodigoDoGuerreiro = CodigoAtual++;
	strcpy(Guerreiros[0].Nome,   "Guerreiro1");
	strcpy(Guerreiros[0].Reino,  "Alaska ");
	strcpy(Guerreiros[0].Titulo, "Gladiador ");
	
    Guerreiros[qtdGuerreiros];
	qtdGuerreiros++;
	
	Guerreiros[1].CodigoDoGuerreiro = CodigoAtual++;
	strcpy(Guerreiros[1].Nome,   "  Naruto");
	strcpy(Guerreiros[1].Reino,  "  Aldeia da folha ");
	strcpy(Guerreiros[1].Titulo, "  Ninja ");
	
    Guerreiros[qtdGuerreiros];
	qtdGuerreiros++;
	
	Guerreiros[2].CodigoDoGuerreiro = CodigoAtual++;
	strcpy(Guerreiros[2].Nome,   "  Pantera Negra");
	strcpy(Guerreiros[2].Reino,  "  Wakanda ");
	strcpy(Guerreiros[2].Titulo, "  Heroi ");
	
    Guerreiros[qtdGuerreiros];
	qtdGuerreiros++;
} 

int SalvarGuerreiro (Guerreiro NovoGuerreiro) {
	int i;
	if( qtdGuerreiros < MAX_GUERREIROS) {
		NovoGuerreiro.CodigoDoGuerreiro = CodigoAtual++;
		Guerreiros[qtdGuerreiros] = NovoGuerreiro;
		qtdGuerreiros++;
		return 1;
		
	}
	if (qtdGuerreiros > MAX_GUERREIROS-1 ) {
		Guerreiro* GuerreiroRealloc = (Guerreiro*) realloc(Guerreiros, (MAX_GUERREIROS+1) * sizeof(Guerreiro));
 		if (GuerreiroRealloc != NULL){
 
    		MAX_GUERREIROS++;
    		Guerreiros = GuerreiroRealloc;
	        NovoGuerreiro.CodigoDoGuerreiro = CodigoAtual++;
            Guerreiros[qtdGuerreiros] = NovoGuerreiro;
            qtdGuerreiros++;
       	    return 1;
		}
	}
}

Guerreiro ObterGuerreiroPeloIndice(int indice ) {
	return Guerreiros[indice];
}


int QuantidadesGuerreiros() {
		return qtdGuerreiros;
}


int obterGuerreiroPeloNome (char* nome, Guerreiro* g){
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(strcmp(Guerreiros[i].Nome,nome)==0){
			(*g) = Guerreiros[i];						
			return 0;
		}
	}
}

int obterGuerreiroPeloCodigo(int codigo, Guerreiro* g){
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(codigo == Guerreiros[i].CodigoDoGuerreiro){
			(*g) = Guerreiros[i];
			return 0;
		}
	}
}


int ApagarGuerreiroPeloCodigo( int codigo) {
	int i;

	for (i=0; i < qtdGuerreiros; i++) {
		if ( Guerreiros[i].CodigoDoGuerreiro == codigo) {
			Guerreiros[i] = Guerreiros[qtdGuerreiros-1];
			Guerreiros[qtdGuerreiros-1].CodigoDoGuerreiro = 0;
			qtdGuerreiros--;
			return 1;
		}
	}
		
	if (qtdGuerreiros < 0.4 * MAX_GUERREIROS){
            
    Guerreiro* guerreiroRealloc = (Guerreiro*) realloc(Guerreiros, TAM_REALLOC_GUERREIROS * sizeof(Guerreiros));
    if (guerreiroRealloc != NULL){
            
        MAX_GUERREIROS--;
        Guerreiros = guerreiroRealloc;
        Guerreiros[i] = Guerreiros[qtdGuerreiros-1];
        Guerreiros[qtdGuerreiros -1].CodigoDoGuerreiro = 0;
	    qtdGuerreiros--;
	    return 1;
           	}   
        }else 
			return 0;				
}

int alterarGuerreiro(int codigo, char* novoNome, char* novoTitulo, char* novoReino){
        int i;
        for (i = 0; i < MAX_GUERREIROS; i++){
        if (codigo == Guerreiros[i].CodigoDoGuerreiro){
            
            strcpy(Guerreiros[i].Nome, novoNome);
            strcpy(Guerreiros[i].Titulo, novoTitulo);
            strcpy(Guerreiros[i].Reino, novoReino);
            
            return 1; 
        }  
    }
}

int alteraNomeGuerreiro(int cod,char* nome){
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(cod == Guerreiros[i].CodigoDoGuerreiro){
		strcpy(Guerreiros[i].Nome,nome);
		return 0;
		}	
	}
}
int alteraReinoGuerreiro(int cod,char* reino){
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(cod == Guerreiros[i].CodigoDoGuerreiro){
		strcpy(Guerreiros[i].Reino,reino);
		return 0;
		}	
	}
}
int alteraTituloGuerreiro(int cod,char* titulo){
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(cod == Guerreiros[i].CodigoDoGuerreiro){
		strcpy(Guerreiros[i].Titulo,titulo);
		return 0;
		}	
	}
}

int VerificaCodigoGuerreiro(int CodigoDoGuerreiro){
	
	int i;
	for (i = 0; i < MAX_GUERREIROS; i++){
		
		if (CodigoDoGuerreiro == Guerreiros[i].CodigoDoGuerreiro){
			return 1;
		}
	}
}



int encerraGuerreiros() {
   free(Guerreiros);
   return 1;
}



