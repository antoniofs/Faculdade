#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int cod_aluno;
    char nome[41];
    int estagio;
    //1: Iniciante - 2: Intermediario - 3: Avançado
} aluno;

typedef struct
{
    int dia;
    int mes;
    int ano;

} tdata;

typedef struct
{
    int cod_aluno;
    tdata data;
    float nota;

} avaliacao;

void cadastrarAluno();
void listaAluno();
void alterarAluno();
void cadastrarAvalicoes();
void listarAvaliacoes();
void menu();

void main ()
{
    menu();
}

void menu()
{

    short int escolha;

    do
    {
    printf("<1>: Cadastrar Aluno\n"
           "<2>: Lista Alunos\n"
           "<3>: Alterar um aluno\n"
           "<4>: Consultar um aluno\n"
           "<5>: Cadastrar avaliações\n"
           "<6>: Lista avaliações\n"
           "<0>: Sair\n");
    printf("\nDeseja fazer..:");
    scanf("%hd", &escolha);

    switch(escolha)
    {
    case 1:
        cadastrarAluno();
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
    }

    }while(escolha != 0);
}

void cadastrarAluno()
{
    char c;
    FILE * arq;
    aluno a;

    if( (arq = fopen("Alunos.bin", "ab")) == NULL) {
        fprintf(stderr, "\nErro: não foi possivel criar o arquivo <Alunos.bin>\n");
        return;
    }
    do
    {
        //Fazendo o codigo do aluno
        fseek(arq, 0, SEEK_END); //indo para o final do arquivo
        a.cod_aluno = ftell(arq) / sizeof(aluno) +1;
        printf("\n\n\tNovo Aluno\n\n");
        printf("\nCodigo do aluno..: %d\n", a.cod_aluno);
        printf("Nome do Aluno: ");
        scanf(" %[^\n]", a.nome);
        printf("Estagio atual:\n <1> Iniciante\n <2> Intermediario\n"
                                " <3> Avancado\n");
        scanf(" %d", &a.estagio);

        fwrite(&a, sizeof(aluno), 1, arq);
        fclose(arq);
        printf("Gostaria de add outro aluno: SIM <S> OR NO<N>");
        scanf(" %c", &c);

    }while(c != 'N' && c != 'n');

}
