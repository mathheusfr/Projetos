#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 12000  // Assumindo 1000 registros por mês
#define NUM_MESES 12
#define TAM_TABELA_HASH 1000  // Tamanho da tabela hash

typedef struct RegistroCriminalidade {
    char nome_cidade[100];
    int homicidio_doloso;
    int total_vitimas_homicidio_doloso;
    int latrocinio;
    int furtos;
    int abigeato;
    int furto_veiculo;
    int roubos;
    int roubo_veiculo;
    int estelionato;
    int delitos_armas_municoes;
    int entorpecentes_posse;
    int entorpecentes_trafico;
    int vitimas_latrocinio;
    int vitimas_lesao_corp_morte;
    int total_vitimas_cvli;
    int exibido;
    struct RegistroCriminalidade *proximo;  
} RegistroCriminalidade;

typedef struct HashTable {
    RegistroCriminalidade *lista[TAM_TABELA_HASH];
} HashTable;

// Função de hash melhorada usando multiplicação pela constante dourada (ouro)
int hash(const char *nome_cidade) {
    unsigned long hash = 5381;
    int c;

    while ((c = *nome_cidade++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % TAM_TABELA_HASH;
}

// Inserir registro na tabela hash
void inserirNaHash(HashTable *tabela, RegistroCriminalidade *registro) {
    int indice = hash(registro->nome_cidade);
    
    // Se a lista na posição índice estiver vazia
    if (tabela->lista[indice] == NULL) {
        registro->proximo = NULL;
        tabela->lista[indice] = registro;
    } else {
        // Se a lista já tiver elementos, insere no início
        registro->proximo = tabela->lista[indice];
        tabela->lista[indice] = registro;
    }

    printf("Registro inserido na tabela hash: %s\n", registro->nome_cidade);
}

// Buscar registro na tabela hash
RegistroCriminalidade *buscarNaHash(HashTable *tabela, const char *nome_cidade, int *comparacoes) {
    int indice = hash(nome_cidade);
    RegistroCriminalidade *atual = tabela->lista[indice];
    *comparacoes = 0;
    while (atual != NULL) {
        (*comparacoes)++;
        if (strcmp(atual->nome_cidade, nome_cidade) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;  // Registro não encontrado
}

// Função para ler dados CSV
int lerDadosCSV(const char *nomeArquivo, RegistroCriminalidade ***registros, int *numRegistros, HashTable *tabelaHash) {
    FILE *fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        return 0;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), fp)) {
        RegistroCriminalidade *registro = (RegistroCriminalidade *)malloc(sizeof(RegistroCriminalidade));
        if (registro == NULL) {
            fclose(fp);
            return 0;
        }
        
        sscanf(linha, "%[^;];%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d",
               registro->nome_cidade,
               &registro->homicidio_doloso,
               &registro->total_vitimas_homicidio_doloso,
               &registro->latrocinio,
               &registro->furtos,
               &registro->abigeato,
               &registro->furto_veiculo,
               &registro->roubos,
               &registro->roubo_veiculo,
               &registro->estelionato,
               &registro->delitos_armas_municoes,
               &registro->entorpecentes_posse,
               &registro->entorpecentes_trafico,
               &registro->vitimas_latrocinio,
               &registro->vitimas_lesao_corp_morte,
               &registro->total_vitimas_cvli);

        // Inserir na tabela hash
        inserirNaHash(tabelaHash, registro);

        (*registros)[*numRegistros] = registro;
        (*numRegistros)++;
    }

    fclose(fp);
    return 1;
}

// Função de comparação para qsort (ordena por nome da cidade)
int comparaCidades(const void *a, const void *b) {
    RegistroCriminalidade *registroA = *(RegistroCriminalidade **)a;
    RegistroCriminalidade *registroB = *(RegistroCriminalidade **)b;
    return strcmp(registroA->nome_cidade, registroB->nome_cidade);
}

// Função para mostrar um registro
void mostrarRegistro(RegistroCriminalidade *registro) {
    printf("Cidade: %s\n", registro->nome_cidade);
    printf("Homicidio Doloso: %d\n", registro->homicidio_doloso);
    printf("Total de Vítimas de Homicidio Doloso: %d\n", registro->total_vitimas_homicidio_doloso);
    printf("Latrocinio: %d\n", registro->latrocinio);
    printf("Furtos: %d\n", registro->furtos);
    printf("Abigeato: %d\n", registro->abigeato);
    printf("Furto de Veículo: %d\n", registro->furto_veiculo);
    printf("Roubos: %d\n", registro->roubos);
    printf("Roubo de Veículo: %d\n", registro->roubo_veiculo);
    printf("Estelionato: %d\n", registro->estelionato);
    printf("Delitos com Armas e Munições: %d\n", registro->delitos_armas_municoes);
    printf("Entorpecentes em Posse: %d\n", registro->entorpecentes_posse);
    printf("Entorpecentes em Tráfico: %d\n", registro->entorpecentes_trafico);
    printf("Vítimas de Latrocínio: %d\n", registro->vitimas_latrocinio);
    printf("Vítimas de Lesão Corporal com Morte: %d\n", registro->vitimas_lesao_corp_morte);
    printf("Total de Vítimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", registro->total_vitimas_cvli);
    printf("\n");
}

// Função para buscar um registro com bsearch
RegistroCriminalidade *buscarRegistroComBSearch(RegistroCriminalidade **registros, int numRegistros, const char *nome_cidade, int *comparacoes) {
    RegistroCriminalidade chave;
    strcpy(chave.nome_cidade, nome_cidade);

    *comparacoes = 0;
    int esquerda = 0;
    int direita = numRegistros - 1;
    
    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = (esquerda + direita) / 2;
        int resultadoComparacao = strcmp(registros[meio]->nome_cidade, nome_cidade);
        if (resultadoComparacao == 0) {
            return registros[meio];
        } else if (resultadoComparacao < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return NULL;
}

// Função para mostrar dados da memória
void mostrarDadosMemoria(int numRegistros, int tamanhoTabela) {
    printf("Número de registros carregados: %d\n", numRegistros);
    printf("Tamanho da tabela hash: %d\n", tamanhoTabela);
    printf("Memória ocupada pelo array de registros: %lu bytes\n", numRegistros * sizeof(RegistroCriminalidade *));
    printf("Memória ocupada pela tabela hash: %lu bytes\n", tamanhoTabela * sizeof(RegistroCriminalidade *));
}

// Função para imprimir a tabela hash para depuração
void imprimirTabelaHash(HashTable *tabela) {
    int i;
    for (i = 0; i < TAM_TABELA_HASH; i++) {
        if (tabela->lista[i] != NULL) {
            printf("Índice %d:\n", i);
            RegistroCriminalidade *atual = tabela->lista[i];
            while (atual != NULL) {
                printf("  Cidade: %s\n", atual->nome_cidade);
                atual = atual->proximo;
            }
        }
    }
}

void buscarTodosComTabelaHash(HashTable *tabelaHash) {
    int totalComparacoes = 0;
    int comparacoesMax = 0;
    int comparacoesMin = 1e9;
    int comparacoes = 0;
    RegistroCriminalidade *resultado = NULL;
    int i;
    for ( i = 0; i < TAM_TABELA_HASH; i++) {
        RegistroCriminalidade *atual = tabelaHash->lista[i];
        while (atual != NULL) {
            comparacoes = 0;
            resultado = buscarNaHash(tabelaHash, atual->nome_cidade, &comparacoes);
            totalComparacoes += comparacoes;
            if (comparacoes > comparacoesMax) {
                comparacoesMax = comparacoes;
            }
            if (comparacoes < comparacoesMin) {
                comparacoesMin = comparacoes;
            }
            atual = atual->proximo;
        }
    }

    printf("Total de comparações: %d\n", totalComparacoes);
    printf("Média de comparações: %.2f\n", (double)totalComparacoes / TAM_TABELA_HASH);
    printf("Máximo de comparações: %d\n", comparacoesMax);
    printf("Mínimo de comparações: %d\n", comparacoesMin);
}

void buscarTodosComBSearch(RegistroCriminalidade **registros, int numRegistros) {
    int totalComparacoes = 0;
    int comparacoesMax = 0;
    int comparacoesMin = 1e9;
    int comparacoes = 0;
    RegistroCriminalidade *resultado = NULL;
	int i;
    for ( i = 0; i < numRegistros; i++) {
        comparacoes = 0;
        resultado = buscarRegistroComBSearch(registros, numRegistros, registros[i]->nome_cidade, &comparacoes);
        totalComparacoes += comparacoes;
        if (comparacoes > comparacoesMax) {
            comparacoesMax = comparacoes;
        }
        if (comparacoes < comparacoesMin) {
            comparacoesMin = comparacoes;
        }
    }

    printf("Total de comparações: %d\n", totalComparacoes);
    printf("Média de comparações: %.2f\n", (double)totalComparacoes / numRegistros);
    printf("Máximo de comparações: %d\n", comparacoesMax);
    printf("Mínimo de comparações: %d\n", comparacoesMin);
}

int main() {
    HashTable tabelaHash = {0};
    RegistroCriminalidade **registros = (RegistroCriminalidade **)malloc(MAX_REGISTROS * sizeof(RegistroCriminalidade *));
    if (registros == NULL) {
        printf("Erro ao alocar memória para registros.\n");
        return 1;
    }

    int numRegistros = 0;

    // Ler os 12 arquivos CSV (um para cada mês)
    int i;
    for ( i = 1; i <= NUM_MESES; i++) {
        char nomeArquivo[50];
        sprintf(nomeArquivo, "mes%02d.csv", i);
        if (!lerDadosCSV(nomeArquivo, &registros, &numRegistros, &tabelaHash)) {
            printf("Erro ao ler o arquivo: %s\n", nomeArquivo);
            return 1;
        }
    }

    // Ordenar os registros por nome de cidade
    qsort(registros, numRegistros, sizeof(RegistroCriminalidade *), comparaCidades);

    // Mostrar dados da memória
    mostrarDadosMemoria(numRegistros, TAM_TABELA_HASH);

    // Buscar e mostrar todos os registros na tabela hash
    printf("Busca na tabela hash:\n");
    buscarTodosComTabelaHash(&tabelaHash);

    // Buscar e mostrar todos os registros com bsearch
    printf("\nBusca com bsearch:\n");
    buscarTodosComBSearch(registros, numRegistros);

    // Limpar memória alocada
    for ( i = 0; i < numRegistros; i++) {
        free(registros[i]);
    }
    free(registros);

    return 0;
}

