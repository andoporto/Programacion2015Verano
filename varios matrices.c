#include <stdio.h>
#include <stdlib.h>
#define FI 5
#define CO 5

void mostrarMenu();
void cargarMatriz(int mat[][CO]);
void mostrarMatriz (int mat[][CO]);
void diagPrincipal (int mat[][CO]);
void diagSecunadria (int mat[][CO]);
void primerTriangulo(int mat[][CO]);
void segundoTriangulo(int mat[][CO]);
void numerosVecinos(int mat[][CO]);

int main()
{

    int mat[FI][CO]={{1,2,3,4,21},
                     {5,6,7,8,22},
                     {9,10,11,12,23},
                     {13,14,15,16,24},
                     {17,18,19,20,25}},
        menu;
    mostrarMenu();
    printf("\n");
    scanf("%d", &menu);
    switch(menu)
    {
        case 1: cargarMatriz(mat);
                printf("\n");
                break;
        case 2: mostrarMatriz(mat);
                printf("\n");
                break;
        case 3: diagPrincipal(mat);
                printf("\n");
                break;
        case 4: diagSecunadria (mat);
                printf("\n");
                break;
        case 5: primerTriangulo(mat);
                printf("\n");
                break;
        //case 6: segundoTriangulo(mat);
               // break;
        case 7: numerosVecinos(mat);
                printf("\n");
                break;
        default: return 1;
    }
    return 0;
}

///////
void mostrarMenu(void)
{
    printf("\t \t \tMenu de opciones:\n"
           "\t \t \t-----------------\n"
           "1. Cargar matriz\n"
           "2. Muestro matriz\n"
           "3. Ver diagonal principal\n"
           "4. Ver diagonal secundaria \n"
           "5. Ver primer triangulo (superior) \n"
           //"6. Ver segundo triangulo (derecho) \n"
           "7. Ver numeros vecinos \n"
           "15. Salir \n");
}

//////
void cargarMatriz(int mat[FI][CO])
{
    int i,
        j;
    printf("Ingrese los numeros que desea cargar: \t");
    for(i=0; i<FI; i++)
    {
        for(j=0; j<CO; j++)
            {
                printf("\nFila %d Columna %d \t ", i, j);
                scanf("%d", &mat[i][j]);
            }
    }
}

///////
void mostrarMatriz (int mat[FI][CO])
{
    int i,
        j;
    for(i=0; i<FI; i++)
    {
        printf("\n");
        for(j=0; j<CO; j++)
        {
            printf("%d \t", mat[i][j]);
        }
    }
}
/////////
void diagPrincipal (int mat[][CO])
{
    int i,
        j;
    for(i=0; i<FI; i++)
    {
        printf("\n");
        for(j=0; j<CO; j++)
        {
            printf("\t");
            if(i==j)
                printf("%d", mat[i][j]);
        }
    }

}
/////////
void diagSecunadria (int mat[][CO])
{
    int i;

    printf("\nLos numeros son:\n");
    for(i=0; i<FI; i++)
    {
        printf("%d \t", mat[i][FI-i-1]);
    }
}

////////////
void primerTriangulo(int mat[][CO])
{
    int i,
        j;
    if( FI == 2 && CO == 2)
        printf("No existen numeros en el triangulo superior debido al tamano de la matriz \n");
    else
    {
        printf("\nLos numeros son: \n");
        for(i=0; i<FI; i++)
            for(j=i+1; j<FI-1-i; j++)
                printf("%d \t", mat[i][j]);
    }

}
//////////

//////
void numerosVecinos(int mat[][CO])
{
    int fila,
        columna,
        i,
        j;
    printf("Ingrese la FILA del numero que desea calcularle sus vecinos: \t");
    scanf("%d", &fila);
    printf("Ingrese la COLUMNA del numero que desea calcularle sus vecinos: \t");
    scanf("%d", &columna);

    printf("Los vecinos del numero %d son: \n", mat[fila-1][columna-1]);

    {
        for(i=fila-2; i<=fila && i<=FI-1; i++)
            for(j=columna-2; j<=columna && j<=CO-1; j++)
                {
                    if(i!=fila-1 || j!=columna-1)
                        printf("%d \t", mat[i][j]);
                }
    }
}
