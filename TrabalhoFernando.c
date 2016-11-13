#include <stdio.h>
#include <stdlib.h>

#define NOMEARQUIVO "ficha_gados.bin"


#define anoo 2016
#define mess 10

typedef struct NASC{
    int mes;
    int ano;
    }nascimento;

typedef struct FAZENDA
{
    int codigo;
    float leite;
    float alim;
    char abate;
    nascimento nasc;
}fazenda;

void incluir(int contador, struct FAZENDA *);
FILE * fileOpen(char nome[],char modo[]);
void carregar(struct FAZENDA *a, int contador);

int main()
{
    struct FAZENDA gado;
    short int numero;
    int contagem = 0, i;
    float total;


    while(1)

    {

        system("color 1F");

        puts(" 1.  Carregar arquivo");

        puts(" 2.  Quantidade total de leite produzida por semana na fazenda.");

        puts(" 3.  Quantidade total de alimento consumido por semana na fazenda.");

        puts(" 4.  Quantidade total de leite que vai ser produzido por semana na fazenda, apos o abate");

        puts(" 5.  Numero de cabeças de gado que irao para o abate.");

        puts(" 6.  Incluir novo registro.");

        puts(" 7.  Listar registros");

        puts(" 8.  Sair do programa.\n");

        printf("\n Opcao: ");

        scanf("%d", &numero);


        switch (numero)

        {

        case 1:
            carregar(&gado,contagem);
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
            incluir(contagem, &gado);
            contagem++;
            break;

        case 7:
            break;

        case 8:
            printf("Voce saiu\n");
            return 0;
            break;
        default:
            system("cls");
            puts("==Comando Invalido Tente Novamente==\n\a");
        }

    }


    return 0;

}

void incluir(int contador, struct FAZENDA *a)
{

    system("cls");
    FILE *file = fileOpen(NOMEARQUIVO,"wb");
    int calcAbate = 0;

    printf("\nDigite o codigo do animal: ");
    scanf("%d", &a[contador].codigo);

    printf("\nDigite o numero de litros de leite p/ semana: ");
    scanf("%f", &a[contador].leite);

    printf("\nDigite o numero de alimento ingerido por semana: ");
    scanf("%f", &a[contador].alim);

    printf("\nDigite o mes de nascimento: ");
    scanf("%d", &a[contador].nasc.mes);

    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &a[contador].nasc.ano);

    //calculo do abate
    calcAbate = anoo * 12 + mess;
    calcAbate = ((a[contador].nasc.ano * 12 + a[contador].nasc.mes) - calcAbate) / 12;

    //Condições do abate
    if (calcAbate > 5 || a[contador].leite < 40.0 || (a[contador].leite > 50.0 && a[contador].leite < 70.0) && a[contador].alim < 50.0)
    {
        a[contador].abate = 'S';
    }
    else
    {
        a[contador].abate = 'N';
    }

     fwrite(a,sizeof(struct FAZENDA),contador,file);

}


FILE* fileOpen(char nome[],char modo[]){
    FILE *fp;
    if((fp = fopen(nome,modo)) == NULL){
        printf("Erro ao abrir o arquivo <%s>",nome);
        exit(1);
    }
    return fp;
}

void carregar(struct FAZENDA *a, int contador){
    FILE *file = fileOpen(NOMEARQUIVO,"rb");
    fread(a,sizeof(struct FAZENDA),2000,file);

}

