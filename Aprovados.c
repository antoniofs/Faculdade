#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char nome[60];
    int matricula;
    char turma;
    float provas[3];
} aluno;

void aprovados(int, aluno []);

int main()
{
    int n, i, j;
    printf("Informe o numero de alunos da turma: ");
    scanf("%d", &n);
    aluno a[n];
    printf("\nInforme os dados dos %d alunos\n", n);
    for (i = 0; i < n; i++) {
        printf("\n%do. aluno\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        printf("Nome.....: ");
        scanf(" %59[^\n]", a[i].nome);
        printf("Turma....: ");
        scanf(" %c", &a[i].turma);
        for (j = 0; j < 3; j++) {
            printf("Nota da %da. prova: ", j + 1);
            scanf("%f", &a[i].provas[j]);
        }
    }
    aprovados(n, a);
    return 0;
}

void aprovados(int n, aluno a[])
{
    int i, j;
    float media;
    bool tem_aprovado = false;
    printf("\n\n\tAlunos Aprovados\n");
    printf("--------------------------------------------------------\n");
    printf("Matricula| Nome                          | Turma | Media\n");
    printf("--------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        media = 0;
        for (j = 0; j < 3; j++) {
            media += a[i].provas[j];
        }
        media /= 3;
        if (media >= 7) {
            tem_aprovado = true;
            printf("%09d| %-30s|   %c   | %5.2f\n", a[i].matricula, a[i].nome, a[i].turma, media);
        }
    }
    if (!tem_aprovado) {
        puts("Nenhum aluno foi aprovado");
    }
    printf("--------------------------------------------------------\n");
}