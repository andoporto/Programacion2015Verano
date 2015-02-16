#include <stdio.h>
#include <string.h>
#define MSG 1
typedef struct
{
    long int dni;
    char apellido [50];
    char nombre [15];
    double sueldo;
}t_emple;
typedef struct
{
    long int dni;
    char apellido [50];
    char nombre [15];
    float promedio;
}t_estu;

void CrearArchivo();
int Comparar(t_estu *pest, t_emple *pemp);
int abrirArchivo(FILE **pf, char *nombre, char *modo, int msg);
void mostrarArchivo(FILE *fp);

int main ()
{
    FILE *pEmple;
    FILE *pEstu;
    t_emple empleado;
    t_estu estudiante;
    CrearArchivo();
    if(!abrirArchivo(&pEstu,"estudiantes","rb",MSG))
        return 1;
    if(!abrirArchivo(&pEmple,"empleados","r+b",MSG))
    {
        fclose(pEstu);
        return 2;
    }
    printf("\nANTES\n");
    mostrarArchivo(pEmple);
    printf("\n---------------------\n");
    printf("\nDESPUES\n");
    fread(&estudiante, sizeof(t_estu),1, pEstu);
    fread(&empleado, sizeof(t_emple),1, pEmple);

    while(!feof(pEstu) && !feof(pEmple))
    {
            if(Comparar(&estudiante, &empleado)==0 && estudiante.promedio>7)
           {
               empleado.sueldo+=(empleado.sueldo*7.28)/100;
               fseek(pEmple, -1L*sizeof(t_emple), SEEK_CUR);
               fwrite(&empleado, sizeof(t_emple), 1, pEmple);
               fseek(pEmple,0,1);
               //se vuelve a leer un nuevo estudiante y empleado
                fread(&estudiante,sizeof(t_estu), 1, pEstu);
               fread(&empleado,sizeof(t_emple), 1, pEmple);
           }
        //si comparar devuelve un 1, es porque estudiante >empleado en cuanto al orden
        //que se determino en la consigna, por lo que hay posibilidad de que sea empleado
        //y se tiene que seguir buscando-> se lee otro registro de empleado
           else
                if(Comparar(&estudiante, &empleado)==1)
                    fread(&empleado,sizeof(t_emple), 1, pEmple);
                else
                    fread(&estudiante,sizeof(t_estu), 1, pEstu);
        //en este caso comparar por descarte devolvio -1, por lo que estudiante<empleado
        //o sea que ya no esta en el archivo de emple y se avanza al prox estudiante
    }
    mostrarArchivo(pEmple);
    fclose(pEmple);
    fclose(pEstu);
    return 0;
}

///FUNCIONES///
void CrearArchivo()
{
    FILE *fpEst=fopen("estudiantes","wb");
    FILE *fpEmp=fopen("empleados", "wb");
    t_estu reg []={{33,"Cast","Matias", 6 },
                    {48,"Gomez","Damian", 7 },
                    {50,"Martinez","Carlos", 8.5},
                    {54,"Paz","Carolina", 2 },
                    {777,"Pereyra","Daniela", 9},
                    {555,"Pereyra","Daniela", 6},
                    {76,"Perez","Roberto", 4 },
                    {344,"Reoj", "Patricia", 8},
                    {89,"Zai", "Melani", 7}};


    t_emple reg_2 []={{35,"Aze","Monica", 6000 },
                    {78,"Gare","Dalma", 5700 },
                    {50,"Martinez","Carlos", 8300 },/*se deberia modificar*/
                    {58,"Paredes","Carmen", 2000 },
                    {99,"Pelu","Fabricio", 2780},
                    {555,"Pereyra","Daniela",6590}, /*OJO NO se deberia modificar*/
                    {777,"Pereyra","Daniela", 9000 },/*se deberia modificar*/
                    {76,"Perez","Roberto", 4500 },
                    {344,"Reoj", "Patricia", 7150},
                    {43,"Zuhi", "Pedro",6.70}};/*se deberia modificar*/


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

////////////////
int Comparar(t_estu *pest, t_emple *pemp)
{
    if(pest->dni== pemp->dni)
        return 0;
    if(strcmpi(pest->apellido, pemp->apellido)==1)
        return 1;
    if(strcmpi(pest->apellido, pemp->apellido)==-1)
        return -1;
    else//entonces mismo apellido
        if(strcmpi(pest->nombre, pemp->nombre)==1)
            return 1;
        else
            if(strcmpi(pest->nombre, pemp->nombre)==-1)
                return -1;
            else
                if(pest->dni > pemp->dni)
                    return 1;
                else
                    return -1;
}

/////////
int abrirArchivo(FILE **pf, char *nombre, char *modo, int msg)
{
    *pf=fopen(nombre, modo);
    if(!(*pf) && msg)
        printf("\nERROR APERTURA DE ARCHIVO\n");
    return (*pf)!=NULL;
}
////////////

void mostrarArchivo(FILE *fp)
{
    t_emple reg;
    long posact=ftell(fp);
    rewind(fp);
    fread(&reg,sizeof(reg),1,fp);
    while(!feof(fp))
    {
        printf("%ld\t%s, %s\t\t%lf\n",
               reg.dni,
               reg.apellido,
               reg.nombre,
               reg.sueldo);
        fread(&reg,sizeof(reg),1,fp);
    }
    fseek(fp,posact,SEEK_SET);
}
