#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int n;
    int inicio;
    int vet[MAX];
} Fila;

Fila* inicializar() {
    Fila* f;
    f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    f->inicio = 0;
    return f;
}

Fila* inserir(Fila* f, int v) {
    if (f->n == MAX) {
        printf("Fila cheia\n");
        exit(1);
    } else {
        int fim;
        fim = (f->n + f->inicio) % MAX;
        f->vet[fim] = v;
        f->n++;
        return f;
    }
}

Fila* remover(Fila* f) {
    if (f->n == 0) {
        printf("Fila vazia\n");
        exit(1);
    } else {
        int v;
        v = f->vet[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        f->n--;
        printf("Removido: %d\n", v);
    }
    return f;
}

void imprimir(Fila* f) {
    if (f->n == 0) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    int i;
    for (i = 0; i < f->n; i++) {
        printf("%d ", f->vet[(f->inicio + i) % MAX]);
    }
    printf("\n");
}

int main() {
    Fila* f = inicializar();

    f = inserir(f, 1);
    f = inserir(f, 2);
    f = inserir(f, 3);
    f = inserir(f, 4);
    f = inserir(f, 5);

    imprimir(f);

    f = remover(f);
    f = remover(f);

    imprimir(f);

    f = inserir(f, 6);
    f = inserir(f, 7);

    imprimir(f);

    free(f);

    return 0;
}

