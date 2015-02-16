#include <stdio.h>
#include <stdlib.h>

#define TAM 15
#define LLENO 2
#define ELEM_EXIST 3
#define INSERT_OK 1

int buscar_e_insertar(int *vec, int elem, int *cant_elem);

int main()
{
    int vec[TAM] = {1,2,3,5,6,7,8,9,11};
    int elem = 12, cant_elem = 9;
    int i, result;

    result = buscar_e_insertar(vec, elem, &cant_elem);

    if (2 == result)
        printf("Vector lleno");
    else if (1 == result){
        printf("Se inserto elemento\n");
        for(i=0; i<=15; i++)
            printf("%d ", *(vec+i));
    }
    else if(3 == result)
        printf("El elemento ya se encontraba");
    else
        printf("ERROR");

    return 0;
}

int buscar_e_insertar(int *vec, int elem, int *cant_elem){
/* Si el elemento ya existe, no lo inserta */

    int found = 0, mid = 0;
    int first = 0, last = (*cant_elem)-1;

    if(*cant_elem >= TAM-1)
        return LLENO;

    mid = (last + first)/2;

    while(!found && first < last){
        if (*(vec+mid) < elem){
            first = mid + 1;
            }
        else if(*(vec+mid) == elem){
            return ELEM_EXIST;
        }
        else
            last = mid-1;

        if(first == last){
            printf("pos: %d", last);
            insertar_por_posicion(vec, last+1, elem);
            (*cant_elem)+=1;
            return INSERT_OK;
            };
        mid = (last + first)/2;
    }
    //return found;

}

void insertar_por_posicion(int * vec, int pos, int elem){
/* Inserta un entero en la posicion que se pasa por argumento en la func
manteniendo el orden del resto de los elementos*/

    int i;
    printf("possss: %d", pos);
    for (i = TAM-2; i >= pos-1; i--){
        printf("vec+i+1: %d - vec+i: %d\n", *(vec+i+1), *(vec+i));
        *(vec+i+1) = *(vec+i);

    }
    *(vec+pos-1) = elem;

}
