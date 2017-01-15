#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Erro: uso incorreto!\nDigite: %s <arquivo>\n", argv[0]);
        return 1;
    }
    FILE * arq;
    char linha[121];
    if ((arq = fopen(argv[1], "a+")) == NULL) {
        fprintf(stderr, "Erro: nao foi possivel abrir/criar o arquivo %s!\n", argv[1]);
        return 1;
    }
    while (fgets(linha, 121, arq) != NULL) { // l� do arquivo
        fputs(linha, stdout); // escreve no v�deo
    }
    while (1) {
        fgets(linha, 121, stdin); // l� do teclado
        if (linha[0] == '\n') break;
        fputs(linha, arq); // escreve no arquivo
    }
    fflush(arq); // descarrega o buffer
    rewind(arq); // volta para o in�cio do arquivo
    while (fgets(linha, 121, arq) != NULL) { // l� do arquivo
        fputs(linha, stdout); // escreve no v�deo
    }
    fclose(arq);
    return 0;
}
/* Comentario feito pelo meu editor fuleira */