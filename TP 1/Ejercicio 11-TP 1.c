/*Ejercicio 11


Construir un programa que lea un n�mero natural N y calcule la suma de los
primeros N n�meros naturales pares.*/


#include <stdio.h>


int suma_primeros_n_pares(int);


int main()
{
    int numero;
    printf("/////////////Suma de los primeros N numeros naturales pares/////////////\n\n");
    do
    {
        printf("Ingrese Numero Natural:  ");
        scanf("%d",&numero);
    }
    while((suma_primeros_n_pares(numero))==-1);
    printf("\n");
    return 0;
}


int suma_primeros_n_pares(int n)
{
    int i=0,res=0;
    if(n<0)
        return -1;
    while(i<=n  )
    {
        if(i%2==0)
            res+=i;
        i++;
    };
    printf("Resultado:  %d",res);
};


