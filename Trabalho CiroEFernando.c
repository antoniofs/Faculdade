/** @uthor: Antonio Flávio Silva Nascimento | N° Matricula 201626192 | Sistema de Informação]
 ** @uthor: Luiz Otávio Bissiato | N° 201626192 | Sistema de Informação
 ** @uthor: Wanderley da Silva e Silva Junior | N° 201626181 | Sistema de Informação
 ** @Materia: Introdução a Computação | Algoritmo
 ** @Date: 20/11/2016
 ** PROGRAMA PARA GERENCIAMENTO DE ALUNOS E CADASTRO DE AVALIAÇÕES.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define NOMEARQUIVO "alunos.bin" //Nome do arquivo alunos em binario
#define TEXTO "alunos.txt" //Nome do arquivo de alunos TXT
#define AVALIACOES "avaliacoes.bin" //Nome do arquivo Binario de Avaliacoes

//Struct alunos
typedef struct
{
    int cod_aluno;
    char nome[41];
    int estagio; //1: Iniciante - 2: Intermediario - 3: Avançado

} aluno;
//Struct data
typedef struct
{
    int dia;
    int mes;
    int ano;

} tdata;
//Struct Avaliacoes
typedef struct
{
    int cod_aluno;
    tdata data;
    float nota;

} avaliacao;

//PROTOTIPO FUNÇÕES
void cadastrarAluno(); //Protipo Cadastrar Aluno
void listaAluno(); //Protipo Listar Aluno
void insertionSort(aluno *a, int);  //Prototipo para ordenar struct com nome e estagio
void alterarAluno(); // Protipo para alterar Aluno
void consultarAluno(); // Prototipo Para Consultar o aluno
void cadastrarAvalicoes(); //Prototipo para cadastro de avaliacoes
void menu();// rototipo para menu
FILE * fileOpen(char nome[],char modo[]); //Prototipo para abertura e leitura de arquivos binarios e txt

//Não feitas
int compara_datas(tdata, tdata);
void listarAvaliacoes();

//Metodo Principal
int main()
{
    menu(); //Chamei Função Menu
    return 0;
}

//Função para implementar o menu
void menu()
{
   // system("color 40"); //Alterar o fundo para vermelho/Preto

    short int escolha; //Variavel para escolha do usuario
    //lAÇO DO MENU - SAI DO LACO QUANDO O VALOR FOR IGUAL A = 0
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
            cadastrarAluno();//cHAMANDO fUNÇÃO VOID
            break;
        case 2:
            listaAluno(); //cHAMANDO fUNÇÃO VOID
            break;
        case 3:
            alterarAluno(); //cHAMANDO fUNÇÃO VOID
            break;
        case 4:
            consultarAluno(); //cHAMANDO fUNÇÃO VOID
            break;
        case 5:
            cadastrarAvalicoes(); //cHAMANDO fUNÇÃO VOID
            break;
        case 6:
            listarAvaliacoes(); //cHAMANDO fUNÇÃO VOID
            break;
        default:
            printf("Ops! Opção errada !\n"); // cASO E TESTE SE VALOR FOR MAIOR QUE 6 E MENOR QUE 0
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

    //LAÇO PARA CADASTRO DE NOVOS ALUNOS sai do laco quando o usuario Digite N
    do
    {

        FILE *arq = fileOpen(NOMEARQUIVO,"ab");

        fseek(arq, 0, SEEK_END); //indo para o final do arquivo
        a.cod_aluno = ftell(arq) / sizeof(aluno) + 1; //Criando valor da matricula

        printf("\n\tNovo Aluno\n");
        printf("\nCodigo do aluno..: %d\n", a.cod_aluno);

        printf("Nome do Aluno: ");
        scanf(" %[^\n]", a.nome);

        printf("Estagio atual:\n <1> Iniciante\n"
               "<2> Intermediario\n"
               "<3> Avancado\n");
        scanf(" %d", &a.estagio);
        //Indo para o final do arquivo e printando com fwrite. fechando o arquivo logo apos
        fseek(arq, 0, SEEK_END);
        fwrite(&a, sizeof(aluno), 1, arq);
        fclose(arq);
        //Laço para cadastrar outro aluno sai do laço quando valor é igual a S ou N
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
//Função para Listar em ordem de estagio e de nomes alfabetica
void listaAluno()
{
    system("cls");
    int i, n;
    char opcao;

    FILE *arq = fileOpen(NOMEARQUIVO,"rb");//Chamando a função

    //TAMANHO DO VETOR
    fseek(arq, 0, SEEK_END);
    n = ftell(arq) / sizeof(aluno);
    aluno a[n];
    rewind(arq);

    //LENDO O ARQUIVO
    fread(a, sizeof(aluno), n, arq);


    //FUNÇÃO PARA ORDENAÇÃO DE ESTÁGIO E NOMES
    insertionSort(a, n);

    printf("\n\n\tAlunos Cadastrados\n");
    printf("----------------------------------------------------------\n");
    printf("#Matricula| Nome do aluno               |  Estagio\n");
    printf("----------------------------------------------------------\n");
    //Listar alunos
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
    //Laço para printar no arquivo TXt
    do
    {

        printf("Gostaria de salva este arquivo em txt ? SIM<s> ou NAO<n>: ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

    }
    while( !(opcao == 'S' || opcao == 'N') );


    //ESCREVENDO NO ARQUIVO TXT
    if(opcao == 's' || opcao == 'S')
    {

        FILE *arq = fileOpen(TEXTO,"w");


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
        fclose(arq);
        //mENSAGEM PARA TER CERTEZA QUE FOI SALVO
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

    //oRDENAÇÃO DE NOMES INDEPEDENTE DE CAIXA ALTA OU CAIXA BAIXA;
    for(i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) && (strncasecmp(aux.nome, v[j - 1].nome, 1) < 0); j--) //Comparando com STRNCaseCMP, para comparar a primeira letra indepedente do CAPS LOXK
            v[j] = v[j-1];
        v[j] = aux;
    }

    //ORDENAÇÃO DE ESTAGIO
    for(i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) && (aux.estagio < v[j - 1].estagio); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }
}
//Função para alterar aluno no binario
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
    //INDO PARA A MATRICULA DIGITADO PELO USUARIO
    fseek(arq, (op - 1) * sizeof(aluno), SEEK_SET);
    fread(&a, sizeof(aluno), 1, arq);
    //caso de teste Caso não exita alunos
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
    //Atializando Informações
    printf("\t\n\nAtualizacao de Informacao\n\n");
    printf("Novo nome:");
    scanf(" %[^\n]", a.nome);
    printf("Estagio novo:\n <1> Iniciante\n <2> Intermediario\n"
           "<3> Avancado\n");
    scanf(" %d", &a.estagio);
    //Escrendo no Arquivo binario na posição exata
    fseek(arq, -sizeof(aluno), SEEK_CUR);
    fwrite(&a, sizeof(aluno), 1, arq);
    fclose(arq);
}
//Função para consultar um aluno
void consultarAluno()
{
    system("cls");
    int n, i, op;

    bool teste = true;

    FILE *arq = fileOpen(NOMEARQUIVO,"rb");

    FILE *file = fileOpen(AVALIACOES,"rb");

    aluno a;
    //Tamanho do vetor
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
        return;
    }

    fclose(file);
    fclose(arq);
}
//Cadastrar Avalções Funcao void
void cadastrarAvalicoes()
{
    register int t = 1;
    system("cls");
    int n, i, op;
    bool teste;
    //Abrindo os arquivos com funcao FILEOpen
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
        scanf("%2d/%2d/%4d", &b.data.dia, &b.data.mes, &b.data.ano);

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
//Função para abrir o arquivo: tem como entrada nome do arquivo e MODO
FILE* fileOpen(char nome[],char modo[])
{
    FILE *fp;
    if((fp = fopen(nome,modo)) == NULL)
    {
        system("color 30");
        printf("\n\tErro no arquivo <%s>\n\n",nome);
        system("pause");
        exit(1);
    }
    return fp;
}
// OBS: NÃO CONSEGUI IMPLEMENTAR ESSA FUNÇÃO, FICOU MUITO CONFUSA E NENHUM MEMBRO DO GRUPO TAMBEM CONSEGUIU FAZER.


//Listar Avaliações
void listarAvaliacoes()
{
    system("cls");
    tdata b, c; //B = DATA DO INICIO - C = DATA FINAL
    avaliacao d; //Avaliação d = DATA
    aluno al;
    bool cont = false;

    FILE *file = fileOpen(AVALIACOES,"rb");

    FILE *arq = fileOpen(NOMEARQUIVO,"rb");

    printf("Favor informe a data inicial: no formato <12/12/2016>: ");
    scanf(" %2d/%2d/%4d", &b.dia, &b.mes, &b.ano);

    printf("Favor informe a data final: no formato <12/12/2016>: ");
    scanf(" %2d/%2d/%4d", &c.dia, &c.mes, &c.ano);

    if(compara_datas(b, c) <= 0)
    {

        while (fread(&d, sizeof(avaliacao), 1, file) > 0)
        {
            if (compara_datas(d.data, b) >= 0)
            {

                if(compara_datas(d.data, c) <= 0)
                {
                    fseek(arq, (d.cod_aluno - 1) * sizeof(aluno), SEEK_SET);
                    fread(&al, sizeof(aluno), 1, arq);
                    if(d.cod_aluno == al.cod_aluno)
                    {
                        cont = true;
                        printf("\nNome: %s\n", al.nome);

                        switch(al.estagio)
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
                        printf("Nota: %f\n", d.nota);
                        printf("Data: %2d/%2d/%4d\n", d.data.dia, d.data.mes, d.data.ano);
                    }
                    else if(!cont)
                    {
                        printf("Nenhum Aluno com essa data! \n");
                        system("pause");
                    }
                }
            }
        }
    }
    else
    {
        printf("Data Invalida !!!");
    }
    system("pause");
}

//Compara datas
int compara_datas(tdata dt1, tdata dt2)
{
    int n1 = dt1.ano  * 10000 + dt1.mes * 100 + dt1.dia;
    int n2 = dt2.ano * 10000 + dt1.mes * 100 + dt1.dia;

    if (n1 > n2)
    {
        return 1;
    }
    else if (n1 < n2)
    {
        return -1;
    }
    if(n1 == n2)
    {
        return 0;
    }
}

