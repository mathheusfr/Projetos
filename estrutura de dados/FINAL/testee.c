#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 12000  // Assumindo 1000 registros por m�s
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

// Fun��o de hash melhorada usando multiplica��o pela constante dourada (ouro)
int hash(const char *nome_cidade) {
    unsigned long hash = 5381;
    int c;

    while ((c = *nome_cidade++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % TAM_TABELA_HASH;
}

// Inserir registro na tabela hash
// Inserir registro na tabela hash
void inserirNaHash(HashTable *tabela, RegistroCriminalidade *registro) {
    int indice = hash(registro->nome_cidade);
    
    // Cria��o de um novo registro na tabela hash
    RegistroCriminalidade *novoRegistro = (RegistroCriminalidade *) malloc(sizeof(RegistroCriminalidade));
    if (novoRegistro == NULL) {
        perror("Erro ao alocar mem�ria para novo registro na tabela hash");
        exit(EXIT_FAILURE);
    }
    memcpy(novoRegistro, registro, sizeof(RegistroCriminalidade));
    novoRegistro->proximo = NULL;

    // Se a lista na posi��o �ndice estiver vazia
    if (tabela->lista[indice] == NULL) {
        tabela->lista[indice] = novoRegistro;
    } else {
        // Se a lista j� tiver elementos, insere no final
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
    return NULL;  // Registro n�o encontrado
}

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


// Fun��o de compara��o para qsort (ordena por nome da cidade)
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



// Fun��o para buscar um registro com bsearch
// Fun��o para buscar um registro com bsearch
RegistroCriminalidade *buscarRegistroComBSearch(RegistroCriminalidade **registros, int numRegistros, const char *nome_cidade, int *comparacoes) {
    RegistroCriminalidade chave;
    strcpy(chave.nome_cidade, nome_cidade);

    *comparacoes = 0;

    RegistroCriminalidade **resultado = (RegistroCriminalidade **)bsearch(&chave, registros, numRegistros, sizeof(RegistroCriminalidade *), comparaCidades);

    if (resultado != NULL) {
        return *resultado;
    } else {
        return NULL;
    }
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
                printf("  Cidade: %s\n", atual->nome_cidade);
                atual = atual->proximo;
            }
        }
    }
}

// Fun��o para buscar todos os registros na tabela hash
void buscarTodosComTabelaHash(HashTable *tabelaHash) {
    int totalComparacoes = 0;
    int comparacoesMax = 0;
    char cidadeMaisComparacoes[100];
    
    // Percorrer toda a tabela hash
    int i;
    for ( i = 0; i < TAM_TABELA_HASH; i++) {
        RegistroCriminalidade *atual = tabelaHash->lista[i];
        while (atual != NULL) {
            int comparacoes = 0;
            RegistroCriminalidade *encontrado = buscarNaHash(tabelaHash, atual->nome_cidade, &comparacoes);
            if (encontrado != NULL) {
                mostrarRegistro(encontrado);
                totalComparacoes += comparacoes;
                if (comparacoes > comparacoesMax) {
                    comparacoesMax = comparacoes;
                    strcpy(cidadeMaisComparacoes, encontrado->nome_cidade);
                }
            }
            atual = atual->proximo;
        }
    }

    printf("Total de compara��es: %d\n", totalComparacoes);
    printf("Busca com mais compara��es (%d): %s\n", comparacoesMax, cidadeMaisComparacoes);
}


void buscarTodosComBSearch(RegistroCriminalidade **registros, int numRegistros) {
    int totalComparacoes = 0;
    int comparacoesMax = 0;
    char cidadeMaisComparacoes[100];
    
    // Ordenar os registros por nome da cidade usando qsort (j� feito no main)
    
    // Percorrer todos os registros ordenados e buscar cada cidade
    int i;
    for (i = 0; i < numRegistros; i++) {
        int comparacoes = 0;
        RegistroCriminalidade chave;
        strcpy(chave.nome_cidade, registros[i]->nome_cidade);
        
        // Buscar o registro utilizando bsearch
        RegistroCriminalidade *registroEncontradoBSearch = buscarRegistroComBSearch(registros, numRegistros, registros[i]->nome_cidade, &comparacoes);
        
        // Exibir o registro apenas se n�o tiver sido exibido anteriormente
        if (registroEncontradoBSearch != NULL) {
            mostrarRegistro(registroEncontradoBSearch);
            totalComparacoes += comparacoes;
            
            // Verificar se � o m�ximo de compara��es at� agora
            if (comparacoes > comparacoesMax) {
                comparacoesMax = comparacoes;
                strcpy(cidadeMaisComparacoes, registros[i]->nome_cidade);
            }
        }
    }

    printf("Total de compara��es: %d\n", totalComparacoes);
    printf("Busca com mais compara��es (%d): %s\n", comparacoesMax, cidadeMaisComparacoes);
}


