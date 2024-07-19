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



// Função de comparação para qsort e bsearch
int compararRegistros(const void *a, const void *b) {
    RegistroCriminalidade *regA = (RegistroCriminalidade *)a;
    RegistroCriminalidade *regB = (RegistroCriminalidade *)b;
    int cmpCidade = strcmp(regA->cidade, regB->cidade);
    if (cmpCidade == 0) {
        return regA->mes - regB->mes;
    }
    return cmpCidade;
}

RegistroCriminalidade *buscarRegistroComBSearch(RegistroCriminalidade *registros, int numRegistros, const char *cidade, int mes, int *comparacoes) {
    // Implementação da busca binária aqui
    // Supondo que registros esteja ordenado por cidade e mes
    int inicio = 0;
    int fim = numRegistros - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        *comparacoes += 1; // Incrementa o número de comparações
        int cmp = strcmp(registros[meio].cidade, cidade);
        if (cmp == 0 && registros[meio].mes == mes) {
            return &registros[meio];
        } else if (cmp < 0 || (cmp == 0 && registros[meio].mes < mes)) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return NULL; // Não encontrado
}

/////////////////////////////////////////
void buscarTodosComBSearch(RegistroCriminalidade *arrayRegistros, int numRegistros) {
    // Ordenar os registros
    qsort(arrayRegistros, numRegistros, sizeof(RegistroCriminalidade), compararRegistros);

    int maxComparacoes = 0;
    char cidadeMaxComparacoes[100] = "";
    int totalComparacoes = 0;

    // Loop por todas as cidades únicas nos registros
    int i;
    for ( i = 0; i < numRegistros; i++) {
        // Se a cidade atual é a mesma que a anterior, continue
        if (i > 0 && strcmp(arrayRegistros[i].cidade, arrayRegistros[i-1].cidade) == 0) {
            continue;
        }

        // Loop pelos meses de 1 a 12
        int mes;
        for ( mes = 1; mes <= MAX_MESES; mes++) {
        	
            int numComparacoes = 0;  // Reinicia o contador de comparações para cada busca

            RegistroCriminalidade chaveBusca;
            strcpy(chaveBusca.cidade, arrayRegistros[i].cidade);
            chaveBusca.mes = mes;

            // Busca binária
            int inicio = 0;
            int fim = numRegistros - 1;
            int meio;
            int encontrado = 0;

            while (inicio <= fim) {
                meio = (inicio + fim) / 2;
                numComparacoes++;  // Contar a comparação

                int cmpCidade = strcmp(arrayRegistros[meio].cidade, chaveBusca.cidade);
                int cmpMes = arrayRegistros[meio].mes - chaveBusca.mes;

                if (cmpCidade == 0 && cmpMes == 0) {
                    encontrado = 1;
                    break;
                } else if (cmpCidade < 0 || (cmpCidade == 0 && cmpMes < 0)) {
                    inicio = meio + 1;
                } else {
                    fim = meio - 1;
                }
            }

            // Mostrar ou processar o registro encontrado
            if (encontrado) {
                printf("Cidade: %s\n", arrayRegistros[meio].cidade);
                printf("Mês: %d\n", arrayRegistros[meio].mes);
                printf("Homicidio Doloso: %d\n", arrayRegistros[meio].homicidio_doloso);
                printf("Total de Vitimas de Homicidio Doloso: %d\n", arrayRegistros[meio].total_vitimas_homicidio_doloso);
                printf("Latrocinio: %d\n", arrayRegistros[meio].latrocinio);
                printf("Furtos: %d\n", arrayRegistros[meio].furtos);
                printf("Abigeato: %d\n", arrayRegistros[meio].abigeato);
                printf("Furto de Veiculo: %d\n", arrayRegistros[meio].furto_veiculo);
                printf("Roubos: %d\n", arrayRegistros[meio].roubos);
                printf("Roubo de Veiculo: %d\n", arrayRegistros[meio].roubo_veiculo);
                printf("Estelionato: %d\n", arrayRegistros[meio].estelionato);
                printf("Delitos com Armas e Municoes: %d\n", arrayRegistros[meio].delitos_armas_municoes);
                printf("Entorpecentes em Posse: %d\n", arrayRegistros[meio].entorpecentes_posse);
                printf("Entorpecentes em Trafico: %d\n", arrayRegistros[meio].entorpecentes_trafico);
                printf("Vitimas de Latrocinio: %d\n", arrayRegistros[meio].vitimas_latrocinio);
                printf("Vitimas de Lesao Corporal com Morte: %d\n", arrayRegistros[meio].vitimas_lesao_corp_morte);
                printf("Total de Vitimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", arrayRegistros[meio].total_vitimas_cvli);
                printf("\n");

                // Atualiza o máximo de comparações se necessário
                if (numComparacoes > maxComparacoes) {
                    maxComparacoes = numComparacoes;
                    strcpy(cidadeMaxComparacoes, arrayRegistros[meio].cidade);
                }
            } else {
                // Se não encontrou, mostrar valores zerados para este mês
                printf("Cidade: %s\n", chaveBusca.cidade);
                printf("Mês: %d\n", chaveBusca.mes);
                printf("Homicidio Doloso: 0\n");
                printf("Total de Vitimas de Homicidio Doloso: 0\n");
                printf("Latrocinio: 0\n");
                printf("Furtos: 0\n");
                printf("Abigeato: 0\n");
                printf("Furto de Veiculo: 0\n");
                printf("Roubos: 0\n");
                printf("Roubo de Veiculo: 0\n");
                printf("Estelionato: 0\n");
                printf("Delitos com Armas e Municoes: 0\n");
                printf("Entorpecentes em Posse: 0\n");
                printf("Entorpecentes em Trafico: 0\n");
                printf("Vitimas de Latrocinio: 0\n");
                printf("Vitimas de Lesao Corporal com Morte: 0\n");
                printf("Total de Vitimas de Crimes Violentos Letais Intencionais (CVLI): 0\n");
                printf("\n");
            }

            // Acumular o total de comparações
            totalComparacoes += numComparacoes;
        }
    }

    // Exibe as informações de total de comparações e busca com mais comparações
    printf("Total de comparações: %d\n", totalComparacoes);
    printf("Busca com mais comparações (%d): %s\n", maxComparacoes, cidadeMaxComparacoes);
}

