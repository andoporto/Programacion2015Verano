#include <stdio.h>
#include <math.h>

int multiplicacionRusa(int , int );

int main()
{
    system("cls");
    int a,b,valor;
    printf("\n Ingrese un numero: ");
    scanf("%d",&a);
    printf("\n Ingrese un numero: ");
    scanf("%d",&b);
    valor= multiplicacionRusa(a,b);
    printf("\n El valor de la multiplicacion rusa vale: %d",valor);
    printf("\n");
    return 0;
}

int multiplicacionRusa(int valor1, int valor2)
{
    int resultado = 0;

    while (1 != valor1) {
        if (1 == (valor1%2)) {
            resultado += valor2;
        }

        valor1 /= 2;
        valor2 *= 2;
    }

    return resultado+valor2;
}
