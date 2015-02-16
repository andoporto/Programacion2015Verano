#include <iostream>
#include <cstdlib>
using namespace std;

main()
{

    float lab[12], suma=0, prom=0;
    int i;
    float rmen=0, rmed=0, rmay=0;

    for (i=0; i<12; i++)
    {
        cout<<"Ingrese numero de computadoras del laboratorio " <<i+1<<endl;
        cin>>lab[i];
        suma=suma+lab[i];
    }
    prom=suma/12;
    cout<<"El promedio es: " <<prom<<endl;

    for (i=0; i<12; i++)
    {

        if(lab[i]>0 && lab[i]<21)
        {
            rmen=rmen+1;
        }
        else if(lab[i]>=21 && lab[i]<=39)
        {
            rmed=rmed+1;
        }
        else
        {
            rmay=rmay+1;
        }
    }
    cout<<"Hay " <<rmen<< " laboratorios con 0-20 computadoras." <<endl;
    cout<<"Hay " <<rmed<< " laboratorios con 21-39 computadoras." <<endl;
    cout<<"Hay " <<rmay<< " laboratorios con mas de 40 computadoras." <<endl;

    system ("PAUSE");
    return 0;
}
