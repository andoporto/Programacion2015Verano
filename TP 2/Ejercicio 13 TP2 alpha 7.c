#include <stdlib.h>
#include <stdio.h>

#define MSG 1

int abrir_archivo (FILE**, char *, char *, int);
void mostrarReg(vect);

int main(void)
{
    int i;
    int vect[90];
    FILE *archi;
    if((archi=fopen("archalea","wb+"))==NULL);
    {
        puts("imposible abrir archivo");
    }
    printf("90 numeros aleatorios del 0 al 99\n\n");
    for(i=0; i<90; i++)
       vect[i]=rand() % 1000;
    fwrite(vect,sizeof(vect),1,archi);
    fclose(archi);
    fread(vect, sizeof(vect),1, archi);
    while (!feof(archi))
    {
        printf("\n Numero : %d", vect);
        fread(vect, sizeof(vect),1, archi);
        i++;
    }
     close(archi);
    return 0;
}

