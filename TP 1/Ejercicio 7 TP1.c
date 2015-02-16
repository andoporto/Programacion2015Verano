/*Ejercicio 7

Desarrollar una función que determine si un número natural es perfecto,
deficiente o abundante.*/

//////////////////////////////

#include <stdio.h>

/////////////////////

void clasificar_natural();

/////////MAIN?///////////

int main()
{
    clasificar_natural();
    printf("\n");
    return 0;
}

//////////Funciones//////////////

void clasificar_natural()
{
    int numero,i,resultado=0;
    do{
        printf("Ingrese Numero Natural a Clasificar: ");
        scanf("%d",&numero);
    }while(numero<0);
    for(i=1;i<numero;i++)
        {
            numero%i==0?(resultado+=i):(resultado);
        };
    printf("\nNUMERO ");
    resultado==numero?(printf("PERFECTO")):(resultado>numero?(printf("ABUNDANTE")):(printf("DEFICIENTE")));
};

//////////////fin//////////////
