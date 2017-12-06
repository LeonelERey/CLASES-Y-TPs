typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    long long int dni;
}xEmpleado;
typedef struct
{
    int idRegistaro;
    int idEmpleado;
    int codTarea;
    int cantidadHoras;
    int precioUnitario;
}xRegistroDias;

void altaEmpleado(ArrayList* lista);
int LeerArchivo(FILE* archivo, ArrayList* lista);
xEmpleado* newEmpleado();
xEmpleado* newEmpleadoParametros(int id,char nombre[],char apellido[],long long int dni);
void modificacion(ArrayList* lista);
void mostrarEmpleados(ArrayList* lista);
int comparaEmpleado(void* empleado1,void* empleado2);
void registrarDias(lista)

