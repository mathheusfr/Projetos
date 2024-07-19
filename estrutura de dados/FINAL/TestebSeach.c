#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 12000  // Assumindo 1000 registros por mês
#define NUM_MESES 12
#define TAM_TABELA_HASH 1000  // Tamanho da tabela hash

typedef struct RegistroCriminalidade {
    char nome_cidade[100];
    int mes;
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
    
    // Criação de um novo registro na tabela hash
    RegistroCriminalidade *novoRegistro = (RegistroCriminalidade *) malloc(sizeof(RegistroCriminalidade));
    if (novoRegistro == NULL) {
        perror("Erro ao alocar memória para novo registro na tabela hash");
        exit(EXIT_FAILURE);
    }
    memcpy(novoRegistro, registro, sizeof(RegistroCriminalidade));
    novoRegistro->proximo = NULL;

    // Se a lista na posição índice estiver vazia
    if (tabela->lista[indice] == NULL) {
        tabela->lista[indice] = novoRegistro;
    } else {
        // Se a lista já tiver elementos, insere no final
        RegistroCriminalidade *atual = tabela->lista[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoRegistro;
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

// Função para ler dados de um arquivo CSV e inserir na tabela hash
int lerDadosCSV(const char *nomeArquivo, HashTable *tabelaHash) {
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
               &registro->mes,
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
    }

    fclose(fp);
    return 1;
}

// Função de comparação para bsearch (ordena por nome da cidade e mês)
int comparaCidadesEMes(const void *a, const void *b) {
    RegistroCriminalidade *cidadeA = (RegistroCriminalidade *)a;
    RegistroCriminalidade *cidadeB = (RegistroCriminalidade *)b;

    int cmp = strcmp(cidadeA->nome_cidade, cidadeB->nome_cidade);
    if (cmp == 0) {
        return cidadeA->mes - cidadeB->mes;
    } else {
        return cmp;
    }
}

// Função para buscar dados de criminalidade por cidade e mês no array ordenado
RegistroCriminalidade *buscarDadosCriminalidade(RegistroCriminalidade dados[], int numDados, const char *cidadeBusca, int mesBusca) {
    RegistroCriminalidade chaveBusca;
    strcpy(chaveBusca.nome_cidade, cidadeBusca);
    chaveBusca.mes = mesBusca;

    // Busca por cidade e mês usando bsearch
    RegistroCriminalidade *resultado = bsearch(&chaveBusca, dados, numDados, sizeof(RegistroCriminalidade), comparaCidadesEMes);

    return resultado;
}

// Função para mostrar um registro
void mostrarRegistro(RegistroCriminalidade *registro) {
    printf("Cidade: %s\n", registro->nome_cidade);
    printf("Mês: %d\n", registro->mes);
    printf("Homicídio Doloso: %d\n", registro->homicidio_doloso);
    printf("Total de Vítimas de Homicídio Doloso: %d\n", registro->total_vitimas_homicidio_doloso);
    printf("Latrocínio: %d\n", registro->latrocinio);
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
    printf("Vítimas de Lesão Corporal: %d\n", registro->vitimas_lesao_corp_morte);
    printf("Total de Vítimas CVLI: %d\n", registro->total_vitimas_cvli);
    printf("\n");
}

// Função para buscar dados de criminalidade por cidade na tabela hash
void buscarDadosPorCidade(HashTable *tabelaHash, const char *cidadeBusca) {
    int comparacoes;
    RegistroCriminalidade *resultado = buscarNaHash(tabelaHash, cidadeBusca, &comparacoes);
    
    if (resultado != NULL) {
        printf("Registro encontrado:\n");
        mostrarRegistro(resultado);
        printf("Número de comparações realizadas na busca: %d\n", comparacoes);
    } else {
        printf("Registro não encontrado para a cidade: %s\n", cidadeBusca);
    }
}

int main() {
    RegistroCriminalidade registros[MAX_REGISTROS];
    int numRegistros = 0;
    HashTable tabelaHash;

    // Inicializar tabela hash	
    int i;
    for ( i = 0; i < TAM_TABELA_HASH; i++) {
        tabelaHash.lista[i] = NULL;
    }

    // Ler dados de todos os arquivos CSV
    for ( i = 1; i <= NUM_MESES; i++) {
        char nomeArquivo[50];
        sprintf(nomeArquivo, "criminalidade-%02d-2023.csv", i);

        if (!lerDadosCSV(nomeArquivo, &tabelaHash)) {
            fprintf(stderr, "Erro ao ler o arquivo: %s\n", nomeArquivo);
            return EXIT_FAILURE;
        }
    }

    // Ordenar registros por nome da cidade e mês
    qsort(registros, numRegistros, sizeof(RegistroCriminalidade), comparaCidadesEMes);

    // Menu de busca
    int opcao;
    do {
        printf("\n");
        printf("Selecione uma opção:\n");
        printf("1 - Buscar dados de criminalidade por cidade e mês\n");
        printf("2 - Buscar dados de criminalidade por cidade na tabela hash\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1: {
                char cidadeBusca[100];
                int mesBusca;

                printf("Digite o nome da cidade: ");
                scanf(" %[^\n]", cidadeBusca);
                printf("Digite o número do mês (1 a 12): ");
                scanf("%d", &mesBusca);

                RegistroCriminalidade *resultado = buscarDadosCriminalidade(registros, numRegistros, cidadeBusca, mesBusca);
                if (resultado != NULL) {
                    printf("Registro encontrado:\n");
                    mostrarRegistro(resultado);
                } else {
                    printf("Registro não encontrado para a cidade %s no mês %d\n", cidadeBusca, mesBusca);
                }
                break;
            }
            case 2: {
                char cidadeBusca[100];

                printf("Digite o nome da cidade: ");
                scanf(" %[^\n]", cidadeBusca);

                buscarDadosPorCidade(&tabelaHash, cidadeBusca);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    // Liberar memória alocada
    for ( i = 0; i < numRegistros; i++) {
        free(registros[i].proximo);  // Liberar listas encadeadas da tabela hash
    }

    return EXIT_SUCCESS;
}

