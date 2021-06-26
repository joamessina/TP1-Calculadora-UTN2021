#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
		int retorno=-1;
		FILE* file;
		if(path != NULL && pArrayListEmployee !=NULL)
		{
			file = fopen(path, "r");
			if(parser_EmployeeFromText(file, pArrayListEmployee)==0)
			{
				retorno = 0;
			}else
			{
				file = fopen(path, "w");
				printf("No existia el archivo y fue creado\n");
				retorno = 0;
			}

		}
		fclose(file);
	    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* file;
	if(path != NULL && pArrayListEmployee !=NULL)
	{
		file = fopen(path, "rb");

		if(parser_EmployeeFromBinary(file,pArrayListEmployee)==0)
		{
			retorno =0;
		}else
		{
			//file = fopen(path, "wb");
			printf("No existia el archivo y fue creado\n");
			retorno = 0;
		}
	}
	fclose(file);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int auxSueldo;
    int auxHT;
    char auxNombre[128];
    Employee* empleado = employee_new();
    if(empleado != NULL && pArrayListEmployee != NULL)
    {
    	if(	utn_getInt("Ingresa el sueldo =", "No puede ingresar ese numero", &auxSueldo, 3, 9999999, 0)==0  &&
    		utn_getInt("Ingresa las horas trabajadas =", "No puede ingresar ese numero", &auxHT, 3, 9999999,0)==0 &&
			utn_getNombre("ingrese el nombre =", "ingrese correctamente el nombre", auxNombre, 3, 128)==0 )
		{
    		if(employee_allSet(empleado,auxNombre,auxSueldo,auxHT,controller_FindNextId(pArrayListEmployee))==0)
    		{
    			ll_add(pArrayListEmployee, empleado);
    			retorno = 0;
    		}
		}
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idUser,auxId,auxHT,auxSueldo;
	char auxNombre[128];
	char auxRespuesta;
	Employee* empleado = employee_new();
	if(pArrayListEmployee!=NULL && empleado != NULL )
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getInt("\nIngrese el id del empleado que deseas modificar: ", "agregue un id correcto", &idUser, 3, 10000, 0)==0)
		{
			empleado = ll_get(pArrayListEmployee, controller_FindId(pArrayListEmployee, idUser));
			employee_allGet(empleado, auxNombre, &auxSueldo, &auxHT, &auxId);
			printf(" %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
			if(utn_getChar("\nDesea modificar este usuario (s - n)= ", "\ningrese s o n", &auxRespuesta, 3)==0)
			{
				switch (modificar())
				{
					case 1:
						if(utn_getNombre("ingrese el nombre =", "ingrese correctamente el nombre", auxNombre, 3, 128)==0)
						{
							employee_setNombre(empleado, auxNombre);
							retorno=0;
						}
					break;

					case 2:
						if(utn_getInt("Ingresa las horas trabajadas =", "No puede ingresar ese numero", &auxHT, 3, 9999999,0)==0 )
						{
							employee_setHorasTrabajadas(empleado, auxHT);
							retorno=0;
						}
					break;

					case 3:
						if(utn_getInt("Ingresa el sueldo =", "No puede ingresar ese numero", &auxSueldo, 3, 9999999, 0)==0)
						{
							employee_setSueldo(empleado, auxSueldo);
							retorno=0;
						}
					break;
					case 4:
						break;

				}
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idUser,auxId,auxHT,auxSueldo;
	char auxNombre[128];
	char auxRespuesta;
	Employee* empleado = employee_new();

	if(pArrayListEmployee!=NULL && empleado!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(utn_getInt("\nIngrese el id del empleado que desea dar de baja: ", "agregue un id correcto", &idUser, 3, 10000, 0)==0)
		{
			empleado = ll_get(pArrayListEmployee, controller_FindId(pArrayListEmployee, idUser));
			employee_allGet(empleado, auxNombre, &auxSueldo, &auxHT, &auxId);
			printf(" %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
			utn_getChar("\nDesea eliminar este usuario (s - n)= ", "\ningrese s o n", &auxRespuesta, 3);
			if(auxRespuesta == 's')
			{
				ll_remove(pArrayListEmployee, controller_FindId(pArrayListEmployee, idUser));
				retorno = 0;
			}
		}
	}
	return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int auxHT;
	int auxSueldo;
	char auxNombre[128];
	int len = ll_len(pArrayListEmployee);
	Employee* empleado = employee_new();
	if ( empleado != NULL && len != 0)
	{
		printf("\n ID   NOMBRE            HORAS TRABAJADAS    SUELDO\n");
		for (int i = 0; i < len; i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			employee_allGet(empleado, auxNombre, &auxSueldo, &auxHT, &auxId);
			printf(" %04d | %-15s | %-16d | %-6d \n", auxId, auxNombre, auxHT, auxSueldo);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int len = ll_len(pArrayListEmployee);
	char auxNombre[128];
	char auxNombre1[128];
	Employee* empleado = employee_new();
	Employee* empleadoAux = employee_new();

	printf("\nSe estan ordenando\n");
	if ( empleado != NULL && empleadoAux != NULL && len != 0)
	{
		for (int i = 0; i < len; i++)
		{
			for ( int j = i + 1; j < len; j++)
			{
				empleado = ll_get(pArrayListEmployee, i);
				empleadoAux = ll_get(pArrayListEmployee, j);
				employee_getNombre(empleado, auxNombre);
				employee_getNombre(empleadoAux, auxNombre1);
				if ( strcmp(auxNombre, auxNombre1) > 0 )
				{
					ll_set(pArrayListEmployee,j, empleado);
					ll_set(pArrayListEmployee,i, empleadoAux);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int auxId;
		int auxHT;
		int auxSueldo;
		char auxNombre[125];
		int len = ll_len(pArrayListEmployee);
	    Employee* empleado = employee_new();
	    FILE* file;

	    if (empleado != NULL && pArrayListEmployee != NULL && len != 0 )
	    {
	    	file = fopen(path, "w");
	        fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
	        for (int i = 0; i < len; i++)
	        {
	            empleado = ll_get(pArrayListEmployee, i);
	            if(employee_allGet(empleado, auxNombre, &auxSueldo, &auxHT, &auxId )==0)
	            {
					fprintf(file, "%d,%s,%d,%d\n", auxId, auxNombre, auxHT, auxSueldo);
					retorno = 0;
	            }
	        }
	    }
	    fclose(file);
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
	    int len = ll_len(pArrayListEmployee);

	    FILE* file;
	    Employee* empleado;// = employee_new();
		file = fopen(path, "wb");

	    if ( file != NULL && pArrayListEmployee != NULL )
	    {
	        for(int i = 0; i < len; i++)
	        {
	            empleado = ll_get(pArrayListEmployee, i);
	            fwrite(empleado,sizeof(Employee),1,file);
	        }
	        retorno = 0;
	    }
	    fclose(file);
	    return retorno;
}


/** \brief find ID in the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \param int idUser the id of the employee
 * \return int
 *
 */

int controller_FindId(LinkedList* pArrayListEmployee,int idUser)
{
	Employee* empleado = NULL;
	int len = ll_len(pArrayListEmployee);
	int auxid;
	if(pArrayListEmployee !=NULL && idUser >0)
	{
		for(int i = 0; i < len; i++ )
			{
				empleado = ll_get(pArrayListEmployee, i);
				employee_getId(empleado, &auxid);
				if( idUser == auxid )
				{
					return i;
				}
			}
	}
	return -1;
}


/** \brief find the max id and return +1
 *
 * \param pArrayListEmployee LinkedList*
 * \return int the new id
 *
 */
int controller_FindNextId(LinkedList* pArrayListEmployee)
{
	int max ;
	int retorno=1;
	int auxId;
	int len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && len >=0)
	for (int i = 0 ; i< len ; i++)
	{
		Employee* aux = employee_new() ;
		aux = ll_get(pArrayListEmployee, i);
		employee_getId(aux, &auxId);
		if (i==0 || auxId > max )
		{
			max=auxId;
		}
	}
	retorno=max+1;
	return retorno;
}




