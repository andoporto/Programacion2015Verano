#include <stdlib.h>
#include <stdio.h>

#define MSG 1

int abrirArchivo(FILE **, const char *, const char *, int);

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

    if(abrirArchivo(vect,"archalea", "rb", MSG)==0)
        exit(1);
    return 0;
}




int abrirArchivo(FILE **fp, const char * nombre, const char * modo, int msg)
{
    *fp = fopen("archalea", "rb");
    if(*fp==NULL && msg==1)
        printf("Error abriendo archivo \n");
    return *fp!=NULL;
}
