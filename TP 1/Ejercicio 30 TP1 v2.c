#include <stdio.h>
#include <stdlib.h>
#define FI 4
#define CO 4

void mostrarMenu();
void cargarMatriz(int mat[][CO]);
void mostrarMatriz (int mat[][CO]);
void diagPrincipal (int mat[][CO]);
void diagSecundaria (int mat[][CO]);
void primerTriangulo(int mat[][CO]);
void segundoTriangulo(int mat[][CO]);
void numerosVecinos(int mat[][CO]);

int main()
{

   int mat[FI][CO]={{0,0,0,0,0},
                     {0,0,0,0,0},
                     {0,0,0,0,0},
                     {0,0,0,0,0},
                   };
      int  menu;
    mostrarMenu();
    printf("\n");
    scanf("%d", &menu);
    switch(menu)
    {
        case 1: cargarMatriz(mat);
                printf("\n");
                //break;
        case 2: mostrarMatriz(mat);
                printf("\n");
                break;
        case 3: diagPrincipal(mat);
                printf("\n");
                break;
        case 4: diagSecundaria (mat);
                printf("\n");
                break;

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
void diagSecundaria (int mat[][CO])
{
   {
    int i,
        j;
    for(i=0; i<FI; i++)
    {
        printf("\n");
        for(j=0; j<CO; j++)
        {
            printf("\t");
            if(FI<CO-1)
                printf("%d", mat[i][j]);
        }
    }

}




