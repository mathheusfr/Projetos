#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

// -------------------- Funções de ordenação --------------------

// Para ordenar por nome
int compareCities(const void* city1, const void* city2) {
    City* c1 = (City*)city1;
    City* c2 = (City*)city2;
    
    return strcmp(c1->name, c2->name);
}

// Para ordenar pelo código
int compareCityCode(const void* city1, const void* city2) {
    City* c1 = (City*)city1;
    City* c2 = (City*)city2;
    
    if (c1->cityCode < c2->cityCode) {
        return -1;
    } else if (c1->cityCode > c2->cityCode) {
        return 1;
    } else {
        return 0;
    }
}

// -------------------- Fim das funções de ordenação --------------------

// -------------------- Início da número 2 --------------------
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));

    if (hashTable == NULL) {
        return NULL;
    }

    hashTable->size = 10;
    hashTable->table = (City**)calloc(hashTable->size, sizeof(City*));

    if (hashTable->table == NULL) {
        free(hashTable);
        return NULL;
    }

    return hashTable;
}

void freeHashTable(HashTable* hashTable) {
    if (hashTable == NULL) {
        return;
    }
    
    int i = 0;
    for (i = 0; i < hashTable->size; i++) {
        City* city = hashTable->table[i];

        while (city != NULL) {
            City* nextCity = city->next;
            free(city);
            city = nextCity;
        }
    }

    free(hashTable->table);
    free(hashTable);
}

unsigned int hashFunction(int cityCode, int size) {
    unsigned int hash = 0;

    while (cityCode > 0) {
        hash = (hash * 31) + (cityCode % 10);
        cityCode /= 10;
    }

    return hash % size;
}

City* createCityNode(char* uf, int ufCode, int cityCode, char* name, int population) {
    City* city = (City*)malloc(sizeof(City));

    if (city == NULL) {
        return NULL;
    }

    strcpy(city->uf, uf);
    city->ufCode = ufCode;
    city->cityCode = cityCode;
    strcpy(city->name, name);
    city->population = population;
    city->next = NULL;

    return city;
}

void insertCity(HashTable* hashTable, char* uf, int ufCode, int cityCode, char* name, int population) {
    City* city = createCityNode(uf, ufCode, cityCode, name, population);

    unsigned int index = hashFunction(cityCode, hashTable->size);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = city;
    } else {
        City* temp = hashTable->table[index];

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = city;
    }
}

int loadCSV(HashTable* hashTable, char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        return -1;
    }

    char line[256];
    char uf[3];
    int ufCode;
    int cityCode;
    char name[100];
    int population;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%2s,%d,%d,%[^,],%d", uf, &ufCode, &cityCode, name, &population);
        insertCity(hashTable, uf, ufCode, cityCode, name, population);
    }

    fclose(file);
    return 0;
}

void printHashTable(HashTable* hashTable) {
    int i = 0;
    int count = 0; // Criada para verificar se a quantidade de registros é igual a do arquivo
    
    for (i = 0; i < hashTable->size; i++) {
        City* city = hashTable->table[i];

        while (city != NULL) {
            printf("UF: %s, UF Code: %d, City Code: %d, Name: %s, Population: %d\n", 
                    city->uf, city->ufCode, city->cityCode, city->name, city->population);
            city = city->next;
            count++;
        }
        
        printf("%d registers.", count);
    }
}

// -------------------- Fim da número 2 --------------------

// -------------------- Início da número 3 --------------------

int getTotalCities(HashTable* hashTable) {
    int totalCities = 0;
    
    int i = 0;
    for (i = 0; i < hashTable->size; i++) {
        City* city = hashTable->table[i];

        while (city != NULL) {
            totalCities++;
            city = city->next;
        }
    }

    return totalCities;
}

City* createCityArray(HashTable* hashTable, int totalCities) {
    City* cityArray = (City*)malloc(totalCities * sizeof(City));

    if (cityArray == NULL) {
        return NULL;
    }

    int index = 0;
    int i = 0;
    for(i = 0; i < hashTable->size; i++) {
        City* city = hashTable->table[i];

        while (city != NULL) {
            memcpy(&cityArray[index], city, sizeof(City));
            index++;
            city = city->next;
        }
    }

    return cityArray;
}

// -------------------- Fim da número 3 --------------------

// -------------------- Início da número 6 --------------------

void searchHashTable(HashTable* hashTable, int cityCode) {
    printf("Busca na tabela de dispersao para o codigo %d:\n\n", cityCode);

    unsigned int index = hashFunction(cityCode, hashTable->size);
    City* city = hashTable->table[index];
    int accessCount = 0;
    int foundCount = 0;

    while (city != NULL) {
        accessCount++;

        if (city->cityCode == cityCode) {
            foundCount++;
            printf("Registro encontrado na tabela de dispersao.\n");
            printf("Indice: %u, Acessos: %d\n", index, accessCount);
            printf("Codigo: %d, Municipio: %s, UF: %s, Populacao: %d\n", city->cityCode, city->name, city->uf, city->population);
        }

        city = city->next;
    }

    if (foundCount == 0) {
        printf("Nenhum registro encontrado na tabela de dispersao para o codigo %d.\n", cityCode);
    }
}

void searchBinarySearch(HashTable* hashTable, int cityCode) {
    printf("\nBusca binaria na tabela de dispersao para o codigo %d:\n", cityCode);

    unsigned int index = hashFunction(cityCode, hashTable->size);
    City* city = hashTable->table[index];
    int accessCount = 0;
    int foundCount = 0;

    while (city != NULL) {
        accessCount++;

        if (city->cityCode == cityCode) {
            foundCount++;
            printf("Registro encontrado na tabela de dispersao.\n");
            printf("Indice: %u, Acessos: %d\n", index, accessCount);
            printf("Codigo: %d, Municipio: %s, UF: %s, Populacao: %d\n", city->cityCode, city->name, city->uf, city->population);
        }

        city = city->next;
    }

    if (foundCount == 0) {
        printf("Nenhum registro encontrado na tabela de dispersao para o codigo %d.\n", cityCode);
    }
}

// -------------------- Fim da número 6 --------------------
