#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i;
    int vect[90];
    printf("90 numeros aleatorios del 0 al 99\n\n");
    for(i=0; i<90; i++)
       vect[i]=rand() % 1000;

    return 0;
}
