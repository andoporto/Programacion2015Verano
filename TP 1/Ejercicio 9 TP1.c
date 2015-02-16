/*Ejercicio 9


Dados dos números naturales A y B, desarrollar una función para obtener el
cociente entero A/B y el resto. (A puede ser 0; B, no).*/


#include <stdio.h>


int division_por_resto(int,int);


///////////MAIN//////////


int main()
{
    int numero_a,numero_b;
    printf("/////////////Division/////////////\n\n");
    do{
        printf("Ingrese Numero A:   ");
        scanf("%d",&numero_a);
        printf("\nIngrese Numero B:    ");
        scanf("%d",&numero_b);
    }while((division_por_resta(numero_a,numero_b)==-1));
    printf("\n");
    return 0;
}


//////////Funciones////////////


int division_por_resta(int a, int b)
{
    int resto=a,i=0;
    if(a<0||b<=0)
        return -1;
    while(resto>=b)
    {
        resto=resto-b;
        i++;
    };
    printf("\n\nCociente:  %d\nResto:  %d",i,resto);
    return 1;
}
