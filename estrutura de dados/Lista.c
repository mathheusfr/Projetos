#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
	int n;
	struct Lista* prox;
	struct Lista* ant;
} Lista;

Lista* inicializar() {
	return NULL;
}

Lista* inserir(Lista* l, int i) {
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	if (novo == NULL) {
		exit(1);
	} else {
		novo->n = i;
		novo->prox = l;
		novo->ant = NULL;
		
		if (l != NULL) {
			l->ant = novo;
		}
		return novo;
	}
}

void mostrar(Lista* l) {
	Lista* p = l;
	while (p != NULL) {
		printf("%d ", p->n);
		p = p->prox;
	}
	printf("\n");
}

int main() {
	Lista* l = inicializar();
	
	l = inserir(l, 10);
	l = inserir(l, 20);
	l = inserir(l, 30);
	
	mostrar(l);
	
	return 0;
}

