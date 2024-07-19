#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 1000  // N�mero m�ximo de cidades
#define MAX_MESES 12       // N�mero m�ximo de meses

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

// Fun��o de compara��o para bsearch
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

// Fun��o para buscar dados de criminalidade por cidade e m�s
void buscarDadosPorCidadeEMes(RegistroCriminalidade dados[], int numDados) {
    char cidadeBusca[100];
    int mesBusca;

    printf("Digite o nome da cidade: ");
    scanf("%s", cidadeBusca);
    printf("Digite o n�mero do m�s (1 a 12): ");
    scanf("%d", &mesBusca);

    RegistroCriminalidade chaveBusca;
    strcpy(chaveBusca.nome_cidade, cidadeBusca);
    chaveBusca.mes = mesBusca;

    // Ordenar os dados para uso do bsearch
    qsort(dados, numDados, sizeof(RegistroCriminalidade), comparaCidades);

    // Busca por cidade e m�s usando bsearch
    RegistroCriminalidade *resultado = bsearch(&chaveBusca, dados, numDados, sizeof(RegistroCriminalidade), comparaCidades);

    if (resultado != NULL) {
        printf("\nDados encontrados para a cidade %s no m�s %d:\n", cidadeBusca, mesBusca);
        printf("Homic�dio Doloso: %d\n", resultado->homicidio_doloso);
        printf("Total de V�timas de Homic�dio Doloso: %d\n", resultado->total_vitimas_homicidio_doloso);
        printf("Latroc�nio: %d\n", resultado->latrocinio);
        printf("Furtos: %d\n", resultado->furtos);
        printf("Abigeato: %d\n", resultado->abigeato);
        printf("Furto de Ve�culo: %d\n", resultado->furto_veiculo);
        printf("Roubos: %d\n", resultado->roubos);
        printf("Roubo de Ve�culo: %d\n", resultado->roubo_veiculo);
        printf("Estelionato: %d\n", resultado->estelionato);
        printf("Delitos com Armas e Muni��es: %d\n", resultado->delitos_armas_municoes);
        printf("Entorpecentes em Posse: %d\n", resultado->entorpecentes_posse);
        printf("Entorpecentes em Tr�fico: %d\n", resultado->entorpecentes_trafico);
        printf("V�timas de Latroc�nio: %d\n", resultado->vitimas_latrocinio);
        printf("V�timas de Les�o Corporal com Morte: %d\n", resultado->vitimas_lesao_corp_morte);
        printf("Total de V�timas de Crimes Violentos Letais Intencionais (CVLI): %d\n", resultado->total_vitimas_cvli);
    } else {
        printf("\nDados n�o encontrados para a cidade %s no m�s %d\n", cidadeBusca, mesBusca);
    }
}

// Menu principal
void mostrarMenu(RegistroCriminalidade dados[], int numDados) {
    int op;
    char nome_cidade[100];

    do {
        printf("\n\n*** Digite a opcao que deseja ***\n");
        printf("0 - SAIR\n");
        printf("1 - BUSCAR TUDO COM BSEARCH\n");
        printf("2 - BUSCAR TUDO COM TABELA HASH\n");
        printf("3 - PROCURAR UM COM BSEARCH\n");
        printf("4 - PROCURAR UM COM TABELA HASH\n");
        printf("5 - DADOS DA MEM�RIA\n");
        
        scanf("%d", &op);
        
        switch (op) {
            case 0: 
                printf("Opera��o finalizada.\n");
                break;
                
            case 1: {
                system("cls");  // limpador de tela
                printf("Busca de todos os registros com bsearch (ordenado por nome da cidade)\n");
                // Implemente aqui a busca de todos os registros com bsearch
                // Utilize qsort para ordenar se necess�rio
                break;
            }
                
            case 2: {
                system("cls");  // limpador de tela
                printf("Busca de todos os registros com tabela hash\n");
                // Implemente aqui a busca de todos os registros com tabela hash
                break;
            }
                
            case 3: {
                system("cls");  
                printf("Busca por cidade e m�s com bsearch\n");
                buscarDadosPorCidadeEMes(dados, numDados);
                break;
            }
                
            case 4: {
                system("cls");  
                printf("Busca por cidade e m�s com tabela hash\n");
                // Implemente aqui a busca por cidade e m�s com tabela hash
                break;
            }
                
            case 5: {
                system("cls");  
                printf("Dados da mem�ria\n");
                // Implemente aqui a fun��o para mostrar dados da mem�ria
                break;
            }
                
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (op != 0);
}

// Fun��o principal
int main() {
    RegistroCriminalidade dados[MAX_CIDADES * MAX_MESES];
    int numDados = 0;
    char nomeArquivo[20];
    FILE *fp;

    // Leitura dos dados de v�rios arquivos
    int mes;
    for (mes = 1; mes <= MAX_MESES; mes++) {
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

    // Exemplo de utiliza��o do menu principal
    mostrarMenu(dados, numDados);

    return 0;
}

