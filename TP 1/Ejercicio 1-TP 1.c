#include <stdio.h>

double fact (int);

int main()
{
    int n;
    double res;

    printf("ingrese numero a calcular el factorial: ");
    scanf("%d",&n);
    res=fact(n);

    printf("El factorial de %d es: %.0f", n, res); // .0f indica que muestre "res" sin decimales.
    printf("\n");
    return 0;

}

double fact (int n)
{
    int i;

    double acum = 1;
    if(n)  //Si el numero es 0 no entra al if y retorna acum = 1.
       for(i=1;i<=n;i++)
            acum *= i;  //
    return acum;
}
