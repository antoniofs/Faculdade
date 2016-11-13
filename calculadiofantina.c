#include <stdio.h>
#include <stdbool.h>

void mostraOpcoes(int c1, int c2, int mdc, int valor);
int calculaMDC(int v1, int v2);

int main()
{
    int a, b, aux, c, mdc;
    printf("Digite o valor de a, de b e de c\n");
    scanf("%d %d %d", &a, &b, &c);
    if (b > a) {
        aux = a;
        a = b;
        b = aux;
    }
    mdc = calculaMDC(a, b);

    mostraOpcoes(a, b, mdc, c);

    return 0;
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
            printf("x = %d  e  y = %d\n",x, y);
            temOp = true;
        }
        x_max -= sub;
    }
    if (temOp == false) {
        printf("\nImpossível sacar R$%d,00 utilizando as duas notas (R$%d,00 e R$%d,00).\n", aux, c1,c2);
    }
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
