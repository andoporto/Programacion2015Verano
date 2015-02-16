#include <stdio.h>
#include <stdlib.h>

#define esBlanco(x)((x)==' '||(x)=='\t')
#define aMayusc(x)((x)>='a'&&(x)<='z'?(x)-32:(x))
#define aMinusc(x)((x)>='A'&&(x)<='Z'?(x)+32:(x))

char* normalizar (char *);
char* normalizar2 (char *);
char* normalizar3 (char *);
char* normalizar4 (char *);

int main()
{
    char cad1[100]={"\t UN\teJEmPlo   ADeCUAdo\t  "};
	char cad11[100]={"\t                UN\teJEmPlo   aDeCUAdo  "};
	char cad12[100]={"\t                UN EJEMPLO   ADECUADO  "};
    char cad2[100]={"   "};
    char cad3[100]={"\tUufFFc Jf \t\t  "};
	char cad31[100]={"\tUUUUUfff JfeY78u \t\t  "};
    printf("\"%s\"\n",normalizar(cad1));
	printf("\"%s\"\n",normalizar(cad11));
	printf("\"%s\"\n",normalizar(cad12));
    printf("\"%s\"\n",normalizar(cad2));
    printf("\"%s\"\n",normalizar(cad3));
	printf("\"%s\"\n",normalizar(cad31));
	printf("\n ----------------------------------------------------------------------------\n");
	char cad4[100]={"\t UN\teJEmPlo   ADeCUAdo\t  "};
    char cad5[100]={"   "};
    char cad6[100]={"\tUufFFc Jf \t\t  "};
	printf("\"%s\"\n",normalizar2(cad4));
    printf("\"%s\"\n",normalizar2(cad5));
    printf("\"%s\"\n",normalizar2(cad6));
    printf("\n ----------------------------------------------------------------------------\n");
    char cad7[100]={"\t UN\teJEmPlo   ADeCUAdo\t  "};
    char cad8[100]={"   "};
    char cad9[100]={"\tUufFFc Jf \t\t  "};
    printf("\"%s\"\n",normalizar3(cad7));
    printf("\"%s\"\n",normalizar3(cad8));
    printf("\"%s\"\n",normalizar3(cad9));
    printf("\n ----------------------------------------------------------------------------\n");
    char cad101[100]={"\t UN\teJEmPlo   ADeCUAdo\t  "};
    char cad111[100]={"   "};
    char cad121[100]={"\tUufFFc Jf \t\t  "};
    printf("\"%s\"\n",normalizar4(cad101));
    printf("\"%s\"\n",normalizar4(cad111));
    printf("\"%s\"\n",normalizar4(cad121));
    printf("\n");
    return 0;
}

char * normalizar (char * cad)
{
    char*pe,*pl; //puntero escritura, puntero lectura
    pe=pl=cad;
    while(*pl)
    {
        while(esBlanco(*pl)&&*pl)
            pl++;
        if(*pl)
        {
            *pe=aMayusc(*pl);
            pe++;
            pl++;
            while(*pl&&!esBlanco(*pl))
            {
                *pe=aMinusc(*pl);
                pe++;
                pl++;
            }
            if(esBlanco(*pl))
            {
                *pe=' ';
                pe++;
                pl++;
            }
        }
    }
    if(pe>cad) //eliminar el ultimo blanco, si todos fueran blancos no retrocede
         pe--;
    *pe='\0';
    return cad;
}

char * normalizar2 (char * cad)
{
    char*pe,*pl; //puntero escritura, puntero lectura
    pe=pl=cad;
    while(*pl)
    {
        while(esBlanco(*pl)&&*pl)
            pl++;
        if(*pl)
        {
            *pe=aMinusc(*pl);
            pe++;
            pl++;
            while(*pl&&!esBlanco(*pl))
            {
                *pe=aMinusc(*pl);
                pe++;
                pl++;
            }
            if(esBlanco(*pl))
            {
                *pe=' ';
                pe++;
                pl++;
            }
        }
    }
    if(pe>cad) //eliminar el ultimo blanco, si todos fueran blancos no retrocede
         pe--;
    *pe='\0';
    return cad;
}


char * normalizar3 (char * cad)
{
    char*pe,*pl; //puntero escritura, puntero lectura
    pe=pl=cad;
    while(*pl)
    {
        while(esBlanco(*pl)&&*pl)
            pl++;
        if(*pl)
        {
            *pe=aMayusc(*pl);
            pe++;
            pl++;
            while(*pl&&!esBlanco(*pl))
            {
                *pe=aMayusc(*pl);
                pe++;
                pl++;
            }
            if(esBlanco(*pl))
            {
                *pe=' ';
                pe++;
                pl++;
            }
        }
    }
    if(pe>cad) //eliminar el ultimo blanco, si todos fueran blancos no retrocede
         pe--;
    *pe='\0';
    return cad;
}

char * normalizar4 (char * cad)
{
    char*pe,*pl; //puntero escritura, puntero lectura
    pe=pl=cad;
    while(*pl)
    {
        int bande=0;
        while(esBlanco(*pl)&&*pl)
            pl++;
        if(*pl && bande==1)
        {
            *pe=aMayusc(*pl);
            pe++;
            pl++;
            while(*pl&&!esBlanco(*pl))
            {
                *pe=aMinusc(*pl);
                pe++;
                pl++;
            }
            if(esBlanco(*pl))
            {
                *pe=' ';
                pe++;
                pl++;
            }
        }
        bande++;
    }
    if(pe>cad) //eliminar el ultimo blanco, si todos fueran blancos no retrocede
         pe--;
    *pe='\0';
    return cad;
}
