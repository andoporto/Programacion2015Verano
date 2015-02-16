#include <stdio.h>
#define TAM 8

void insertar(int *);
void mostrar(int *);

int main()
{

    printf("\n");
    int v[TAM]= {2,4,7,9,16,55,90,91};
    mostrar(v);
    printf("\n");
    insertar(v);
    printf("\n");
    mostrar(v);
    printf("\n");
    return 0;
}


void insertar(int *p)
{
    int i,num,aux;
    printf("\n Ingrese el numero: ");
    scanf("%d", &num);
    for(i=0; i<TAM; i++)
        if(*p>num)
        {
            aux=*p;
            *p=num;
            num=aux;
            p++;
        }
        else
            p++;
}

void mostrar(int *p)
{
    int i;
    for(i=0; i<TAM; i++)
    {
        printf("\t %d",*p);
        p++;
    }
}
