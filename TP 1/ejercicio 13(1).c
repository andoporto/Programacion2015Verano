#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dni;
    char nombre[50];
    char apellido[50];
    double sueldo;
} t_empleado;

typedef struct{
    int dni;
    char nombre[50];
    char apellido[50];
    float promedio;
} t_alumno;


int main()
{
    CrearArchivo();

    FILE *pAlumno, *pEmpleado;
    t_alumno alumno;
    t_empleado empleado;

    if(!abrirArchivo(&pAlumno, "estudiantes", "rb", 1) || !abrirArchivo(&pEmpleado, "empleados", "r+b", 1))
    {
        fclose(pAlumno);
        fclose(pEmpleado);
        exit(1);
    }

    //Si cualquiera de las 2 se queda sin registros ya no voy a actualizar nada.
    fread(&empleado, sizeof(t_empleado), 1, pEmpleado);
    fread(&alumno, sizeof(t_alumno), 1, pAlumno);
    while(!feof(pEmpleado) && !feof(pAlumno))
    {
        int comparacion = compararRegistros(&empleado, &alumno);
        if(comparacion == 0)
        {
            if(alumno.promedio > 7)
                actalizarRegistros(&empleado, &pEmpleado);
            fread(&empleado, sizeof(t_empleado), 1, pEmpleado);
            fread(&alumno, sizeof(t_alumno), 1, pAlumno);
        }
        else
        {
            if(comparacion > 0)
                fread(&alumno, sizeof(t_alumno), 1, pAlumno);
            else
                fread(&empleado, sizeof(t_empleado), 1, pEmpleado);
        }
    }

    fclose(pEmpleado);
    fclose(pAlumno);

    mostrarArchivo();

    return 0;
}

void mostrarArchivo()
{
    FILE *fpEmp=fopen("empleados", "rb");
    t_empleado empleado;
    fread(&empleado, sizeof(t_empleado), 1, fpEmp);
    while(!feof(fpEmp))
    {
        printf("DNI: %d\n", empleado.dni);
        printf("Apellido: %s\n", empleado.apellido);
        printf("Nombre: %s\n", empleado.nombre);
        printf("Sueldo: %f\n\n", empleado.sueldo);
        fread(&empleado, sizeof(t_empleado), 1, fpEmp);
    }
    fclose(fpEmp);
}

void CrearArchivo()
{
    FILE *fpEst=fopen("estudiantes","wb");
    FILE *fpEmp=fopen("empleados", "wb");
    t_alumno reg []={{33,"DDD","AAA", 7.1 },
                    {48,"DDE","AAA", 7 },
                    {50,"DDD","AAB", 8.5},
                    {54,"DDE","ABB", 2 },
                    {555,"DDD","BBB", 6},
                    {777,"DDD","BBB", 9},
                    {778,"DDD","BBB", 4 },
                    {344,"DDD", "CCC", 8},
                    {89,"DDE", "CCC", 7.1},
                    {43,"DDF", "CCC",6.70}};

    t_empleado reg_2 []={{30,"DDD","AAA", 6000 },
                    {33,"DDD","AAA", 5700 }, //El sueldo debe cambiar a:9849.6
                    {50,"DDD","AAB", 8300 }, //El sueldo debe cambiar a:14342.4
                    {58,"DDD","BBB", 2000 },
                    {777,"DDD","BBB", 2780}, //El sueldo debe cambiar a:4803.84
                    {778,"DDD","BBB",6590},
                    {80,"DDE","CCC", 9000 },
                    {89,"DDE","CCC", 4500 },//El sueldo debe cambiar a:7776
                    {344,"FFF", "CCC", 7150},
                    {400,"FFF", "CCC", 7000}};

    if(fpEmp!=NULL )
    {
        fwrite(reg_2, sizeof(reg_2),1,fpEmp);
        fclose(fpEmp);
    }

    if(fpEst!=NULL)
    {
        fwrite(reg, sizeof(reg),1,fpEst);
        fclose(fpEst);
    }
}


int abrirArchivo(FILE **pf, char * nombre, char * modo, int mostrarMensaje)
{
    *pf = fopen(nombre,modo);
    if(!*pf && mostrarMensaje)
        printf("Error al abrir archivo\n");

    return *pf != NULL;
}

//Devuelve > 0  si alumno es mayor a empleado
//Devuelve < 0 si alumno es menor a empleado
//Devuelve = 0 si son iguales
int compararRegistros(const t_alumno * alumno, const t_empleado * empleado)
{
    int comparacion = strcmp(alumno->apellido, empleado->apellido);
    if(comparacion == 0)
    {
        comparacion = strcmp(alumno->nombre, empleado->nombre);
        if(comparacion == 0)
            comparacion = alumno->dni - empleado->dni;
    }

    return comparacion;
}

void actalizarRegistros(t_empleado * empleado, FILE **pf)
{
    empleado->sueldo *= 1.728;
    fseek(*pf, -1L * sizeof(t_empleado), SEEK_CUR);
    fwrite(empleado, sizeof(t_empleado), 1, *pf);
    fseek(*pf, 0L, SEEK_CUR);
}













