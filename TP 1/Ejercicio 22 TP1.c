#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int insertar_en_posi(int *,int);

int main()
{
    int m[TAM]={1,2,3,4,5};
    int posi=0;
    printf("\n Ingrese posicion a ingresar");
    scanf("%d",&posi);
    insertar_en_posi(m,posi);
    return 0;
}


int insertar_en_posi (int *m,int posicion)
{
    for(posicion=0;posicion<TAM;posicion++)
    {
       printf("\n Ingrese numero ");
       scanf("%d",&m[posicion]);
    }
}
