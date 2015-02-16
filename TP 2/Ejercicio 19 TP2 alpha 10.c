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
    FILE *arch1;
    FILE *arch2;
    FILE *arch3;

    archi=fopen("archalea.dat","w+b");
    if(!archi)
    {
        puts("imposible abrir archivo");
    }
    else
    {
        printf("90 numeros aleatorios del 0 al 99\n\n");
        for(i=0; i<89; i++)
        {
            vect=rand() % 1000;
            fwrite(&vect,sizeof(vect),1,archi);
        }
        fclose(archi);

        archi=fopen("archalea.dat","r+b"); //abro el archivo original

        arch1=fopen("archa11.dat","w+b");
        if(!arch1)
            puts("imposible abrir archivo");
        //else
           // exit 1;

        if(archi)
        {
            int conta=0;
            while (!feof(archi))
            {
                printf("\n posicion= %d Numero : %d", conta+1,vect);
                conta++;
                fread(&vect, sizeof(vect),1, archi);
            }
        }
        archi=fopen("archalea.dat","w+b");
        if(!archi)
        {
            puts("imposible abrir archivo");
        }
        else
        {
            puts("imposible abrir archivo");

        }
        close(archi);
        printf("\n");
        return 0;
    }
}
