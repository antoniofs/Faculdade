#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    int cod_aluno;
    char nome[41];
    int estagio; //1: Iniciante - 2: Intermediario - 3: Avançado

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

//FUNÇÕES
void cadastrarAluno();
void listaAluno();
void insertionSort(aluno *a, int);
void insertionSortName(aluno *a, int vetor[]);
void alterarAluno();
void cadastrarAvalicoes();
void listarAvaliacoes();
void menu();
int compara_datas(tdata[], tdata[]);

void main ()
{
    menu();
}

//Função para implementar o menu; Entrada: numero de >= 0 e < 6.
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
            listaAluno();
            break;
        case 3:
            alterarAluno();
            break;
        case 4:
            //alterarAluno();
            break;
        case 5:
            //cadastrarAvalicoes();
            break;
        case 6:
            break;
        default:
            printf("Ops! Opção errada !");
        }

    }
    while(escolha != 0);
}

//Função para Cadastro de aluno, entrada: nome do aluno, estagio, Saída dados salvo em file binario.
void cadastrarAluno()
{
    char c;
    FILE * arq;
    aluno a;
    system("cls");
    do
    {

        if( (arq = fopen("Alunos.bin", "ab")) == NULL)
        {
            fprintf(stderr, "\nErro: não foi possivel criar o arquivo <Alunos.bin>\n");
            system("pause");
            return;
        }
        fseek(arq, 0, SEEK_END); //indo para o final do arquivo
        a.cod_aluno = ftell(arq) / sizeof(aluno) + 1;

        printf("\n\tNovo Aluno\n");
        printf("\nCodigo do aluno..: %d\n", a.cod_aluno);
        printf("Nome do Aluno: ");
        scanf(" %[^\n]", a.nome);
        printf("Estagio atual:\n <1> Iniciante\n <2> Intermediario\n"
               " <3> Avancado\n");
        scanf(" %d", &a.estagio);

        fwrite(&a, sizeof(aluno), 1, arq);
        fclose(arq);

        do
        {
            printf("Gostaria de add outro aluno: SIM <S> OR NO<N>: ");
            scanf(" %c", &c);
            c = toupper(c);
        }
        while( !(c == 'N' || c == 'S') );


    }
    while(c != 'N');
    system("cls");

}

void listaAluno()
{
    system("cls");
    int i, n;
    char opcao;

    FILE * arq;

    if( (arq = fopen("alunos.bin", "rb")) == NULL)
    {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        system("pause");
        return;
    }

    //TAMANHO DO VETOR
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(aluno);
    aluno a[n];
    rewind(arq);

    //LENDO O ARQUIVO
    fread(a, sizeof(aluno), n, arq);
    fclose(arq);

    insertionSort(a, n);


    for(i = 0; i < n; i++)
    {
        printf("\nMatricula: %d", a[i].cod_aluno);
        printf("\nNome: %s\n", a[i].nome);
        switch(a[i].estagio)
        {
        case 1:
            printf("Estagio: <1> Iniciante\n");
            break;
        case 2:
            printf("Estagio: <2> Intermediario\n");
            break;
        case 3:
            printf("Estagio: <3> Avancado\n");
            break;

        }
    }
    printf("\n");
    do
    {

        printf("Gostaria de salva este arquivo em txt ? SIM<s> ou NAO<n>: ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

    }
    while( !(opcao == 'S' || opcao == 'N') );



    if(opcao == 's' || opcao == 'S')
    {

        if( (arq = fopen("alunos.txt", "w")) == NULL)
        {
            fprintf(stderr, "\nErro de abertura do arquivo");
            return;
        }
        //ESCREVENDO NO ARQUIVO TXT
        for(i = 0; i < n; i++)
        {
            fprintf(arq, "\nNome: %s\n"
                    "Matricula: %d\n", a[i].nome, a[i].cod_aluno);

            switch(a[i].estagio)
            {
            case 1:
                fprintf(arq,"Estagio: <1> Iniciante\n");
                break;
            case 2:
                fprintf(arq,"Estagio: <2> Intermediario\n");
                break;
            case 3:
                fprintf(arq,"Estagio: <3> Avancado\n");
                break;

            }

        }
        fclose(arq);
    }

}

void insertionSort(aluno *v, int n)
{

    int i, j;
    aluno aux;

    for(j = 1; i < n; i++)
    {

        aux = v[i];
        for(j = i - 1; j >= 0 && strncasecmp)
    }



}