#include <stdio.h>
#include <stdlib.h>

void selecao(int Vet[], int n){

    int menor, aux ;

    int i, j;
    for(i = 0 ; i < n-1 ; i++)
    {
        menor = i ;

        for(j = i + 1 ; j < n ; j++)
        {
            if(Vet[menor] > Vet[j])
                menor = j ;
        }

        if(i != menor){
            aux = Vet[i];
            Vet[i] = Vet[menor];
            Vet[menor] = aux;
        }
    }

}

int main (){



    int Vetor[] = {3, 4, 6, 7, 5, 1, 2};

    selecao(Vetor, 6);

    int i;
    for(i = 0; i < 6; i++)
    {
        printf("%d - ", Vetor[i]);

    }




    return 0;
}
