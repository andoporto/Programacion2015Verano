#include <iostream.h>
#include <stdlib.h>
#include <string.h>

class Persona {
public:
Persona(char *n) { strcpy(nombre, n); }
virtual char *VerNombre(char *n) { strcpy(n, nombre); return n;}
protected:
char nombre[30];
};

class Empleado : public Persona {
public:
Empleado(char *n) : Persona(n) {}
char *VerNombre(char *n) { strcpy(n, "Emp: "); strcat(n, nombre);
return n;}
};

class Estudiante : public Persona {
public:
Estudiante(char *n) : Persona(n) {}
char *VerNombre(char *n) { strcpy(n, "Est: "); strcat(n, nombre);
return n;}
};

int main()
{
char n[40];
Persona *Pepito = new Estudiante("Jose");
Persona *Carlos = new Empleado("Carlos");
cout << Carlos->VerNombre(n) << endl;
cout << Pepito->VerNombre(n) << endl;
delete Pepito;
delete Carlos;
system("pause");
return 0;
}

