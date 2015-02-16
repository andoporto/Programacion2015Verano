#include <stdio.h>
#include <stdlib.h>

void division(int,int);

int main()
{
    int a,b;
    printf("\n Ingrese un numero: ");
    scanf("%d",&a);
    do{
    printf("\n Ingrese un numero: ");
    scanf("%d",&b);
    } while (b==0);
    division(a,b);
    return 0;
}

void division(int dividendo,int divisor)
{
    int cociente, resto;
    cociente = dividendo / divisor;
    resto = dividendo % divisor;
    printf("\n El valor del cociente es: %d \n",cociente);
    printf("\n El valor del resto es: %d \n",resto);
}



