
#include <stdio.h>
#include <string.h>

typedef int entero; //en el main puedo usar entero en vez de int

struct fecha
{
    int dd,
        mm,
        aa;
};

typedef struct //otra fecha, estructura sin nombre
{
    int dd;
    int mm;
    int aa;
} t_fecha;



typedef struct
{
    char nom[15];
    char ap[25];
    int dni;
    int sueldo[12]; // vector con sueldos mensuales
    t_fecha fnac;
} t_persona;

int main()
{
    struct fecha f1;
    t_fecha f2;
    f1.dd=5;
    scanf("%d",&f1.mm);
    f2.dd=f1.dd;
    t_persona p1,p2;
    t_persona p[10]; //array de personas
    strcpy(p1.nom,"Juan");
    scanf("%s",p1.ap);
    f1.aa=1900;
    p1.fnac.aa=f1.aa;
    p1.fnac=f2; //f2 es de t_fecha
    p2=p1;
    strcpy(p2.nom,p1.nom);
    p2.sueldo[4]= 10000;
    p[3].sueldo[4]=20000;

    printf("\n");
    return 0;
}
