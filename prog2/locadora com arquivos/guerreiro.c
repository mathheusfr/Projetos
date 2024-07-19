#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "guerreiro.h"

int MAX_GUERREIROS = 5;
Guerreiro* Guerreiros;
FILE *arq_guerreiros;

int qtdGuerreiros = 0;
int CodigoAtualGuerreiro = 0; 

int InicializarGuerreiros() { 
    
    Guerreiro g;
    
    
    arq_guerreiros = fopen("guerreiros.txt", "r+b");
    if (arq_guerreiros == NULL){
        
        printf ("Erro no arquivo\n");
        system("pause");
        return 0;
    }
    
    fseek(arq_guerreiros, 0, SEEK_END);
    
    int tam_bytes = ftell(arq_guerreiros);
    
    qtdGuerreiros = (tam_bytes/sizeof(Guerreiro));
    
    fseek(arq_guerreiros, 0, SEEK_SET);
    
    int i;
    for (i = 0; i < qtdGuerreiros; i++){
        
        fread(&g, sizeof(Guerreiro), 1, arq_guerreiros);
        if(g.CodigoDoGuerreiro > CodigoAtualGuerreiro){
            
            CodigoAtualGuerreiro = g.CodigoDoGuerreiro;
        }
    }
    
    CodigoAtualGuerreiro++;
}


int QuantidadeGuerreiros() {
    
    return qtdGuerreiros;
};


Guerreiro ObterGuerreiroPeloIndicee(int indice ) {
	return Guerreiros[indice];
}


int obterGuerreiroPeloIndice(int indice, Guerreiro* g){
    Guerreiro guerreiro; 
    rewind(arq_guerreiros);
    fseek(arq_guerreiros, indice* sizeof(Guerreiro), SEEK_SET);
    
    fread(&guerreiro, sizeof(Guerreiro), 1, arq_guerreiros);
    
    *g = guerreiro;
    
    return 1;
}

int SalvarGuerreiro(Guerreiro g) {
    
if (qtdGuerreiros < MAX_GUERREIROS){
    
    g.CodigoDoGuerreiro = CodigoAtualGuerreiro++;

    fseek(arq_guerreiros, 0, SEEK_END);
    fwrite(&g, sizeof(Guerreiro), 1, arq_guerreiros);
    
    qtdGuerreiros++;

   	return 1;

}

    else{
        return 0;
    }
    
}

int obterGuerreiroPeloNomee (char* nome, Guerreiro* g) {
int i;
for(i=0;i<MAX_GUERREIROS;i++){
	if(strcmp(Guerreiros[i].Nome,nome)==0){
		(*g) = Guerreiros[i];						
		return 0;
		}
	}
}


int obterGuerreiroPeloCodigo(int codigo, Guerreiro* g) {
    
Guerreiro grrero;

int i;

rewind(arq_guerreiros);
fseek(arq_guerreiros, 0, SEEK_CUR);

for (i = 0; i < qtdGuerreiros; i++){
    
    fread(&grrero, sizeof(Guerreiro), 1, arq_guerreiros);

    if(codigo == grrero.CodigoDoGuerreiro){
    	
        *g = grrero;
        
        return 1;
	}
        
} else 
	return 0;
}


int ApagarGuerreiroPeloCodigo(int codigo){
  
FILE* arquivoExcluirGuerreiro;
Guerreiro guerreiroExcluir;
int i; 

arquivoExcluirGuerreiro = fopen("excluirGuerreiro.txt", "w+b");

rewind(arq_guerreiros);

if((arq_guerreiros == NULL || arquivoExcluirGuerreiro == NULL)){

printf ("problema na abertura do arquivo\n");
system("pause");

}

else{
        
        fflush(arq_guerreiros);
        
        while(fread(&guerreiroExcluir, sizeof(Guerreiro), 1, arq_guerreiros) == 1){
        
        if(codigo != guerreiroExcluir.CodigoDoGuerreiro){
            
            fwrite(&guerreiroExcluir, sizeof(Guerreiro), 1, arquivoExcluirGuerreiro);
            codGuerreiroAtual--;    
        }
	}
}
    
    
    fclose(arq_guerreiros);
    fclose(arquivoExcluirGuerreiro);
    remove("guerreiros.txt");
    rename("excluirGuerreiro.txt", "guerreiros.txt");
    arq_guerreiros = fopen("guerreiros.txt", "r+b");
    return 1;

return 0;

}


int alterarGuerreiro(int codigo, Guerreiro g) {
	
	Guerreiro Guerreiros;
    FILE* alterarCadastroG = fopen("guerreiroAlterado.txt", "w+b");
    
    rewind(arq_guerreiros);
    
    while(fread(&Guerreiros, sizeof(Guerreiro), 1, arq_guerreiros) == 1){
        
        if(Guerreiros.CodigoDoGuerreiro != g.CodigoDoGuerreiro){
            
        	fwrite(&Guerreiros, sizeof(Guerreiro), 1, alterarCadastroG);
        }
        
        else{
        	
            fwrite(&g, sizeof(Guerreiro), 1, alterarCadastroG);
        }
    }
        
        fclose(arq_guerreiros);
        fclose(alterarCadastroG);
        remove("guerreiros.txt");
        rename("guerreiroAlterado.txt", "guerreiros.txt");
        arq_guerreiros = fopen("guerreiros.txt", "r+b");
        
        return 1;

}

int alteraNomeGuerreiro(int cod,char* nome)  {
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(cod == Guerreiros[i].CodigoDoGuerreiro){
		strcpy(Guerreiros[i].Nome,nome);
		return 0;
		}	
	}
}

int alteraReinoGuerreiro(int cod,char* reino)  {
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(cod == Guerreiros[i].CodigoDoGuerreiro){
		strcpy(Guerreiros[i].Reino,reino);
		return 0;
		}	
	}
}

int alteraTituloGuerreiro(int cod,char* titulo) {
	int i;
	for(i=0;i<MAX_GUERREIROS;i++){
		if(cod == Guerreiros[i].CodigoDoGuerreiro){
		strcpy(Guerreiros[i].Titulo,titulo);
		return 0;
		}	
	}
}

int VerificaCodigoGuerreiro(int CodigoDoGuerreiro) {
	
	int i;
	for (i = 0; i < MAX_GUERREIROS; i++){
		
		if (CodigoDoGuerreiro == Guerreiros[i].CodigoDoGuerreiro){
			return 1;
		}
	}
}

int encerraGuerreiros() {
  fclose(arq_guerreiros);
   return 1;
}



