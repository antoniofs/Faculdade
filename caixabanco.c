#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int calculaMDC(int, int);
void ordenaCedulas(int *, int *);
void mostraOpcoes(int, int, int, int);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int valor_de_saque, qtd_cedulas, cedula1, cedula2, mdc;
    do {
    printf("Digite quanto deseja sacar: R$");
    scanf("%d", &valor_de_saque);
    }while(valor_de_saque < 2);

    printf("\nDigite com quantas cédulas diferentes deseja sacar essa quantia (1 ou 2): ");
    scanf("%d", &qtd_cedulas);
    while (qtd_cedulas != 1 && qtd_cedulas != 2) {
        printf("\nQuantidade de cédulas inválida.\nDigite 1 ou 2.\n");
        scanf("%d", &qtd_cedulas);
    }

    if (qtd_cedulas == 1) {
        cedula2 = 0;
        printf("\nDigite qual cédula (2.00, 5.00, 10.00, 20.00, 50.00 ou 100.00): ");
        scanf("%d", &cedula1);
        while(cedula1 != 2 && cedula1 != 5 && cedula1 != 10 && cedula1 != 20 && cedula1 != 50 && cedula1 != 100) {
            printf("\nValor inválido.\nDigite novamente o valor da cédula (2.00, 5.00, 10.00, 20.00, 50.00 ou 100.00): ");
            scanf("%d", &cedula1);
        }
        if ((valor_de_saque % cedula1) != 0) {
            printf("\nImpossível sacar R$%d,00 apenas com notas de R$%d,00.\n", valor_de_saque, cedula1);
            return 1;
        }
        printf("\nOpção de saque: %d notas de R$%d,00.\n", valor_de_saque/cedula1, cedula1);
    }else {
        printf("\nDigite quais cédulas (2.00, 5.00, 10.00, 20.00, 50.00 ou 100.00): ");
        scanf("%d %d", &cedula1, &cedula2);
        while (cedula1 == cedula2) {
            printf("Digite um valor diferente para segunda cédula: ");
            scanf("%d", &cedula2);
        }

        mdc = calculaMDC(cedula1, cedula2);

        if ((valor_de_saque % mdc) != 0) {
            printf("\nImpossível sacar R$%d,00 apenas com notas de R$%d,00 e R$%d,00.\n", valor_de_saque, cedula1, cedula2);
            return 1;
        }
        if (cedula1 < cedula2) {
            ordenaCedulas(&cedula1,&cedula2);
        }

        mostraOpcoes(cedula1, cedula2, mdc, valor_de_saque);

    }
    return 0;
}

int calculaMDC(int v1, int v2)
{
    int maior, menor, resto;
    if (v1 > v2) {
        maior = v1;
        menor = v2;
    }else {
        maior = v2;
        menor = v1;
    }
    resto = maior % menor;
    while (resto != 0) {
        maior = menor;
        menor = resto;
        resto = maior % menor;
    }
    return menor;
}

void ordenaCedulas(int *v1, int *v2)
{
    int aux;
    aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

void mostraOpcoes(int c1, int c2, int mdc, int valor)
{
    int sub, soma, x_max, y_max, i, aux, j, x, y;
    bool temOp = false;
    aux = valor;
    if (mdc != 1) {
        sub = c2 / mdc;
        soma = c1 / mdc;
    }else {
        sub = c2;
        soma = c1;
    }

    x_max = valor / c1;
    if (c1 * x_max == valor) {
        x_max -= sub;
    }
    y_max = valor / c2;
    printf("\n");
    for (i = 0; i < 3; i++) {
        valor = aux;
        x = 0;
        y = 0;
        for (j = x_max; j > 0; j--) {
            x = j;
            if ((valor - c1*j) % c2 == 0 && (valor - c1*j) != 0) {
                break;
            }
        }
        valor -= c1 * x;
        y = valor / c2;
        if (c1 * x + c2 * y == aux && (x != 0 && y != 0)) {
            printf("%dª opção: %d notas de R$%d,00 e %d notas de R$%d,00.\n", i+1, x, c1, y, c2);
            temOp = true;
        }
        x_max -= sub;
    }
    if (temOp == false) {
        printf("\nImpossível sacar R$%d,00 utilizando as duas notas (R$%d,00 e R$%d,00).\n", aux, c1,c2);
    }
}
