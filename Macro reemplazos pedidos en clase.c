#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FAC(x)      y = 1; \
                    for(i = 1; i <= x ; i++) \
                        y *= i
#define ES_BLANCO(X)    (X) == ' ' || (X) == '\t' ? 1 : 0
#define ES_NUM(X)   (X) >= '0' && (X) <= '9' ? 1 : 0
#define ES_LETRA(X) ((X) >= 'A' && (X) <= 'Z') || ((X) >= 'a' && (X) <= 'z') ? 1 : 0
#define PARTE_ENTERA(X) (int) (X)
#define REDONDEO(X)  PARTE_ENTERA(((X) - PARTE_ENTERA(X)) * 10) >= 5 ? PARTE_ENTERA(X) + 1 : PARTE_ENTERA(X)
#define EXPONENCIAL(X,Y) cont=1;res=0;term=1;\
                             while(term > (Y)){\
                                  res+=term;\
                                  term=pow((X),cont)/facto(cont);\
                                  cont++;\
                             }
int facto(int);
int main()
{
    int i,
    y,
    num,
    cont=1;
    float num2,
    num3,
    term=1,
         res=0;

    printf("Ingrese numero entero: ");
    scanf("%d",&num);

    FAC(num);

    printf("\nIngrese numero real: ");
    scanf("%f",&num2);

    printf("\nParte entera de %.2f: %d\n", num2, PARTE_ENTERA(num2));
    printf("\nRedondeo de %.2f: %d\n", num2, REDONDEO(num2));

    printf("ingrese toleracia: ");
    scanf("%f",&num3);

    EXPONENCIAL(num,num3);

    printf("\nEl resultado de e elevado a %d es: %.2f",num, res);
    printf("\nEl factorial de %d es: %d\n", num, facto(num));

    return 0;
}

int facto(int n)
{
    return !n ? 1 : n * facto(n - 1);
}
