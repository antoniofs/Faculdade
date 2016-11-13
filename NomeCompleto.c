#include <stdio.h>
#include <string.h>

int main()
{
    char nome[51];
    int i;
    printf("Informe seu nome completo: ");
    scanf(" %50[^\n]", nome);

    // desconsidera os espa�os em branco no final do nome
    for (i = strlen(nome) - 1; i >= 0 && nome[i] == ' '; i--);
    nome[i + 1] = '\0';
    // procura o ultimo espa�o em branco do nome
    for (; i >= 0 && nome[i] != ' '; i--);

    if (i == -1) {
        printf("Voce nao digitou o nome completo!\n");
    }
    else {
        // imprime o �ltimo sobrenome
        printf("%s, ", nome + (i + 1));

        // imprime o primeiro nome
        for (i = 0; nome[i] != ' '; i++) {
            printf("%c", nome[i]);
        }
        printf("\n");
    }
    return 0;
}
