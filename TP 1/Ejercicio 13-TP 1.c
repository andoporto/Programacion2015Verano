/*Ejercicio 13


Construir un programa que determine
si un número natural es primo.*/


#include <stdio.h>


int esPrimo(int);


int main()
{
    int valor = 0;

    printf("\nIngrese un valor para verificar si es primo: ");
    fflush(stdin);
    scanf("%d", &valor);

    printf("\n%d ", valor);
    if (!esPrimo(valor)) {
        printf("no ");
    }
    printf("es primo.");
        printf("\n");
    return 0;
}

int esPrimo(int valor)
{
    int i = 0;

    for (i = valor-1; i > 1; i--) {
        if (0 == (valor%i)) {
            return 0;
        }
    }

    return 1;
}



