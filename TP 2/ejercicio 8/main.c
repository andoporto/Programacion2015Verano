#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main()
{
    int i,op=0;
    char palabra[30]={};
    char texto[100]={"hola estoy probando la cantidad de hola que aparece en el texto hola"};
    char menu[][50]={"PRIMER PALABRA Y CUANTAS VECES SE REPITE(1)","CANTIDAD DE PALABRAS(2)","LONGITUD DE PALABRA MAS LARGA(3)","SALIR(4)"};
    printf("*****************MENU DE TEXTO****************\n\n");
    do
    {
        for(i=0;i<4;i++)
        printf("%s\n",menu[i]);
        printf("\nINGRESE OPCION\n");
        scanf("%d",&op);
        system("cls");
        switch(op)
        {
            case 1:{
                    printf("%s\n",texto);
                    primerpalabra(texto,palabra);
                    printf("La primer palabra inresada fue:\n");
                    printf("%s\n",palabra);
                    printf("Se repite %d veces\n",mismapalabra(texto,palabra));
                    system("pause");
                    }break;
            case 2:{
                    printf("La cantidad de palabras es %d\n",cantidadpalabras(texto));
                    system("pause");
                    }break;
            case 3:{
                    printf("La longitud de la palabra mas larga es %d\n",longitud(texto));
                    system("pause");
                    }break;
            case 4:break;
            default :{
                        printf("La opcion no existe\n");
                        printf("INGRESE OPCION\n");
                        system("pause");
                    }break;
            }
    system("cls");
    fflush(stdin);
    }while(op!=4);
    return 1;


}
