#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libtp2ej13.h"

void crearArchivoEmpEstAuto()
{
    FILE *pemp, *pest; //punteros a archivos

    //Carga empleados
    t_empleado empleado[]= { {35777888,"Albondiga","Jose",10000.8},
        {30999444,"Crack","Soledad",23000.9},
        {28444222,"Espatula","Carlos",15800.3},
        {39555111,"Guido","Tamara",19500.5},
        {29666444,"Indigo","Sofia",30400.6},
        {39444777,"Koala","Martin",25800.9},
        {31444333,"Koala","Tamara",11000.9},
        {33888999,"Massa","Pedro",80000.3},
        {35999888,"Massa","Pedro",35000.7},
        {38444555,"Plancha","Mara",201000.9}
    };

    //Carga estudiantes
    t_estudiante estudiante[]= { {33222111,"Almacen","Teresa",8},
        {35888666,"Babilonia","Juan",9.3},
        {30999444,"Crack","Soledad",8.9},
        {24555666,"Finca","Carlos",7.2},
        {39999666,"Guido","Tamara",7},
        {39444777,"Koala","Martin",6},
        {31444333,"Koala","Tamara",9},
        {35999888,"Massa","Pedro",8}
    };

    pemp=fopen("empleado.bin", "wb");
    pest=fopen("estudiantes.bin", "wb");

    fwrite(&empleado, sizeof(t_empleado),10,pemp); //graba 10 registros
    fwrite(&estudiante,sizeof(t_estudiante),8,pest); //graba 8 registros

    fclose(pemp);
    fclose(pest);
}

int crearArchivosManual(FILE** pemp,FILE** pestud)
{
    t_empleado empleado;
    t_estudiante estudiante;

    *pemp=fopen("empleado.bin", "wb");
    *pestud=fopen("estudiantes.bin", "wb");

    if(!*pemp || !*pestud)
    {
        puts("ERROR AL ABRIR ARCHIVOS");
        exit(2);
    }

    while(cargaRegEmpleado(&empleado))
        fwrite(&empleado,sizeof(t_empleado),1,*pemp);

    while(cargaRegEstudiante(&estudiante))
        fwrite(&estudiante,sizeof(t_estudiante),1,*pestud);

    fclose(*pemp);
    fclose(*pestud);

    return(1);
}

int cargaRegEmpleado(t_empleado* emp)
{
    char resp;

    system("cls");
    puts("ARCHIVO DE EMPLEADOS");
    puts("Desea cargar un nuevo registro?");
    fflush(stdin);
    scanf("%c", &resp);

    if('n'==resp)
        return 0;

    puts("Ingrese DNI");
    scanf("%ld", &(emp->dni));

    puts("Ingrese Apellido");
    fflush(stdin);
    fgets(emp->apellido, sizeof(emp->apellido), stdin);

    puts("Ingrese Nombre");
    fflush(stdin);
    fgets(emp->nombre, sizeof(emp->nombre), stdin);

    puts("Ingrese Sueldo");
    scanf("%lf", &emp->sueldo);

    return 1;
}

int cargaRegEstudiante(t_estudiante* est)
{
    char resp;

    system("cls");
    puts("ARCHIVO DE ESTUDIANTES");
    puts("Desea cargar un nuevo registro?");
    fflush(stdin);

    scanf("%c", &resp);

    if('n'==resp)
        return 0;

    puts("Ingrese DNI");
    scanf("%ld", &(est->dni));

    puts("Ingrese Apellido");
    fflush(stdin);
    fgets(est->apellido, sizeof(est->apellido), stdin);

    puts("Ingrese Nombre");
    fflush(stdin);
    fgets(est->nombre, sizeof(est->nombre), stdin);

    puts("Ingrese promedio");
    scanf("%f", &est->promedio);

    return 1;
}

int comparaApNomYDni(t_empleado* empleado,t_estudiante* estudiante)
{
    int comp;

    comp=strcmp(empleado->apellido, estudiante->apellido);
    if(0==comp)
        comp=strcmp(empleado->nombre, estudiante->nombre); //compara nombre
    if(0==comp)
        comp=empleado->dni-estudiante->dni; //compara dni
    return (comp>0)?1:(comp<0)? -1: 0;
}

void mostrarArchivos(FILE**pemp, FILE**pest)
{
    t_empleado empleado;
    t_estudiante estudiante;

    fseek(*pemp,0,SEEK_SET); //vuelve al inicio
    fseek(*pest,0,SEEK_SET); //vuelve al inicio

    fread(&empleado, sizeof(t_empleado),1,*pemp); //lee un registro
    fread(&estudiante,sizeof(t_estudiante),1,*pest); //lee un registro

    puts("ARCHIVO DE EMPLEADOS");

    while(!feof(*pemp))
    {
        //muestra a cada empleado
        printf("%ld\t%s %s\t%.2lf\n",  empleado.dni,empleado.apellido,empleado.nombre,empleado.sueldo);
        fread(&empleado, sizeof(t_empleado),1,*pemp);
    }

    puts("ARCHIVO DE ESTUDIANTES");
    while(!feof(*pest))
    {
        printf("%ld\t%s %s\t%.2f\n", estudiante.dni,estudiante.apellido,estudiante.nombre,estudiante.promedio);
        fread(&estudiante,sizeof(t_estudiante),1,*pest);  //lee el siguiente registro
    }

    fseek(*pemp,0,SEEK_SET); //vuelve al inicio
    fseek(*pest,0,SEEK_SET); //vuelve al inicio
}
