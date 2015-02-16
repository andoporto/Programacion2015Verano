// Normalizar Cadenas en una SOLA PASADA con inserción de comas luego del Apellido



#define ES_BLANCO(x) (x==' ' || x == '32') ? 1 : 0
#define ES_MAYUSCULA(x) (x>='A' && x <='Z') ? 1 : 0
#define ES_MINUSCULA(x) (x>='a' && x <='z') ? 1 : 0
#define ES_LETRA(x) (x>='a' && x <='z' || x>='A' && x <='Z') ? 1 : 0
#define ES_NUMERO(x) (x >= 0 && x <= 9) ? 1 : 0
#define ES_PUNTO(x) (x == '.') ? 1 : 0
#define A_MAYUSCULA(x) (x>='a' && x <='z') ? x-32 : x
#define A_MINUSCULA(x) (x>='A' && x <='Z') ? x+32 : x

char *normalizar(char *s);

void tareaClase4()
{
    char s2[323] =  " Simone matIas maxIMILIANO gates william henry torvalds linus benedict";
    printf("string de prueba: %s\n", s2);
    char * s3;
    s3 = normalizar(s2);
    printf("PRUEBA2: %s", s3);
}

char *normalizar(char *s)
{
    char *orig = s;
    char *dest = s;
    int esApellido = 1;

    while(*orig)
    {
        while(*orig && ES_BLANCO(*orig))
            orig++;

        if(*orig && (!ES_BLANCO(*orig)) && (!ES_PUNTO(*orig)))
        {
            *dest = A_MAYUSCULA(*orig);
            orig++;
            dest++;
        }

        while(*orig && (!ES_BLANCO(*orig)) && (!ES_PUNTO(*orig)))
        {
            *dest = A_MINUSCULA(*orig);
            orig++;
            dest++;
        }

        if(esApellido)
        {
            *dest = ',';
            dest++;
            esApellido = 0;
        }

        if(ES_PUNTO(*orig))
        {
            esApellido = 1;
            *dest = *orig;
            orig++;
            dest++;
        }

        if(ES_BLANCO(*orig))
        {
            *dest = *orig;
            orig++;
            dest++;
        }
    }

    if(dest>s && *(dest)-1 == '\0')
        dest--;
    *dest = '\0';

    return s;
}
