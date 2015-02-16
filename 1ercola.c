#define TAM 6

typedef struct
{

} t_info;

typedef struct
{
    t_info cola[TAM];
    int pri;
    int ult;
} t_cola;

void crearCola(t_cola *pc);
int colaVacia(const t_cola *pc);
int colaLlena(const t_cola *pc);
int verPrimero(const t_cola *pc,t_info *info);
int ponerEnCola(t_cola, const t_info *info);
int sacarDeCola(t_cola, const t_info *info);
void vaciarCola(t_cola *pc);

int main()
{
    t_info info;
    t_cola cola;
    crearCola(const &cola);

}
