#ifndef FUNCIONES_ARRAY_H_INCLUDED
#define FUNCIONES_ARRAY_H_INCLUDED
#define TAM 20
int abrirArchivo(FILE**,char*,char*);
void ingresardatos(float *d,int *cant);
float buscar(float *dato,int* cant);
float promedio(float *dato,int * cant);
void mostrar(float *dato,int *cant);
void ingresardatos(float*d,int *cant)
{
    float aux=1;
    int i=0;
    while(aux!=0&&i<*cant)
    {
        printf("Ingrese valor //0 para terminar//\n");
        scanf("%f",&aux);
        d[i]=aux;
        printf("se copio el dato: %.2f\n",d[i]);
        i++;
    }
    if(aux==0)
    *cant=(i-1);
}
void mostrar(float *dato,int *cant)
{
    int i=0;
    for(i=*cant-1;i>=0;i--)
    printf("%.2f\n",dato[i]);
}
float buscar(float *dato,int *cant)
{
    int i=0;
    float aux=dato[i];
    while(i<*cant)
    {
        if(aux>dato[i])
            aux=dato[i];
        i++;
    }
    return aux;
}
float promedio(float * dato,int *cant)
{
    int i,prom=*cant;
    float aux=0;
    for(i=0;i<*cant;i++)
      aux+=dato[i];
    return aux/prom;
}
int abrirArchivo(FILE**fp,char*nombre,char*modo)
{
    if((*fp=fopen(nombre,modo))==NULL)
    {
        printf("El archivo no se pudo abrir\n");
        return 0;
    }
    else
    {
        printf("******El archivo se abrio correctamente******\n\n");
        return 1;
    }
}
#endif // FUNCIONES_ARRAY_H_INCLUDED
