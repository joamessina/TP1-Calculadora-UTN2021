#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_generarNuevoId(void);
int employee_validName(char* cadena,int limite);
int employee_allSet(Employee* this,char* nombre, int sueldo,int horasTrabajadas, int id);
int employee_allGet(Employee* this,char* nombre, int *sueldo,int *horasTrabajadas, int *id);
#endif // employee_H_INCLUDED
