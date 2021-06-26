 /*
 * arrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Joaquin Gabriel Messina
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"
static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Busca usuarios que no contengan iformacion
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int buscarLibre(Employee* list, int len)
{
	int retorno =-1;
	int i;
	if (list != NULL && len > 0)
	{
		for(i=0; i < len ;i++)
			{
				if (list[i].isEmpty==1)
				{
					retorno = i;
					break;
				}
			}
	}
	return retorno;
}


/* Cada vez que la llamo me devuelve un ID nuevo
 * que nunca me devolvio antes
 */

static int generarIdNuevo(void)
{
	static int id=0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}


/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */

int addEmployee(Employee* list, int len)
{
	int retorno = -1;
	int espacioLibre;
	Employee bufferEmployee;


	if(buscarLibre(list,len)>=0)
	{
		espacioLibre=buscarLibre(list, len);

	}
	if(	list != NULL && len > 0)
	{
		if(	utn_getInt("\nIngrese el Sector = ", "\n", &bufferEmployee.sector, 2, 9999999, 0) ==0 &&
			utn_getNombre("\nIngrese nombre = ","\nError ingrese un nombre correcto",bufferEmployee.name,2,LONG_NOMBRE) == 0 &&
			utn_getNombre("\nIngrese apellido = ","\nError ingrese un apellido correcto",bufferEmployee.lastName,2,LONG_NOMBRE) == 0 &&
			utn_getFloat("\nIngrese el sueldo = ", "\nError ingrese un valor correcto (0-9999999)", &bufferEmployee.salary, 0, 9999999, 2)== 0)
			{
				bufferEmployee.id= generarIdNuevo();
				bufferEmployee.isEmpty = FALSE;
				list[espacioLibre] = bufferEmployee;

			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Imprime los empleados  cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int printEmployee(Employee* list, int len)
{
	int retorno = -1;
	int contador=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				mostrarUsuario(list, i);
				contador++;
			}
		}

		if (contador ==0)
		{
			printf("\nNo hay ningun usuario para mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}




/**
 * \brief Imprime los empleados  cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int mostrarUsuario(Employee* list,int indice)
{
	int retorno = -1;

	if(list != NULL && indice >= 0 )
	{
		if(list[indice].isEmpty==0)
		{
			printf("Id:%d - Sector: %d - Nombre: %s - apellido: %s - salario :%.2f \n",list[indice].id,list[indice].sector,list[indice].name,list[indice].lastName,list[indice].salary);
			retorno = 0;
		}else
		{
			printf("No existe el usuario");
		}
	}
	return retorno;
}



/**
 * \brief Imprime los empleados  cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int id, es el idd que desea encontrar
 * \return (-1) Error / (0) Ok
 *
 */
int findEmployeeById(Employee* list,int len,int id)
{
	int retorno =-1;
	if(list != NULL && len > 0)
		{
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0 && list[i].id== id)
				{
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}


/**
 * \brief Elimina un usuario poniendo el isEmpty=1
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */

int removeEmployee(Employee* list, int len)
{

	int retorno = -1;
	if(list != NULL && len >= 0 )
	{
		int aux;
		char Borrar;
		int auxId;
		if(	utn_getInt("\nIngrese el id del usuario que desea elimnar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			if(findEmployeeById(list, len, aux)!= -1 )
			{
				auxId=findEmployeeById(list, len, aux);
				mostrarUsuario(list,auxId);
				printf("\ndesea elimnar este usuario = (s - n)");
				fflush(stdin);
				scanf("%c",&Borrar);
				if (Borrar=='s')
				{
					list[auxId].isEmpty=1;
					printf("\nse elimino correctamente el usuario\n");
					retorno=1;
				}else
				{
					printf("\nse cancelo la eliminacion del usuario\n");
				}
			}else
			{
				printf("\nNo encontro un usuario con el id que ingresaste\n");
			}
		}
	}
 return retorno;
}


/**
 * \brief calcula el promedio de todos los usuarios ingresados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param float* pPromedio, devuelve el promedio al main
 * \return (-1) Error / (0) Ok
 *
 */

float calcularSalariosYpromedio(Employee *list,int len,float* pPromedio)
{
	int retorno = -1;
	float total=0;
	float flag=0;
	if(list != NULL && len >= 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				total=total + list[i].salary;
				flag++;
			}
		}
		*pPromedio=total/flag;
		retorno = total;
	}
		return retorno;
}



/**
 * \brief Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int modificarEmployee(Employee list[],int len)
{
	int retorno = -1;
	int switchNumber;
	Employee bufferEmployee;
	int aux;
	int auxId;


	if(list != NULL && len >= 0 )
	{

		if(	utn_getInt("\nIngrese el id del usuario que desea cambiar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			auxId=findEmployeeById(list, len, aux);
			if(list[auxId].isEmpty==0)
			{
				mostrarUsuario(list,auxId);
				bufferEmployee = list[auxId];
				printf("\nQue desea cambiar\n1-Nombre\n2-apellido\n3-salario\n4-sector\n5-salir");
				fflush(stdin);
				scanf("%d",&switchNumber);

				switch (switchNumber)
				{
					case 1:
						if(utn_getNombre("\nIngrese nombre = ","\nError ingrese un nombre correcto",bufferEmployee.name,2,LONG_NOMBRE)==0)
						{
							strncpy(list[auxId].name , bufferEmployee.name,51);
						}
						break;
					case 2:
						if(utn_getNombre("\nIngrese apellido = ","\nError ingrese un apellido correcto",bufferEmployee.lastName,2,LONG_NOMBRE) == 0 )
						{
							strncpy(list[auxId].lastName ,bufferEmployee.lastName,51);
						}
						break;
					case 3:
						if(utn_getFloat("\nIngrese el sueldo = ", "\nError ingrese un valor correcto (0-9999999)", &bufferEmployee.salary, 0, 9999999, 2)== 0)
						{
							list[auxId].salary = bufferEmployee.salary;
						}
						break;
					case 4:
						if(utn_getInt("\nIngrese el Sector = ", "\n", &bufferEmployee.sector, 2, 9999999, 0) ==0)
						{
							list[auxId].sector = bufferEmployee.sector;
						}
						break;
					case 5:
						printf("salio exitosamente del modificar\n ");
						break;
					default:
						printf("\nOpcion invalida!!\n\n");
						break;
				}
				retorno = 1;
			}
		}
	}
	return retorno;
}


/**
 * \brief Calcula cuantos sueldos son mayores al promedio
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int promedio, es el promedio
 * \return (-1) Error / (0) Ok
 *
 */
int calcSueldosMayores(Employee list[],int len,int promedio)
{
	int retorno= -1;
	int contadorMay=0;
	if(list != NULL && len >= 0)
		{
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0 && list[i].salary > promedio)
				{
					contadorMay++;
				}
			}
			retorno = contadorMay;
		}

	return retorno;
}

/**
 * \brief Acomoda los usuarios por sector y luego por apellido y los muestra
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */

int sortEmployeesLastNameSector(Employee* list, int len)
{
    int retorno = -1;
    int i;
    Employee bufferEmployee;
    int flagSwap = 1;
    if(list != NULL && len > 0)
    {
        while(flagSwap)
        {
            flagSwap = 0;
            for (i = 0; i < (len - 1); i++)
            {
                if(list[i].isEmpty || list[i+1].isEmpty)
                {
                    continue;
                }
                if( strncmp(list[i].lastName, list[i+1].lastName,51) > 0 ||
                    (strncmp(list[i].lastName, list[i+1].lastName,51) == 0 &&
                    list[i].sector > list[i+1].sector))
                {
                	bufferEmployee = list[i];
                    list[i] = list[i+1];
                    list[i+1] = bufferEmployee;
                    flagSwap = 1;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}








/**
 * \brief Muestra un menu
 */


int menu()
{
    int opcion;
    printf("\n----------------------------------------");
    printf("\n                ABM                      \n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Informes\n");
    printf("5-Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int informes()
{
    int respuesta;

    printf("                INFORMES                \n\n");
    printf("1-Listado empleados\n");
    printf("2-Total y promedio salarios\n");
    printf("3-Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &respuesta);

    return respuesta;
}
