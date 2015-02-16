/*Ejercicio 10


Construir un programa que lea un número natural N y calcule la suma de los
primeros N números naturales.*/


#include <stdio.h>


int suma_primeros_n(int);


int main()
{
    int numero;
    printf("/////////////Suma de los primeros N numeros naturales/////////////\n\n");
    do
    {
        printf("Ingrese Numero Natural:  ");
        scanf("%d",&numero);
    }
    while((suma_primeros_n(numero))==-1);
    printf("\n");
    return 0;
}


int suma_primeros_n(int n)
{
    int i=0,res=0;
    if(n<0)
        return -1;
    while(i<=n)
    {
        res+=i;
        i++;
    };
    printf("Resultado:  %d",res);
};




/*Version Alternativa


int suma_primeros_n(int n)
{
    float res=0;
    if(n<0)
        return -1;
    res=(((float)n/2)*((float)n+1));
    printf("Resultado:  %.0f",res);
};




*/
