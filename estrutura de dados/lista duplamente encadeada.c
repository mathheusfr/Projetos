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

Lista* remover(Lista* l, int i) {
	Lista* p = l;
	while (p != NULL && p->n != i) {
		p = p->prox;
	}
	if (p == NULL) {
		return l; 
	}
	if (p->ant == NULL) {
		l = p->prox;
	} else {
		p->ant->prox = p->prox;
	}
	if (p->prox != NULL) {
		p->prox->ant = p->ant;
	}
	free(p);
	return l;
}

void mostrar(Lista* l) {
	Lista* p = l;
	while (p != NULL) {
		printf("%d ", p->n);
		p = p->prox;
	}
	printf("\n");
}

void mostrar_inverso(Lista* l) {
	if (l == NULL) return;

	Lista* p = l;
	while (p->prox != NULL) {
		p = p->prox;
	}
	while (p != NULL) {
		printf("%d ", p->n);
		p = p->ant;
	}
	printf("\n");
}

int main() {
	Lista* l = inicializar();
	
	l = inserir(l, 10);
	l = inserir(l, 20);
	l = inserir(l, 30);
	
	printf("Lista: ");
	mostrar(l);

	l = remover(l, 20);
	
	printf("Lista após remover 20: ");
	mostrar(l);
	
	printf("Lista em ordem inversa: ");
	mostrar_inverso(l);
	
	return 0;
}

