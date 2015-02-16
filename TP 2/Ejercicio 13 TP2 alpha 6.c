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
    //for(i=0; i<90; i++)
    //    printf("posicion= %d valor= %d\n",i+1,vect[i]);
  /*  if((archi=fopen("archalea","rb"))==NULL);
    {
        puts("imposible abrir archivo");
    }*/

   // if(abrirArchivo(vect,"archalea", "rb", MSG)==0)
    //    exit(1);
    fclose(archi);
    fread(vect, sizeof(vect),1, archi);
    while (!feof(archi))
    {
        mostrarReg(&vect);
        fread(&vect, sizeof(vect),1, archi);
    }
     close(archi);
    return 0;
}

int abrir_archivo(FILE **archi, char * nombre, char * modo, int msj)
{
    *archi= fopen(nombre, modo);
    if (!*archi && msj)
        printf("Error abriendo el archivo");
    return *archi !=NULL;
}

void mostrarReg( vect )
{
    printf("\nEl numero es es: %d \n", vect);

}
