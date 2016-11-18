#include <stdio.h>
#include <stdlib.h>


void selecao (int n, char v[])
{   int i, j, x;
	int min;
   for (i = 0; i < n-1; ++i) {
      min = i;
      for (j = i+1; j < n; ++j)
         if (v[j] < v[min])  min = j;
      x = v[i]; v[i] = v[min]; v[min] = x;
   }
}


int main()
{
    int i;
    char v[7] = {'b', 'i', 'c', 'i', 'a', 't', 'o'};

    selecao(7, v);

    for(i = 0; i < 7; i++)
    {
        printf("%c", v[i]);
    }

}
