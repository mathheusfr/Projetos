#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dragoes.h"


int MAX_DRAGOES = 5;

Dragao* Dragoes;
FILE *arq_dragoes;

int qtdDragoes = 0;
int CodigoAtualDragao = 0; 

int alocarDragoes(){
    
}

int InicializarDragoes(){ 
    
    Dragao d;
    
    arq_dragoes = fopen("dragoes.txt", "r+b");
    if (arq_dragoes == NULL){
        
        printf ("Erro no arquivo\n");
        system("pause");
        return 0;
    }
    
    fseek(arq_dragoes, 0, SEEK_END);
    
    int tam_bytes = ftell(arq_dragoes); 
    
    qtdDragoes = (tam_bytes/sizeof(Dragoes));
    
    fseek(arq_dragoes, 0, SEEK_SET);
     
    int i;
    for (i = 0; i < qtdDragoes; i++){
        
        fread(&d, sizeof(Dragao), 1, arq_dragoes);
        if(d.codigo > CodigoAtualDragao){
            
            CodigoAtualDragao = d.codigo;
        }
    }
    
    CodigoAtualDragao++;
}


int QuantidadeDragoes(){
    
    return qtdDragoes;
}


Dragao ObterDragaoPeloIndicee(int indice ) {
	return Dragoes[indice];
}

int obterDragaoPeloIndice(int indice, Dragao* d){
    
  
    Dragao Dragoes; 
    rewind(arq_dragoes);
    fseek(arq_dragoes, indice* sizeof(Dragao), SEEK_SET);
    
    fread(&Dragoes, sizeof(Dragao), 1, arq_dragoes);
    
    *d= Dragoes;
    
    return 1;
}

int SalvarDragao(Dragao  d){
    
    if (qtdDragoes < MAX_DRAGOES){
        
        d.codigo = CodigoAtualDragao++;
    
        fseek(arq_dragoes, 0, SEEK_END);
        fwrite(&d, sizeof(Dragao), 1, arq_dragoes);
        
        qtdDragoes++;

       	return 1;     
	}
}

int obterDragaoPeloNomee (char* nome, Dragao* d){
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

int ApagarDragaoPeloCodigo(int codigo){
  
    FILE* arquivoExcluirDragao;
    Dragao dragoesExcluir;
    int i; 
    
    arquivoExcluirDragao = fopen("excluirDragao.txt", "w+b");
    
    rewind(arq_dragoes);
    
    if((arq_dragoes == NULL || arquivoExcluirDragao == NULL)){

	printf ("problema na abertura do arquivo\n");
	system("pause");

    }
    
    else{
            
            fflush(arq_dragoes);
            
            while(fread(&dragoesExcluir, sizeof(Dragao), 1, arq_dragoes) == 1){
            
            if(codigo != dragoesExcluir.codigo){
                
                fwrite(&dragoesExcluir, sizeof(Dragoes), 1, arquivoExcluirDragao);
                CodigoAtualDragao--;
    
            }
		}
    }
        
            
            fclose(arq_dragoes);
            fclose(arquivoExcluirDragao);
            remove("dragoes.txt");
            rename("excluirDragao.txt", "dragoes.txt");
            arq_dragoes = fopen("dragoes.txt", "r+b");
            return 1;

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


int alteraNomeDragao(int codigo,char* nome){
	int i;
	for(i=0;i<MAX_DRAGOES;i++){
		if(codigo == Dragoes[i].codigo){
		strcpy(Dragoes[i].Nome,nome);
		return 0;
		}	
	}
}

int alterarUnidadeDragao(int codigo, int* novoEstoque){
        int i;
        for (i = 0; i < MAX_DRAGOES; i++){
        if (codigo == Dragoes[i].codigo){
            
    			Dragoes[i].UnidadeEmEstoque = *novoEstoque;   
            return 1; 
        }  
    }
}

int alterarPrecoDragao(int codigo, int* novoPreco){
        int i;
        for (i = 0; i < MAX_DRAGOES; i++){
        if (codigo == Dragoes[i].codigo){
            
    		Dragoes[i].preco = *novoPreco;
         return 1; 
        }  
    }
}

int alterarIdadeDragao(int codigo, int* novaIdade){
        int i;
        for (i = 0; i < MAX_DRAGOES; i++){
        if (codigo == Dragoes[i].codigo){
            
    		Dragoes[i].idade = *novaIdade;
    
          
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
   fclose(arq_dragoes);
   return 1;
}


