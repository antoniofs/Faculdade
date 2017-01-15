#include <stdio.h>

int main(int argc, char * argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Erro: uso incorreto!\nDigite: %s <origem> <destino>\n", argv[0]);
        return 1;
    }
    FILE * in, * out;
    if ((in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Arquivo nao encontrado (%s)!\n", argv[1]);
        return 1;
    }
    if ((out = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Nao foi possivel criar o arquivo %s!\n", argv[2]);
        fclose(in);
        return 1;
    }
    int b;
    while (1) {
        b = fgetc(in);
        if (feof(in)) break;
        fputc(b, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}