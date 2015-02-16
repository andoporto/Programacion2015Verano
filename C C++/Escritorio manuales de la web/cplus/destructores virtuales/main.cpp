#include <iostream>
#include <iomanip>

using namespace std;

class base
{
public:
    base()
    {
        cout<<endl<<"base constructora de A";
    }
    /*virtual*/ ~base()
    {
        cout<<endl<<"base destructora de A";
    }
// Si no ponemos el virtual, no hace comprobacion de tipos.
};
class der:public base
{
public:
    der()
    {
        cout<<endl<<"constructor derivado de B";
    }
    ~der()
    {
        cout<<endl<<"base destructora de B";
    }
};
int main(void)
{
    base *p=new der;
    delete p; // El uso de delete con un objeto, llama al destructor del objeto.
}
