#include <stdio.h>
#include <stdlib.h>

#define DIAS 30

int main(void)
{
    float temperaturas[DIAS];
    float soma = 0.0f;
    float menor = 0.0f;
    float maior = 0.0f;

    printf("========================================\n");
    printf("   CONTROLE DE TEMPERATURA MENSAL\n");
    printf("========================================\n");
    printf("Informe a temperatura media de cada dia (C).\n\n");

    // Lê e processa as temperaturas diárias.
    for (int i = 0; i < DIAS; i++) {
        printf("Temperatura do dia %02d: ", i + 1);
        if (scanf("%f", &temperaturas[i]) != 1) {
            fprintf(stderr, "Entrada invalida. Informe um valor numerico.\n");
            return EXIT_FAILURE;
        }

        soma += temperaturas[i];
        if (i == 0 || temperaturas[i] < menor) {
            menor = temperaturas[i];
        }
        if (i == 0 || temperaturas[i] > maior) {
            maior = temperaturas[i];
        }
    }

    printf("\n============= RESUMO DO MES =============\n");
    printf("%-8s | %s\n", "Dia", "Temperatura (C)");
    printf("------------------------------------------\n");
    // Apresenta os dados armazenados no vetor.
    for (int i = 0; i < DIAS; i++) {
        printf("Dia %02d   | %8.2f\n", i + 1, temperaturas[i]);
    }

    printf("------------------------------------------\n");
    printf("Media mensal: %.2f C\n", soma / DIAS);
    printf("Maior temperatura: %.2f C\n", maior);
    printf("Menor temperatura: %.2f C\n", menor);
    printf("==========================================\n");

    return EXIT_SUCCESS;
}