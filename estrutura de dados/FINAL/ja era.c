#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 1000  // Número máximo de cidades
#define MAX_MESES 12       // Número máximo de meses

typedef struct {
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
} RegistroCriminalidade;

// Função de comparação para bsearch
int comparaCidades(const void *a, const void *b) {
    RegistroCriminalidade *cidadeA = (RegistroCriminalidade *)a;
    RegistroCriminalidade *cidadeB = (RegistroCriminalidade *)b;

    int cmp = strcmp(cidadeA->nome_cidade, cidadeB->nome_cidade);
    if (cmp == 0) {
        return cidadeA->mes - cidadeB->mes;
    } else {
        return cmp;
    }
}

// Função para buscar dados de criminalidade por cidade e mês
RegistroCriminalidade *buscarDadosCriminalidade(RegistroCriminalidade dados[], int numDados, const char *cidadeBusca, int mesBusca) {
    RegistroCriminalidade chaveBusca;
    strcpy(chaveBusca.nome_cidade, cidadeBusca);
    chaveBusca.mes = mesBusca;

    // Ordenando os dados para uso do bsearch
    qsort(dados, numDados, sizeof(RegistroCriminalidade), comparaCidades);

    // Busca por cidade e mês usando bsearch
    RegistroCriminalidade *resultado = bsearch(&chaveBusca, dados, numDados, sizeof(RegistroCriminalidade), comparaCidades);

    return resultado;
}

// Função principal (exemplo de uso)
int main() {
    RegistroCriminalidade dados[MAX_CIDADES * MAX_MESES];
    int numDados = 0;
    char nomeArquivo[20];
    FILE *fp;

    // Leitura dos dados de vários arquivos
    int mes;
    for ( mes = 1; mes <= MAX_MESES; mes++) {
        snprintf(nomeArquivo, sizeof(nomeArquivo), "mes%02d.csv", mes);
        fp = fopen(nomeArquivo, "r");
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
            continue;
        }

        char linha[256];
        while (fgets(linha, sizeof(linha), fp)) {
            sscanf(linha, "%[^;];%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d",
                   dados[numDados].nome_cidade,
                   &dados[numDados].homicidio_doloso,
                   &dados[numDados].total_vitimas_homicidio_doloso,
                   &dados[numDados].latrocinio,
                   &dados[numDados].furtos,
                   &dados[numDados].abigeato,
                   &dados[numDados].furto_veiculo,
                   &dados[numDados].roubos,
                   &dados[numDados].roubo_veiculo,
                   &dados[numDados].estelionato,
                   &dados[numDados].delitos_armas_municoes,
                   &dados[numDados].entorpecentes_posse,
                   &dados[numDados].entorpecentes_trafico,
                   &dados[numDados].vitimas_latrocinio,
                   &dados[numDados].vitimas_lesao_corp_morte,
                   &dados[numDados].total_vitimas_cvli);
            dados[numDados].mes = mes;
            numDados++;
        }

        fclose(fp);
    }

    // Exemplo de utilização da função buscarDadosCriminalidade
    char cidadeBusca[100];
    int mesBusca;
    printf("Digite o nome da cidade: ");
    scanf("%s", cidadeBusca);
    printf("Digite o número do mês (1 a 12): ");
    scanf("%d", &mesBusca);

    RegistroCriminalidade *resultado = buscarDadosCriminalidade(dados, numDados, cidadeBusca, mesBusca);

    if (resultado != NULL) {
        printf("Dados encontrados para a cidade %s no mês %d:\n", cidadeBusca, mesBusca);
        printf("Homicídio Doloso: %d\n", resultado->homicidio_doloso);
        printf("Total de Vítimas de Homicídio Doloso: %d\n", resultado->total_vitimas_homicidio_doloso);
        printf("Latrocínio: %d\n", resultado->latrocinio);
        printf("Furtos: %d\n", resultado->furtos);
        printf("Abigeato: %d\n", resultado->abigeato);
        printf("Furto de Veículo: %d\n", resultado->furto_veiculo);
        printf("Roubos: %d\n", resultado->roubos);
        printf("Roubo de Veículo: %d\n", resultado->roubo_veiculo);
        printf("Estelionato: %d\n", resultado->estelionato);
        printf("Delitos com Armas e Munições: %d\n", resultado->delitos_armas_municoes);
        printf("Entorpecentes em Posse: %d\n", resultado->entorpecentes_posse);
        printf("Entorpecentes em Tráfico: %d\n", resultado->entorpecentes_trafico);
        printf("Vítimas de Latrocínio: %d\n", resultado->vitimas_latrocinio);
        printf("Vítimas de Lesão Corporal com Morte: %d\n", resultado->vitimas_lesao_corp_morte);
        printf("Total de Vítimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", resultado->total_vitimas_cvli);
    } else {
        printf("Dados não encontrados para a cidade %s no mês %d\n", cidadeBusca, mesBusca);
    }

    return 0;
}

