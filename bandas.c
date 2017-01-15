#include <stdio.h>
#include <string.h>

typedef struct {

    char nome[100];
    char tipo_musical[100];
    unsigned short int ranking;
    unsigned short int integrantes;

}BANDA;


BANDA bandas[5];

//protótipo
int incluir_banda();
int consulta_banda_ranking();
int consulta_tipo_musical();
int consulta_banda_nome();
int listar_bandas();


int main(){

  char op;

  do{
    system("cls");
    printf("Bandas Musicais\n\n");
    printf("Escolha uma opcao:\n\n");
    printf("1-Incluir Banda\n");
    printf("2-Consultar banda por ranking\n");
    printf("3-Consultar banda por tipo musical\n");
    printf("4-Consultar banda por nome\n");
    printf("5-Listar bandas\n");
    printf("6-Sair\n");

    op = getche();

    system("cls");

    switch(op){
    case '1':
        printf("Incluir Banda...\n\n");
        incluir_banda();
    break;
    case '2':
        printf("Consultar banda por ranking...\n\n");
        consulta_banda_ranking();
    break;
    case '3':
        printf("Consultar banda por tipo musical...\n\n");
        consulta_tipo_musical();
    break;
    case '4':
        printf("Consultar banda por nome...\n\n");
        consulta_banda_nome();
    break;
    case '5':
        printf("Listar bandas...\n\n");
        listar_bandas();
    break;
    case '6':
        printf("bye...");
    break;

    default:
        printf("Opcao Invalida\n\n");

    }

    if(op !='6')
        system("pause");
  }
  while(op != '6');

}


int incluir_banda(){

    static int index=0;

    //leitura do arquivo
    FILE *file;
    file = fopen("bandas.bin","r+b");
    if(file == NULL){
        file = fopen("bandas.bin","w+b");
        index=0;
    }

    index = fread(bandas, sizeof(BANDA),5,file);
    index++;

    printf("\nIndex: %d\n",index);

    char nome[100];
    char tipo_musical[100];
    unsigned short int integrantes,ranking;

    printf("Cadastro de Banda\n\nNome da banda: ");
    scanf(" %[^\n]s",nome);
    printf("Tipo Musical: ");
    scanf(" %[^\n]s",tipo_musical);
    printf("Qtde Integrantes: ");
    scanf("%d",&integrantes);
    printf("Ranking: ");
    scanf("%hd",&ranking);

    strcpy(bandas[index].nome,nome);
    strcpy(bandas[index].tipo_musical,tipo_musical);
    bandas[index].integrantes;
    bandas[index].ranking;

    index++;

    fwrite(bandas, sizeof(BANDA),1,file);

    fclose(file);


}
int consulta_banda_ranking(){

    int index;
    unsigned short int ranking,i;

    printf("Consulta de Banda por Ranking\n\nRanking: ");
    scanf("%hd",&ranking);


    //leitura do arquivo
    FILE *file;
    file = fopen("bandas.bin","rb");
    if(file == NULL){
        printf("Voce nao cadastrou nenhuma banda...");
        return 0;
    }

    index = fread(bandas, sizeof(BANDA),5,file);

    for(i=0 ; i < 5 ; i++){
        printf("for %d...\n",i);
        if(bandas[i].ranking == ranking){
           printf("A Banda no ranking %d eh %s: ",ranking,bandas[i].nome);
        }
    }
    fclose(file);


}
int consulta_tipo_musical(){

}
int consulta_banda_nome(){

}
int listar_bandas(){

}


