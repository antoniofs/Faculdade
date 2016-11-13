/*
* Aluno(s): Luiz Otávio Bissiato Pinheiro da Silva (SI) 201625449.
*
* Trabalho: Verificar se um CPF é válido ou Inválido.
*
* Disciplina: Matemática Discreta.
*
* Data: 08/10/2016 - Última edição: 11/10/2016.
*/
#include "stdio.h"
#include "stdlib.h"
#include <conio.h>

void main()
{
    int somatoria, i, a, num;
    char dig10, dig11, cpf[11];
    system("color FC");
    printf(" ->  Informe Seu CPF Com os algarismos Unidos\n\t\n\t");
    gets(cpf);

    somatoria = 0;
    for (i=0; i<9; i++)
    {
        num = cpf[i] - 48;	//ASCII
        somatoria = somatoria + (num * (10 - i));
    }
    a = 11 - (somatoria % 11);
    if ((a == 10) || (a == 11))
        dig10 = '0';
    else
        dig10 = a + 48;

    somatoria = 0;
    for (i=0; i<10; i++)
    {
        num = cpf[i] - 48;
        somatoria = somatoria + (num * (11 - i));
    }
    a = 11 - (somatoria % 11);
    if ((a == 10) || (a == 11))
        dig11 = '0';
    else
        dig11 = a + 48;
system("color FA");
    if ((dig10 == cpf[9]) && (dig11 == cpf[10]))

        printf("\n        CPF Valido !\n");
    else
        printf("\n        CPF Invalido !\n");
}



