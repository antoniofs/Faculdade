#include <stdio.h>
#define NOME_ARQ "cliente.dat"

typedef struct {
    int numConta;
    char nome[60];
    float saldo;
} cliente;

void cadastrar_cliente(void);
void listar_clientes(void);
void depositar(void);

int main()
{
    int op;
    do {
        printf("\n\n\tCADASTRO DE CLIENTES\n");
        printf("<1> Cadastrar um cliente\n");
        printf("<2> Listar os clientes cadastrados\n");
        printf("<3> Realizar um deposito\n");
        printf("<0> Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: cadastrar_cliente();
                    break;
            case 2: listar_clientes();
                    break;
            case 3: depositar();
                    break;
            case 0: break;
            default: printf("\nErro: opcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}

void depositar()
{
    FILE * arq;
    cliente c;
    int conta;
    float valor;
    if ((arq = fopen(NOME_ARQ, "r+b")) == NULL) {
        fprintf(stderr, "\nErro: nao ha' nenhuma conta cadastrada!\n");
        return;
    }
    printf("\nDeposito\n");
    printf("Numero da conta: ");
    scanf("%d", &conta);
    // Exerc�cio: trocar o la�o (acesso sequencial) por um fseek (acesso direto)
    fseek(arq, (conta - 1) * sizeof(cliente), SEEK_SET);
    fread(&c, sizeof(cliente), 1, arq);
/*    while (fread(&c, sizeof(cliente), 1, arq) > 0) {
        if (c.numConta == conta) break;
    } */
    if (feof(arq) || conta <= 0) {
        fprintf(stderr, "\nErro: nao ha' nenhuma conta com esse numero (%d)!\n", conta);
        fclose(arq);
        return;
    }
    printf("Nome do cliente: %s\n", c.nome);
    printf("Saldo atual....: R$ %.2f\n", c.saldo);
    printf("Valor do deposito: R$ ");
    scanf("%f", &valor);
    c.saldo += valor;
    fseek(arq, -sizeof(cliente), SEEK_CUR); // volta 1 estrutura no arquivo
    fwrite(&c, sizeof(cliente), 1, arq);
    fclose(arq);
}

void cadastrar_cliente()
{
    FILE * arq;
    cliente c;
    if ((arq = fopen(NOME_ARQ, "ab")) == NULL) {
        fprintf(stderr, "\nErro: nao foi possivel criar o arquivo %s!\n", NOME_ARQ);
        return;
    }
    fseek(arq, 0, SEEK_END); // vai para o final do arquivo
    c.numConta = ftell(arq) / sizeof(cliente) + 1;
    printf("\n\nNovo Cliente\n");
    printf("Numero da conta: %d\n", c.numConta);
    printf("Nome do cliente: ");
    scanf(" %59[^\n]", c.nome);
    printf("Saldo da conta.: R$ ");
    scanf("%f", &c.saldo);
    fwrite(&c, sizeof(cliente), 1, arq);
    fclose(arq);
    printf("\nClinte cadastrado com sucesso!\n");
}

void listar_clientes()
{
    FILE * arq;
    //cliente c;

    if ((arq = fopen(NOME_ARQ, "rb")) == NULL) {
        fprintf(stderr, "\nNao ha' nenhum cliente cadastrado!\n");
        return;
    }
    fseek(arq, 0, SEEK_END);
    int n = ftell(arq) / sizeof(cliente), i;
    cliente c[n];
    rewind(arq);
    fread(c, sizeof(cliente), n, arq);
    fclose(arq);
    printf("\n\n\tClientes Cadastrados\n");
    printf("--------------------------------------------------\n");
    printf("#Conta| Nome do cliente               |  Saldo\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%06d| %-30s|%10.2f\n", c[i].numConta, c[i].nome, c[i].saldo);
    }
    /*
    while (fread(&c, sizeof(cliente), 1, arq) > 0) {
        printf("%06d| %-30s|%10.2f\n", c.numConta, c.nome, c.saldo);
    }
    */
    printf("--------------------------------------------------\n");
    //fclose(arq);
}