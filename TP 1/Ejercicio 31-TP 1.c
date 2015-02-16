#include <stdio.h>
#include <conio.h>

int main()
{
    printf("\n");
    return 0;
}




int mat[3][4];
   	int i,j;
   	printf("ingrese los valores por fila");
   	for(i=0;i<3;i++)
       	for(j=0;j<4;j++)
    	       scanf("%d",&mat[i][j]);

    for(i=0;i<3;i++)
       for(j=0;j<4;j++)
           printf("la matriz quedo como %d ",mat[i][j]);
