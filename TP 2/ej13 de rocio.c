#include <stdio.h>
#include <stdlib.h>
#define MSG 1

typedef struct
{
    int dni;
    char ape[51],
         nombre[31];
    double sueldo;
}t_emple;

typedef struct
{
    int dni;
    char ape[51],
         nombre[31];
    float prom;
}t_estu;

/*int abrirArchivo1(FILE **, char *, char*, int);
int abrirArchivo2(FILE **, char *, char*, int);
int cargarRegistros(t_emple *, t_estu *);*/
void crearArchivo();
int abrirArchivo(FILE **, const char *, const char *, int);
int comparar(const t_emple, const t_estu);
void mostrarArchivo(FILE*);

int main()
{

   FILE *fp_emple,
        *fp_estu;
   t_emple reg_emple;
   t_estu reg_estu;

    crearArchivo();
    if(abrirArchivo(&fp_emple, "empleados.bin", "r+b", MSG)==0)
        exit(1);
    if(abrirArchivo(&fp_estu, "estudiantes.bin", "rb", MSG)==0)
       {
         fclose(fp_emple);
         exit(2);
       }

    printf("\t \t \t ANTES \n \n");
    mostrarArchivo(fp_emple);
    printf("\t \t \t DESPUES \n \n");

    fread(&reg_estu, sizeof(reg_estu), 1, fp_estu);
    fread(&reg_emple, sizeof(reg_emple), 1, fp_emple);
    while(!feof(fp_estu) && !feof(fp_emple))
    {
        while(comparar(reg_emple, reg_estu)>0)
            fread(&reg_estu, sizeof(reg_estu), 1, fp_estu);
        while(comparar(reg_emple, reg_estu)<0)
            fread(&reg_emple, sizeof(reg_emple), 1, fp_emple);
        if((reg_emple.dni == reg_estu.dni) && reg_estu.prom>7)
        {
            reg_emple.sueldo += (reg_emple.sueldo)*0.728;
            fseek(fp_emple, (-1L)*sizeof(reg_emple), SEEK_CUR);
            fwrite(&reg_emple, sizeof(reg_emple), 1, fp_emple);
            fseek(fp_emple, 0, SEEK_CUR);
        }
        fread(&reg_estu, sizeof(reg_estu), 1, fp_estu);
    }
    mostrarArchivo(fp_emple);
    fclose(fp_emple);
    fclose(fp_estu);

    /*t_emple reg_emple;
    t_estu reg_estu;
    if(!abrirArchivo1(&fp_emple, "Empleados.bin", "wb", MSG))
        exit(1);
    if(!abrirArchivo2(&fp_estu, "Estudiantes.bin", "wb", MSG))
        exit(2);
    while(cargarRegistros(&reg_emple, &reg_estu))
    {
        fwrite(&reg_emple, sizeof(t_emple), 1, fp_emple);
        fwrite(&reg_estu, sizeof(t_estu), 1, fp_estu);
    }*/
    return 0;
}

//////
/*int abrirArchivo1(FILE **fp, char *nombre, char*modo, int msg)
{
    *fp = fopen("empleados.bin", "wb");
    if(!(*fp) && msg)
    {
        printf("ERROR abriendo empleados.bin \n");
        exit(1);
    }
    return (*fp)!=NULL;
}

/////
int abrirArchivo2(FILE **fp, char *nombre, char*modo, int msg)
{
    *fp = fopen("estudiantes.bin", "wb");
    if(!(*fp) && msg)
    {
        printf("ERROR abriendo estudiantes.bin \n");
        exit(1);
    }
    return (*fp)!=NULL;
}
//////
int cargarRegistros(t_emple * preg_emple, t_estu * preg_estu)
{
   preg_emple[] = {{11222333, "Arjona", "Ricardo", 15000},
                       {22333444, "Arjona", "Sara", 16000},
                       {33444555, "Arjona", "Sara", 17000}};
   preg_estu[] = {{11222333, "Arjona", "Ricardo", 7.0},
                       {22333444, "Arjona", "Sara", 6.5},
                       {33444555, "Arjona", "Sara", 9}};
    return 1;
}
//////*/
//////
void crearArchivo(void)
{
    FILE *fp1,
         *fp2;
    fp1 = fopen("empleados.bin", "wb");

    t_emple reg_emple[] = {{11, "Arjona", "Ricardo", 15000},
                          {223, "Arjona", "Sara", 16000},
                          {2227, "Arjona", "Sara", 17000},
                          {3000, "Baez", "Agustin", 20000},
                          {4000, "Ceres", "Roberto", 22000},
                          {5000, "Paez", "Micaela", 50000}};
    if(fp1!=NULL)
        fwrite(&reg_emple, sizeof(reg_emple), 1, fp1);
    fclose(fp1);

    fp2 = fopen("estudiantes.bin", "wb");

    t_estu reg_estu[] = {{11, "Arjona", "Ricardo", 7.0},
                        {223, "Arjona", "Sara", 6.5},
                        {2227, "Arjona", "Sara", 9},         //se debe cambiar
                        {6000, "Bueno", "Rodrigo", 9},
                        {4000, "Ceres", "Roberto", 9}};         //se debe modificar
    if(fp2!=NULL)
        fwrite(&reg_estu, sizeof(reg_estu), 1, fp2);
    fclose(fp2);
}

//////
int abrirArchivo(FILE **fp, const char * nombre, const char * modo, int msg)
{
    *fp = fopen("empleados.bin", "rb");
    if(*fp==NULL && msg==1)
        printf("Error abriendo archivo \n");
    return *fp!=NULL;
}

/////
int comparar(const t_emple regEmple, const t_estu regEstu)
{
    int dif=(regEmple.ape-regEstu.ape);
    if(dif>0)
        return 1;
    if(dif<0)
        return -1;
    else
    {
        dif=(regEmple.nombre-regEstu.nombre);
        if(dif>0)
            return 1;
        if(dif<0)
            return -1;
        else
        {
            dif=regEmple.dni-regEstu.dni;
            if(dif>0)
                return 1;
            if(dif<0)
                return -1;
            else
                return 0;
        }
    }
}

/////
void mostrarArchivo(FILE * fp)
{
    t_emple regEmple;

    printf("DNI: \t Apellido: \t Nombre: \t Sueldo: \n");
    fread(&regEmple, sizeof(regEmple), 1, fp);
    while(!feof(fp))
    {
        printf("%d \t| %s \t| %s \t| %.2lf \n", regEmple.dni, regEmple.ape, regEmple.nombre, regEmple.sueldo);
        fread(&regEmple, sizeof(regEmple), 1, fp);
    }
}
