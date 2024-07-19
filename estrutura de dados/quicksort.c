#include <stdio.h>
#include <stdlib.h>

int Particao(int* array, int baixo, int alto) {
    int pivo = array[alto];
    int i = baixo - 1;
    int j;
    for (j = baixo; j < alto; j++) {
        if (array[j] <= pivo) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[alto];
    array[alto] = temp;
    return (i + 1);
}

void QuickSort(int* array, int baixo, int alto) {
    if (baixo < alto) {
        int pivo = Particao(array, baixo, alto);
        QuickSort(array, baixo, pivo - 1);
        QuickSort(array, pivo + 1, alto);
    }
}

void PreencheArrayDecrescente(int* array, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        array[i] = tamanho - i;
    }
}

int main() {
    int tamanhos[] = {5000000, 10000000}; 
    int k;
    for (k = 0; k < 2; k++) {
        int tamanho = tamanhos[k];
        int* array = (int*)malloc(tamanho * sizeof(int));
        if (array == NULL) {
            printf("Erro ao alocar memória para o array de tamanho %d\n", tamanho);
            return 1;
        }

        PreencheArrayDecrescente(array, tamanho);

        QuickSort(array, 0, tamanho - 1);

        printf("QuickSort completado para tamanho %d\n", tamanho);

        free(array);
    }

    return 0;
}

