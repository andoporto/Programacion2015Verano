/*Ejercicio 5

En la serie de Fibonacci, cada término es la suma de los dos anteriores y los
dos primeros términos son 1
Serie: 1 1 2 3 5 8 13 21 34 ...
Desarrollar una función para determinar si un entero pertenece a la serie de
Fibonacci. */

#include <stdio.h>
#include <conio.h>

////////////Declaracion de Funciones//////////////

void fibonacci(int);

//////////////MAIN/////////////////

int main()
{
    int numero;
    printf("Ingrese un numero entero: ");
    scanf("%d",&numero);
    fibonacci(numero);
    printf("\n");
    return 0;
}

////////////////Funciones/////////////////

void fibonacci(int num)
{
    int fib_pri=1,fib_seg=1,res=1;
    while(num!=res&&res<=num)
    {
        res=fib_pri+fib_seg;
        fib_pri=fib_seg;
        fib_seg=res;
    };
    res==num?(printf("El numero pertenece a la secuencia Fibobacci")):(printf("El numero no pertenece a la secuencia Fibonacci"));
};

/////////////////fin////////////////
