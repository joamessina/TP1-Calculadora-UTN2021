#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	int var;
	char buffer[4][20];
	if (pFile != NULL )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		while( !feof(pFile) )
		{
			var = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if ( var == 4 )
			{
				Employee* auxEmp = employee_new();
				if(auxEmp != NULL)
				{
					auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
					ll_add(pArrayListEmployee, auxEmp);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int var;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while( !feof(pFile) )
		{
			Employee* auxEmp = employee_new();
			if (auxEmp != NULL)
			{
				var = fread(auxEmp,sizeof(Employee),1,pFile);
				if ( var == 1 )
				{
					ll_add(pArrayListEmployee, auxEmp);
				}
				retorno = 0;
			}
		}
	}
	return retorno;
}
