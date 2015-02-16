#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a , b, suma,i, producto;
    suma = 0;
    producto = 0;
    printf("\n Ingrese un numero: ");
    scanf("%d",&a);
    printf("\n Ingrese un numero: ");
    scanf("%d",&b);
    suma=b;
    for (i=0;i<suma ;i++ )
    {
        producto = producto+ a;
    }
    printf("\n El valor del producto es: %d \n",producto);
    return 0;
}
