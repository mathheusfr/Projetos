#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
	int topo;
	int vet[MAX];
}Pilha;

Pilha* inicializar() {
	Pilha* p;
	p = (Pilha*) malloc(sizeof(Pilha));
	p->topo == 0;
	return p;
}

Pilha* push(Pilha* p, int v) {
	if (p->topo == MAX) {
		exit(1);
	}else {
		
		p->vet[p->topo] = v;
		p->topo++;
		return p;
	}
}

Pilha* pop(Pilha* p) {
	if (p->topo == 0) {
		exit(1);
	}else {
		int v;
		v = p->vet[p->topo -1];
		p->topo--;
		
	}
}

int main () {
	
	return 0;
}
