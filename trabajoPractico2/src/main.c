/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Joaquin Gabriel Messina
 Description : TrabajoPractico2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayEmployees.h"



int main(void) {
	setbuf(stdout, NULL);
	float pPromedio;
	char seguir='s';
	int bandera=0;
	Employee empleados[5];
	initEmployees(empleados, 5);


	do
	{
		switch (menu())
		{
			case 1:
				addEmployee(empleados, 5);
				bandera++;
				system("pause");
				system("cls");

				break;
			case 2:
				if(bandera>0)
				{
					if(modificarEmployee(empleados, 5)!=-1)
					{
						printf("\nse pudo modificar correctamente");
					}else
					{
						printf("\nNo se pudo modificar");
					}

				}else
					printf("\nNo se ingreso ningun empleado todavia \n");

				break;
			case 3:
				if(bandera>0)
				{
					removeEmployee(empleados, 5);

					system("pause");
					system("cls");
				}else
				{
					printf("\nNo se ingreso ningun empleado todavia \n");
				}
				break;
			case 4:
			if(bandera>0)
			{
				switch (informes())
				{

						case 1:

							if(sortEmployeesLastNameSector(empleados, 5) !=-1)
							{
								sortEmployeesLastNameSector(empleados, 5);
								printEmployee(empleados, 5);
							}else
							{
								printf("\nNo encontro usuarios");
							}

							break;
						case 2:
							if(calcularSalariosYpromedio(empleados, 5,&pPromedio) !=-1)
							{
								printf("\nEl total de los salarios es =$%.2f\n",calcularSalariosYpromedio(empleados,5,&pPromedio));
								printf("\nEl promedio de los salarios es =$%.2f\n",pPromedio);
								printf("\nLa cantidad de sueldo que superan el promedio es = %d\n",calcSueldosMayores(empleados,5,pPromedio));
							}
							break;
						case 3:

							break;
						default:
							printf("\nOpcion invalida!!\n\n");
							break;
						}
				}
				else
				{
					printf("\nNo se ingreso ningun empleado todavia \n");
				}

	                break;
	                case 5:
	                system("cls");
	                seguir='n';

	                break;

	            default:
	                system("cls");
	                printf("\nIngrese opcion correcta\n\n");
	                break;
	        }
	                fflush(stdin);
	            }while (seguir=='s');

	return 0;
}
