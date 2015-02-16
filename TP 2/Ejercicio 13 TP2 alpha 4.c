#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i;
    int vect[90];
    FILE *archi;
    if((archi=fopen("archalea","wb"))==NULL);
    {
        puts("imposible abrir archivo");
    }
    printf("90 numeros aleatorios del 0 al 99\n\n");
    for(i=0; i<90; i++)
       vect[i]=rand() % 1000;
    fwrite(vect,sizeof(vect),1,archi);
    for(i=0; i<90; i++)
        printf("posicion= %d valor= %d\n",i+1,vect[i]);
    return 0;
}
