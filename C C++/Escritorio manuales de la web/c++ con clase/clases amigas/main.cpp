#include <iostream>
using namespace std;

/* Clase para elemento de lista enlazada */
class Elemento {
  public:
   Elemento(int t);                           /* Constructor */
   int Tipo() { return tipo;}                /* Obtener tipo */
  private:                                         /* Datos: */
   int tipo;                                         /* Tipo */
   Elemento *sig;                      /* Siguiente elemento */
  friend class Lista;                   /* Amistad con lista */
};

/* Clase para lista enlazada de números*/
class Lista {
  public:
   Lista() : Cabeza(NULL) {}                  /* Constructor */
                                              /* Lista vacía */
   ~Lista() { LiberarLista(); }                /* Destructor */
   void Nuevo(int tipo);                  /* Insertar figura */
   Elemento *Primero()            /* Obtener primer elemento */
   { return Cabeza; }
   /* Obtener el siguiente elemento a p */
   Elemento *Siguiente(Elemento *p) {
      if(p) return p->sig; else return p;};
   /* Si p no es NULL */
   /* Averiguar si la lista está vacía */
   bool EstaVacio() { return Cabeza == NULL;}

  private:
   Elemento *Cabeza;           /* Puntero al primer elemento */
   void LiberarLista(); /* Función privada para borrar lista */
};

/* Constructor */
Elemento::Elemento(int t) : tipo(t), sig(NULL) {}
  /* Asignar datos desde lista de parámetros */

/* Añadir nuevo elemento al principio de la lista */
void Lista::Nuevo(int tipo) {
   Elemento *p;

   p = new Elemento(tipo);  /* Nuevo elemento */
   p->sig = Cabeza;
   Cabeza = p;
}

/* Borra todos los elementos de la lista */
void Lista::LiberarLista() {
   Elemento *p;

   while(Cabeza) {
      p = Cabeza;
      Cabeza = p->sig;
      delete p;
   }
}

int main() {
   Lista miLista;
   Elemento *e;

   // Insertamos varios valores en la lista
   miLista.Nuevo(4);
   miLista.Nuevo(2);
   miLista.Nuevo(1);

   // Y los mostramos en pantalla:
   e = miLista.Primero();
   while(e) {
      cout << e->Tipo() << " ,";
      e = miLista.Siguiente(e);
   }
   cout << endl;

   return 0;
}
