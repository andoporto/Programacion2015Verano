#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones_array.h"
int main()
{
    FILE*arch;
    float dato[TAM]={},min=0,prom=0;
    int i=0,cant=0;
    char op;
    if(abrirArchivo(&arch,"EJERCICIO 1.txt","wt")==0)
    exit(1);
    printf("CANTIDAD DE DATOS A INGRESAR\n");
    scanf("%d",&cant);
    ingresardatos(dato,&cant);
    system("cls");
    fflush(stdin);
    printf("**************INGRESE LA OPCION***************\n");
    const char opciones[][50]={"(B)uscar minimo elemento","(C)alcular el promedio en posiciones pares","(M)ostrar en orden inverso","(S)alir"};
    do
    {
        for(i=0;i<4;i++)
        printf("\n%s\n",opciones[i]);
        scanf("%c",&op);
        op=toupper(op);
        system("cls");
        switch(op)
        {
            case'B': {
                        min = buscar(dato,&cant);
                        printf("El minimo valor ingresado es: %.2f\n",min);
                        system("pause");
                        }break;
            case'C': {
                        prom=promedio(dato,&cant);
                        printf("El promedio de los valores ingresados es : %.2f\n",prom);
                        system("pause");
                        }break;
            case'M': {
                        mostrar(dato,&cant);
                        system("pause");
                        }break;
            case'S': {

                        }break;
            default: {
                        printf("opcion incorrecta\n");
                        printf("Ingrese una nueva opcion\n");
                        system("pause");
                        }
        }
        system("cls");
        fflush(stdin);
    }while(op!='S');
    for(i=0;i<cant;i++)
    fprintf(arch,"%.2f\n",dato[i]);
    return 1;
}
