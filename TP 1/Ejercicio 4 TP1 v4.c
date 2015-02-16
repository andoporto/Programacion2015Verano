#include <conio.h>
#include <stdio.h>

double calculo_raiz_cuadrada (const double*, const double*);

int main()
{
    double a, tol,raiz;
    puts("\n::::::RAIZ CUADRADA::::::");
    do
    {
        printf("\nIngrese el numero al cual desea calcularle la raiz cuadrada//RECUERDE QUE EL NUMERO DEBE SER ENTERO POSITIVO// \n");

        scanf("%lf", &a);
    }
    while(!(a >= 0));
	
    do
    {
        printf("\nIngrese una tolerancia//RECUERDE QUE A MENOR TOLERANCIA MAYOR EXACTITUD, VALORES ENTEROS O DECIMALES// \n");

        scanf("%lf", &tol);
    }
    while (tol <= 0);
    raiz = calculo_raiz_cuadrada(&a, &tol);
    printf("\nLa raiz cuadrada de %lf \n con una tolerancia de %.10lf es: %.10lf", a, tol, raiz);
    printf("\n");
    return 0;
}




double calculo_raiz_cuadrada(const double *p_a, const double *p_tol)
{
    if (*p_a == 0)
        return(0);
    else
    {
        double raiz = *p_a, t = *p_tol;
        while (t != raiz)
        {
            t = raiz;
            raiz = (*p_a/raiz + raiz)/2;
        }
        return raiz;
    }
}
