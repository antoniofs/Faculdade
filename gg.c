#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQ "ficha_bandas.dat"


void preencherBanda();
void printaBanda();
void menu();
void funcaoRanking();
void estilomusica();
void nomebanda();

int x = 0;

struct banda
{
    char nome[30];
    char estilo[10];
    int numero_integrantes;
    int ranking;
};
typedef struct banda Bandas;

Bandas vetBandas[4], liBandas[4];

void main(void)
{
system("color 30");
    menu();

}
void funcaoRanking()
{
    FILE * arq;

    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        return;
    }
    fread(vetBandas, sizeof(Bandas), 5, arq);
    int ranking_teclado = 0;
    register int y = 0;
    printf("\n Digite um numero no Ranking de 1 a 5: \n");
    scanf("%d", &ranking_teclado);
    for(y = 0; y < 5; y++)
    {
        if(vetBandas[y].ranking == ranking_teclado)
        {
            printf(" R.E.G.I.S.T.R.O %d:\n", y + 1);
            printf("\nNome: %s\n", vetBandas[y].nome);
            printf("\Estilo: %s\n", vetBandas[y].estilo);
            printf("\nNumero de integrantes: %d\n", vetBandas[y].numero_integrantes);
            printf("\n Ranking: %d\n", vetBandas[y].ranking);

        }
    }
}

void estilomusica()
{
    FILE * arq;

    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        return;
    }
    fread(vetBandas, sizeof(Bandas), 5, arq);

    char estilo_teclado[10];
    register int y = 0;

    printf("\nDigite um estido de musica: \n");
    scanf("%s", &estilo_teclado);

    for(y = 0; y < 5; y++)
    {
        if(strcmp(vetBandas[y].estilo, estilo_teclado) == 0)
        {
            printf(" R.E.G.I.S.T.R.O %d:", y + 1);
            printf("\nNome: %s\n", vetBandas[y].nome);
            printf("\Estilo: %s\n", vetBandas[y].estilo);
            printf("\nNumero de integrantes: %d\n", vetBandas[y].numero_integrantes);
            printf("\n Ranking: %d\n", vetBandas[y].ranking);

        }
    }


}


void nomebanda()
{
    FILE * arq;

    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        return;
    }
    fread(vetBandas, sizeof(Bandas), 5, arq);


    char nomebanda[10];
    register int y = 0;
    int indicador = 0;

    printf("\n Digite um nome da banda qual deseja pesquisar: \n");
    scanf("%s", &nomebanda);

//    fread(vetBandas, struct(Bandas), 5, arq);

    for(y = 0; y < 5; y++)
    {
        if(strcmp(vetBandas[y].nome, nomebanda) == 0)
        {
            printf("Essa banda esta na lista de suas favoritas\n");
            indicador = 1;
        }
    }

    if (indicador == 0)
    {
        printf("Essa banda nao eh umas de suas favoritas\n");
    }


}

void preencherBanda()
{
    FILE * arq;
    if ( (arq = fopen(NOME_ARQ, "wb")) == NULL)
    {
        fprintf(stderr, "\nErro: não foi possivel criar o arquivo <%s>\n", NOME_ARQ);
        return;
    }
    for(x = 0; x < 5; x++)
    {
        printf("\nR.E.G.I.S.T.R.O %d:\n ", x + 1);
        printf("\nNome: ");
        scanf(" %[^\n]", vetBandas[x].nome);
        printf("\nEstilo: ");
        scanf(" %[^\n]", vetBandas[x].estilo);
        printf("\nNumero de integrantes: ");
        scanf("%d", &vetBandas[x].numero_integrantes);
        printf("\nRanking: ");
        scanf("%d", &vetBandas[x].ranking);
    }

    fwrite(vetBandas, sizeof(Bandas), 5, arq);
    fclose(arq);

}


void printaBanda()
{
    FILE * arq;

    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        return;
    }
    fread(vetBandas, sizeof(Bandas), 5, arq);
    int x = 0;


    for(x = 0; x < 5; x++)
    {
        printf(" R.E.G.I.S.T.R.O %d:\n", x + 1);
        printf("\nNome: %s\n", vetBandas[x].nome);
        printf("\Estilo: %s\n", vetBandas[x].estilo);
        printf("\nNumero de integrantes: %d\n", vetBandas[x].numero_integrantes);
        printf("\nRanking: %d\n", vetBandas[x].ranking);

    }
}

void menu()
{
    int escolha = 0, x = 0;
    do
    {

        printf(" \n 1= Preencher Bandas");
        printf(" \n 2= Imprimir Bandas");
        printf(" \n 3= Pesquisa Por Ranking");
        printf(" \n 4= Pesquisa Por Estilo");
        printf(" \n 5= Pesquisa Por Nome");
        printf(" \n 0= E.X.I.T \n\n\n");
        scanf("%d", &escolha);
        switch(escolha)
        {
        case 1:
            preencherBanda();
            break;
        case 2:
            printaBanda();
            break;
        case 3:
            funcaoRanking();
            break;
        case 4:
            estilomusica();
            break;
        case 5:
            nomebanda();
            break;
        }
    }
    while(escolha != 0);
}


FILE* fileOpen(char nome[],char modo[]){
    FILE *fp;
    if((fp = fopen(nome,modo)) == NULL){
        printf("Erro ao abrir o arquivo <%s>",nome);
        exit(1);
    }
    return fp;
}
