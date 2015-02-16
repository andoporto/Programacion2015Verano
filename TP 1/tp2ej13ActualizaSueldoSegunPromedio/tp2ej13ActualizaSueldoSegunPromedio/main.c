#include <stdio.h>
#include <stdlib.h>
#include "libtp2ej13.h"

int main()
{
    char archExis;
    int comp;
    FILE *pemp, *pestud;
    t_empleado empleado;
    t_estudiante estudiante;

    crearArchivoEmpEstAuto();
    ///Bloque de creacion de archivo
    /*do{ puts("Desea crear archivos nuevos? s/n");
        scanf("%c", &archExis);
        }while(archExis!='s' && archExis!='n');

    if('s'==archExis)
        crearArchivosManual(&pemp, &pestud);*/

    ///Apertura de archivo
    pemp=fopen("empleado.bin", "r+b");
    pestud=fopen("estudiantes.bin", "rb");

    if(!pemp || !pestud)
    {
        puts("ERROR AL ABRIR ARCHIVO");
        exit(1);
    }

    mostrarArchivos(&pemp, &pestud);

    ///Bloque de proceso de archivo
    fread(&empleado, sizeof(t_empleado),1,pemp);
    fread(&estudiante,sizeof(t_estudiante),1,pestud);

    while(!feof(pemp) && !feof(pestud))
    {
        comp=comparaApNomYDni(&empleado, &estudiante);

        if(0==comp) //iguales
        {
            if(estudiante.promedio>=7)
            {
                empleado.sueldo*=1.0728;
                fseek(pemp, -1L*sizeof(t_empleado), SEEK_CUR);
                fwrite(&empleado,sizeof(t_empleado),1,pemp);
                fseek(pemp,0, SEEK_CUR);
            }
            fread(&empleado, sizeof(t_empleado),1,pemp);
            fread(&estudiante,sizeof(t_estudiante),1,pestud);
        }

        if(comp<0) //emp<est -1
            fread(&empleado, sizeof(t_empleado),1,pemp);

        if(comp>0) //emp>est 1
            fread(&estudiante,sizeof(t_estudiante),1,pestud);
    }

    mostrarArchivos(&pemp, &pestud);

    fclose(pemp);
    fclose(pestud);
    printf("\n");
    return 1;
}
