#include <time.h> //Contagem do tempo.
#include "bubblesort.h"
#include "dataset.h"

void swapBubbleSort(int *a, int *b) { //Fun��o de troca de dados que � chamada quando necess�rio.
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int data[], int n) {
    int i;
    
    if (n == 1)
        return;

    // Percorre o array e compara elementos adjacentes.
    for (i = 0; i < n - 1; i++) {
        // Se o elemento atual for maior que o pr�ximo, realiza a troca.
        if (data[i] > data[i + 1])
            swapBubbleSort(&data[i], &data[i + 1]); //A troca � realizada chamando a fun��o swapBubbleSort
    }

    // Chama recursivamente a fun��o bubbleSort para o subarray restante.
    bubbleSort(data, n - 1);
}

void timeBubbleSort(int data[], int size, int data_set){
    clock_t start, end; //Vari�veis para controle de in�cio e fim do tempo de execu��o.
    double cpu_time_used; //Vari�vel para salvar o tempo de execu��o.
    
    start = clock(); //Inicia a contagem.
    bubbleSort(data, size); //Faz a ordena��o.
    end = clock(); //Finaliza a contagem.
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //Faz o c�lculo de quantos segundos.
    printf("Bubble Sort;%d;%f\n", data_set, cpu_time_used); //Imprime na tela mostrando qual conjunto utilizado o tempo exigido para ordena��o.
}
