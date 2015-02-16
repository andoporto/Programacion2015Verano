#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,suma;
    suma=0;
    printf("\n Ingrese un numero: ");
    scanf("%d",&n);
    for (i=0;i<=n ;i++ )
    {
        suma = suma + i;
    }
    printf("\n El valor de la suma es: %d \n",suma);
    return 0;
}
