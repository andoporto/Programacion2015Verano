#include <stdio.h>
#include <math.h>

int factorial(int);
double exponencial(int, float);

int main(void)
{
    float tol=0.1; //original 0.01
    int exponente;

    printf("\nIntroduzca el exponente: ");
    scanf("%d",&exponente);
    printf("\n e elevado a %d es: %f",exponente,exponencial(exponente,tol));
    printf("\n");
    return 0;
}
///////////////// funcion exponencial ///////////////
double exponencial(int x,float tol)
{
    double pot=tol,numerador=1.0,potencia=1.0,denominador=1;
    int n=1,bandera=0;
    if (x<0)
    {
        x=-x;
        bandera=1;
    }
    while(pot>=tol)
    {
        numerador*=x;
        denominador*=n;
        pot=(numerador/denominador);
        potencia += pot;
        n++;
    }
    if(bandera==1)
        return(1/potencia);
    else
        return(potencia);
}

