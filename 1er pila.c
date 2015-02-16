#include <stdio.h>














t_info info;
t_pila pila;
crearPila(&pila);



int main()
{
    t_info info;
    t_pila pila;
    cearPila(&pila);
    cargarInfo(&info);
    apilar(&pila,&info);
    return 0;
}
