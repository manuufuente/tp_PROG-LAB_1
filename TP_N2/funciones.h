#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/** inicializa el campo estado en 0
 *
 * \ arrays de tipo estructura
 * \ tamaño del arrays
 *
 */
void inicializarEstado(ePersona[],int);


/** \ Ordena alfabeticamente los nombres
 *
 * \param arrays de tipo estructura
 * \param tamaño del arrays
 * \return void
 *
 */
void ordenarporNombre(ePersona[],int);


/** \ muestra los datos de una persona
 *
 * \param tipo de dato de una estructura
 * \return void
 *
 */
void mostrarPersona(ePersona);


/** \ muestra todas las personas del arrays de estructuras
 *
 * \param arrays de tipo estructura
 * \param tamaño del arrays
 * \return void
 *
 */
void mostrarLasPersonas(ePersona[],int);

/** \ busca si una persona ya fue ingresada al sistema
 *
 * \param Entero ingresado por el usuario
 * \param arrays de estructura
 * \param tamaño del arrays
 * \return devuelve -1 si no encontro a nadie o devuelve el indice del arrays de la persona que tiene el mismo DNI
 *
 */
int buscarPersona(int,ePersona[],int);

/** \ busca en el arrays un campo que tenga el estado=0
 *
 * \param arrays de estructuras
 * \param tamaño del arrays
 * \return devuelve -1 si no encontro lugar o devuelve el indice del arrays que este disponible.
 *
 */
int buscarLibre(ePersona[],int);

/** \brief Valida el ingreso de solo numeros
 *
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 *
 */
int esNumero(char[]);

/** \brief Valida el ingreso de solo letras
 *
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 *
 */
int esLetra(char str[]);

/** \brief Inicializa el vector de edades con asteriscos
 *
 * \param edades menores a 18
 * \param edades de 18-35
 * \param edades mayores a 35
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void inicializaVectorEdades(char[],char[],char[],char,int);

/** \brief Borra asteriscos del vector de edades
 *
 * \param vector de edades
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void BorrarAsteriscos(char[],int,int);

/** \brief Imprime el grafico de edades
 *
 * \param menores a 18
 * \param entre 19-35
 * \param mayores a 35
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void ImprimeGrafico(char[],char[],char[],int);

#endif