//////////////////////////////////////

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

void buscarTodosComTabelaHash(int numRegistros) {
    int totalComparacoes = 0;
    int comparacoesMax = 0;
    char cidadeMaisComparacoes[100] = "";

    // Percorrer toda a tabela hash
    int i;
    for ( i = 0; i < MAX_CIDADES; i++) {
        Node *atual = tabelaHash[i];
        while (atual != NULL) {
            int comparacoes = 0;
            Node *temp = tabelaHash[i];

            // Contar comparações ao percorrer a lista encadeada
            while (temp != NULL) {
                comparacoes++;
                if (strcmp(temp->data.cidade, atual->data.cidade) == 0 && temp->data.mes == atual->data.mes) {
                    break;
                }
                temp = temp->next;
            }

            if (temp != NULL) {
                // Mostrar os dados do registro encontrado
                printf("Cidade: %s\n", atual->data.cidade);
                printf("Mês: %d\n", atual->data.mes);
                printf("Homicidio Doloso: %d\n", atual->data.homicidio_doloso);
                printf("Total de Vitimas de Homicidio Doloso: %d\n", atual->data.total_vitimas_homicidio_doloso);
                printf("Latrocinio: %d\n", atual->data.latrocinio);
                printf("Furtos: %d\n", atual->data.furtos);
                printf("Abigeato: %d\n", atual->data.abigeato);
                printf("Furto de Veiculo: %d\n", atual->data.furto_veiculo);
                printf("Roubos: %d\n", atual->data.roubos);
                printf("Roubo de Veiculo: %d\n", atual->data.roubo_veiculo);
                printf("Estelionato: %d\n", atual->data.estelionato);
                printf("Delitos com Armas e Municoes: %d\n", atual->data.delitos_armas_municoes);
                printf("Entorpecentes em Posse: %d\n", atual->data.entorpecentes_posse);
                printf("Entorpecentes em Trafico: %d\n", atual->data.entorpecentes_trafico);
                printf("Vitimas de Latrocinio: %d\n", atual->data.vitimas_latrocinio);
                printf("Vitimas de Lesao Corporal com Morte: %d\n", atual->data.vitimas_lesao_corp_morte);
                printf("Total de Vitimas de Crimes Violentos Letais Intencionais (CVLI): %d\n", atual->data.total_vitimas_cvli);
                printf("\n");

                totalComparacoes += comparacoes;

                // Atualizar a cidade com mais comparações, se necessário
                if (comparacoes > comparacoesMax) {
                    comparacoesMax = comparacoes;
                    strcpy(cidadeMaisComparacoes, atual->data.cidade);
                }
            }

            atual = atual->next;
        }
    }

    // Exibir informações finais de comparações
    printf("Total de comparações: %d\n", totalComparacoes);
    if (comparacoesMax > 0) {
        printf("Busca com mais comparações (%d): %s\n", comparacoesMax, cidadeMaisComparacoes);
    } else {
        printf("Nenhuma busca realizada.\n");
    }
}

void mostrarDadosMemoria(int numRegistros, int tamanhoTabela) {
    printf("Número de registros carregados: %d\n", numRegistros);
    printf("Tamanho da tabela hash: %d\n", tamanhoTabela);
    printf("Memória ocupada pelo array de registros: %lu bytes\n", numRegistros * sizeof(RegistroCriminalidade));
    printf("Memória ocupada pela tabela hash: %lu bytes\n", tamanhoTabela * sizeof(Node *));
}


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
                buscarTodosComBSearch(arrayRegistros, numRegistros); // Corrigir a chamada
                break;

            case 2:
                buscarTodosComTabelaHash(numRegistros);
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
    					mostrarDadosMemoria(numRegistros, MAX_CIDADES);
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
    FILE *fp;
    char nomeArquivo[20];
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
