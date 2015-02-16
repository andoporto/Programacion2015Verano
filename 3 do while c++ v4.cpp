#include<iostream>
#include<cstdlib>
using namespace std;

main()
{
    float datos[5];
    int i, posicion;
    char resp;
    for(i=0; i<5; i++)
    {
        cout<<"Ingrese valor " <<i+1<< " : ";
        cin>>datos[i];
    }
    cout<<"Esta seccion permite recuperar un dato del arreglo ";
    cout<<"segun una posicion ingresada desde el teclado. \n";

    do
    {
        do
        {
            cout<<"Ingrese numero de elemento a recuperar dentro del arreglo: ";
            cin>>posicion;

        }
        while(posicion-1<0 || posicion-1>4);
        cout<<"El valor en la posicion " <<posicion<< " es " <<datos[posicion-1]<<"\n\n";


        cout<<"Desea recuperar otro numero? (s/n): ";
        cin>>resp;
    }
    while(resp=='s'|| resp=='S');
    return 0;
}

