
//Numeros Aleatorios en ANSI C

//necesitamos las librerias

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
*getRandomInt — returns a random int value
*/

int getRandomInt()
{
    int toret=0;

    srand(time(NULL));//inicializamos la semilla aleatoria utilizando la hora del sistema

    toret= (int) (rand());
    return toret;
}
