#include <iostream.h>
#include <stdlib.h>
#include <string.h>
class Persona {
public:
Persona(char *n) { strcpy(nombre, n); }
Persona(const Persona &p);
virtual char *VerNombre(char *n) { strcpy(n, nombre); return n;}
virtual Persona* Clonar() { return new Persona(*this);}
protected:
char nombre[30];
};
Persona::Persona(const Persona &p)
{
strcpy(nombre, p.nombre);
cout << "Per: constructor copia." << endl;
}
class Empleado : public Persona {
public:
Empleado(char *n) : Persona(n) {}
Empleado(const Empleado &e);
char *VerNombre(char *n) { strcpy(n, "Emp: "); strcat(n, nombre);
return n;}
virtual Persona* Clonar() { return new Empleado(*this);}
};
Empleado::Empleado(const Empleado &e) : Persona(e)
{
cout << "Emp: constructor copia." << endl;
}
class Estudiante : public Persona {
public:
Estudiante(char *n) : Persona(n) {}
Estudiante(const Estudiante &e);
char *VerNombre(char *n) { strcpy(n, "Est: "); strcat(n, nombre);
return n;}
virtual Persona* Clonar() { return new Estudiante(*this);}
};
Estudiante::Estudiante(const Estudiante &e) : Persona(e)
{
cout << "Est: constructor copia." << endl;
}
int main()
{
char n[40];
Persona *Pepito = new Estudiante("Jose");
Persona *Carlos = new Empleado("Carlos");
Persona *Gente[2];
cout << Carlos->VerNombre(n) << endl;
cout << Pepito->VerNombre(n) << endl;
Gente[0] = Carlos->Clonar();
cout << Gente[0]->VerNombre(n) << endl;
Gente[1] = Pepito->Clonar();
cout << Gente[1]->VerNombre(n) << endl;
delete Pepito;
delete Carlos;
delete Gente[0];
delete Gente[1];
system("pause");
return 0;
}
