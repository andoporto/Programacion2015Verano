#include <stdio.h>
#include <stdlib.h>

int cargarVector(int *vec,int canTotElem, int cantActElem);///si al vector lo declaro con [] solo lo voy a poder usar con subindice
int buscarElemento(int *vec,int cantActElem,int dat);
int eliminarElemento(int *vec,int cantActElem,int dat);
void mostrarVector(int *vec,int cantActElem);



int main()
{
    int ce=7,i,dat;
    int vec[10]={1,2,3,4,5,6,7};
    printf("\n");
    mostrarVector(vec,ce);
    printf("\n INGRESE EL ELEMENTO A ELIMINAR ");
    scanf("%d",&dat);
    if((eliminarElemento(vec,ce,dat))!=-1)
    {
           printf("\n LOS ELEMENTOS DEL VECTOR DESPUES DE ELIMINAR SON \n\n");
           mostrarVector(vec,ce);
    }else
    {
        printf("\n NO SE ENCONTRO EL ELEMENTO ");
    }
    printf("\n");
    return 0;
}

void mostrarVector(int *vec,int ce)
{
    int i;

    for(i=0;i<ce;i++)
        printf("%d \n",*(vec+i));
}
int eliminarElemento(int *vec,int cantActElem,int dat)
{
    int pos,i;
    if((pos=buscarElemento(vec,cantActElem,dat))==-1)
    {
        return -1;
    }
    i=pos;
    while(i<cantActElem)
    {
        *(vec+i)=*(vec+(++i));

    }
    return 1;
}


int buscarElemento(int *vec,int cantActElem,int dat)
{
    int i=0;

    while(i<cantActElem)
    {
        if(*(vec+i)==dat)
          return i;
        i++;
    }
    return -1;
}

int cargarVector(int *vec,int canTotElem, int cantActElem)
{
    int dat;

    printf("INGRESE DATO A GUARDAR....PARA SALIR PULSE EL NUM 0 \n");
    scanf("%d",&dat);
    while(cantActElem<canTotElem && dat !=0)
    {
        *(vec+cantActElem)=dat;
        cantActElem++;
        system("cls");
        printf("INGRESE DATO A GUARDAR....PARA SALIR PULSE EL NUM 0 \n");
        scanf("%d",&dat);

    }
    return cantActElem;
}
