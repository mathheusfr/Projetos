#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int idade;
} Pessoa;

typedef struct {
    int n;
    int inicio;
    Pessoa vet[MAX];
} FilaPrioridade;

FilaPrioridade* inicializarFila() {
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->n = 0;
    f->inicio = 0;
    return f;
}

FilaPrioridade* inserirFila(FilaPrioridade* f, int idade) {
    if (f->n == MAX) {
        exit(1);
    } else {
        int posicao_insercao = f->n;
        
        while (posicao_insercao > 0 && f->vet[posicao_insercao - 1].idade < idade) {
            f->vet[posicao_insercao] = f->vet[posicao_insercao - 1];
            posicao_insercao--;
        }
        
        f->vet[posicao_insercao].idade = idade;
        f->n++;
        
        return f;
    }
}


void retirarFila(FilaPrioridade* f) {
    if (f->n == 0) {
        printf("Fila de prioridade vazia.\n");
        exit(1);
    } else {
        // Desloque os elementos para remover o primeiro elemento
        int i;
        for ( i = 0; i < f->n - 1; i++) {
            f->vet[i] = f->vet[i + 1];
        }
        f->n--;
    }
}

void imprimir(FilaPrioridade* f) {
    if (f->n == 0) {
        printf("Fila de prioridade vazia.\n");
    } else {
    	int i;
        for ( i = 0; i < f->n; i++) {
            printf("%d ", f->vet[i].idade);
        }
        printf("\n");
    }
}

int main() {
    FilaPrioridade* f = inicializarFila();

    inserirFila(f, 20);
    inserirFila(f, 100);
    inserirFila(f, 20);
    inserirFila(f, 100);
    
    retirarFila(f);
    
    imprimir(f);

    retirarFila(f);

    imprimir(f);

    return 0;
}

