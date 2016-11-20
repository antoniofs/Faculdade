/** @uthor: Antonio Flávio Silva Nascimento | N° Matricula 201626192 | Sistema de Informação
 ** @Materia: Introdução a Computação | Algoritmo
 ** @Date: 20/11/2016
 ** PROGRAMA PARA GERENCIAMENTO DE ALUNOS E CADASTRO DE AVALIAÇÕES.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define NOMEARQUIVO "alunos.bin"
#define TEXTO "alunos.txt"
#define AVALIACOES "avaliacoes.bin"


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

//PROTOTIPO FUNÇÕES
void cadastrarAluno();
void listaAluno();
void insertionSort(aluno *a, int);
void alterarAluno();
void consultarAluno();
void cadastrarAvalicoes();
void menu();
FILE * fileOpen(char nome[],char modo[]);

//Não feitas
int compara_datas(tdata[], tdata[]);
void listarAvaliacoes();

void main ()
{
    menu();
}

//Função para implementar o menu
void menu()
{
    system("color 40");

    short int escolha;

    do
    {
        printf("\nGERENCIAMENTOS DE ALUNOS\n\n"
               "<1>: Cadastrar Aluno\n"
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
            consultarAluno();
            break;
        case 5:
            cadastrarAvalicoes();
            break;
        case 6:
            break;
        default:
            printf("Ops! Opção errada !\n");
            system("pause");
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

    //LAÇO PARA CADASTRO DE NOVOS ALUNOS
    do
    {

        FILE *arq = fileOpen(NOMEARQUIVO,"ab");

        fseek(arq, 0, SEEK_END); //indo para o final do arquivo
        a.cod_aluno = ftell(arq) / sizeof(aluno) + 1;

        printf("\n\tNovo Aluno\n");
        printf("\nCodigo do aluno..: %d\n", a.cod_aluno);

        printf("Nome do Aluno: ");
        scanf(" %[^\n]", a.nome);

        printf("Estagio atual:\n <1> Iniciante\n"
               "<2> Intermediario\n"
               "<3> Avancado\n");
        scanf(" %d", &a.estagio);

        fseek(arq, 0, SEEK_END);
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

    FILE *arq = fileOpen(NOMEARQUIVO,"rb");

    //TAMANHO DO VETOR
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(aluno);
    aluno a[n];
    rewind(arq);

    //LENDO O ARQUIVO
    fread(a, sizeof(aluno), n, arq);
    fclose(arq);

    //FUNÇÃO PARA ORDENAÇÃO DE ESTÁGIO E NOMES
    insertionSort(a, n);

    printf("\n\n\tAlunos Cadastrados\n");
    printf("----------------------------------------------------------\n");
    printf("#Matricula| Nome do aluno               |  Estagio\n");
    printf("----------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%9d |", a[i].cod_aluno);
        printf(" %-30s|", a[i].nome);
        switch(a[i].estagio)
        {
        case 1:
            printf("<1> Iniciante\n");
            printf("-------------------------------------------------------\n");
            break;
        case 2:
            printf("<2> Intermediario\n");
            printf("-------------------------------------------------------\n");
            break;
        case 3:
            printf("<3> Avancado\n");
            printf("-------------------------------------------------------\n");
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

        FILE *arq = fileOpen(TEXTO,"w");

        //ESCREVENDO NO ARQUIVO TXT
        fprintf(arq, "\n\n\tAlunos Cadastrados\n");
        fprintf(arq, "----------------------------------------------------------\n");
        fprintf(arq, "#Matricula| Nome do aluno               |  Estagio\n");
        fprintf(arq, "----------------------------------------------------------\n");

        for(i = 0; i < n; i++)
        {


            fprintf(arq, "%9d |"
                    " %-30s|", a[i].cod_aluno, a[i].nome);

            switch(a[i].estagio)
            {
            case 1:
                fprintf(arq,"<1> Iniciante\n");
                fprintf(arq, "-------------------------------------------------------\n");
                break;
            case 2:
                fprintf(arq,"<2> Intermediario\n");
                fprintf(arq, "-------------------------------------------------------\n");
                break;
            case 3:
                fprintf(arq,"<3> Avancado\n");
                fprintf(arq, "-------------------------------------------------------\n");
                break;

            }

        }
        printf("\nArquivo Salvo com sucesso!\n");
        system("Pause");
    }

    fclose(arq);




}

//Função para ordenar os estagios e nomes
void insertionSort(aluno *v, int n)
{
    int i, j;
    aluno aux;

    for(i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) && (strncasecmp(aux.nome, v[j - 1].nome, 1) < 0); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }

    for(i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) && (aux.estagio < v[j - 1].estagio); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }
}

void alterarAluno()
{
    system("cls");
    int n, i, op;
    bool teste;

    FILE *arq = fileOpen(NOMEARQUIVO,"r+b");

    //Tanto de Alunos
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(aluno);
    aluno a;
    rewind(arq);

    printf("Informe a Matricula do aluno: ");
    scanf("%d", &op);

    fseek(arq, (op - 1) * sizeof(aluno), SEEK_SET);
    fread(&a, sizeof(aluno), 1, arq);
    if (a.cod_aluno != op && op > n)
    {
        fprintf(stderr, "\nErro: nao ha' nenhuma aluno com esse numero\n");
        fclose(arq);
        return;
    }

    printf("Nome: %s\n", a.nome);
    switch(a.estagio)
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

    printf("\t\n\nAtualizacao de Informacao\n\n");
    printf("Novo nome:");
    scanf(" %[^\n]", a.nome);
    printf("Estagio novo:\n <1> Iniciante\n <2> Intermediario\n"
           "<3> Avancado\n");
    scanf(" %d", &a.estagio);

    fseek(arq, -sizeof(aluno), SEEK_CUR);
    fwrite(&a, sizeof(aluno), 1, arq);
    fclose(arq);
}

void consultarAluno()
{
    system("cls");
    int n, i, op;

    bool teste = true;

    FILE *arq = fileOpen(NOMEARQUIVO,"rb");

    FILE *file = fileOpen(AVALIACOES,"rb");

    aluno a;

    fseek(file, 0, SEEK_END);
    n = ftell(file) / sizeof(avaliacao);
    rewind(file);

    avaliacao b[n];




    printf("Informe a Matricula do aluno: ");
    scanf("%d", &op);
    fseek(arq, (op - 1) * sizeof(aluno), SEEK_SET);
    fread(&a, sizeof(aluno), 1, arq);
    if(a.cod_aluno == op)
    {
        printf("Nome: %s\n", a.nome);

        switch(a.estagio)
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

        fread(b, sizeof(avaliacao), n, file);
        printf("\n--------------------------------------------------------------------\n");
        for(i = 0; i < n; i++)
        {
            if(b[i].cod_aluno == op)
            {
                printf("Avaliacao %d", i + 1);
                printf("\nNota: %.2f\n", b[i].nota);
                printf("\nData: %d/%d/%d\n", b[i].data.dia, b[i].data.mes, b[i].data.ano);
                printf("\n--------------------------------------------------------------------\n");
            }
        }

    }
    else
    {
        printf("Não exite esse aluno cadastrado");
    }

    fclose(file);
    fclose(arq);
}

void cadastrarAvalicoes()
{
    register int t = 1;
    system("cls");
    int n, i, op;
    bool teste;

    FILE *file = fileOpen(AVALIACOES,"ab");

    FILE *arq = fileOpen(NOMEARQUIVO,"rb");

    avaliacao b;
    aluno a;

    printf("Informe a Matricula do aluno: ");
    scanf("%d", &op);

    fseek(arq, (op - 1) * sizeof(aluno), SEEK_SET);
    fread(&a, sizeof(aluno), 1, arq);
    if(a.cod_aluno == op)
    {


    printf("Nome: %s\n", a.nome);
    switch(a.estagio)
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
    printf("Favor digite a data atual: (EX. 12/12/2012): ");
    scanf("%d/%d/%d", &b.data.dia, &b.data.mes, &b.data.ano);

    printf("Nota da sua avaliação: (EX. 10.0): ");
    scanf("%f", &b.nota);

    b.cod_aluno = a.cod_aluno;
    printf("%d", b.cod_aluno);


    fwrite(&b, sizeof(avaliacao), 1, file);
    fclose(file);
    }
    else
    {
        printf("Não existe esse aluno cadastrado");
    }
}

FILE* fileOpen(char nome[],char modo[])
{
    FILE *fp;
    if((fp = fopen(nome,modo)) == NULL)
    {
        printf("Erro no arquivo <%s>",nome);
        exit(1);
    }
    return fp;
}
/*
void listarAvaliacoes()
{
    tdata b, c;
    int n;

    printf("Favor informe a data inicial: ");
    scanf("%d/%d/%d", b.dia, b.mes, b.ano);

    printf("Favor informe a data final: ");
    scanf("%d/%d/%d", c.dia, c.mes, c.ano);

    n = compara_datas(b, c);

    if(n >= 0 )
    {

    }

}
int compara_datas(tdata dt1, tdata dt2)
{
    if(dt1 > dt2)
    {
        return 1;
    }
    else if (dt1 < dt2)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}
*/
