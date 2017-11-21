typedef struct
{
    int tiempo;
    char prioridad[50];
    char descripcion[50];
}xTarea;
xTarea* newPersona();
xTarea* newPersonaParametros( char descripcion[],char prioridad[],int horas);
void mostrarTarea(ArrayList* lista);
int leerArchivo (FILE* archivo,ArrayList* lista);
int comparaTarea(void* persona1,void* persona2);
int crearLista (ArrayList* lista,ArrayList* lista2,ArrayList* lista3);
int resolverTarea (ArrayList* lista);
int crearLista (ArrayList* lista,ArrayList* lista2,ArrayList* lista3);
