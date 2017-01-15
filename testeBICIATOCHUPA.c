#include <stdio.h>

typedef struct
{
    char nome[100];
    char sexo;
    float peso;
    float altura;
    long long cpf;
}pessoa;

void teste(pessoa[], int);

int main ()
{
    pessoa a[100];
    int n = 100;
    teste(a, n);


}

void teste(pessoa t[], int n)
{
    static int i;

    for(i = 0; i < 1; i++)
    {
        scanf(" %s", t[i].nome);
        scanf(" %c", &t[i].sexo);
        scanf(" %f", &t[i].peso);
        scanf(" %f", &t[i].altura);
        scanf(" %ll", &t[i].cpf);

    }


}
