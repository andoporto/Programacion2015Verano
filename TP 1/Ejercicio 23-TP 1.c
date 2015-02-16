#include <stdio.h>
#define TAM 8

void insertar(int *);
void mostrar(int *);

int main()
{
    int v[TAM]= {2,4,7,9,16,55,90,91};
    insertar(v);
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
