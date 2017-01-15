#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <math.h>
 
short int verificarPrimo(short int);
void ce();
 
int main ()
{
    short int primo1, primo2, i = 0;
    int phi, n, e, d, s, m;
    char mensagem[500];
    bool boolprimo1 = true, boolprimo2 = true;
 
    printf("TRABALHO DE ANTONIO FLAVIO| SISTEMA DE INFORMAÇÃO | 201626192\n");
    printf("SI > CC");
 
    printf("\n\t\tAtencao os numeros primos devem ser\n");
    printf("\t\t\t\t<2,3,5,7>\n\n");
 
    printf("Coloque um numero primo.: ");
    scanf("%1hd", &primo1);
 
    printf("Coloque o segundo numero primo.: ");
    scanf("%1hd", &primo2);
 
    //Verificação para saber se o numero é primo
    boolprimo1 = verificarPrimo(primo1);
    boolprimo2 = verificarPrimo(primo2);
 
    if(primo1 == primo2 || boolprimo1 || boolprimo2)
    {
        system("color 40");
        printf("\nErro na entrada por favor tentar novamente\n");
        system("pause");
 
    }
 
    n = primo1 * primo2; //Descobrindo o N°
 
 
    m = (primo1-1) * (primo2 - 1);
 
    for(i = 0; i < m; i++)
    {
        if(fmod(m, i) == 1)
           e = i; break;
 
    }
 
    printf("%d\n", d);
    printf("\n\nEntre com a mensagem por favor\n");
    printf("Mensagem.:");
    scanf(" %[^\n]", mensagem);
 
 
    return 0;
}
 
short int verificarPrimo(short int numero)
{
    int i, vetorDePrimo[5] = {2, 3, 5, 7};
 
    for(i = 0; i < 5; i++)
    {
        if(numero == vetorDePrimo[i])
        {
            return 0;
        }
 
    }
    if (i >= 5)
    {
        return 1;
    }
}
