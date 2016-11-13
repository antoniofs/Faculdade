#include <stdio.h>
#include <stdlib.h>
#define al 2


typedef struct {

 char nome[60];
 int matricula;
 char turmas;
 float provas[3];

}alunos;

int passou(int, alunos[]);

int main ()
{

    int i = 0, x = 0; //Manipulação de Vetores
    alunos aluno[al];
    int somatorio = 0, vetor[al], t = 0, ultimo = 0;

    while (i < al)
    {
        printf("Nome do Aluno %i: ", i + 1);
        fflush(stdin);
        scanf("%60[^\n]", aluno[i].nome);

        printf("Numero do Matricula aluno %i: ", i + 1);
        scanf("%d", &aluno[i].matricula);

        fflush(stdin);
        printf("Turma do Aluno %i: ", i + 1);
        scanf("%c", &aluno[i].turmas);

        for(x = 0; x < 3; x++)
        {
        printf("Prova %i: ", x + 1);
        scanf("%f", &aluno[i].provas[x]);

        }
        i++;
        printf("\n");
    }

      x = 0;

    for(i = 0; i < al; i++)
    {
        while(x < 3)
        {
            somatorio += aluno[i].provas[x];
            x++;
        }
        x = 0;
        if ((somatorio / 3) >= 7)
        {
            vetor[t] = i;
            t++;
            ultimo += (somatorio / 3);
        }
        somatorio = 0;
    }

    for(i = 0; i < t; i++)
    {
        x = vetor[i];
        printf("Nome: %s\n", aluno[x].nome);
        printf("Matricula %d\n", aluno[x].matricula);
        printf("Turma: %c\n", aluno[x].turmas);
    }
    printf("A media da sala foi %d", ultimo / t);


    return 0;
}
