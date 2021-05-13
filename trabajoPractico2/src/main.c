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
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TAM 3
#define FALSO 0
#define VERDAD 1
#define ERROR -1
#define EXITO 0

int main()
{
	setbuf(stdout,NULL);
    sEmployee empleado[TAM];
    int opcion;
    int es;
    int idAutomatico;
    int orden;
    int flagHayEmpleado;
    int optionEdit;
    int sector;
    char name[20];
    char lastname[20];
    char salaryAux[50];
    char sectorAux[50];
    char respuesta;
    float salary;

    initEmployees(empleado, TAM);

    do
    {
        es = ERROR;
        opcion = showMenuAndGetOption();
        switch(opcion)
        {
        case 1:
            if(findFreePlace(empleado, TAM) == EXITO)
            {

                if (!getStringLetras("Ingrese el nombre: ",name))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }
                if (!getStringLetras("\nIngrese el apellido: ",lastname))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }
                if (!getStringNumeros("\nIngrese el salario: ",salaryAux))
                {
                    printf ("El salario debe ser numerico\n");
                    break;
                }
                salary = atoi(salaryAux);

                if (!getStringNumeros("\nIngrese el sector: ",sectorAux))
                {
                    printf ("El sector debe ser numerico\n");

                    break;
                }
                sector = atoi(sectorAux);
                es = addEmployee(empleado, TAM, idAutomatico, name, lastname, salary, sector);
                if(es == EXITO)
                {
                    flagHayEmpleado = VERDAD;
                }
                else
                {
                    flagHayEmpleado = FALSO;
                }
                showMessage(es, 1, flagHayEmpleado);
            }
            else
            {
                printf("Array lleno.\n\n");
            }
            break;
        case 2:
            flagHayEmpleado = hayEmpleados(empleado, TAM);

            if(flagHayEmpleado == VERDAD)
            {
                idAutomatico = getIDEmployee(empleado,TAM);
                es = removeEmployee(empleado, TAM, idAutomatico);
                break;
            }
            printf("\nDebe dar de alta a un empleado para realizar esta opcion.");

            break;
        case 3:
            flagHayEmpleado = hayEmpleados(empleado, TAM);

            if(flagHayEmpleado == VERDAD)
            {
                idAutomatico = getindex(empleado,TAM);

                if(idAutomatico >= 0)
                {
                    optionEdit = getOptionEdit();

                    switch((int) optionEdit)
                    {
                    case 1:
                        if (!getStringLetras("Ingrese nuevo nombre: ",name))
                        {
                            printf ("El nombre debe estar compuesto solo por letras\n");
                            es=ERROR;
                            break;
                        }
                        strcpy(empleado[idAutomatico].name, name);
                        es = EXITO;
                        break;
                    case 2:
                        if (!getStringLetras("\nIngrese nuevo apellido: ",lastname))
                        {
                            printf ("El apellido debe estar compuesto solo por letras\n");
                            es=ERROR;
                            break;
                        }
                        strcpy(empleado[idAutomatico].lastName, lastname);
                        es = EXITO;
                        break;
                    case 3:
                        if (!getStringNumeros("\nIngrese el nuevo salario: ",salaryAux))
                        {
                            printf ("El salario debe ser numerico\n");
                            break;

                        }
                        else
                        {
                            salary = atoi(salaryAux);
                            empleado[idAutomatico].salary=salary;
                            es = EXITO;
                        }
                        break;
                    case 4:
                        if (!getStringNumeros("\nIngrese el nuevo sector: ",sectorAux))
                        {
                            printf ("El sector debe ser numerico\n");
                        }
                        else
                        {
                            sector = atoi(salaryAux);
                            empleado[idAutomatico].sector=sector;
                            es = EXITO;
                        }
                        break;
                    default:
                        es=ERROR;
                        printf("Opcion incorrecta\n");
                        break;
                    }
                }
                else
                {
                    showMessage(es, 5, flagHayEmpleado);
                }
            }
            else
            {
                showMessage(es, 4, flagHayEmpleado);
            }
            break;
        case 4:
            flagHayEmpleado = hayEmpleados(empleado, TAM);

            if( flagHayEmpleado == VERDAD)
            {
                es = printEmployees(empleado, TAM);
                if(es == ERROR)
                {
                    printf("Error al imprimir los empleados.\n\n");
                }
                TotalPromedioSalarios(empleado, TAM);
                es = EXITO;
            }
            else
            {
                showMessage(es, 4, flagHayEmpleado);
            }
            break;

        case 5:
            flagHayEmpleado = hayEmpleados(empleado, TAM);

            if( flagHayEmpleado == VERDAD)
            {
                orden = getOrder();
                es = sortEmployees(empleado, TAM, orden);
                if(es == ERROR)
                {
                    printf("Error al ordenar la lista de empleados.\n\n");
                }

                es = printEmployees(empleado, TAM);
                if(es == ERROR)
                {
                    printf("Error al imprimir los empleados.\n\n");
                }
                TotalPromedioSalarios(empleado, TAM);
                es = EXITO;
            }
            else
            {
                showMessage(es, 4, flagHayEmpleado);
            }
            break;
        default:
            break;
        }
        respuesta = getRespuesta();
    }
    while(respuesta == 's');

    return 0;
}
