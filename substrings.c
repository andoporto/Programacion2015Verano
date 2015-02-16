#include <stdio.h>
#include <string.h>

#define TAM 50


void invertNumerSubstrings(char*);

int main()
{
    char chain[TAM];
    printf("\n Ingrese chain: ");
    gets(chain);
    fflush(stdin);
    char result;
    result=(void)invertNumerSubstrings(chain);
    printf("\n Chain modified: ");
    puts(chain);
    printf("\n");
    return 0;
}

void invertNumerSubstrings(char* chain)
{

    char *pl= chain;
    char* chain_ptr=chain;   // chain_ptr to hold starting address of chain
    char* final=(char*)malloc(sizeof(chain));
    char* final_ptr=final;  // // final_ptr to hold starting address of final
    memset(final, '\0', sizeof(chain));

    while(*pl!='\0')
    {

        if(*pl>=49 && *pl<=57) //
        {
            int shift=*pl-48; // to find the shift amount
            int i=0;
            *pl++;

            for(i=shift-1; i>=0; i--)
            {
                *final=*(pl+i);
                final++;
            }
            pl=pl+shift;  // seek the pointer to correct position
        }

        else
        {
            *final=*pl;
            pl++;
            final++;

        }
    }

    chain=chain_ptr; // assign original address of chain to chain again

    while(*final_ptr !='\0')
    {
        *chain=*final_ptr ;
        final_ptr++;
        chain++;
    }
    *chain='\0';

   // free(final);

}
