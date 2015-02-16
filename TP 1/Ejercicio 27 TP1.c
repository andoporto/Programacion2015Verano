#include <stdio.h>
#include <stdlib.h>
#define aMayusc(X)((X)>='a'&&(X)<='z'?(X)-32:(X))
#define TAM 20

int palindromo (char*);

int main()
{
    char cad[TAM];
    printf("Ingrese una cadena: ");
    gets(cad);
    if (palindromo(cad))
        printf ("\n La cadena es un palindromo");
    else
        printf ("\n La cadena no es un palindromo");
    printf ("\n");
    return 0;
}

int palindromo (char* cad)
{
    char *pinicial,*pfinal;
    pinicial=pfinal=cad;
    if (!*cad)      // Por si la cadena esta vacia
        return 0;
    while (*pfinal) //Llevo el puntero pfinal hasta el final de la cadena
    {
        pfinal++;
    }
    pfinal--; //Retrocedo una posicion por que despues del while me dejo el puntero en \0
    while (pinicial<pfinal)  //Recorre hasta la mitad, para no comprarar de nuevo la 2da parte de la cadena
    {
        if (aMayusc(*pinicial) != aMayusc(*pfinal))  //A la primera que encuentra un caracter que no sea igual, sale de la funcion
            return 0;
        pinicial++;
        pfinal--;
    }
    return 1;
}
