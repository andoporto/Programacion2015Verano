#include <stdio.h>
#include <conio.h>

float ealax(int, float);

int main()
{
  int x;
  float tol, exp;
  printf("ingrese el numero a calcular el exponencial: ");
  scanf("%d",&x);
  printf("ingrese la tolerancia: ");
  scanf("%f",&tol);
  exp=ealax(x, tol);
  printf("el exponencial de %d es: %f", x, exp);
  printf("\n");
  getche();

}

//desarrollo de funcion//

float ealax(int x, float tol)
{
  float acum=0, termino=1;
  int ciclo=1;
  do
  {
    acum+=termino;
    termino=termino*x/ciclo;
    ciclo++;
  }  while(termino>=tol);
  return acum+=termino;
}
