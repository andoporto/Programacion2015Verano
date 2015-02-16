#include <stdio.h>
#include <conio.h>


double potencia_e(int,float);


int main()
{
    int x;
    float tolerancia;
    do
    {
        printf("Tolerancia>0? ");
        scanf("%f",&tolerancia);
    }while(tolerancia<=0);
    printf("e^");
    scanf("%d",&x);
    system("cls");
    printf("e^%d= %.10f",x,(potencia_e(x,tolerancia)));
    printf("\n");
    return 0;
}


double potencia_e(int x,float tol)
 {
    int b=0;
    double e=1,i=1,numerador=1,denominador=1,termino=1;
    if(x<0)
    {
        x=(-x);
        b=1;
    };
    while(termino>=tol)
    {
        termino=((numerador*=x)/(denominador*=i));
        e+=termino;
        i++;
     };
    if(b==0)
        return e;
    else
        return (1/e);
 };
