#include <stdio.h>

#define TAMANHO 10

static void imprimir_precos(const char *titulo, const float precos[TAMANHO])
{
    int i;

    printf("%s", titulo);
    for (i = 0; i < TAMANHO; i++) {
        printf(" R$ %.2f", precos[i]);
    }
    printf("\n");
}

static void ordenar(float precos[TAMANHO], int crescente)
{
    int i;
    int j;

    for (i = 0; i < TAMANHO - 1; i++) {
        for (j = 0; j < TAMANHO - 1 - i; j++) {
            if ((crescente && precos[j] > precos[j + 1]) ||
                (!crescente && precos[j] < precos[j + 1])) {
                float temporario = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = temporario;
            }
        }
    }
}

int main(void)
{
    float precos[TAMANHO] = {
        12.50f, 4.20f, 19.90f, 8.75f, 15.30f,
        6.40f, 22.10f, 3.99f, 11.25f, 18.60f
    };
    float ordenados[TAMANHO];
    int i;

    imprimir_precos("Precos originais:", precos);

    for (i = 0; i < TAMANHO; i++) {
        ordenados[i] = precos[i];
    }
    ordenar(ordenados, 1);
    imprimir_precos("Precos em ordem crescente:", ordenados);

    for (i = 0; i < TAMANHO; i++) {
        ordenados[i] = precos[i];
    }
    ordenar(ordenados, 0);
    imprimir_precos("Precos em ordem decrescente:", ordenados);

    return 0;
}