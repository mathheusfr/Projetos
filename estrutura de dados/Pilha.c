#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int topo;
	int tam[MAX];
}Pilha;


Pilha* inicializarPilha() {
	Pilha* p;	
	p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}

Pilha* push(Pilha* p, int v) {
	if (p->topo == MAX) {
		exit(1);
	}else {
		p->tam[p->topo] = v;
		p->topo++;
	}
}

void mostrarPilha(Pilha* p ) {
	if (p->topo == 0 ) {
		printf (" Pilha vazia ");
		exit(1);
	}else {
		int i;
		for (i=0; i < p->topo; i++ ) {
			printf (" \n %d ", p->tam[i]);
		}
	}
	
}


int main () {
	
	Pilha *p;
	
	p = inicializarPilha();
	
	push(p,10);
	push(p,10);
	push(p,10);
	
	mostrarPilha(p);
	
	return 0;
}
