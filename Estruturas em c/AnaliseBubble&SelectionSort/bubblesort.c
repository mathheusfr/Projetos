#include <time.h> //Contagem do tempo.
#include "bubblesort.h"
#include "dataset.h"

void swapBubbleSort(int *a, int *b) { //Função de troca de dados que é chamada quando necessário.
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
        // Se o elemento atual for maior que o próximo, realiza a troca.
        if (data[i] > data[i + 1])
            swapBubbleSort(&data[i], &data[i + 1]); //A troca é realizada chamando a função swapBubbleSort
    }

    // Chama recursivamente a função bubbleSort para o subarray restante.
    bubbleSort(data, n - 1);
}

void timeBubbleSort(int data[], int size, int data_set){
    clock_t start, end; //Variáveis para controle de início e fim do tempo de execução.
    double cpu_time_used; //Variável para salvar o tempo de execução.
    
    start = clock(); //Inicia a contagem.
    bubbleSort(data, size); //Faz a ordenação.
    end = clock(); //Finaliza a contagem.
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //Faz o cálculo de quantos segundos.
    printf("Bubble Sort;%d;%f\n", data_set, cpu_time_used); //Imprime na tela mostrando qual conjunto utilizado o tempo exigido para ordenação.
}
