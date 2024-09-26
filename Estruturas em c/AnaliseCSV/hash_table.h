#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct City {
    char uf[3];
    int ufCode;
    int cityCode;
    char name[100];
    int population;
    struct City* next;
} City;

typedef struct HashTable {
    int size;
    City** table;
} HashTable;

HashTable* createHashTable();
void freeHashTable(HashTable* hashTable);
unsigned int hashFunction(int cityCode, int size);
City* createCityNode(char* uf, int ufCode, int cityCode, char* name, int population);
void insertCity(HashTable* hashTable, char* uf, int ufCode, int cityCode, char* name, int population);
int loadCSV(HashTable* hashTable, char* filename);
void printHashTable(HashTable* hashTable);
int getTotalCities(HashTable* hashTable);
City* createCityArray(HashTable* hashTable, int totalCities);
int compareCities(const void* city1, const void* city2);
int compareCityCode(const void* city1, const void* city2);
void searchBinarySearch(HashTable* hashTable, int cityCode);
void searchHashTable(HashTable* hashTable, int cityCode);


#endif
