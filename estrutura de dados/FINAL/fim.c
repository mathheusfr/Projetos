#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 1000  // Número máximo de cidades na tabela hash
#define MAX_MESES 12       // Número máximo de meses

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
} DadosCriminais;

// Estrutura para a lista encadeada usada na tabela hash
typedef struct Node {
    DadosCriminais data;
    struct Node *next;
} Node;

// Tabela hash como um array de listas encadeadas
Node *tabelaHash[MAX_CIDADES];

// Função hash para calcular o índice na tabela hash
int hash(const char *cidade, int mes) {
    // Implementação básica de hash para demonstração
    int hash = 0;
    int length = strlen(cidade);
    int i;
    for ( i = 0; i < length; i++) {
        hash += cidade[i];
    }
    return (hash + mes) % MAX_CIDADES;
}

// Função para inserir dados na tabela hash
void inserirNaHash(const DadosCriminais *dados) {
    int indice = hash(dados->cidade, dados->mes);

    // Criar novo nó para armazenar os dados
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
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

int main() {
    // Inicializar a tabela hash
    int i;
    for ( i = 0; i < MAX_CIDADES; i++) {
        tabelaHash[i] = NULL;
    }

    // Leitura dos dados de vários arquivos e inserção na tabela hash
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
            DadosCriminais dados;
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
        }

        fclose(fp);
    }

    // Busca por cidade e mês usando tabela hash
    char cidadeBusca[100];
    int mesBusca;
    printf("Digite o nome da cidade: ");
    scanf("%s", cidadeBusca);
    printf("Digite o número do mês (1 a 12): ");
    scanf("%d", &mesBusca);

    int comparacoes;
    Node *resultado = buscarNaHash(cidadeBusca, mesBusca, &comparacoes);

    if (resultado != NULL) {
        printf("Dados encontrados para a cidade %s no mês %d:\n", cidadeBusca, mesBusca);
        printf("Homicídio Doloso: %d\n", resultado->data.homicidio_doloso);
        printf("Total de Vítimas de Homicídio Doloso: %d\n", resultado->data.total_vitimas_homicidio_doloso);
        printf("Latrocínio: %d\n", resultado->data.latrocinio);
        printf("Furtos: %d\n", resultado->data.furtos);
        printf("Abigeato: %d\n", resultado->data.abigeato);
        printf("Furto de Veículo: %d\n", resultado->data.furto_veiculo);
        printf("Roubos: %d\n", resultado->data.roubos);
        printf("Roubo de Veículo: %d\n", resultado->data.roubo_veiculo);
        printf("Estelionato: %d\n", resultado->data.estelionato);
        printf("Delitos com Armas e Munições: %d\n", resultado->data.delitos_armas_municoes);
        printf("Entorpecentes em Posse: %d\n", resultado->data.entorpecentes_posse);
        printf("Entorpecentes em Tráfico: %d\n", resultado->data.entorpecentes_trafico);
        printf("Vítimas de Latrocínio: %d\n", resultado->data.vitimas_latrocinio);
        printf("Vítimas de Lesão Corporal com Morte: %d\n", resultado->data.vitimas_lesao_corp_morte);
        printf("Total de Vítimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", resultado->data.total_vitimas_cvli);
        printf("Número de comparações necessárias: %d\n", comparacoes);
    } else {
        printf("Dados não encontrados para a cidade %s no mês %d\n", cidadeBusca, mesBusca);
    }

    return 0;
}

