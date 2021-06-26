#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/utn.h"



static int myGets(char *cadena, int longitud);

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush // __fpurge
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief 	Verifica una cadena recibida como parametro para determinir
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esUnNombreValido(char* cadena,int limite)
{
	int respuesta = 1; // TODO OK

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}





/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;

}
/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNickName(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;

}

static int myGets(char *cadena, int longitud)
{
	fflush(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}


/**
 * \brief Solicita un float al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param float* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getFloat(char* mensaje,char* mensajeError,float* pResultado,float minimo,float maximo,int reintentos){
	int retorno = -1;
	float bufferFloat;
	int resultadoScan;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = getFloat(&bufferFloat);
			if(resultadoScan && minimo <= bufferFloat && maximo >= bufferFloat){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
				printf("\n-REINTENTOS: %d \n",reintentos);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * getFloat: consigue un float
 * pFloat: cadena de caracteres a ser analizada
 * Retorno: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
int getFloat(float* pFloat){
	int retorno = 0;
	char bufferFloat[64];
	if(pFloat != NULL){
		fflush(stdin);

		if(!myGets(bufferFloat,sizeof(bufferFloat)) && esFlotante(bufferFloat,sizeof(bufferFloat))){
			*pFloat = atof(bufferFloat);
			retorno = 1;
		}
	}
	return retorno;
}


/*
 * esFlotante: Verifica si la cadena ingresada es flotante
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Retorno: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
int esFlotante(char* array,int limite){
	int retorno = -1;
	int i = 0;
	int contadorDePuntos = 0;

	if(array != NULL && limite > 0){
		retorno = 1;
		if(array[0] != '+' || array[0] != '-'){
			i = 1;
		}
		while(array[i] != '\0'){
			if((array[i] < '0' || array[i] > '9') && array[i] != '.'){
				retorno = 0;
				break;
			}
			if(array[i] == '.'){
				contadorDePuntos++;
				if(contadorDePuntos > 1){
					retorno = 0;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}



/**
 * \brief Solicita un string al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getCuit(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				isCuit(bufferString,LIMITE_BUFFER_STRING)==1 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
/*
*
 * isCuit: Verifica si la cadena ingresada es un cuit
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Retorno: 1 (verdadero) si la cadena es cuit , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */

int isCuit(char* cadena,int limite)
{
    int respuesta = 0;

    for (int i = 0; i <= limite && cadena[i] != '\0'; i++)
    {
        if( (cadena[2] == '-' && cadena[11] == '-') &&
            (cadena[i] >= '0' && cadena[i] <= '9'))
        {
            respuesta = 1; // Todo bien
            break;
        }
    }
    return respuesta;
}

/**
 * \brief Solicita un string al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getAviso(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite
				)
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;

}


/**
 * \brief muestra el menu principal
 * \return valor del menu
 *
 */

int menu()
{
	int opcion;
    printf("                ABM                      \n\n");
    printf("1) Cargar los datos (data.csv)\n");
	printf("2) Cargar los datos (data.bin)\n");
	printf("3) Alta empleado\n");
	printf("4) Modificar empleado\n");
	printf("5) Baja empleado\n");
	printf("6) Listar empleados\n");
	printf("7) Ordenar empleados\n");
	printf("8) Guardar los datos (data.csv)\n");
	printf("9) Guardar los datos (data.bin)\n");
	printf("10) Salir\n");

    utn_getInt("\nIngrese opcion: ", "Ingrese una opcion entre 1 y 10", &opcion, 1, 10, 1);

    return opcion;
}

/**
 * \brief muestra el menu de informes
 * \return valor del menu
 *
 */


int informes()
{
    int respuesta;

    printf("                INFORMES                \n\n");
    printf("1-Cliente con más avisos\n");
    printf("2-Cantidad de avisos pausados\n");
    printf("3-Rubro con mas avisos\n");
    printf("4-Cliente con más avisos activos\n");
    printf("5-Cliente con más avisos pausados\n");
    printf("6-Salir\n");
    utn_getInt("\nIngrese opcion: ", "", &respuesta, 1, 6, 1);

    return respuesta;
}


/**
 * \brief muestra el menu testeo
 * \return valor del menu
 *
 */
int modificar()
{
    int respuesta;

    printf("                Modificar                \n\n");
    printf("1-Nombre\n");
    printf("2-Horas trabajadas\n");
    printf("3-Sueldo\n");
    printf("4-Salir\n");
    utn_getInt("\nIngrese opcion: ", "", &respuesta, 1, 4, 1);

    return respuesta;
}


/**
 * \brief Solicita un char al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param char* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) Error / (0) Ok
 *
 */


int utn_getChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 )
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush // __fpurge
			resultadoScanf = scanf("%c" , &bufferChar);
			if(resultadoScanf == 1 && (bufferChar == 's' || bufferChar == 'n'))
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

