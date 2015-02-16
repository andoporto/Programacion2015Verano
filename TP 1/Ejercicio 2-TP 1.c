/* Ejercicio 2

Desarrollar una función para calcular el combinatorio m sobre n.

*/

#include <stdio.h>
#include <conio.h>

///////////////////////Prototipos/////////////////////////

int validar(int,int);
double factorial(int);
double numero_combinatorio(int,int);

//////////////////////MAIN//////////////////////////

int main()
{
    int num_m,num_n;
    do
    {
        printf("Ingrese Numero N ");
        scanf("%d",&num_n);
        system("cls");
        printf("Ingrese Numero M: ");
        scanf("%d",&num_m);
        system("cls");
    }while(validar(num_m,num_n)==0); //Creo que podria haberme ahorrado la funcion
    printf("El Numero Combinatorio es: %.0f",(numero_combinatorio(num_m,num_n)));
    getch();
}

////////////////Funciones////////////////

int validar(int m, int n)
{
    return (n>=0? (m>=n? 1 : 0) : 0); //Para validar las condiciones
}

//////

double factorial (int num)
{
    double aux=1,i;
    if(num>0)
    {
        for(i=1;i<=num;i++)
        {
            aux=aux*i;
        };
    };
    return aux;
};

////////

double numero_combinatorio (int m,int n)
{
    return((factorial(m))/((factorial(n))*(factorial(m-n))));
}

///////////////FIN/////////////
