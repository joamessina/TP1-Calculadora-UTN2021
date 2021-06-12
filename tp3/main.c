#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main()
{
	char seguir='s';
	int bandera=0;
	int banderaLoad=0;
    setbuf(stdout, NULL);

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(bandera!=0)
		{
			system("pause");
			system("cls");
		}
		bandera++;
        switch(menu())
        {
            case 1:
            	if(banderaLoad == 0)
				{
					if(controller_loadFromText("data.csv",listaEmpleados)==0)
					{
						printf("se cargo correctamente los empleado\n");
						banderaLoad++;
					}
					else
						printf("no se pudo cargar los empleado\n");
				}else
					printf("Ya se cargo los usuarios\n");
                // Cargar los datos (data.csv)
                break;

            case 2:
            	if(banderaLoad == 0)
            	{
            		if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
            		{
						printf("se cargo correctamente los empleado\n");
						banderaLoad++;
            		}
					else
						printf("no se pudo cargar los empleado\n");
            	}else
            		printf("Ya se cargo los usuarios\n");

            	//Cargar los datos (data.bin)
            	break;

            case 3:
            	//Alta empleado
            	if(banderaLoad != 0)
					if(controller_addEmployee(listaEmpleados)==0)
						printf("Se agrego correctamente el empleado\n");
					else
						printf("No se agrego el empleado\n");
            	else
            		printf("Se deben cargar los usuarios primero\n");
			   break;
            case 4:
            	if(banderaLoad != 0)
					if(controller_editEmployee(listaEmpleados)==0)
						printf("Se modifico correctamente el empleado\n");
					else
						printf("No se modifico el empleado\n");
            	else
					printf("Se deben cargar los usuarios primero\n");
            	//Modificar empleado
			   break;
            case 5:
            	if(banderaLoad != 0)
					if(controller_removeEmployee(listaEmpleados)==0)
						printf("Se elimino correctamente el empleado\n");
					else
						printf("No se elimino el empleado\n");
            	else
					printf("Se deben cargar los usuarios primero\n");
			   break;
            case 6:
            	if(banderaLoad != 0)
					if(controller_ListEmployee(listaEmpleados)==0)
						printf("\n");
					else
						printf("No se pudo mostrar los empleados\n");
				else
					printf("Se deben cargar los usuarios primero\n");
			   break;
            case 7:
            	if(banderaLoad != 0)
					if(controller_sortEmployee(listaEmpleados)==0)
						printf("Se ordenaron los empleados\n");
            		else
            			printf("no se pudieron ordenaron los empleados\n");
				else
					printf("Se deben cargar los usuarios primero\n");
            	//Ordenar empleados
			   break;
            case 8:
            	if(banderaLoad != 0)
					if(controller_saveAsText("data.csv", listaEmpleados)==0)
						printf("Se pudo guardar los empleados\n");
					else
						printf("No se pudo guardar los empleados\n");
            	else
            		printf("Se deben cargar los usuarios primero\n");
            	//Guardar los datos (data.csv)
			   break;
            case 9:
            	if(banderaLoad != 0)
					if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
						printf("Se pudo guardar los empleados\n");
					else
						printf("No se pudo guardar los empleados\n");
            	else
            		printf("Se deben cargar los usuarios primero\n");
            	//Guardar los datos (data.bin)
            	break;
            case 10:
            	//Salir
            	 seguir='n';
				break;
        }
    }while(seguir=='s');
    return 0;
}
