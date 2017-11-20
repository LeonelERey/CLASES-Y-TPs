typedef struct
{
    int id;
    char nombre[50];
    char color[100];
    char apellido[50];
}xPersona;

xPersona* newPersona();
xPersona* newPersonaParametros( char nombre[],int id,char color[],char apellido[]);
void agregarpersona(ArrayList* lista,xPersona* persona);
void mostrarPersona(ArrayList* lista,xPersona* persona);
void EliminarPersona(ArrayList* lista, xPersona* persona);
void ModifocarPersona(ArrayList* lista, xPersona* persona);
void PosicionEspecificada(ArrayList* lista, xPersona* persona);
int comparaPersonas(void* id,void* aux);
int LeerArchivo( FILE* Archivo,ArrayList* lista);
int guardarArchivo(FILE* Archivo,ArrayList* lista);
int crearCopiaSeguridad(FILE* archivo,ArrayList* lista);
void VerificacionPos(ArrayList* lista,xPersona* persona,int aux);