// Menu principal
void mostrarMenu(RegistroCriminalidade **registros, int numRegistros, HashTable *tabelaHash) {
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
        printf("6 - IMPRIMIR TABELA HASH (DEBUG)\n");
        
        scanf("%d", &op);
        
        switch (op) {
            case 0: 
                printf("Operacao finalizada\n");
                break;
                
           case 1: {
		        system("cls");  // Limpar tela no Windows, use "clear" no Linux
		        printf("Busca de todos os registros com bsearch (ordenado por nome da cidade)\n");
		
		        // Chamada da fun��o para buscar todos com bsearch
		        buscarTodosComBSearch(registros, numRegistros);
		        break;
    		}
            case 2: {
                system("cls");  // Limpar tela no Windows, use "clear" no Linux
                  buscarTodosComTabelaHash(tabelaHash);
                break;
            }
            case 3: {
                system("cls");  // Limpar tela no Windows, use "clear" no Linux
                printf("Digite o nome da cidade: ");
                scanf(" %[^\n]", nome_cidade);
                int comparacoes = 0;
                RegistroCriminalidade *registroEncontradoBSearch = buscarRegistroComBSearch(registros, numRegistros, nome_cidade, &comparacoes);
                if (registroEncontradoBSearch != NULL) {
                    mostrarRegistro(registroEncontradoBSearch);
                    printf("Comparacoes necessarias: %d\n", comparacoes);
                } else {
                    printf("Registro para cidade %s n�o encontrado.\n", nome_cidade);
                }
                break;
            }
            case 4: {
                system("cls");  // Limpar tela no Windows, use "clear" no Linux
                printf("Digite o nome da cidade: ");
                scanf(" %[^\n]", nome_cidade);
                int comparacoes = 0;
                RegistroCriminalidade *registroEncontradoHash = buscarNaHash(tabelaHash, nome_cidade, &comparacoes);
                if (registroEncontradoHash != NULL) {
                    mostrarRegistro(registroEncontradoHash);
                    printf("Comparacoes necessarias: %d\n", comparacoes);
                } else {
                    printf("Registro para cidade %s n�o encontrado.\n", nome_cidade);
                }
                break;
            }
            case 5: 
                system("cls");  // Limpar tela no Windows, use "clear" no Linux
                mostrarDadosMemoria(numRegistros, TAM_TABELA_HASH);
                break;
            case 6:
                system("cls");  // Limpar tela no Windows, use "clear" no Linux
                imprimirTabelaHash(tabelaHash);
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 0);
}

int main() {
    RegistroCriminalidade **registros = (RegistroCriminalidade **)malloc(MAX_REGISTROS * sizeof(RegistroCriminalidade *));
    if (registros == NULL) {
        printf("Erro ao alocar mem�ria\n");
        return 1;
    }
    int numRegistros = 0;
    char nomeArquivo[20];

    // Inicializar tabela hash
    HashTable tabelaHash;
    int i;
    for ( i = 0; i < TAM_TABELA_HASH; i++) {
        tabelaHash.lista[i] = NULL;
    }
   
    for ( i = 1; i <= NUM_MESES; i++) {
        snprintf(nomeArquivo, sizeof(nomeArquivo), "mes%02d.csv", i);
        printf("Processando arquivo: %s\n", nomeArquivo);
        if (!lerDadosCSV(nomeArquivo, &registros, &numRegistros, &tabelaHash)) {
            printf("Erro ao ler o arquivo %s\n", nomeArquivo);
        }
    }

    printf("Total de registros lidos: %d\n", numRegistros);

    // Ordenar os registros por nome da cidade usando qsort
    qsort(registros, numRegistros, sizeof(RegistroCriminalidade *), comparaCidades);

    // Mostrar menu
    mostrarMenu(registros, numRegistros, &tabelaHash);

    // Liberar mem�ria alocada

    for ( i = 0; i < numRegistros; i++) {
        free(registros[i]);
    }
    free(registros);

    for (  i = 0; i < TAM_TABELA_HASH; i++) {
        RegistroCriminalidade *atual = tabelaHash.lista[i];
        while (atual != NULL) {
            RegistroCriminalidade *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    return 0;
}

