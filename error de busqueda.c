#include<stdio.h>

int main()
{

    int A[20]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int inf,sup,mit,dato,n=20;
    printf("Dame un dato a buscar: ");
    scanf("%d", &dato);
    inf=0;
    sup=n-1;

    while(inf<=sup)
    {
        mit=(inf+sup)/2;

        if(A[mit]==dato)
        {
            printf("Dato %d encontrado en la posicion %d", dato, mit);

        }
        else if(A[mit]>dato)
        {
            inf=mit;
            mit=(inf+sup)/2;

        }
        else if(A[mit]<dato)
        {
            sup=mit;
            mit=(inf+sup)/2;
        }
    }
    getch();
    return 0;
}
