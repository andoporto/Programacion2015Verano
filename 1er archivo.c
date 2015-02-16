FILE *pf;

pf=fopen("datos.bin","wb");

if(!pf)
{
    printf("Error apertura datos.bin");
    EXIT(1); //si no pude abrir el archivo
}
