#include <stdio.h>
#include <stdlib.h>

void menu();
void codificar();


int main ()
{
     menu();
    return 0;
}

void menu()
{
    int op;
    do
    {
        printf("\n\t\tCRIPTOGRAFIA RSA\t\n");

        printf("<1> Codificar uma mensagem\n"
               "<2> Descodificar a mensagem\n"
               "<0> Sair do programa\n");

        scanf("%d", &op);

        switch(op)
        {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        }

    }while(op == 0);
}
