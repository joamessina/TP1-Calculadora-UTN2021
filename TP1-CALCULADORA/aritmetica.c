/*
 Joaquin Gabriel Messina
 */
#include<stdio.h>
#include "aritmetica.h"

float suma(float numero_1, float numero_2)
{
	return numero_1 + numero_2;
}

float resta(float numero_1, float numero_2)
{
	return numero_1 - numero_2;
}

float multiplicacion(float numero_1, float numero_2)
{
	return numero_1 * numero_2;
}

float division(float numero_1, float numero_2)
{
	if(numero_2 == 0)
	{
		printf("no se divide por 0");
	}
	else
	{
		return numero_1 / numero_2;
	}
}
int factorial(float num)
{
	int fact= 1;
    int entero = (int)num;

	while(entero > 1)
	{
		fact = entero * fact;
		entero = entero - 1;
	}
	return fact;
}

float menu()
{
	int flag = 0;
	float numero_1;
	float numero_2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialA;
	int resultadoFactorialB;

    while (flag != 5)
	{
	    //menu
	    printf("1. ingresar primer numero: \n");
	    printf("2. ingresar segundo numero: \n");
	    printf("3. hacer cuentas: \n");
	    printf("4. mostrar resultados: \n");
	    printf("5. cerrar: \n");
		scanf("%d",&flag);
		switch(flag)
		{
		    //primer numero
        case 1:
            printf("ingrese el primer numero: ");
            scanf("%f",&numero_1);
            printf("\n");
            break;
            //segundo numero
        case 2:
            printf("ingrese el segundo numero: ");
            scanf("%f",&numero_2);
            printf("\n");
            break;
            //hace cuentas
        case 3:
            resultadoFactorialA = factorial(numero_1);
            resultadoSuma = suma(numero_1, numero_2);
            resultadoResta = resta(numero_1, numero_2);
            resultadoMultiplicacion = multiplicacion(numero_1, numero_2);
            resultadoDivision = division(numero_1, numero_2);

            resultadoFactorialB = factorial(numero_2);
            break;
            //entrega resultados
        case 4:
            printf("El resultado de %f+%f es: %f\n", numero_1, numero_2, resultadoSuma);
            printf("El resultado de %f-%f es: %f\n", numero_1, numero_2, resultadoResta);
            printf("El resultado de %f*%f es: %f\n", numero_1, numero_2, resultadoMultiplicacion);
            printf("El resultado de %f/%f es: %f\n", numero_1, numero_2, resultadoDivision);
            printf("El factorial de %f es: %d\n", numero_1, resultadoFactorialA);
            printf("El factorial de %f es: %d\n", numero_2, resultadoFactorialB);
		}
	}
}




