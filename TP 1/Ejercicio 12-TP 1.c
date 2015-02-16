/*Ejercicio 11


Construir un programa que lea un número natural N y calcule la suma de los
primeros N números naturales pares.*/


#include <stdio.h>


int suma_primeros_n_pares_menores(int);


int main()
{
    int numero;
    printf("/////////////Suma de los numeros naturales pares menores a N/////////////\n\n");
    do
    {
        printf("Ingrese Numero Natural:  ");
        scanf("%d",&numero);
    }
    while((suma_primeros_n_pares_menores(numero))==-1);
    printf("\n");
    return 0;
}


int suma_primeros_n_pares_menores(int n)
{
    int i=0,res=0;
    if(n<0)
        return -1;
    while(i<n )
    {
        if(i%2==0)
            res+=i;
        i++;
    };
    printf("Resultado:  %d",res);
};


