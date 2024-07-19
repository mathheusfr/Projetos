#include <stdio.h>

int busca_bin(int n, int* vet, int elem) {
   int ini = 0;
   int fim = n - 1;
   int meio;
   
   while (ini <= fim) {
       meio = (ini + fim) / 2;
       if (elem < vet[meio])
           fim = meio - 1;
       else if (elem > vet[meio])
           ini = meio + 1;
       else
           return meio;
   }
   return -1;
}

int soma_recursiva(int n) {
    if (n == 0)
        return 0;
    else
        return n + soma_recursiva(n - 1);
}


void mostrar_array(int* vet, int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int n = 10;
    int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    printf("Array: ");
    mostrar_array(vet, n);
    
    int elem = 5;
    int resultado_busca = busca_bin(n, vet, elem);
    if (resultado_busca != -1)
        printf("Elemento %d encontrado no índice %d\n", elem, resultado_busca);
    else
        printf("Elemento %d não encontrado\n", elem);
    
    int resultado_soma = soma_recursiva(2);
    printf("A soma de todos os números de 0 até %d é: %d\n", 2, resultado_soma);
    
    return 0;
}

