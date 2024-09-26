#include <time.h> //Contagem do tempo.
#include "linearsearch.h"
#include "dataset.h"

int linearSearch(int data[], int size, int value) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (data[i] == value) {
            return i; // Retorna a posição quando o valor é encontrado.
        }
    }
    return -1; // Retorna -1 se não encontra o valor.
}

void timeLinearSearch(int data[], int size, int value, int data_set){
    clock_t start, end; // Variáveis para controle de início e fim do tempo de execução.
    double cpu_time_used; // Variável para salvar o tempo de execução.
    start = clock(); // Inicia a contagem.
    
    // Faz a busca.
    int index = linearSearch(data, size, value);
    
    end = clock(); // Finaliza a contagem.
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Faz o cálculo de quantos segundos.
    
    if(index != -1) printf("Linear Search;%d;%f\n", data_set, cpu_time_used); // Imprime na tela mostrando qual conjunto utilizado o tempo exigido para ordenação.
    else printf("Linear Search;%d;NULL\n", data_set); // Retorna nulo se não achar o valor.
}
