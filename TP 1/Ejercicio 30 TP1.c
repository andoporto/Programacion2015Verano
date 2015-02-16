#include <stdio.h>
#include <stdlib.h>
#define FI 4
#define CO 4

void mostrarMenu();

void mostrarMatriz (int mat[][CO]);
void diagPrincipal (int mat[][CO]);
void diagSecundaria (int mat[][CO]);
void mostrarTrazaDiagonalPrincipal (int [][CO]);
void mostrarTrazaDiagonalSecundaria (int [][CO]);




int main()
{

    int mat[FI][CO]= {{1,0,0,2},
        {0,1,2,0},
        {0,2,1,0},
        {2,0,0,1},
    };
    int  menu;
    mostrarMenu();
    printf("\n");
    scanf("%d", &menu);
    switch(menu)
    {

    case 1:
        mostrarMatriz(mat);
        printf("\n");
        break;
    case 2:
        diagPrincipal(mat);
        printf("\n");
        break;
    case 3:
        diagSecundaria (mat);
        printf("\n");
        break;
    case 4:
        mostrarTrazaDiagonalPrincipal (mat);
        printf("\n");
        break;
    case 5:
        mostrarTrazaDiagonalSecundaria (mat);
        printf("\n");
        break;
    default:
        return 1;
    }
    return 0;
}

///////
void mostrarMenu(void)
{
    printf("\t \t \tMenu de opciones:\n"
           "\t \t \t-----------------\n"
           "1. Muestro matriz\n"
           "2. Ver diagonal principal\n"
           "3. Ver diagonal secundaria \n"
           "4. Calcular traza de diagonal principal \n"
           "5. Calcular traza de diagonal secundaria \n"
           "6. Salir \n");
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
                printf("%d", mat[i][FI-i-1]);
        }
    }

}
///////////

void mostrarTrazaDiagonalPrincipal (int m[][CO])
{
    int i;
    int acu=0;
    for(i=0; i<CO; i++)
        acu+=m[i][i];
    printf("\n La traza de la diagonal principal es: %d\n",acu);
}

void mostrarTrazaDiagonalSecundaria (int m[][CO])
{
    int i,j;
    int acu=0;
    for(i=0; i<CO; i++)
        acu+=m[i][CO-i-1];
    printf("\n La traza de la diagonal secundaria es: %d\n",acu);
}

void diagSecundaria (int m[][CO])
{
    int i;
    for(i=0; i<CO; i++)
            printf("\n\t%d\n",m[i][CO-i-1]);
}

