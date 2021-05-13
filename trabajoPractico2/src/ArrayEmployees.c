 /*
 * arrayEmployees.c
 *
 *  Created on: 13 may. 2021
 *      Author: Joaquin Gabriel Messina
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define FALSO 0
#define VERDAD 1
#define ERROR -1
#define EXITO 0
#define DESCENDENTE 0
#define ASCENDENTE 1



int initEmployees(sEmployee* list, int len)
{
    int ret = ERROR;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = VERDAD;
        }
        ret = EXITO;
    }
    return ret;
}


int addEmployee(sEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int ret = ERROR;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == VERDAD)
            {
                list[i].id = 10 + i;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = FALSO;
                ret = EXITO;
                break;
            }
        }
    }

    return ret;
}

int findEmployeeById(sEmployee* list, int len,int id)
{
    int ret = ERROR;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == FALSO)
            {
                ret = i;
                break;
            }
        }
    }

    return ret;
}


int removeEmployee(sEmployee* list, int len, int id)
{
    char respuesta;
    int ret = ERROR;
    if(len > 0 && list != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                printf("\nEstas seguro que quiere dar de baja al Empleado: \n");
                printf("\n--->%10s    %10s    <---\n",list[i].name,list[i].lastName);
                respuesta=getRespuesta();
                if(respuesta=='s')
                {
                    list[i].isEmpty = VERDAD;
                    ret = EXITO;
                    printf("Se realizo la baja exitosa.\n");
                    break;
                }
                else
                {
                    printf("\nUsted cancelo la baja con exito.\n");

                    break;
                }

            }
            else
            {
                printf("\nEl id ingresado no existe.");
            }
        }
    }

    return ret;
}


int sortEmployees(sEmployee* list, int len, int order)
{
    int ret = ERROR;
    sEmployee aux;
    if(len > 0 && list != NULL)
    {
        switch(order)
        {
        case DESCENDENTE:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == FALSO && list[i].isEmpty == FALSO)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == FALSO && list[i].isEmpty == FALSO)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
            ret = EXITO;
            break;
        case ASCENDENTE:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == FALSO && list[i].isEmpty == FALSO)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == FALSO && list[i].isEmpty == FALSO)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
            ret = EXITO;
            break;
        default:
            printf("Opcion de ordenamiento invalida ");
        }
    }
    return ret;
}


int printEmployees(sEmployee* list, int length)
{
    int ret = ERROR;
    if(length > 0)
    {
        printf("\n\nID              Name                  LastName       Salary      Sector\n");
        for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == FALSO)
            {
                fflush(stdin);
                printf("%6d %15s %23s %15.2f %6d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        printf("\n\n");
        ret = EXITO;
    }

    return ret;
}


void TotalPromedioSalarios (sEmployee empleado[], int len)
{
    float prom = 0;
    float total = 0;
    int cantEmployee = 0;
    int salariomayorapromedio = 0;

    for(int i = 0; i < len; i++)
    {
        if(empleado[i].isEmpty == FALSO)
        {
            cantEmployee++;
            total += empleado[i].salary;
        }
    }
    prom = total/cantEmployee;

    for(int i = 0; i < len; i++)
    {
        if(empleado[i].isEmpty == FALSO)
        {
            if(empleado[i].salary > prom)
            {
                salariomayorapromedio++;
            }
        }
    }

    printf("Total Salarios: %.2f\n\n", total);
    printf("Promedio Salarios: %.2f\n\n", prom);
    printf("Cantidad de Empleados que superan el promedio: %d\n\n", salariomayorapromedio);
}


int getIDEmployee(sEmployee empleado[],int tam)
{
    int id;
    printEmployees(empleado,tam);
    printf("Ingrese ID del Empleado ");
    scanf("%d", &id);
    return id;
}



void showMessage(int idret, int from, int hayempleados)
{
    if(idret != ERROR)
    {
        printf("\nEl proceso finalizo exitosamente\n");
    }

    else if(hayempleados == VERDAD)
    {
        switch(from)
        {
        case 1:
            printf("\nError al dar de alta el Empleado.\n\n");
            break;
        case 2:
            printf("\nNo se encuentra el ID del Empleado.\n\n");
            break;
        case 3:
            printf("\nDebe cargar bien el tipo de dato.\n\n");
            break;
        case 4:
            printf("\nSe completo la operacion\n\n");
            break;
        case 5:
            printf("\nId Ingresado no existe.\n");
            break;
        default:
            printf("ERROR");
            break;
        }
    }
    else
    {
        if(from == 1)
        {
            printf("Error al dar de alta el Empleado.\n\n");
        }
        else
        {
            printf("Error al ejecutar la operacion. Debe dar de alta un Empleado primero.\n\n");
        }

    }

}



int hayEmpleados(sEmployee empleado[], int tam)
{
    int ret = FALSO;

    for(int i = 0; i < tam; i++)
    {
        if(empleado[i].isEmpty == FALSO)
        {
            ret = VERDAD;
            break;
        }
    }

    return ret;
}


int showMenuAndGetOption()
{
    int opcion;

    fflush(stdin);
    printf("1-Alta\n");
    printf("2-Baja\n");
    printf("3-Modificacion\n");
    printf("4-Mostrar empleados\n");
    printf("5-Ordenar empleados\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 5)
    {
        printf("Opcion incorrecta\n\n");
        opcion = showMenuAndGetOption();

        scanf("%d", &opcion);
    }

    return opcion;
}


int getOptionEdit()
{
    char optionAux[50];
    int option;
    printf("Ingrese un valor segun el  campo que desea modificar: \n\n1 - NOMBRE\n2 - APELLIDO\n3 - SALARIO\n4 - SECTOR\n\n");
       if (!getStringNumeros("\nIngrese una opcion: ",optionAux))
                {
                    printf ("La opcion es de 1 a 4.\n");

                }

                else
                {


                option=atoi(optionAux);
                }



    return option;
}



int getOrder()
{
    int order;
    printf("Ingrese el orden en que quiere ordenar el sector y apellido de los empleados\n0. Descendente\n1. Ascendente\n");
    scanf("%d", &order);
    return order;
}



char getRespuesta()
{
    char respuesta;

    fflush(stdin);
    printf("Desea continuar? [s/n]\n");
    scanf("%c", &respuesta);

    while(respuesta != 's' && respuesta != 'n')
    {
        fflush(stdin);
        printf("Desea continuar? [s/n]\n");
        scanf("%c", &respuesta);
    }
    return respuesta;
}

int findFreePlace(sEmployee empleado[], int tam)
{
    int ret = ERROR;

    for(int i = 0; i < tam; i++)
    {
        if(empleado[i].isEmpty == VERDAD)
        {

            ret = EXITO;
        }
    }

    return ret;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    int i=0;
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        i++;
    }
    return i;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int getindex(sEmployee empleado[],int tam)
{
    int id;
    int idAutomatico = ERROR;
    fflush(stdin);
    printEmployees(empleado,tam);
    printf("Ingrese el ID del Empleado \n");
    scanf("%d", &id);
    idAutomatico = findEmployeeById(empleado,tam,  id);
    return idAutomatico;
}
