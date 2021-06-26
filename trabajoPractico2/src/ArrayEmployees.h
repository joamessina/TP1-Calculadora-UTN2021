
#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int buscarLibre(Employee* arrayAlumnos, int len);
int addEmployee(Employee* list, int len);
int printEmployee(Employee* list, int len);
int removeEmployee(Employee* list, int len);
int mostrarUsuario(Employee* list,int indice);
int findEmployeeById(Employee* list,int len,int id);
int modificarEmployee(Employee* list,int len);
float calcularSalariosYpromedio(Employee *list,int len,float* pPromedio);
int sortEmployeesLastNameSector(Employee* list, int len);
int calcSueldosMayores(Employee list[],int len,int promedio);

int informes();
int menu();

