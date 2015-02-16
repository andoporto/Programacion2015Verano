#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define aMayus(x) ((x)>='a'&&(x)<='z'?(x)-32:(x))
#define esBlanco(x) ((x)==' '|| (x)=='\t'?1:0)
void primerpalabra(char*,char*);
int mismapalabra(char*,char*);
int cantidadpalabras(char*);
int longitud(const char*);
void primerpalabra(char*d,char*p)
{
    char *ini=d;
    while(*d!=' ')
    {
        *p=*d;
        *p++;
        *d++;
    }
}
int mismapalabra(char* c1, char* c2)
{
   int cant=0;
   char* pos_inicial=c2;
   while(*c1)
   {
       if(aMayus(*c2)==aMayus(*c1))
       {
           while(*c2&&*c1&&aMayus(*c2)==aMayus(*c1))
            {
                *c1++;
                *c2++;
            }
            if(!*c2)
            cant+=1;
        c2=pos_inicial;
       }
    *c1++;
   }
   return cant;
}
int cantidadpalabras(char*p)
{
    printf("%s\n",p);
    int cant=1;
    while(*p)
    {
        if(esBlanco(*p))
        cant+=1;
    *p++;
    }
return cant;
}
int longitud(const char*p)
{
    int ini=0,fin=0;
    printf("%s\n",p);
    while(*p)
    {
        while(esBlanco(*p)==0&&(*p))
            {
                ini++;
                *p++;
            }
        if(ini>fin)
            fin=ini;
        *p++;
        ini=0;
    }
return fin;
}


#endif // FUNCIONES_H_INCLUDED
