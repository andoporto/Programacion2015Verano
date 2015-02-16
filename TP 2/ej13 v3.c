#include <stdio.h>
#include <stdlib.h>
#define MSJ 1

// cambiar algo del archivo, los que cumplen este mes cambiarlo a mayuscula

typedef struct
{
    int dd,mm,aa;
} t_fecha;

typedef struct
{
    char nom[30];
    char ape[20];
    float sueldo;
    t_fecha fecha;
} t_reg;

int abrir_archivo (FILE**, char *, char *, int);
int cargarReg(t_reg *);
void mostrarReg(t_reg *);

int main()
{
    t_reg reg;
    FILE *pf;
    if (!abrir_archivo(&pf, "datos.bin", "w+b", MSJ))
        exit(1);
    while (cargarReg(&reg))
           fwrite(&reg, sizeof(t_reg),1, pf);
    fseek(pf,0l,0);
    fread(&reg, sizeof(t_reg),1, pf);
    while (!feof(pf))
    {

        mostrarReg(&reg);
        fread(&reg, sizeof(t_reg),1, pf);
    }
    fclose(pf);
    return 0;
}

int abrir_archivo(FILE **pf, char * nombre, char * modo, int msj)
{
    *pf= fopen(nombre, modo);
    if (!*pf && msj)
        printf("Error abriendo el archivo");
    return *pf !=NULL;
}
int cargarReg( t_reg * preg)
{
    int elec;
    printf("\nIngrese el nombre: ");
    gets(preg->nom);
    fflush(stdin);
    printf("\nIngrese el apellido: ");
    gets(preg->ape);
    fflush(stdin);
    printf("\nIngre la fecha de nacimiento: ");
    scanf("%d%d%d", &preg->fecha.dd, &preg->fecha.mm, &preg->fecha.aa);
    fflush(stdin);
    printf("\nIngrese el sueldo: ");
    scanf("%f", &preg->sueldo);
    fflush(stdin);
    printf(" \n¿Que quiere hacer?\n"
           "0. Dejar de ingresar\n"
           "1. seguir ingresando\n");
    scanf("%d", &elec);
    fflush(stdin);
    return elec;
}

void mostrarReg( t_reg * reg)
{
    printf("\nEl nombre y apellido es: %s %s", reg->nom, reg->ape);
    printf("\nEl sueldo es: %f", reg->sueldo);
    printf("\nLa fecha de nacimiento es: %d %d %d", reg->fecha.dd, reg->fecha.mm, reg->fecha.aa);
}
