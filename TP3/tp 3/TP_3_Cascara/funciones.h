#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[30];
    char genero[20];
    int duracion;
    char descripcion[101];
    int puntaje;
    char linkImagen[50];
    int idMovie;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie,int cantidad);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movie, int cantidad);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modificarPelicula(EMovie *movie, int cantidad);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

/**
 *  Inicializa los arrays de la estructura
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 */
void inicializarArray(EMovie *movie,int cantidad);

/**
 *  Busca en los arrays de estructura un espacio para cargar
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 *  @return retorna de acuerdo a si hay espacio o no
 */
int buscarEspacio(EMovie *movie, int cantidad);

/**
 *  Busca si coincide el Id ingresado con el id del array
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 *  @param idAux, El id ingresado a comparar
 *  @return retorna de acuerdo a si pudo encontrar el id igual o no
 */
int  buscarPorId(EMovie *movie, int cantidad,int idAux);

/**
 *  Muestra el array de peliculas cargadas
 *  @param movie la estructura a ser eliminada al archivo
 *  @param cantidad la estructura a ser agregada al archivo
 */
void mostrarPelicula(EMovie *movie, int cantidad);


#endif // FUNCIONES_H_INCLUDED
