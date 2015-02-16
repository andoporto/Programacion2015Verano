#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 60

char* calculoPalabras(char*);

int main()
{
    char cadena[TAM];
    printf("Ingrese cadena a calcular: ");
    gets(cadena);
    //printf("La primera de la cadena es: %d\n", strlen(cadena));
   // printf("La cadena normalizada es: %s\n", normalizar(cadena));
   // printf("El largo de la cadena normalizada es: %d\n", strle
}

char* calculoPalabras(char*cadena)
{
    char* p1=cadena; //Puntero de primera palabra al primer elemento de la cadena
    char *primerpalabra[TAM];
    while (*p1!='') //mientras p1 tenga alguna letra
    {
        p1++; //recorro el array con p1

    }

    char* p2=cad; //Puntero de segunda palabra al primer elemento de la cadena
    //p1--; //retrocedo un lugar para volver a preguntar

    while(*p1==*p2) //si son iguales recorrro con p2 el array
    {
        p2++;
    }


}
