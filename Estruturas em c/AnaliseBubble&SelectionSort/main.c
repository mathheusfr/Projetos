#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h> // Validação da acentuação e caracteres especiais.

// Inclusão das funções.
#include "bubblesort.h"
#include "selectionsort.h"
#include "binarysearch.h"
#include "linearsearch.h"
#include "dataset.h"

// Tamanhos dos conjuntos de dados para ordenação.
#define SIZE1 1
#define SIZE2 1
#define SIZE3 1
#define SIZE4 1

// Tamanhos dos conjuntos de dados para busca.
#define SIZE5 1
#define SIZE6 1
#define SIZE7 1
#define SIZE8 7000000000

 // Inicia cada array para cada conjunto de dados.
int* data_7;
int* data_8;
  
// Contador para quantidade de rodadas que o código deve ter.
int count = 0; 
int rounds = 1;

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "Portuguese"); // Validação da acentuação e caracteres especiais.
  
  printf("Gerando arquivo CSV com os dados. Por favor, aguarde!");
  
// Alocação de memória para garantir o trabalho com grandes dados.
  data_7 = (int*)malloc(SIZE7*sizeof(int));
  data_8 = (int*)malloc(SIZE8*sizeof(int));
  
  // Verificação da alocação.
  if (data_7 == NULL || data_8 == NULL) {
        printf("\nErro na alocação de memória. Execute o programa novamente.\n");
        return 1;
  }
  
  FILE *file = fopen("dados.csv", "w"); // Abre o arquivo para escrita.

  if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
  }

  freopen("dados.csv", "w", stdout); // Redireciona a saída padrão para o arquivo.
  
  while(count != rounds){
              
  // Controle das rodadas.
  printf("Rodada de numero %d.\n\n", count);
  
  // Cabeçalho do CSV.
  printf("ALGORITMO;DATA_SET;SEGUNDOS\n");
  
   // Iníco dos algoritmos de busca. Os dados já gerados ordenadamente de 1 até SIZE - 1.
  
  generateDataForSearch(data_7, SIZE7);
  generateDataForSearch(data_8, SIZE8);
  
  timeBinarySearch(data_7, SIZE7, SIZE7 - 1, 3); // Chama a função de busca para conjunto de dados 3.
  timeBinarySearch(data_8, SIZE8, SIZE8 - 1, 4); // Chama a função de busca para conjunto de dados 4.
  
  timeLinearSearch(data_7, SIZE7, SIZE7 - 3, 3); // Chama a função de busca para conjunto de dados 3.
  timeLinearSearch(data_8, SIZE8, SIZE8 - 4, 4); // Chama a função de busca para conjunto de dados 4.
  
  count++;
  
  printf("\n");
  } // Encerra o While.
  
  // Libera a memória.
  free(data_7);
  free(data_8);
  
  fclose(file); // Fecha o arquivo.
  freopen("CON", "w", stdout); // Retorna a saída padrão para o console.
  printf("Arquivo CSV gerado com sucesso!\n");
  system("start dados.csv"); // Abre o arquivo gerado.
  
  system("PAUSE");	
  return 0;
}

