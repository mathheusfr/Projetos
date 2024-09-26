#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#include "hash_table.h"


// -------------------- Fun��es de teste de acesso(Exerc�cio 4) --------------------

// Para fazer a busca bin�ria em todas as cidades
void testBSearch(City* cityArray, int totalCities) {
    // Ordenar o array pelo c�digo da cidade
    qsort(cityArray, totalCities, sizeof(City), compareCityCode);
    
    // Acesso a todas as cidades usando busca bin�ria
    printf("\nAcesso a todas as cidades usando bsearch(): ");
    int i, verificate = 0, count = 0;
    for (i = 0; i < totalCities; i++) {
        int cityCodeToFind = cityArray[i].cityCode;
        City key;
        key.cityCode = cityCodeToFind;
        
        City* result = bsearch(&key, cityArray, totalCities, sizeof(City), compareCityCode);
        
        if (result == NULL) {
           printf("Erro: Cidade com codigo %d nao encontrada.\n", cityCodeToFind);
           verificate = 1;
        } 
        count++;
    }
    if (verificate == 0) {
       printf("todas as cidades foram encontradas, totalizando %d registros.\n", count);
    }
}

// Para fazer a busca pela tabela hash em todas as cidades
void testHashTableSearch(HashTable* hashTable, City* cityArray, int totalCities) {    
    printf("\nAcesso a todas as cidades usando tabela dispersa: ");
    int i, verificate = 0, count = 0;

    for (i = 0; i < totalCities; i++) {
        int cityCodeToFind = cityArray[i].cityCode;
        unsigned int index = hashFunction(cityCodeToFind, hashTable->size);

        City* city = hashTable->table[index];

        while (city != NULL) {
            if (city->cityCode == cityCodeToFind) {
                verificate = 1;
                break;  // Cidade encontrada
            }
            city = city->next;
        }

        if (city == NULL) {
            printf("Erro: Cidade com c�digo %d n�o encontrada. ", cityCodeToFind);
            count--;
            printf("Registro n�mero: %d \n", count);
        }
        count++;
    }

    if (verificate == 1) {
        printf("Todas as cidades foram encontradas totalizando %d registros.\n", count);
    } else if(verificate == 0){
        printf("Houve falha ao encontrar algumas cidades, totalizando %d registros.\n", count);
    }
}

// -------------------- Fun��es de teste de acesso(Exerc�cio 5) --------------------

void testBSearchTotalAcesses(City* cityArray, int totalCities) {
    // Ordenar o array pelo c�digo da cidade
    qsort(cityArray, totalCities, sizeof(City), compareCityCode);
    
    // Acesso a todas as cidades usando busca bin�ria
    printf("\nAcesso a todas as cidades usando algoritmo de busca binaria com total de acessos:\n\n");
    int i, totalAccesses = 0;

    for (i = 0; i < totalCities; i++) {
        int cityCodeToFind = cityArray[i].cityCode;

        City key;
        key.cityCode = cityCodeToFind;

        int low = 0;
        int high = totalCities - 1;
        int accessCount = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            accessCount++;

            if (cityArray[mid].cityCode == cityCodeToFind) {
                printf("Codigo: %d, Nome: %s\n", cityArray[mid].cityCode, cityArray[mid].name);
                break;
            }
            else if (cityArray[mid].cityCode < cityCodeToFind) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        totalAccesses += accessCount;
    }

    printf("Total de acessos: %d\n", totalAccesses);
    printf("\nFim do acesso a todas as cidades usando algoritmo de busca binaria com total de acessos informado acima.\n\n");
}

// -------------------- Fun��es de teste de acesso(Exerc�cio 6) --------------------

void testHashTableSearchTotalAcesses(HashTable* hashTable, City* cityArray, int totalCities) {
    printf("\nAcesso a todas as cidades usando tabela de dispersao com total de acessos:\n\n");
    int i, totalAccesses = 0;

    for (i = 0; i < totalCities; i++) {
        int cityCodeToFind = cityArray[i].cityCode;

        unsigned int index = hashFunction(cityCodeToFind, hashTable->size);
        City* city = hashTable->table[index];
        int accessCount = 0;

        while (city != NULL) {
            accessCount++;

            if (city->cityCode == cityCodeToFind) {
                printf("C�digo: %d, Nome: %s\n", city->cityCode, city->name);
                break;
            }

            city = city->next;
        }

        totalAccesses += accessCount;
    }

    printf("Total de acessos: %d\n", totalAccesses);
    printf("\nFim do acesso a todas as cidades usando tabela de dispersao com total de acessos informado acima.\n\n");
}



