#include <stdio.h>
#include <stdlib.h>

#define MAX 2

//declaração da estrutura
typedef struct  {
      int x;
      int y;
}ponto;



int main(){

    ponto p[MAX];
    ponto p_linha[MAX];

    FILE *file;

    if((file = fopen("arquivoX.bin","rb")) == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    //for(i = 0 ; i < MAX ; i++)
    fread(&p, sizeof(ponto),2,file);

    printf("Ponto 1: %d %d\nPonto 2: %d %d",p[0].x,p[0].y,p[1].x,p[1].y);

}
