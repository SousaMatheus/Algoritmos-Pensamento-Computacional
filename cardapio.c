#include <stdio.h>

#define MAX_QUANTIDADE 20

static int lerInteiro(const char *mensagem, int *valor) {
    int resultado;
    int caractere;
    int entradaValida = 1;

    printf("%s", mensagem);
    resultado = scanf("%d", valor);

    if (resultado == EOF) {
        return -1;
    }

    if (resultado != 1) {
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
        return 0;
    }

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
        if (caractere != ' ' && caractere != '\t' && caractere != '\r') {
            entradaValida = 0;
        }
    }

    return entradaValida;
}

static void exibirCardapio(void) {
    printf("\n--- Cardapio ---\n");
    printf("1. Prato feito - R$ 25.00\n");
    printf("2. Suco - R$ 8.00\n");
    printf("3. Sobremesa - R$ 12.00\n");
}

int main(void) {
    int opcao = -1;
    int item;
    int quantidade;
    int ultimoItem = 0;
    int ultimaQuantidade = 0;
    double ultimoTotal = 0.0;
    double preco;
    double subtotal;

    printf("Cardapio Digital\n");
    printf("Consulte os pratos e escolha seu pedido.\n");
    printf("Bem-vindo(a)!\n");

    do {
        printf("\n=== Cardapio Digital ===\n");
        printf("1. Ver cardapio\n");
        printf("2. Fazer pedido\n");
        printf("3. Consultar pedido\n");
        printf("0. Sair\n");

        int leitura = lerInteiro("Escolha uma opcao: ", &opcao);
        if (leitura < 0) {
            printf("\nEntrada encerrada.\n");
            break;
        }
        if (leitura == 0) {
            printf("Entrada invalida. Digite um numero do menu.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                exibirCardapio();
                break;
            case 2:
                exibirCardapio();
                if (lerInteiro("Escolha o item (1 a 3): ", &item) != 1 ||
                    item < 1 || item > 3) {
                    printf("Item invalido. Pedido nao registrado.\n");
                    break;
                }
                if (lerInteiro("Quantidade (1 a 20): ", &quantidade) != 1 ||
                    quantidade < 1 || quantidade > MAX_QUANTIDADE) {
                    printf("Quantidade invalida. Use um valor de 1 a 20.\n");
                    break;
                }

                switch (item) {
                    case 1:
                        preco = 25.0;
                        break;
                    case 2:
                        preco = 8.0;
                        break;
                    default:
                        preco = 12.0;
                        break;
                }

                ultimoItem = item;
                ultimaQuantidade = quantidade;
                subtotal = preco * quantidade;
                if (subtotal >= 50.0) {
                    ultimoTotal = subtotal * 0.90;
                    printf("Promocao: desconto de 10%% aplicado.\n");
                } else {
                    ultimoTotal = subtotal;
                }
                printf("Pedido registrado: %d unidade(s), total R$ %.2f.\n",
                       quantidade, ultimoTotal);
                break;
            case 3:
                if (ultimoItem == 0) {
                    printf("Ainda nao ha pedido registrado.\n");
                } else {
                    printf("Ultimo pedido: item %d, %d unidade(s), total R$ %.2f.\n",
                           ultimoItem, ultimaQuantidade, ultimoTotal);
                }
                break;
            case 0:
                printf("Encerrando o Cardapio Digital. Obrigado e ate logo!\n");
                break;
            default:
                printf("Opcao invalida. Escolha 1, 2, 3 ou 0 para sair.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

