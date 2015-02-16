#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j,cte=1,TAM=4,mat[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

   for(i=0;i<TAM;i++)
   {
       for(j=0;j<TAM;j++)
        printf("%d\t",mat[i][j]);
    printf("\n");
   }
/**Trisngulo I**/
   for(i=0;i<TAM;i++)
   {
       for(j=cte;j<TAM;j++)
           printf("%d\t",mat[i][j]);
    cte++;
    TAM--;
    printf("\n");
   }
/**Triangulo III**/
   for(i=TAM;TAM>cte;i--)
   {
       for(j=cte;j<TAM;j++)
           printf("%d\t",mat[i][j]);
    cte++;
    TAM--;
    printf("\n");
   }
/**Triangulo IV**/
    for(j=0;j<TAM;j++)
    {
        for(i=cte;i<TAM;i++)
            printf("%d\t",mat[i][j]);
    printf("\n");
    TAM--;
    cte++;
    }
/**Triangulo II**/
    for(j=TAM;TAM>cte;j--)
    {
        for(i=cte;i<TAM;i++)
            printf("%d\t",mat[i][j]);
        TAM--;
        cte++;
    }
   return 1;
}

