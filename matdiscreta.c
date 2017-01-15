#include <stdio.h>
//Nome: Myrna Shuman (Ciencias da computacao)
//      Fernanda Sanches (Ciencias da computacao)
int main (void){
 int cpfx1[10];
 int i, soma1=0, result1=0;
 int y1, soma2=0, result2=0, y2;
   printf("informe os nove primeiros digitos do cpf:\n obs: de enter em cada numero digitado.\n");
  for(i=1; i<10; i++){

  scanf("%d", &cpfx1[i]);
    result1 = cpfx1[i] * i;
    soma1 = soma1 + result1;
      y1 = (soma1%11);


  }
  printf("o primeiro digito eh %d\n", y1);

  int cpf2[10];
  printf("informe os dez primeiros digitos do cpf:\nde enter em cada numero digitado.\n");
  for(i=0; i<10; i++){
    scanf("%d", &cpf2[i]);
    result2 = cpf2[i] * i;
    soma2 = soma2 + result2;
      y2 = (soma2%11);

  }

   printf("OS DOIS ULTIMOS NUMEROS %d%d", y1, y2);

 return 0;
}
