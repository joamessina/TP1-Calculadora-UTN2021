#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "Employee.h"


/** \brief free the memory direction
 *
 * \param Employee* this memory direction of the linked list
 *
 */

void employee_delete(Employee* this)
{
	free(this);
}


/** \brief free the memory direction
 *
 * \return Employee*  memory direction of new employee
 *
 */
Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}


/** \brief add all the params to the employee
 *
 * \param char* idStr  the Id of the new employee
 * \param char* nombreStr the name of the new employee
 * \param char* char* horasTrabajadasStr the working hours of the new employee
 * \param char* sueldoStr the salary of the new employee
 * \return Employee*
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee = employee_new();
	if(pEmployee!=NULL)
	{
		if(employee_allSet(pEmployee, nombreStr, atoi(sueldoStr), atoi(horasTrabajadasStr), atoi(idStr))==0)
		{
			return pEmployee;
		}
	}
	else{printf("Error - No quedan libres"); }
		return NULL;
}


//******************************************

/** \brief set the id in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int return 0 - ok -1 - error
 *
 */
int employee_setId(Employee* this,int id)
{
	if(this != NULL && id>0)
	{
		this->id = id;
		return  0;
	}
	return  -1;
}


/** \brief get the id in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_getId(Employee* this,int* id)
{	if(this != NULL)
	{
		*id =this->id;
		return 0;
	}
	else
		return -1;
}



//******************************************

/** \brief set the working hour in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int horasTrabajadas the working hour of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	if(this != NULL && (horasTrabajadas>=0 && horasTrabajadas < 999999))
	{
		this->horasTrabajadas = horasTrabajadas;
		return 0;
	}
	return -1;
}


/** \brief set the working hour in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int horasTrabajadas the working hour of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		return 0;
	}
	else
		return -1;
}

//******************************************

/** \brief set the salary in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int salary the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && (sueldo >=0 && sueldo <= 99999))
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}


/** \brief set the salary in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int salary the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{	if(this != NULL)
	{
		*sueldo =this->sueldo;
		return 0 ;
	}
	else
		return -1;
}

//*****************************************************

/** \brief set the name in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int nombre the name of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && employee_validName(nombre,(int)sizeof(nombre)))
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno=0;
	}
	return retorno;
}


/** \brief set the name in the employee
 *
 * \param Employee* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{	if(this != NULL)
	{
		strncpy(nombre, this->nombre,(int)sizeof(this->nombre));
		return 0;
	}
	else
		return -1;
}


/** \brief return the id in the employee
 *
 * \return int  return a new Id
 *
 */
int employee_generarNuevoId(void)
{
    static int id = 0;
    id = id+1;
    return id;
}



/** \brief string send to valid the name
 *
 * \param char* cadena string with a name
 * \param int limite len of the string
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_validName(char* cadena,int limite)
{
	int respuesta = -1;

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			 cadena[i] != '.')
		{
			respuesta = 1;
			break;
		}
	}
	return respuesta;
}


/** \brief add all the params to the employee
 *
 * \param Employee* the memory direction of the employee
 * \param char* idStr  the Id of the new employee
 * \param char* nombreStr the name of the new employee
 * \param char* char* horasTrabajadasStr the working hours of the new employee
 * \param char* sueldoStr the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int employee_allSet(Employee* this,char* nombre, int sueldo,int horasTrabajadas, int id)
{
	if (this!=NULL)
	{
		employee_setId(this,id);
		employee_setHorasTrabajadas(this,horasTrabajadas);
		employee_setSueldo(this, sueldo);
		employee_setNombre(this, nombre);
		return 0;
	}
	return -1;
}


/** \brief add all the params to the employee
 * \param Employee* the memory direction of the employee
 * \param char* idStr  the Id of the new employee
 * \param char* nombreStr the name of the new employee
 * \param char* char* horasTrabajadasStr the working hours of the new employee
 * \param char* sueldoStr the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */


int employee_allGet(Employee* this,char* nombre, int *sueldo,int *horasTrabajadas, int *id)
{
	if(this!=NULL)
	{
			employee_getId(this, id);
			employee_getHorasTrabajadas(this, horasTrabajadas);
			employee_getSueldo(this, sueldo);
			employee_getNombre(this, nombre);
			return 0;
	}
	return -1;

}




