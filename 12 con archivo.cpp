#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define M 3
#define N 50
#define C 2

int main ()
{
    char nombre [M][N]= {"\0"};
    float nota[M][C];
    int i, j, c=0;
    float sum, prom[M];
    FILE *arch;

    arch=fopen("cristian.dat", "wb");

    for(i=0; i<M; i++)

    {
        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        fgets(nombre[i], N, stdin);
        fflush(stdin);
        for (j=0; j<C; j++)
        {
            printf("Ingrese las notas: ");
            scanf("%f", &nota[i][j]);
        }
    }

    for(i=0; i<M; i++)
    {
        sum=0;
        for (j=0; j<C; j++)
        {
            sum+=nota[i][j];
        }
        prom[i]=(sum/C);
    }

    while(!feof(arch) && c<M)
    {
        fwrite(nombre[c], sizeof(char), N, arch);
        fwrite(&prom[c], sizeof(float), N, arch);
        c++;
    }


    fclose(arch);

    system("cls");
    printf("APELLIDO Y NOMBRE\t\t\tNOTAS\t\t\tPROMEDIO\n");
    printf("________________________________________________________________________\n");

    for (i=0; i<M; i++)
    {
        printf("%s\t\t\t", nombre [i]);

        for (j=0; j<C; j++)
        {
            printf ("%.2f\t\t\t", nota [i][j]);
        }

        printf ("%.2f\n", prom[i]);
    }

   return 0;
}


