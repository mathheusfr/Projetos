#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 12000  // Assumindo 1000 registros por m�s
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
    int mes; // Novo campo para armazenar o m�s
    struct RegistroCriminalidade *proximo;  
} RegistroCriminalidade;

typedef struct HashTable {
    RegistroCriminalidade *lista[TAM_TABELA_HASH];
} HashTable;

// Fun��o de hash melhorada usando multiplica��o pela constante dourada (ouro)
int hash(const char *nome_cidade) {
    unsigned long hash = 5381;
    int c;

    while ((c = *nome_cidade++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % TAM_TABELA_HASH;
}

// Fun��o de compara��o para qsort (ordena por nome da cidade)
int comparaCidades(const void *a, const void *b) {
    RegistroCriminalidade *registroA = *(RegistroCriminalidade **)a;
    RegistroCriminalidade *registroB = *(RegistroCriminalidade **)b;
    return strcmp(registroA->nome_cidade, registroB->nome_cidade);
}

// Fun��o para mostrar um registro
void mostrarRegistro(RegistroCriminalidade *registro) {
    printf("Cidade: %s\n", registro->nome_cidade);
    printf("Homicidio Doloso: %d\n", registro->homicidio_doloso);
    printf("Total de V�timas de Homicidio Doloso: %d\n", registro->total_vitimas_homicidio_doloso);
    printf("Latrocinio: %d\n", registro->latrocinio);
    printf("Furtos: %d\n", registro->furtos);
    printf("Abigeato: %d\n", registro->abigeato);
    printf("Furto de Ve�culo: %d\n", registro->furto_veiculo);
    printf("Roubos: %d\n", registro->roubos);
    printf("Roubo de Ve�culo: %d\n", registro->roubo_veiculo);
    printf("Estelionato: %d\n", registro->estelionato);
    printf("Delitos com Armas e Muni��es: %d\n", registro->delitos_armas_municoes);
    printf("Entorpecentes em Posse: %d\n", registro->entorpecentes_posse);
    printf("Entorpecentes em Tr�fico: %d\n", registro->entorpecentes_trafico);
    printf("V�timas de Latroc�nio: %d\n", registro->vitimas_latrocinio);
    printf("V�timas de Les�o Corporal com Morte: %d\n", registro->vitimas_lesao_corp_morte);
    printf("Total de V�timas de Crimes Violentos Letais Intencionais (CVLI): %d\n", registro->total_vitimas_cvli);
    printf("\n");
}

// Fun��o para mostrar dados da mem�ria
void mostrarDadosMemoria(int numRegistros, int tamanhoTabela) {
    printf("N�mero de registros carregados: %d\n", numRegistros);
    printf("Tamanho da tabela hash: %d\n", tamanhoTabela);
    printf("Mem�ria ocupada pelo array de registros: %u bytes\n", numRegistros * sizeof(RegistroCriminalidade *));
    printf("Mem�ria ocupada pela tabela hash: %u bytes\n", tamanhoTabela * sizeof(RegistroCriminalidade *));
}

// Fun��o para imprimir a tabela hash para depura��o
void imprimirTabelaHash(HashTable *tabela) {
	int i;
    for ( i = 0; i < TAM_TABELA_HASH; i++) {
        if (tabela->lista[i] != NULL) {
            printf("�ndice %d:\n", i);
            RegistroCriminalidade *atual = tabela->lista[i];
            while (atual != NULL) {
                printf("  Cidade: %s, M�s: %d\n", atual->nome_cidade, atual->mes);
                atual = atual->proximo;
            }
        }
    }
}

// Fun��o para buscar registro usando busca bin�ria por nome e m�s
RegistroCriminalidade *buscarRegistroComBSearchPorNomeEMes(RegistroCriminalidade **registros, int numRegistros, const char *nome_cidade, int mes) {
    // Ordenar o array de registros por nome da cidade e m�s
    qsort(registros, numRegistros, sizeof(RegistroCriminalidade *), comparaCidades);

    // Definir o registro de busca
    RegistroCriminalidade busca;
    strcpy(busca.nome_cidade, nome_cidade);
    busca.mes = mes;

    // Procurar o registro usando bsearch
    return bsearch(&busca, registros, numRegistros, sizeof(RegistroCriminalidade *), comparaRegistrosPorNomeEMes);
}

// Fun��o para comparar registros por nome da cidade e m�s para bsearch
int comparaRegistrosPorNomeEMes(const void *a, const void *b) {
    RegistroCriminalidade *registroA = *(RegistroCriminalidade **)a;
    RegistroCriminalidade *registroB = *(RegistroCriminalidade **)b;
    int cmp = strcmp(registroA->nome_cidade, registroB->nome_cidade);
    if (cmp == 0) {
        return registroA->mes - registroB->mes;
    }
    return cmp;
}

int main() {
    RegistroCriminalidade **registros = (RegistroCriminalidade **)malloc(MAX_REGISTROS * sizeof(RegistroCriminalidade *));
    if (registros == NULL) {
        perror("Erro ao alocar mem�ria para registros");
        return EXIT_FAILURE;
    }

    int numRegistros = 0;
    HashTable tabelaHash;
    for (int i = 0; i < TAM_TABELA_HASH; i++) {
        tabelaHash.lista[i] = NULL;
    }

    // Ler dados do arquivo CSV e preencher registros
    if (!lerDadosCSV("dados.csv", &registros, &numRegistros, &tabelaHash)) {
        fprintf(stderr, "Erro ao ler dados do arquivo CSV\n");
        return EXIT_FAILURE;
    }

    // Mostrar registros carregados
    for (int i = 0; i < numRegistros; i++) {
        mostrarRegistro(registros[i]);
    }

    // Mostrar dados de mem�ria
    mostrarDadosMemoria(numRegistros, TAM_TABELA_HASH);

    // Imprimir tabela hash para depura��o
    imprimirTabelaHash(&tabelaHash);

    // Buscar registro usando busca bin�ria por nome e m�s
    int comparacoes = 0;
    RegistroCriminalidade *resultado = buscarRegistroComBSearchPorNomeEMes(registros, numRegistros, "Porto Alegre", 5);
    if (resultado != NULL) {
        printf("Registro encontrado:\n");
        mostrarRegistro(resultado);
    } else {
        printf("Registro n�o encontrado.\n");
    }
    printf("N�mero de compara��es realizadas: %d\n", comparacoes);

    // Liberar mem�ria alocada
    for (int i = 0; i < numRegistros; i++) {
        free(registros[i]);
    }
    free(registros);

    return EXIT_SUCCESS;
}

