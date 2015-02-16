#include <iostream.h>
#include <stdlib.h>
#include <string.h>


class Persona {
public:
Persona(char *n) {strcpy(nombre, n);}
virtual void Mostrar() = 0;
protected:
char nombre[30];
};
class Empleado : public Persona {
public:
Empleado(char *n, int s) : Persona(n), salario(s) {}
void Mostrar();
int LeeSalario() {return salario;}
void ModificaSalario(int s) {salario = s;}
protected:
int salario;
};
void Empleado::Mostrar()
{
cout << "Empleado: " << nombre << ", Salario: " << salario <<
endl;
}
class Estudiante : public Persona {
public:
Estudiante(char *n, float no) : Persona(n), nota(no) {}
void Mostrar();
float LeeNota() {return nota;}
void ModificaNota(float no) {nota = no;}
protected:
float nota;
};
void Estudiante::Mostrar()
{
cout << "Estudiante: " << nombre << ", Nota: " << nota << endl;
}
int main()
{
Persona *Pepito = new Empleado("Jose", 1000);
Persona *Pablito = new Estudiante("Pablo", 7.56);
char n[30];
Pepito->Mostrar();
Pablito->Mostrar();
system("pause");
return 0;
}
