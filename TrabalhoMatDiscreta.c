/** @uthor: Antonio Flávio
 ** @Curso: Sistema de Informação
 ** @Materia: Matematica Discreta
 ** @Version 1.0 Beta Antonio life
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Faça um programa para receber um cpf e verificar se os digitos são validos ou não.]
 * Entrada: CPF do usuario.
 * Sainda: Verificação dos digitos.
*/


// D1 = Digito 1 - D2 = Digito 2; p = potencia; vetor = CPF;
int main ( )
{
    long long int CPF = 0, mult = 0;

    int  D1 = 0, D2 = 0, i = 0, p = 9, digito1 = 0, digito2 = 0, vetor[11] = { 0 };

    printf("\n digite o CPF: " ) ;
    scanf("%lld" , &CPF );

    vetor[0] = CPF /10000000000; //Primeiro numero do cpf

    for (i = 1; i < 9; i++)
    {
        mult = (int)pow(10,p) + 1;
        if (i >= 4)
        {
            mult = mult - 1;
        }
        if (i == 6 || i == 8)
        {
            mult = mult + 1;
        }
        vetor[i] = (CPF / mult) % 10;
        p--;
    }
    digito1 = ( CPF % 100 ) / 10;
    digito2 = CPF % 10;

    for (i = 0; i <= 8; i++)
    {
        D1 += vetor[i] * (i + 1);
    }
    D1 %= 11;
    vetor[9] = D1;

    for (i = 1; i <= 8; i++)
    {
        D2 += vetor[i] * i;
    }
    printf("%d", D2);
    D2 %= 11;
    //vetor[10] = D2;
/*
    if (D1 == digito1 && D2 == digito2)
    {
        system("cls");
        system("color 4F");
        printf("\t\tSeu CPF: %lld\n\t\tEsta correto!!!", CPF);
    }
    else
    {
        printf("DIGITOS: %d%d\n", digito1, digito2);
        printf("DIGITOS DO CPF INVALIDOS!!! TENTAR NOVAMENTE!!!");

    }
*/
    system("pause");
}
