#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 1000  // Número máximo de cidades na tabela hash
#define MAX_MESES 12      // Número máximo de meses

typedef struct {
    char cidade[100];
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
} RegistroCriminalidade;

// Estrutura para a lista encadeada usada na tabela hash
typedef struct Node {
    RegistroCriminalidade data;
    struct Node *next;
} Node;

// Tabela hash como um array de listas encadeadas
Node *tabelaHash[MAX_CIDADES];

// Função hash para calcular o índice na tabela hash
int hash(const char *cidade, int mes) {
    int hash = 0;
    int length = strlen(cidade);
    int i;
    for ( i = 0; i < length; i++) {
        hash += cidade[i];
    }
    return (hash + mes) % MAX_CIDADES;
}

// Função para inserir dados na tabela hash
void inserirNaHash(const RegistroCriminalidade *dados) {
    int indice = hash(dados->cidade, dados->mes);

    // Criar novo nó para armazenar os dados
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novo->data = *dados;
    novo->next = NULL;

    // Inserir no início da lista encadeada correspondente ao índice
    if (tabelaHash[indice] == NULL) {
        tabelaHash[indice] = novo;
    } else {
        novo->next = tabelaHash[indice];
        tabelaHash[indice] = novo;
    }
}

// Função para buscar dados na tabela hash
Node *buscarNaHash(const char *cidade, int mes, int *comparacoes) {
    int indice = hash(cidade, mes);
    Node *temp = tabelaHash[indice];
    *comparacoes = 0;

    while (temp != NULL) {
        (*comparacoes)++;
        if (strcmp(temp->data.cidade, cidade) == 0 && temp->data.mes == mes) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;  // Dados não encontrados
}

// Função para mostrar os dados da memória
void mostrarDadosMemoria() {
	int i;
    for ( i = 0; i < MAX_CIDADES; i++) {
        Node *temp = tabelaHash[i];
        while (temp != NULL) {
            printf("Cidade: %s, Mês: %d\n", temp->data.cidade, temp->data.mes);
            temp = temp->next;
        }
    }
}

// Função de comparação para qsort
int compararRegistros(const void *a, const void *b) {
    RegistroCriminalidade *registroA = (RegistroCriminalidade *)a;
    RegistroCriminalidade *registroB = (RegistroCriminalidade *)b;
    int cmpCidade = strcmp(registroA->cidade, registroB->cidade);
    if (cmpCidade == 0) {
        return registroA->mes - registroB->mes;
    }
    return cmpCidade;
}

// Função do menu principal
void mostrarMenu(RegistroCriminalidade *arrayRegistros, int numRegistros) {
    int op;
    char cidade[100];
    int mes;
	int i;
    do {
        printf("\n\n*** Digite a opcao que deseja ***\n");
        printf("0 - SAIR\n");
        printf("1 - BUSCAR TUDO COM BSEARCH\n");
        printf("2 - BUSCAR TUDO COM TABELA HASH\n");
        printf("3 - PROCURAR UM COM BSEARCH\n");
        printf("4 - PROCURAR UM COM TABELA HASH\n");
        printf("5 - DADOS DA MEMÓRIA\n");

        scanf("%d", &op);

        switch (op) {
            case 0:
                break;

            case 1:
                // Implementar busca de todos os registros com bsearch
               
                for ( i = 0; i < numRegistros; i++) {
                    printf("Cidade: %s, Mês: %d\n", arrayRegistros[i].cidade, arrayRegistros[i].mes);
                }
                break;

            case 2:
                // Implementar busca de todos os registros com tabela hash
                mostrarDadosMemoria();
                break;

            case 3:
                printf("Digite o nome da cidade: ");
                scanf("%s", cidade);
                printf("Digite o número do mês (1 a 12): ");
                scanf("%d", &mes);

                RegistroCriminalidade chave;
                strcpy(chave.cidade, cidade);
                chave.mes = mes;

                RegistroCriminalidade *resultadoBSearch = bsearch(&chave, arrayRegistros, numRegistros, sizeof(RegistroCriminalidade), compararRegistros);

                if (resultadoBSearch != NULL) {
                    printf("\nDados encontrados para a cidade %s no mês %d:\n", cidade, mes);
                    printf("Homicídio Doloso: %d\n", resultadoBSearch->homicidio_doloso);
                    printf("Total de Vítimas de Homicídio Doloso: %d\n", resultadoBSearch->total_vitimas_homicidio_doloso);
                    printf("Latrocínio: %d\n", resultadoBSearch->latrocinio);
                    printf("Furtos: %d\n", resultadoBSearch->furtos);
                    printf("Abigeato: %d\n", resultadoBSearch->abigeato);
                    printf("Furto de Veículo: %d\n", resultadoBSearch->furto_veiculo);
                    printf("Roubos: %d\n", resultadoBSearch->roubos);
                    printf("Roubo de Veículo: %d\n", resultadoBSearch->roubo_veiculo);
                    printf("Estelionato: %d\n", resultadoBSearch->estelionato);
                    printf("Delitos com Armas e Munições: %d\n", resultadoBSearch->delitos_armas_municoes);
                    printf("Entorpecentes em Posse: %d\n", resultadoBSearch->entorpecentes_posse);
                    printf("Entorpecentes em Tráfico: %d\n", resultadoBSearch->entorpecentes_trafico);
                    printf("Vítimas de Latrocínio: %d\n", resultadoBSearch->vitimas_latrocinio);
                    printf("Vítimas de Lesão Corporal com Morte: %d\n", resultadoBSearch->vitimas_lesao_corp_morte);
                    printf("Total de Vítimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", resultadoBSearch->total_vitimas_cvli);
                } else {
                    printf("\nDados não encontrados para a cidade %s no mês %d\n", cidade, mes);
                }
                break;

            case 4:
                printf("Digite o nome da cidade: ");
                scanf("%s", cidade);
                printf("Digite o número do mês (1 a 12): ");
                scanf("%d", &mes);

                int comparacoesHash;
                Node *resultadoHash = buscarNaHash(cidade, mes, &comparacoesHash);

                if (resultadoHash != NULL) {
                    printf("\nDados encontrados para a cidade %s no mês %d:\n", cidade, mes);
                    printf("Homicídio Doloso: %d\n", resultadoHash->data.homicidio_doloso);
                    printf("Total de Vítimas de Homicídio Doloso: %d\n", resultadoHash->data.total_vitimas_homicidio_doloso);
                    printf("Latrocínio: %d\n", resultadoHash->data.latrocinio);
                    printf("Furtos: %d\n", resultadoHash->data.furtos);
                    printf("Abigeato: %d\n", resultadoHash->data.abigeato);
                    printf("Furto de Veículo: %d\n", resultadoHash->data.furto_veiculo);
                    printf("Roubos: %d\n", resultadoHash->data.roubos);
                    printf("Roubo de Veículo: %d\n", resultadoHash->data.roubo_veiculo);
                    printf("Estelionato: %d\n", resultadoHash->data.estelionato);
                    printf("Delitos com Armas e Munições: %d\n", resultadoHash->data.delitos_armas_municoes);
                    printf("Entorpecentes em Posse: %d\n", resultadoHash->data.entorpecentes_posse);
                    printf("Entorpecentes em Tráfico: %d\n", resultadoHash->data.entorpecentes_trafico);
                    printf("Vítimas de Latrocínio: %d\n", resultadoHash->data.vitimas_latrocinio);
                    printf("Vítimas de Lesão Corporal com Morte: %d\n", resultadoHash->data.vitimas_lesao_corp_morte);
                    printf("Total de Vítimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", resultadoHash->data.total_vitimas_cvli);
                    printf("Número de comparações necessárias: %d\n", comparacoesHash);
                } else {
                    printf("\nDados não encontrados para a cidade %s no mês %d\n", cidade, mes);
                }
                break;

            case 5:
                printf("\nDados da Memória:\n");
                mostrarDadosMemoria();
                break;

            default:
                printf("\nOpção inválida.\n");
        }
    } while (op != 0);
}

int main() {
    // Inicializar a tabela hash
    int i;
    for ( i = 0; i < MAX_CIDADES; i++) {
        tabelaHash[i] = NULL;
    }

    // Alocar dinamicamente o array de registros
    RegistroCriminalidade *arrayRegistros = NULL;
    int numRegistros = 0;
    int capacidadeRegistros = 100;

    arrayRegistros = (RegistroCriminalidade *)malloc(capacidadeRegistros * sizeof(RegistroCriminalidade));
    if (arrayRegistros == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o array de registros.\n");
        exit(1);
    }

    // Leitura dos dados de vários arquivos e inserção na tabela hash e no array
    char nomeArquivo[20];
    FILE *fp;
	int mes;
    for ( mes = 1; mes <= MAX_MESES; mes++) {
        snprintf(nomeArquivo, sizeof(nomeArquivo), "mes%02d.csv", mes);
        fp = fopen(nomeArquivo, "r");
        if (fp == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo %s\n", nomeArquivo);
            continue;
        }

        char linha[256];
        while (fgets(linha, sizeof(linha), fp)) {
            if (numRegistros >= capacidadeRegistros) {
                capacidadeRegistros *= 2;
                arrayRegistros = (RegistroCriminalidade *)realloc(arrayRegistros, capacidadeRegistros * sizeof(RegistroCriminalidade));
                if (arrayRegistros == NULL) {
                    fprintf(stderr, "Erro ao realocar memória para o array de registros.\n");
                    exit(1);
                }
            }

            RegistroCriminalidade dados;
            sscanf(linha, "%[^;];%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d",
                   dados.cidade,
                   &dados.homicidio_doloso,
                   &dados.total_vitimas_homicidio_doloso,
                   &dados.latrocinio,
                   &dados.furtos,
                   &dados.abigeato,
                   &dados.furto_veiculo,
                   &dados.roubos,
                   &dados.roubo_veiculo,
                   &dados.estelionato,
                   &dados.delitos_armas_municoes,
                   &dados.entorpecentes_posse,
                   &dados.entorpecentes_trafico,
                   &dados.vitimas_latrocinio,
                   &dados.vitimas_lesao_corp_morte,
                   &dados.total_vitimas_cvli);
            dados.mes = mes;

            inserirNaHash(&dados);
            arrayRegistros[numRegistros++] = dados;
        }

        fclose(fp);
    }

    // Ordenar o array utilizando qsort
    qsort(arrayRegistros, numRegistros, sizeof(RegistroCriminalidade), compararRegistros);

    // Exemplo de utilização do menu principal
    mostrarMenu(arrayRegistros, numRegistros);

    // Liberar a memória alocada para o array de registros
    free(arrayRegistros);

    return 0;
}

