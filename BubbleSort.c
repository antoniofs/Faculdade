#include <stdio.h>
#include <stdlib.h>

void bubble(int *, int);

int main()
{
    int vetor[] = {3, 5, 8, 1, 9};
    int i = 0;

    int n = 4;

    bubble(vetor, n);

    for( ; i < n; i++)
    {

        printf("%d - ", vetor[i]);

    }


    return 0;
}


void bubble(int vetor[], int n)
{
    int k = n, i = 0, j = 0, aux;

        for( i = 0; i < n; i++)
        {
            for(j = 0; j < k; j++)
            {
                if(vetor[j] > vetor[j + 1])
                {
                    aux = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = aux;
                }

            }

            k--;
        }
}
