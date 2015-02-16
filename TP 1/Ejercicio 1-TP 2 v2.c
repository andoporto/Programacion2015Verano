#include <conio.h>
#include <stdio.h>


int calculo_factorial(int);
float calculo_numero_combinatorio(int, int);




 int main()
 {
    int m, n;
    float num_comb;
    puts("\n::::::CALCULO DEL NUMERO COMBINATORIO::::::");
    do
    {
        printf("\nRECUERDE QUE LOS NUMEROS A INGRESAR m Y n TIENEN QUE CUMPLIR CON LA SIGUIENTE REGLA"
               "\n\t::::::::::::::::::::::: m >= n  Y  n >= 0 :::::::::::::::::::::::");
        printf("\n\nIngrese el numero m: ");
        scanf("%d", &m);
        printf("\nIngrese el numero n: ");
        scanf("%d", &n);
    }
    while (!(m >= n  &&  n >= 0));
    num_comb = calculo_numero_combinatorio (m, n); //la funcion de num combinatorio podria ser entera porque nunca da con coma//
    printf("El numero combinatorio de %d sobre %d es: %.2f", m, n, num_comb);
    printf("\n");
	return 0;
 }






int calculo_factorial(int f)
{
    int fact;
    if(f == 0)
        return(1);
    else
    {
        fact = f * calculo_factorial (f-1);
        return (fact);
    }
}


float calculo_numero_combinatorio(int n1, int n2)
{
    float res;
    res = (calculo_factorial(n1) / (calculo_factorial(n2) * (calculo_factorial(n1 - n2))));
    return (res);
}
