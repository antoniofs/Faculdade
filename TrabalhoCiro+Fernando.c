#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_MAX 100 //QUANTIDADE DE ALUNOS

typedef struct
{
    int cod_aluno; // código do aluno
    char nome[41]; // nome do aluno
    int estagio; // estágio que o aluno está cursando: 1 (Iniciante), 2 (Intermediário) ou 3 (Avançado)
} aluno; // estrutura que representa um aluno

typedef struct
{
    int dia;
    int mes;
    int ano;
} tdata; // estrutura que representa uma data

typedef struct
{
    int cod_aluno; // código do aluno que fez a avaliação
    tdata data; // data da avaliação
    float nota; // nota da avaliação
} avaliacao; // estrutura que representa uma avaliação

void menu();
void cadastrarAlunos();

int main ()
{

    menu();

    return 0;
}

void menu()
{
    unsigned short int opcao;

    while(1)
    {
        system("color 40");
        printf(" <1> Cadastrar aluno\n"
               " <2> Listar Alunos\n"
               " <3> Alterar Dados de Aluno\n"
               " <4> Colsultar Aluno\n"
               " <5> Cadastrar Avaliações\n"
               " <6> Listar Avaliações\n"
               " <0> Sair.\n\n");

         printf("Opcao: ");
         scanf("%hu", &opcao);

         switch(opcao)
         {
         case 1:
             cadastrarAlunos();
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            break;
         case 0:
             printf("Voce saiu do sistema\n\n");

             system("pause");

             exit(1);

            break;
         }

    }

}

void cadastrarAlunos()
{
    aluno novo[TAM_MAX];
    int i;
    FILE *file;

    if ( (file = fopen("alunos.al", "ab")) == NULL)
    {
        fprintf(stderr, "\nErro: nao foi possivel criar o arquivo <ALUNOS.AL>");
        return;
    }

    fseek(file, 0, SEEK_END);
    novo[i].cod_aluno = ftell(file) / sizeof(aluno);

    //Cadastro de novo aluno
    printf("Aluno com matricula |%3d|",novo[i].cod_aluno);

    printf("Nome do aluno: ");
    scanf(" %[^\n]", novo[i].nome);

    printf("Estágio do aluno: ");
    scanf("%d", &novo[i].estagio);

}
