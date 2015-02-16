/*Ejercicio 8

Dados dos números naturales (incluido el cero), obtener su producto por sumas
sucesivas.*/

#include <stdio.h>

int producto_por_suma(int,int);

int main()
{
    int primer,segundo;
    do{
        printf("Ingrese Primer Numero Natural:  ");
        scanf("%d",&primer);
        printf("Ingrese Segundo Numero Natural: ");
        scanf("%d",&segundo);
    }while((producto_por_suma(primer,segundo))==-1);
    printf("\n");
    return 0;
}


int producto_por_suma(int prim, int seg)
{
    int i=1,res=0;
    if(prim<0||seg<0)
        return -1;
    while(i<=seg)
    {
        res+=prim;
        i++;
    };
    printf("Resultado: %d",res);
    return res;
};
