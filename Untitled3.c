#include <stdio.h>
#include <stdlib.h>


/* Aritm�tica modular � tamb�m considerada como o "algoritmo do rel�gio".

Ao extrair o modulo 12, como resposta poss�vel pode-se ter n�meros de
0 a 11. Nunca negativo, pois a ideia � de um rel�gio com 12 posi��es, sendo
a primeira o zero e a �ltima o 11.

Por�m o operador de m�dulo do C (operador %) computa apenas o resto da divis�o
e gera n�meros negativos. Em C:

-2 mod 12 = -2 (n�o est� entre 0 e 11)
2 mod -12 = 2��(n�o est� entre -11 e 0)

O C dizer que -2 mod 12 � -2 significa dizer que ele est� a -2 de dist�ncia do
final do rel�gio, ou seja, est� em 10 (o in�cio e tamb�m o final do rel�gio � o zero).

Dizer que 2 mod -12 significa um rel�gio ao contr�rio (0, -1, -2, -3, .. -11, andando
no sentido anti-hor�rio) e que o valor 2 est� a 2 posi��es de dist�ncia do 0, ou seja,
est� em -10.

Nesta artim�tica modular o resultado da opera��o PRECISA SER do mesmo sinal
do divisor.

Observou-se que o operador de m�dulo do python (%) n�o tem este comportamento,
calculando o m�dulo n�o negativo. A biblioteca bn.h do openssl possui ambos,
tanto a fun��o BN_mod que simplesmente retorna o resto da divis�o (comportamento
igual ao %) como a fun��o BN_nnmod que calcula o m�dulo n�o negativo.

Nesta vers�o em C resolveu-se fazer uma pequena corre��o na resposta dada pelo
operador de m�dulo, pois o algoritmo de euclides precisa do m�dulo positivo.
*/
long mod(long a, long b)
{
����long r = a % b;

����/* Uma corre�� � necess�ria se r e b n�o forem do mesmo sinal */

����/* se r for negativo e b positivo, precisa corrigir */
����if ((r < 0) && (b > 0))
���return (b + r);

����/* Se ra for positivo e b negativo, nova correcao */
����if ((r > 0) && (b < 0))
���return (b + r);

����return (r);
}

long euclides_ext(long a, long b, long c)
{
����long r;

����r = mod(b, a);

����if (r == 0) {
���return (mod((c / a), (b / a)));���// retorna (c/a) % (b/a)
����}

����return ((euclides_ext(r, a, -c) * b + c) / (mod(a, b)));
}

int main(int argc, char *argv[])
{
����long p, q, e, qq, n, d;

����/* O objetivo desta implementa��o do algoritmo de euclides extendido � o
������ c�lculo do valor do D da chave privada correspondente a Ke=(n,e)
������ para isto s�o necess�rios fornecer o p, o q e o valor de e
���� */
����if (argc != 4) {
���fprintf(stderr, "ERRO. faltou passar valor de p, q, e\n");
���fprintf(stderr, "Forma de uso:\n");
���fprintf(stderr, "\t%s p q e\n", argv[0]);
���return (1);
����}

����/* pegando os valores de p, q e n fornecidos como argumentos do main */
����p = atol(argv[1]);
����q = atol(argv[2]);
����e = atol(argv[3]);

����/* calculando o n */
����n = p * q;

����/* calculando o quociente de euler, chamado aqui de qq */
����qq = (p - 1) * (q - 1);


����/* chamando a fun��o que calcula o d. Ela retorna um n�mero que case na
������ express�o: d*e mod qq = X

������ Tem-se o e e o qq. Para o RSA o X deve ser 1, pois d*e mod qq = 1
���� */
����d = euclides_ext(e, qq, 1);

����printf("\nVALORES CALCULADOS:\n");
����printf("N��= %10li\nE��= %10li\nqq = %10li\nD��= %10li\n", n, e, qq,
����� d);
����printf("\n*** Verifique com ***\n");
����printf("\techo \"(%li * %li) %% %li\"|bc\n\n", d, e, qq);
����printf("\t(deve resultar em 1)\n\n\n");

}
