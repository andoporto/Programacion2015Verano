#ifndef LIBTP2EJ13_H_INCLUDED
#define LIBTP2EJ13_H_INCLUDED

#define TAMAP 30
#define TAMN 50

typedef struct
{
    long dni;
    char apellido[TAMAP];
    char nombre[TAMN];
    double sueldo;
}t_empleado;

typedef struct
{
    long dni;
    char apellido[TAMAP];
    char nombre[TAMN];
    float promedio;
}t_estudiante;

int crearArchivos(FILE** pemp,FILE** pestud);
int cargaRegEmpleado(t_empleado* emp);
int cargaRegEstudiante(t_estudiante* est);
int comparaApNomYDni(t_empleado* empleado,t_estudiante* estudiante);
void crearArchivoEmpEstAuto();
void mostrarArchivos(FILE**pemp, FILE**pest);



#endif // LIBTP2EJ13_H_INCLUDED
