#include <time.h> //Contagem do tempo.
#include <sys/time.h>
#include <Windows.h>
#include "binarysearch.h"
#include "dataset.h"

int binarySearch(int data[], int size, int value) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Verifica se o valor está no meio do array
        if (data[mid] == value) {
            return mid;
        }

        // Se o valor for menor que o valor do meio, descarta a metade direita
        if (data[mid] > value) {
            end = mid - 1;
        }
        // Se o valor for maior que o valor do meio, descarta a metade esquerda
        else {
            start = mid + 1;
        }
    }

    // Valor não encontrado
    return -1;
}

void timeBinarySearch(int data[], int size, int value, int data_set){
    // Medição de tempo.
    clock_t start, end; // Variáveis para controle de início e fim do tempo de execução.
    double cpu_time_used; // Variável para salvar o tempo de execução.
    start = clock(); // Inicia a contagem.
    
    // Faz a busca.
    int index = binarySearch(data, size, value);
    
    end = clock(); // Finaliza a contagem.
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Faz o cálculo de quantos segundos.
    
    if(index != -1) printf("Binary Search;%d;%f\n", data_set, cpu_time_used); // Imprime na tela mostrando qual conjunto utilizado o tempo exigido para ordenação.
    else printf("Binary Search;%d;NULL\n", data_set);
}

