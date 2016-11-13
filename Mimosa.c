#include <stdio.h>
#include <stdlib.h>

#define NOMEARQUIVO "ficha_gados.bin"

struct data{

   int mes,ano;

};

struct ficha_gado{
    int cod;
    float qtde_litros;
    float qtde_alimento;
    struct data data_nasc;
    char abate;

};

struct ficha_gado gados[2000];

//secao de prototipos
int load_file(void);
int insert(void);
FILE * fileOpen(char nome[],char modo[]);


int main()
{
    char op;

    do{

        printf("\nMenu!\n");
        op = getch();

        switch(op){
        case '6':
            insert();
            break;
        case '1':
            load_file();
            break;
        }


    }while(op != '8');



    return 0;
}


int insert(){

    FILE *file = fileOpen(NOMEARQUIVO,"wb");
    printf("Cod: ");
    scanf("%d",&gados[0].cod);
    printf("Litros: ");
    scanf("%f",&gados[0].qtde_litros);
    printf("Alimentacao (kg): ");
    scanf("%f",&gados[0].qtde_alimento);
    printf("Nascimento (mes/ano): ");
    scanf("%d",&gados[0].data_nasc.mes);
    scanf("%d",&gados[0].data_nasc.ano);

    int meses=12 * 2016 + 10,idade;
    idade =  meses - (gados[0].data_nasc.mes + gados[0].data_nasc.ano * 12) ;



    if( idade > 5*12 || gados[0].qtde_litros < 40 || (gados[0].qtde_litros >= 50 && gados[0].qtde_litros <= 70 && gados[0].qtde_alimento > 50) ){
       gados[0].abate = 'S';
    }else{
       gados[0].abate = 'N';
    }

    fwrite(gados,sizeof(struct ficha_gado),1,file);


}

int load_file(){
    FILE *file = fileOpen(NOMEARQUIVO,"rb");
    fread(gados,sizeof(struct ficha_gado),2000,file);

    printf("Litros %f",gados[0].qtde_litros);

}



FILE* fileOpen(char nome[],char modo[]){
    FILE *fp;
    if((fp = fopen(nome,modo)) == NULL){
        printf("Erro ao abrir o arquivo <%s>",nome);
        exit(1);
    }
    return fp;
}

