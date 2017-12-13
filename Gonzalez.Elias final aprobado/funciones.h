typedef struct
{
    int id;
    long int dni;
    char nombre[20];
    char apellido[20];
}xCliente;
typedef struct
{
    long int dniCliente;
    char nombreCliente[20];
    char apellidoCliente[20];
    char articulo[20];
    float costo;
    int estado;
    int numeroServicio;
}xServico;


int LeerArchivos(FILE* archivo, ArrayList* lista,ArrayList* lista2);
xCliente* newCliente();
xCliente* newClienteParametros(int id,char nombre[],char apellido[],long int dni);
xServico* newServico();
xServico* newServicoParametros(char nombre[],char apellido[],long int dni,char articulo[],float costo,int estado,int numeroServicio);
void altaCliente(ArrayList* lista);
void modificacion(ArrayList* lista);
void eliminacion(ArrayList* lista);
void mostrarClientes(ArrayList* lista);
void nuevoServicio (ArrayList* lista,ArrayList* lista2);
void finalizar (ArrayList* lista2);
void mostrarServicio(ArrayList* lista2);

