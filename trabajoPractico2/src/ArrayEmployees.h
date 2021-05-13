/*
 * arrayEmployees.h
 *
 *  Created on: 13 may. 2021
 *      Author: Joaquin Gabriel Messina
 */
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;



/** \brief Para indicar que todas las posiciones en la matriz están vacías
 * esta funcion pone el flag (isEmpty) en VERDAD en todos
 * posicion del array.
 * \param lista sEmployee* con puntero para el array de employees
 * \param len int Array length.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int initEmployees(sEmployee* list, int len);

/** \brief agregue en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía.
 * \param list employee*.
 * \param len int.
 * \param id int.
 * \param name[] char.
 * \param lastName[] char.
 * \param salary float.
 * \param sector int.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free.
 */
int addEmployee(sEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief busco en Employee por Id y devuelve la posición del índice en la matriz.
 * \param list sEmployee*.
 * \param len int.
 * \param id int.
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found].
 */
int findEmployeeById(sEmployee* list, int len,int id);

/** \brief Remuevo a sEmployee por Id (pongo isEmpty Flag en 1).
 * \param list sEmployee*.
 * \param len int.
 * \param id int.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't.find a employee] - (0) if Ok.
 */
int removeEmployee(sEmployee* list, int len, int id);

/** \brief Ordeno los elementos en la matriz de empleados, el orden de los argumentos indica el orden ASCENDENTE o DESCENDENTE.
 * \param list sEmployee*.
 * \param len int.
 * \param order int [1] indicate ASCENDENTE - [0] indicate DESCENDENTE.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int sortEmployees(sEmployee* list, int len, int order);

/** \brief Imprimo el contenido del array employees
 * \param list sEmployee*.
 * \param length int.
 * \return int.
 */
int printEmployees(sEmployee* list, int length);

/** \brief muestra el monto total de salarios, el promedio de salarios y todos los empleados que superen el promedio con su salario.
 * \param lista de empleados.
 * \param tamaño.
 * \return void.
 */
void TotalPromedioSalarios (sEmployee[], int);

/** \brief devuelve el ID ingresado por el usuario.
 * \return  int id.
 */
int getIDEmployee(sEmployee empleado[],int tam);

/** \brief muestra el mensaje segun de donde provenga la llamada.
 * \param int id de retorno.
 * \param int origen de la llamada.
 * \param int [0] - No hay empleados // [1] - hay empleados.
 */
void showMessage(int, int, int);

/** \brief verifica si hay empleados en el array.
 * \param lista de empleados.
 * \param int tama�o.
 * \return [0] - NO hay empleados // [1] - hay empleados.
 */
int hayEmpleados(sEmployee[], int);

/** \brief muestra el menu y devuelve la opcion ingresada por el usuario.
 * \return int opcion.
 */
int showMenuAndGetOption();

/** \brief devuelve el indice del array donde se aloja el id de empleado ingresado por el usuario.
 * \param lista de empleados.
 * \return int indice.
 */
int getindex(sEmployee empleado[],int tam);


/** \brief devuelve la opcion ingresada por el usuario para modificar un campo del empleado.
 * \return int opcion del campo a editar.
 */
int getOptionEdit();

/** \brief devuelve el orden en que el usuario selecciono ordenar la lista.
 * \return int [0] - DOWN // [1] UP.
 */
int getOrder();

/** \brief devuelve la respuesta seleccionada por el usuario.
 * \return char respuesta [s/n].
 */
char getRespuesta();

/** \brief Busca un lugar libre en el array .
 * \param tomo el empleado del array semployee.
 * \param int es cantidad de empleados.
 * \return devuelve exito o error.
 */
int findFreePlace(sEmployee[], int);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);
/**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 */


/**
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);


/**
* \brief Solicita un texto numerico al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargara el texto ingresado
* \return 1 si el texto contiene solo numeros
*/
int getStringNumeros(char mensaje[],char input[]);


#endif // ARRAYEMPLOYEES_H_INCLUDED
