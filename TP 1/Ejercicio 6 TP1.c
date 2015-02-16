/*Ejercicio 6

Desarrollar una función que obtenga el seno de X con tolerancia TOL.*/

//////////////////////////////
/*
A partir de una cantidad de terminos cambia el numero drasticamente en vez de darle mas precision al resultado (Ej: Seno(5)=0.0871... al hacerlo con esta funcion a partir de x^9/9! el resultado cambia a -0.95) Agregue unos printf para poder verlo.

¿Qué me estoy olvidando?
*/
/////////////////////////////

#include <stdio.h>
#include <math.h>
#include <conio.h>

//////////////////////////////
void funcion_seno(int,float);

/////////////MAIN/////////////////

int main()
{
    int num;
    float tolerancia;
    printf("Sen(x) \t Ingrese el valor de x: ");
    scanf("%d",&num);
    printf("Tolerancia:");
    scanf("%f",&tolerancia);
    funcion_seno(num,tolerancia);
    printf("\n");
    return 0;
}

//////////////Funciones////////////////

void funcion_seno(int x,float tol)
{
    int i=3,b=2;
    double seno=x,numerador=x,denominador=1,termino=1;
    while((fabs(termino))>=tol)
    {
        printf("\nSeno +termino:%f",seno);
        termino=((numerador*=(x*x))/(denominador*=(i*(i-1))));
        printf("\nNumerador:  %f\nDenominador:    %f",numerador,denominador);
        b%2==0?(termino=-termino):(termino);
        b++;
        printf("\nTermino:    %0.10f\n",termino);
        seno+=termino;

        i+=2;
    }
    printf("Seno(%d)=%.10f",x,seno);
};

////////////////fin//////////////////////
