#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
           // alterarAluno();
            break;
        case 4:
            //alterarAluno();
            break;
        case 5:
            //cadastrarAvalicoes();
            break;
        case 6:
            break;
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

    do
    {

        if( (arq = fopen("Alunos.bin", "ab")) == NULL)
        {
            fprintf(stderr, "\nErro: não foi possivel criar o arquivo <Alunos.bin>\n");
            system("pause");
            return;
        }

        rewind(arq);
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

    if ((arq = fopen("Alunos.bin", "rb")) == NULL)
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

    //FUNÇÃO PARA ORDENAÇÃO DE ESTÁGIO
    insertionSort(a, n);

    printf("\n\t Alunos Cadastrados\n\n");

    for(i = 0; i < n; i++)
    {
        printf("Matricula: %d\n", a[i].cod_aluno);
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

        if( (arq = fopen("alunos.txt", "a")) == NULL)
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

//Função para ordenar os estagios
void insertionSort(aluno *v, int n)
{
    int i, j, t, one = 0, two = 0, tres = 0;
    aluno aux;
    int um[50] = {0}, dois[50] = {0}, trees[50] = {0};
    for(i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) &&(aux.estagio < v[j-1].estagio); j--)
        {
            v[j] = v[j - 1];

        }

        v[j] = aux;

    }

    for(t = 0; t < n; t++)
    {

     if (v[t].estagio == 1)
     {
         um[one] = v[t].cod_aluno;
         one++;
     }
      else if(v[t].estagio == 2)
      {
          dois[two] = v[t].cod_aluno;
          two++;
      }
      else if(v[t].estagio == 3)
      {
          trees[tres] = v[t].cod_aluno;
          tres++;
      }

    }

    for(i = 1; i < one; i++)
    {
        aux = v[i];
        for(j = i; (j>0) && (strcasecmp(aux.nome, v[j-1].nome) < 0); j--)
        {
            v[j] = v[j - 1];

        }

        v[j] = aux;

    }


    for(i = one + 1; i < (two * 2); i++)
    {
        aux = v[i];
        for(j = i; (v[i].estagio == 2) && (j>one ) && (strcasecmp(aux.nome, v[j-1].nome) < 0); j--)
        {
            v[j] = v[j - 1];

        }

        v[j] = aux;

    }

    for(i = (two * 2) + 1; i <= n ; i++)
    {
        aux = v[i];
        for(j = i; (v[i].estagio == 3) && (j >= ( two * 2)) && (strcasecmp(aux.nome, v[j-1].nome) < 0); j--)
        {
            v[j] = v[j - 1];

        }

        v[j] = aux;

    }

}
/*
//Função guiada por deus, ops para ordernar nomes
void insertionSortName(aluno *v, int vetor[])
{
    int i, j, k = 1;
    aluno aux;
    do
    {
        for(i = 0; i < vetor[k]; i++)
        {
            aux = v[i];
            for(j = i; (j >= 0) && (strcmp(aux.nome, v[j-1].nome) < 0); j--)
            {
                if(j > 0)
                {
                  v[j] = v[j - 1];
                }

            }
            if (j > 0)
            {
                v[j] = aux;
            }

        }
        k++;
    }
    while(k < 3);


}
*/
void alterarAluno()
{
    system("cls");
    int n, i, op;
    FILE * arq;
    bool teste;

    if ( (arq = fopen("Alunos.bin", "r+b") ) == NULL)
    {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        return;
    }

    //TAMANHO DO VETOR
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(aluno);
    aluno a[n];
    rewind(arq);

    fread(a, sizeof(aluno), n, arq);
    fclose(arq);

    printf("Informe a Matricula do aluno: ");
    scanf("%d", &op);

    for(i = 0; i <= n; i++)
    {
        if(a[i].cod_aluno == op)
        {
            printf("Nome: %s\n", a[i].nome);

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

            printf("\t\n\nAtualização de Informacao\n\n");
            printf("Novo nome:");
            scanf(" %[^\n]", a[i].nome);
            printf("Estagio novo:\n <1> Iniciante\n <2> Intermediario\n"
                                    "<3> Avancado\n");
            scanf(" %d", &a[i].estagio);

            fseek(arq, 0, SEEK_SET);
            fwrite(a, sizeof(aluno), 1, arq);
            fclose(arq);
            teste = false;
            break;

        }
        else
        {
            teste = true;
        }

    }
    if(teste)
    {
        printf("\tAluno não encontrado\n\n");
    }
    system("Pause");
}
/*
void cadastrarAvalicoes()
{
    register int t = 1;
    system("cls");
    int n, i, op;
    FILE * arq, * file;
    bool teste;

    if ( (file = fopen("avaliacoes.bin", "ab") ) == NULL)
    {
        fprintf(stderr, "\nNao foi possivel criar o arquivo avalicoes.bin!\n");
        return;
    }

    if ( (arq = fopen("alunos.bin", "rb") ) == NULL)
    {
        fprintf(stderr, "\nNao ha' nenhuma avaliação cadastrada!\n");
        return;
    }

    //TAMANHO DO VETOR
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(aluno) + 1;
    aluno a[n];
    avaliacao b;
    rewind(arq);

    fread(a, sizeof(aluno), n, arq);
    fclose(arq);

    printf("Informe a Matricula do aluno: ");
    scanf("%d", &op);

    for(i = 0; i <= n; i++)
    {
        if(a[i].cod_aluno == op)
        {
            printf("Nome: %s\n", a[i].nome);

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

            printf("Favor digite a data atual: (EX. 12/12/2012): ");
            scanf("%d/%d/%d", &b.data.dia, &b.data.mes, &b.data.ano);

            printf("Nota da sua avaliação: (EX. 10.0): ");
            scanf("%f", &b.nota);

            b.cod_aluno = a[i].cod_aluno;

            teste = false;


        fwrite(&b, sizeof(avaliacao), 1, file);
        fclose(file);

        break;
        }
        else
        {
            teste = true;
        }

    }
    if(teste)
    {
        printf("\tAluno não encontrado\n\n");
    }
    system("Pause");


}

void listarAvaliacoes()
{
    FILE *av;
    tdata c[2];

    if( (av = fopen("avaliacoes.bin", "rb")) == NULL)
    {
        printf("Não foi cadastrados avaliações");
    }

    //avaliacao c[2];

    printf("Informe uma data inicial: (EX. 12/12/2012): ");
    scanf("%d/%d/%d", c[0].dia, c[0].mes, c[0].ano);

    printf("Informe uma data final: (EX. 12/12/2012): ");
    scanf("%d/%d/%d", c[1].dia, c[1].mes, c[1].ano);

    compara_datas(c[], c[]);



}

int compara_datas(tdata ano[], tdata anox[])
{
    if(ano[1].ano < anox[0].ano)
    {
        return -1;
    }
    else if(ano[1].ano == anox[0].ano && ano[1].mes == anox[0].mes == && ano[1].dia == anox[0].dia)
    {
        return 0;
    }
    else if(ano[1] > anox[0].ano)
    {
        return 1;
    }
    else
    {
        return -1;
    }


}
*/