// -------------------- Fim das fun��es de teste de acesso --------------------

int main(int argc, char *argv[]) {
	    
    // -------------------- In�cio da n�mero 2 --------------------
    
    HashTable *hashTable = createHashTable();

    if (hashTable == NULL) {
        printf("Erro ao criar a tabela dispersa.\n");
        return 1;
    }

    if (loadCSV(hashTable, "cidades.csv") != 0) {
        printf("Erro ao carregar o arquivo CSV.\n");
        return 1;
    }

    /*printf("Tabela Dispersa:\n");
    printHashTable(hashTable);*/
    
    // -------------------- Fim da n�mero 2 --------------------
    
    
    // -------------------- In�cio da n�mero 3 --------------------
    
    // Cria nova estrutura de dados
    int totalCities = getTotalCities(hashTable);
    City* cityArray = createCityArray(hashTable, totalCities);

    if (cityArray == NULL) {
        printf("Erro ao criar o array de cidades.\n");
        return 1;
    }
    
    // Ordena as cidades pelo c�digo
    qsort(cityArray, totalCities, sizeof(City), compareCityCode);
    
    // Dados ordenados  
    int i = 0;
    int count = 0;
    for (i = 0; i < totalCities; i++) {
        //printf("UF: %s, UF Code: %d, City Code: %d, Name: %s, Population: %d\n", cityArray[i].uf, cityArray[i].ufCode, cityArray[i].cityCode, cityArray[i].name, cityArray[i].population);
        count++;
    }
    printf("%d registros ordenados para efetuacao da busca binaria.\n", count);
    
    // -------------------- Fim da n�mero 3 --------------------  
    
    // -------------------- In�cio da n�mero 4 --------------------
    
    // Verifica��o antes de exibir o resultado da busca bin�ria
    if (cityArray != NULL) {
        testBSearch(cityArray, totalCities);
    } else {
        printf("Erro ao criar o array de cidades.\n");
    }
    
    // Verifica��o antes de exibir o resultado da busca na tabela dispersa
    if (cityArray != NULL) {
        testHashTableSearch(hashTable, cityArray, totalCities);
    } else {
        printf("Erro ao criar o array de cidades.\n");
    }

    
    // -------------------- Fim da n�mero 4 --------------------
    
    
    // -------------------- In�cio da n�mero 5 --------------------
    
    // Verifica��o antes de exibir o resultado da busca na tabela dispersa
    if (cityArray != NULL) {
        testBSearchTotalAcesses(cityArray, totalCities);
    } else {
        printf("Erro ao criar o array de cidades.\n");
    }
    
    // -------------------- Fim da n�mero 5 --------------------
    
    // -------------------- In�cio da n�mero 6 --------------------
    
	if (cityArray != NULL) {
        testHashTableSearchTotalAcesses(hashTable, cityArray, totalCities);
    } else {
        printf("Erro ao criar o array de cidades.\n");
    }
    
    // -------------------- In�cio da n�mero 6 --------------------
    
	insertCity(hashTable, "RS", 10, 6001, "Albatroz", 5000);
	insertCity(hashTable, "SC", 20, 6001, "Borussia", 4000);
	insertCity(hashTable, "PR", 30, 6001, "Palmital", 3000);
	insertCity(hashTable, "MT", 40, 6001, "Laranjeiras", 2000);
	
	int searchCityCode = 6001;
	searchHashTable(hashTable, searchCityCode);
	searchBinarySearch(hashTable, searchCityCode);

    
    // -------------------- Fim da n�mero 6 --------------------    
    
    free(cityArray);
    freeHashTable(hashTable);
    
    printf("\n");
    system("PAUSE");	
    return 0;
}
