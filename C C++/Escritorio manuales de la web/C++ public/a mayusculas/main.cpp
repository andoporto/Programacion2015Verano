#include <iostream>

using namespace std;

void aMayusculas(char *cadena);
void cambiaNum(int *numero);
int main(){
char palabra[10];
int numero;
cout<<"teclea una cadena "<<endl;
cin.getline(palabra,10);
aMayusculas(palabra);
cout<<endl<<palabra<<endl;
cout<<"ahora teclea un numero"<<endl;
cin>>numero;
cambiaNum(&numero);
cout<<"este numero se cambio a: "<<numero;
cin.ignore();
cin.get();
return 0;
}
void aMayusculas(char *cadena){
for(int i=0;cadena[i]!='\0';++i)
cadena[i]+=('A'-'a');
}
void cambiaNum(int *numero){
*numero *= *numero;
}
