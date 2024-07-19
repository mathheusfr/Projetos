#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int* vetor, int tamanho) {
    int aux;
	int i;
	int j;
    for ( i = tamanho - 1; i >= 1; i--) {
        for ( j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void mostrarVetor(int* vetor, int tamanho) {
	int i;
    for ( i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int tamanho = 10;

    printf("Vetor original:\n");
    mostrarVetor(vetor, tamanho);

    BubbleSort(vetor, tamanho);

    printf("Vetor ordenado:\n");
    mostrarVetor(vetor, tamanho);

    return 0;
}

