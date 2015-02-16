#include <conio.h>
#include <stdio.h>
#define TAM 11


int cargar_vector(int*, int);
void mostrar_vector(int*, int);
int insertar_en_vector23 (int*, int);
void ordenar_vector_asc(int*, int);
int buscar_menor(int*, int, int);
void intercambiar(int*, int*);


void main()
{
    int cant_elementos=0, v[TAM];


    cant_elementos =  cargar_vector(v,cant_elementos);


    printf("\n\nLa cant de elementos es: %d\n\n", cant_elementos);


    ordenar_vector_asc(v, cant_elementos);


    mostrar_vector(v, cant_elementos);


    cant_elementos = insertar_en_vector23(v, cant_elementos);


    ordenar_vector_asc(v, cant_elementos);


    mostrar_vector(v, cant_elementos);


    getch();


}


int cargar_vector (int *v, int cant_elementos)
{
    int i = 0;
    char op;


    while (cant_elementos <= TAM - 1)
    {
        printf("\nIngrese el valor a cargar: ");
        scanf("%d", v);
        printf("\n¿Desea ingresar otro valor? //Presione s para SI o n para NO: ");
        fflush(stdin);
        scanf("%c", &op);
        if( op == 's')
        {
            cant_elementos++;
            v++;
        }
        else
            return cant_elementos+1;
    }
    printf("\n\n¡¡¡El vector esta lleno!!!");
    return cant_elementos;
}


void mostrar_vector (int *v, int cant_elementos)
{
    int i;
    puts("\nEL VECTOR ES: ");
    for(i=0; i<cant_elementos; i++)
        printf("\t\t\tv[%d] = %d\n", i, v[i]);
}


int insertar_en_vector23(int *v, int cant)
{
    int valor;
    if(cant == TAM)
    {
        puts("NO SE PUEDE INSERTAR, EL VECTOR ESTA LLENO");
        return cant;
    }
    else
    {
        printf("Ingrese el valor a inseetar: ");
        scanf("%d", &valor);
        *(v+cant) = valor;
        return cant+1;
    }
}


void ordenar_vector_asc(int* v, int cant_elementos)
{
    int pos_menor, i;
    for (i=0; i<=cant_elementos-2; i++)
    {
        pos_menor = buscar_menor (v, i, cant_elementos - 1);
        if( pos_menor != i)
            intercambiar(v+i, v+pos_menor);
    }
}


int buscar_menor(int* v, int d, int h)
{
    int pos_menor = d, i;
    for(i = d+1; i<= h; i++)
        if(*(v+i) < *(v+pos_menor))
            pos_menor = i;
    return pos_menor;
}


void intercambiar(int* x, int* y)
{
    int x_bis = *x;
    *x = *y;
    *y = x_bis;
}
