#include <stdio.h>
#include <stdlib.h>
#define MSG 1

int abrir_archivo (FILE**, char *, char *, int);
void mostrarReg(vect);

int main(void)
{
    int i;
    int vect;
    FILE *archi;
    archi=fopen("archalea.dat","w+b");
    if(!archi)
    {
        puts("imposible abrir archivo");
    }
    else
    {
        printf("90 numeros aleatorios del 0 al 99\n\n");
        for(i=0; i<90; i++)
        {
            vect=rand() % 1000;
            fwrite(&vect,sizeof(vect),1,archi);
        }
        fclose(archi);

        archi=fopen("archalea.dat","r+b");
        if(archi)
        {
            while (!feof(archi))
            {
                printf("\n Numero : %d", vect);
                fread(&vect, sizeof(vect),1, archi);
            }
        }
        else
        {
            puts("imposible abrir archivo");
        }

    }
    close(archi);
    return 0;
}
