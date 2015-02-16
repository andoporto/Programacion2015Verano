#include <stdio.h>
#include <conio.h>

#define TAM 10


void InicializarVector(int *, int );
void MostrarVector(int *, int );
int CargarVector(int *, int , int );
void Insertar(int *, int , int , int );
void InsertarOrdenado(int *, int , int );
void Eliminar(int *, int , int );
int EsPalindromo(int *, int );
int ConvertirCadenaAEntero(char *, int );
int Exponencial(int , int );

int main()
{
    int *vec[TAM];
    InicializarVector( *vec,TAM);
    MostrarVector(*vec,TAM);
    printf("\n");
    return 0;
}





void InicializarVector(int *vec, int longitud)
{
    int i;
    for(i=0; i < longitud; i++)
        vec[i] = 0;
}

void MostrarVector(int *vec, int longitud)
{
    int i;
    for(i=0; i<longitud; i++)
        printf("%d,", *(vec + i));

    printf("\n");
}

int CargarVector(int *vec, int cantElementosMaxima, int cantActualElementos)
{
    int dato;
    printf("Ingresar Dato: ");
    scanf("%d", &dato);

    while(cantActualElementos <= cantElementosMaxima && dato != 0)
    {
        *(vec + cantActualElementos) = dato;
        cantActualElementos++;
        printf("Ingresar Dato: ");
        scanf("%d", &dato);
    }

    return cantActualElementos;
}

void Insertar(int *vec, int dato, int pos, int longitud)
{
    int i;
    for(i=longitud; i>=pos;i--)
    {
        *(vec+i+1) = *(vec +i);
        if(i== pos)
        {
            *(vec + i) = dato;
            return;
        }

    }
}

void InsertarOrdenado(int *vec, int dato, int longitud)
{
    int i;
    for(i=longitud; i >= 0; i--)
        if(*(vec + i) > dato)
            *(vec + i + 1) = *(vec +i);
        else
        {
            *(vec +i+1) = dato;
            return;
        }
}

void Eliminar(int *vec, int pos, int longitud)
{int Exponencial(int dato, int exponente)
    int i;
    for(i=0; i<longitud; i++)
        if(i>=pos)
            *(vec+i) = *(vec+i+1);

    *(vec + longitud) = 0;
}

void EliminarPrimerAparicion(int *vec, int dato, int longitud)
{
    int i;
    int datoEncontrado=0;
    for(i=0; i<longitud; i++)
    {
        if(*(vec+i) == dato)
            datoEncontrado = 1;
        if(datoEncontrado)
            *(vec+i) = *(vec+i+1);
    }
    *(vec+longitud) = 0;
}

int EliminarDato(int *vec, int dato, int longitud)
{
    int i;
    int cantDatosEliminados = 0;
    int verificarCopiado = 0;
    for(i=0; i< longitud; i++)
    {
        if(*(vec +i + cantDatosEliminados) == dato)
        {
            cantDatosEliminados++;
            longitud--;
            verificarCopiado = 1;
        }

        *(vec + i) = *(vec + i + cantDatosEliminados);

        //Por si el numero aparece dos veces seguidas.
        if(verificarCopiado)
        {
            i--;
            verificarCopiado = 0;
        }
    }

    return cantDatosEliminados;
}


int EsPalindromo(int *vec, int longitud)
{
    int i;
    for(i=0; i <=longitud/2; i++)
    {
        if(*(vec+i) != *(vec+longitud-1-i))
            return 0;
    }
    return 1;
}

int ConvertirCadenaAEntero(char *vec, int longitud)
{
    int entero=0;
    int i;

    for(i=0; i < longitud; i++)
    {
        entero += (((int)*(vec+i)) - '0') * Exponencial(10,longitud-i-1);
    }

    return entero;
}

int Exponencial(int dato, int exponente)
{
    if(exponente == 0)
        return 1;

    int num = dato;
    while(exponente > 1)
    {
        num *= dato;
        exponente--;
    }

    return num;
}

