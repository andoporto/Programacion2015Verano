

// Función Es fecha válida by Módica

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int dia,
        mes,
        anio;
} t_fecha;

void IngrDato();
int EsFechaValida(int,int,int);
int CantDiasMes(int,int);
int EsBisiesto(int);

int main()
{
    system("cls");
    IngrDato();
    printf("\n");
    return 0;
}

void IngrDato()
{
    t_fecha fecha;
    printf("\n Ingrese el d%ca: ",161);
    scanf("%d",&fecha.dia);
    printf("\n Ingrese el mes: ");
    scanf("%d",&fecha.mes);
    printf("\n Ingrese un a%co: ",164);
    scanf("%d",&fecha.anio);

    if (EsFechaValida(fecha.dia,fecha.mes,fecha.anio) == 1)
        printf("\n Es valida");
    else
        printf("\n No es valida");
}



int EsFechaValida(int dia,int mes,int anio)
{
    int fv = 0;
    if (anio > 1600)
        if (mes >= 1 && mes <= 12)
            if (dia >= 1 && dia <= CantDiasMes(mes,anio))
                fv = 1;
    return (fv);
}


int CantDiasMes(int mm,int aa)
{
    int cdm;
    cdm = 31;

    if(mm == 4 || mm == 6 || mm == 9 || mm == 11 )
    {
        cdm = 30;
    }
    else
    {
        if (mm == 2)
        {
            cdm = 28+EsBisiesto(aa);
        }
    }
    return(cdm);
}

int EsBisiesto(int a)
{
    int b;
    if ((a%4==0 || a%100==0)||(a%400==0))
        b=1;
    else
        b=0;
    return(b);
}






void suma_dias( t_fecha* fecha , int n )
{
    if(n<0)
        resta_dias(fecha, -n);
        else{
            t_fecha->fecha.dia += n;
            while( fecha->fecha.dia > cant_dias_mes( fecha->fecha.mes , fecha->fecha.anio ) )
            {
                fecha->fecha.dia -= cant_dias_mes( fecha->fecha.mes , fecha->fecha.anio );
                fecha->fecha.mes++;
                if( fecha->fecha.mes > 12 )
                {
                    fecha->fecha.mes = 1;
                    fecha->a++;
                }
            }
        }
}
