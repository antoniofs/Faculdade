#include <stdio.h>
#include <stdlib.h>

/* Faça  um programa que simule um banco
 * Entradas: Valor de Saque, Quantidades de cedulas, Quais cedulas
 * Saida: quantidade de cada cedulas para atingir aqueles valor do usuario
 */
 void CalcCedulas(float, int, int, int); //Prototipo

 int main ()
 {
     static float saque = 0, dinheiro = 0;
     int qtdCedulas = 0, cedulas = 0, cedulas1 = 0;


     //Saque
     printf("Favor informe o valor de saque: ");
     scanf("%f", &saque);

     if(saque < 2.0)
     {
         printf("Valor de saque inferior a R$2,00(DOIS REAIS)\n");
         exit(1);
     }

     printf("Favor infrome a quantidade de cedulas: ");
     scanf("%d", &qtdCedulas);

     if (qtdCedulas == 2)
     {
         printf("Informe a primeira e segunda cedulas");
         scanf("%d %d", &cedulas, &cedulas1);
         if (cedulas > 100 && cedulas < 2 || cedulas1 > 100 && cedulas1 < 2)
         {
             printf("Valor incorretor informar cedulas de 2,00 - 5,00 - 10,00 - 20,00 - 50,00 - 100,00");

             exit(1);
         }

     }
     else
     {
         printf("Informe a quantidade de cedulas");
         scanf("%d", &cedulas);
         if (cedulas > 100 && cedulas < 2)
         {
             printf("Valor incorretor informar cedulas de 2,00 - 5,00 - 10,00 - 20,00 - 50,00 - 100,00");

             exit(1);
         }
     }


     CalcCedulas(saque, qtdCedulas, cedulas, cedulas1);

     return 0;
 }


 //Funcao do calculo
void CalcCedulas(float saque, int qtd, int cedula, int cedulas1)
{
    static sobra = 1;


    if (qtd == 2)
    {
    sobra =  cedula % cedulas1; //EX: 50 % 20 = 10 (FAMOSO MDC);
    /*E DPS.....
    //CALC ?

    50 = 20.2 + 10
    10 = 50 - 20.2



    */






    }


}
