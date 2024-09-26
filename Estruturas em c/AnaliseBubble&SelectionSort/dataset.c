#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "dataset.h"

void generateData(int data[], int size) { //Gera os dados recebendo o array e o tamanho desejado.
    int i;
    
    for (i = 0; i < size; i++) {
        data[i] = size - i;
    }
}

void generateDataForSearch(int data[], int size) { //Gera os dados recebendo o array maior e o tamanho desejado para utilizar com as buscas.
    int i;
    
    for (i = 0; i < size; i++) {
        data[i] = i;
    }
}

void printData(int data[], int size) { //Verifica��o para saber se os dados est�o sendo gerados corretamente. N�o interefere no funcionamento do c�digo.
    int i;
    
    for (i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n\n");
}
