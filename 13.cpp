#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    char apellido[21];
    char nombre[21];
    float prosuel;
};

void crearchivos(int tipo, char *nombre);
void actualizar(char *, char *, float suel);
void mostrarchivo(int tipo, char *nombre);

int main()
{
    int opc;
    float suel;
    do
    {
        //clrscr();
        printf("\n\n\t<<< Opciones >>>");
        printf("\n\n\t1.Crear archivo estudiantes\n");
        printf("\n\t2.Crear archivo empleados\n");
        printf("\n\t3.Actualizar archivo empleados\n");
        printf("\n\t4.Mostrar archivo estudiantes\n");
        printf("\n\t5.Mostrar archivo empleados\n");
        printf("\n\t0.Salir");
        printf("\n\n\t--------------------------------------------------------");
        printf("\n\n\tOpcion numero:\t");
        scanf("%d", &opc);
        fflush(stdin);
        switch (opc)
        {
        case 1:
        {
            crearchivos(0, "estudiantes.dat");
            break;
        }
        case 2:
        {
            crearchivos(1, "empleados.dat");
            break;
        }
        case 3:
        {
           // clrscr();
            printf("\n\tIngrese el importe que se le sumara al sueldo a los empleados que ");
            printf("\n\n\tademas sean estudiantes y posean promedio mayor a 7:\t\t");
            scanf("%f", &suel);
            actualizar("empleados.dat", "estudiantes.dat", suel);
            break;
        }
        case 4:
        {
            mostrarchivo(0, "estudiantes.dat");
            break;
        }
        case 5:
        {
            mostrarchivo(1, "empleados.dat");
            break;
        }
        default:
        {
            break;
        }
        }
    }
    while (opc != 0);
}

void crearchivos(int tipo, char *nombre)
{
    FILE *fp;
    info datos;
    fp = fopen(nombre, "wb");
    clrscr();
    printf("\n\tIngrese Apellido (Para terminar >>> \"0\"):\t");
    gets(datos.apellido);
    while(strcmpi(datos.apellido,"0"))
    {
        printf("\n\tIngrese Nombre:\t\t\t\t\t");
        gets(datos.nombre);
        if(tipo)
            printf("\n\tIngrese Sueldo:\t\t\t\t\t");
        else
            printf("\n\tIngrese Promedio:\t\t\t\t");
        scanf("%f", &datos.prosuel);
        fflush(stdin);
        fwrite(&datos, sizeof(datos), 1, fp);
        clrscr();
        printf("\n\tIngrese Apellido (Para terminar >>> \"0\"):\t");
        gets(datos.apellido);
    }
    fclose(fp);
}


void actualizar (char *archiempleados, char *archiestudiantes, float suel)
{
    char nomemp[42], nomest[42];
    int comp;
    FILE *archivoemp, *archivoest;
    info est, emp;
    archivoemp = fopen(archiempleados, "rb+");
    archivoest = fopen(archiestudiantes, "rb");

    clrscr();
    fread(&emp, sizeof(emp), 1, archivoemp);
    fread(&est, sizeof(est), 1, archivoest);

    while(!feof(archivoemp) && !feof(archivoest))
    {
        strcpy(nomemp, emp.apellido);
        strcat(nomemp, emp.nombre);
        strcpy(nomest, est.apellido);
        strcat(nomest, est.nombre);
        comp = strcmpi(nomemp, nomest);
        if (comp < 0)  // 'emple' <= 'estud'
            fread(&emp, sizeof(emp), 1, archivoemp);
        else
        {
            if (comp == 0)
            {
                if(est.prosuel > 7)
                {
                    fseek(archivoemp, -1L*sizeof(emp) , 1);
                    emp.prosuel += suel;
                    fwrite(&emp, sizeof(emp), 1, archivoemp);
                    fseek(archivoemp, 0L*sizeof(emp), 1);
                }
                fread(&emp, sizeof(emp), 1, archivoemp);
                fread(&est, sizeof(est), 1, archivoest);
            }
            else
            {
                fread(&emp,sizeof(emp),1,archivoemp);
            }
        }
    }
    fcloseall();
}

void mostrarchivo(int tipo, char *nombre)
{
    FILE *fp;
    info datos;
    fp = fopen(nombre, "rb");
    clrscr();
    fread(&datos, sizeof(datos), 1, fp);
    while(!feof(fp))
    {
        if(tipo)
        {
            printf("\n\tApellido:\t%s", datos.apellido);
            printf("\n\n\tNombre:\t\t%s", datos.nombre);
            printf("\n\n\tSueldo:\t\t$ %.2f\n", datos.prosuel);
            fread(&datos, sizeof(datos), 1, fp);
        }
        else
        {
            printf("\n\tApellido:\t%s", datos.apellido);
            printf("\n\n\tNombre:\t\t%s", datos.nombre);
            printf("\n\n\tPromedio:\t%.2f\n", datos.prosuel);
            fread(&datos, sizeof(datos), 1, fp);
        }
    }
    printf("\n\t--------------------------------------------------------");
    printf("\n\n\tPresione ENTER para continuar");
    getchar();
    fclose(fp);
}

