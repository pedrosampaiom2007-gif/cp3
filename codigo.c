#include <stdio.h>
#include <stdlib.h>
 
int opcao = 0;
 
void consultarSaldo(float saldo) {
    printf("\n---- SALDO ATUAL ----\n");
    printf("R$ %.2f\n", saldo);
    printf("---------------------\n");
    system("pause");
}
 
float realizarSaque(float saldo) {
    float valor;
    printf("Valor do saque: ");
    scanf("%f", &valor);
    while (getchar() != '\n');
 
    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        printf("Saque de R$ %.2f realizado!\n", valor);
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
    return saldo;
}
 
float realizarDeposito(float saldo) {
    float valor;
    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);
    while (getchar() != '\n');
 
    if (valor > 0) {
        saldo += valor;
        printf("Deposito de R$ %.2f realizado!\n", valor);
    } else {
        printf("Valor invalido!\n");
    }
    return saldo;
}
 
void exibirMenu() {
    printf("\n===================================\n");
    printf("       CAIXA ELETRONICO            \n");
    printf("===================================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("0 - Sair\n");
    printf("===================================\n");
    printf("Escolha uma Opcao: ");
    scanf("%d", &opcao);
    while (getchar() != '\n');
 
    if (opcao < 0 || opcao > 3) {
        printf("OPCAO INVALIDA!\n");
    }
}
 
int main() {
    float saldo = 1000.0f;
 
    do {
        system("cls");
        exibirMenu();
 
        switch (opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarSaque(saldo);
                break;
            case 3:
                saldo = realizarDeposito(saldo);
                break;
            case 0:
                printf("Saindo....\n");
                break;
            default:
                printf("Invalido\n");
        }
    } while (opcao != 0);
 
    printf("Obrigado por usar nosso ATM!\n");
    return 0;
}
