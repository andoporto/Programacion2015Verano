#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 50
#define MENU_COND(x) ((x)!='s' && (x)!='b' && (x)!='i' && (x)!='p')?1:0
#define ERROR_ARCHIVO 0
#define SAVE_OK 1

void cantidad_elementos(int * cant);
void cargar_vector(float *vec, int * cant_elem);
void mostrar_opciones(void);
char seleccionar_opcion(void);
void menu(char opt, float *vec, int cant_elem);
void buscar_menor(float * vec, int cant_elem);
void promedio_pares(float * vec, int cant_elem);
void mostrar_inverso(float * vec, int cant_elem);
int grabar_archivo(FILE * file, float * vec, int cant_elem);

int main()
{
    char op;
    float vec[50];
    int cant=0, res = 0;
    FILE * file;

    cantidad_elementos(&cant);
    cargar_vector(vec, &cant);

    do
    {
        mostrar_opciones();
        op = seleccionar_opcion();
        menu(op, vec, cant);
    }
    while(op != 's');

    res = grabar_archivo(file, vec, cant);

    if(res)
    {
        printf("El archivo se grabo correctamente");
        exit(0);
    }
    else
    {
        printf("Error al grabar el archivo");
        exit(1);
    }

    return 0;
}

void cantidad_elementos(int * cant)
{

    do
    {
        printf("Ingrese cantidad de elementos a ingresar (Max %d): ", TAM);
        scanf("%d", cant);
        fflush(stdin);
        printf("\n");
    }
    while(*cant >= TAM);

}

void cargar_vector(float *vec, int * cant_elem)
{

    int i = 0;
    float elem = -1;

    for(i = 0; i < *cant_elem && elem != 0; i++)
    {
        printf("El ingreso corta con un 0\n");
        printf("Ingrese elem %d: ", i+1);
        scanf("%f", &elem);
        fflush(stdin);
        printf("\n");
        *(vec+i) = elem;
    }

    *cant_elem = i - 1;


}
void mostrar_opciones(void)
{

    printf("\n");
    printf("\t **** OPCIONES ****\n");
    printf("B - Buscar minimo\n");
    printf("P - Promedio pares\n");
    printf("I - Mostrar inverso\n");
    printf("S - Salir\n");
    printf("\n");

}

char seleccionar_opcion(void)
{

    char opt;

    do
    {
        printf("Inserte Opcion: ");
        fflush(stdin);
        scanf(" %c", &opt);
        printf("\n");
        opt = tolower(opt);

        if (MENU_COND(opt))
            printf("Ingrese nuevamente\n");
    }
    while(MENU_COND(opt));

    return opt;
}

void menu(char opt, float *vec, int cant_elem)
{

    switch(opt)
    {
    case 'b':
        buscar_menor(vec, cant_elem);
        break;
    case 'p':
        promedio_pares(vec, cant_elem);
        break;
    case 'i':
        mostrar_inverso(vec, cant_elem);
        break;

    }
}

void buscar_menor(float * vec, int cant_elem)
{

    float menor = *vec;
    int i=0;

    for(i = 0; i<cant_elem; i++)
    {
        if(*(vec+i) < menor)
            menor = *(vec+i);
    }

    printf("El menor es: %.2f\n", menor);



}

void promedio_pares(float * vec, int cant_elem)
{

    float sum = 0;
    int cant_pasadas = 0, i = 0;

    for(i = 0; i<cant_elem; i +=2)
    {
        sum+=(*(vec+i));
        cant_pasadas++;
    }

    printf("El promedio de las posiciones pares es: %.2f\n", sum/cant_pasadas);

}

void mostrar_inverso(float * vec, int cant_elem)
{

    int i = 0;

    for(i = cant_elem - 1; i >= 0; i--)
        printf("%.2f ", *(vec+i));
    printf("\n");
}

int grabar_archivo(FILE * file, float * vec, int cant_elem)
{

    int i = 0;

    file = fopen("array.txt", "wt");

    if(!file)
        return ERROR_ARCHIVO;

    for(i=0; i<cant_elem; i++)
        fprintf(file, "%.2f\n", *(vec+i));

    fclose(file);

    return SAVE_OK;

}

