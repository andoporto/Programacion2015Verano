
#include <stdio.h>
#include <math.h>

void calcularParteEntera();

int main()
{
    system("cls");
    calcularParteEntera();
    printf("\n");
    return 0;
}


void calcularParteEntera()
{
    //float valor = 0.f;
    float valor = 0;
    printf("\nIngrese un valor para calcular su parte entera: ");
    fflush(stdin);
    scanf("%f", &valor);

    printf("\nLa parte entera de %.2f es %.0f",valor,floor(valor));
}
