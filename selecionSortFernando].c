#include <stdio.h>
#include <stdlib.h>

// Esta função rearranja o vetor v[0..n-1]
// em ordem crescente.
void selecao (int n, int v[])
{
    int i, j, min, x;
    for (i = 0; i < n; ++i)
    {
        min = i;
        for (j = i+1; j < n; ++j)
            if (v[j] < v[min])  min = j;
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main ()
{
    int i;
    int copas[] = {2,6,7,1,8,9,14,11,10,3,4,12,5,13};
    int paus[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};
    int espadas[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};
    int ouro[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};

    selecao(14, copas);
    printf("%c: ", 003);
    for(i = 0; i < 11; i++)
    {
        switch(i)
        {
        case 0:
            printf("A - ");
            i++;
            break;
        case 10:
            printf("J - Q - K - ");
            break;

        }
        if(i != 10)
        {
            printf("%d - ", copas[i]);
        }

    }

    return 0;
}
