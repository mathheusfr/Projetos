#include <time.h> //Contagem do tempo.
#include "selectionsort.h"
#include "dataset.h"

//Selection Sort com recursividade.
void swapSelectionSort(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        swapSelectionSort(&arr[min_idx], &arr[i]);
    }
}

//Selection Sort sem recursividade.
/*void selectionSort(int data[], int n) {
    int i, j, min, aux;
    for(i = 0; i < (n - 1); i++){
          min = i;
          for(j = (i + 1); j < n; j++){
                if(data[j] < data[min]) min = j;
          }
          if(i != min){
               aux = data[i];
               data[i] = data[min];
               data[min] = aux;
          }
    }
}*/

void timeSelectionSort(int data[], int size, int data_set){
    clock_t start, end; //Vari�veis para controle de in�cio e fim do tempo de execu��o.
    double cpu_time_used; //Vari�vel para salvar o tempo de execu��o.
    
    start = clock(); //Inicia a contagem.
    selectionSort(data, size); //Faz a ordena��o.
    end = clock(); //Finaliza a contagem.
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //Faz o c�lculo de quantos segundos.
    printf("Selection Sort;%d;%f\n", data_set, cpu_time_used); //Imprime na tela mostrando qual conjunto utilizado o tempo exigido para ordena��o.
}
