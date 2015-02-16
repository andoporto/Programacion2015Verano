#include <iostream>
#include <stdlib.h>

using namespace std;

class Tiempo
{
public:
    Tiempo(int h=0, int m=0) : hora(h), minuto(m) {}
    void Mostrar();
    Tiempo operator+(Tiempo h);
    bool operator>(Tiempo h);
    void operator+=(Tiempo h);
    Tiempo operator>>(Tiempo h);
private:
    int hora;
    int minuto;
};
Tiempo Tiempo::operator+(Tiempo h)
{
    Tiempo temp;
    temp.minuto = minuto + h.minuto;
    temp.hora = hora + h.hora;
    if(temp.minuto >= 60)
    {
        temp.minuto -= 60;
        temp.hora++;
    }
    return temp;
}
void Tiempo::Mostrar()
{
    cout << hora << ":" << minuto << endl;
}
int main()
{
    Tiempo Ahora(12,24), T1(4,45);
    T1 = Ahora + T1; // (1)
    T1.Mostrar();
    (Ahora + Tiempo(4,45)).Mostrar(); // (2)
    if(Tiempo(1,32) > Tiempo(1,12)) cout << "1:32 es mayor que 1:12" <<
                                             endl;
    else cout << "1:32 es menor o igual que 1:12" << endl;
    Ahora += Tiempo(1,32);
    Ahora.Mostrar();
    T1 = Ahora >> Tiempo(13,43) >> T1 >> Tiempo(12,32);
    T1.Mostrar();
    system("PAUSE");
    return 0;
}

bool Tiempo::operator>(Tiempo h)
{
    return (hora > h.hora || (hora == h.hora && minuto > h.minuto));
}

void Tiempo::operator+=(Tiempo h)
{
    minuto += h.minuto;
    hora += h.hora;
    while(minuto >= 60)
    {
        minuto -= 60;
        hora++;
    }
}

Tiempo Tiempo::operator>>(Tiempo h)
{
    if(*this > h) return *this;
    else return h;
}


