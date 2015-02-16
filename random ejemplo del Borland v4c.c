#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i;
    printf("90 numeros aleatorios del 0 al 99\n\n");
    for(i=0; i<90; i++)
       printf("posicion= %d valor= %d\n", i+1,rand() % 1000);
    return 0;
}
