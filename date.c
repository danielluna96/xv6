#include "types.h"
#include "user.h"
#include "date.h"

int bisiesto(int);
void dia(int,int,int);
void mes(int);
void fechayhorautc(void);
//En un arreglo de char agrego los d�as de la semana
char dias[7][9] = {
	"Lunes",
	"Martes",
	"Miercoles",
	"Jueves",
	"Viernes",
	"Sabado",
	"Domingo"
};
//En un arreglo de char agrego los meses
char meses[12][10] = {
	"Enero",
	"Febrero",
	"Marzo",
	"Abril",
	"Mayo",
	"Junio",
	"Julio",
	"Agosto",
	"Septiembre",
	"Octubre",
	"Noviembre",
	"Diciembre"
};

// main
int main(int argc, char *argv[])
{
	// Si se ejecuta sin argumentos adicionales muestra la fecha y hora en formato UTC
	if(argc==1)
		fechayhorautc();  // Ejecuta la funci�n para mostrar la fecha y hora en UTC
	else
	{
		printf(1,"Uso: fecha \n");
	}
exit();
}

// Esta funci�n imprime en pantalla le hora y fecha en formato UTC
void fechayhorautc()
{
	struct rtcdate r;
	if (date(&r)) //Usa la funci�n date y en r se carga la fecha y hora.
	{
		printf(2, "Fecha Incorrecta\n");
		exit();
	}
	printf(1,"Hora: %d:%d:%d ",r.hour,r.minute,r.second);  // Imprime en pantalla la hora en UTC
	dia(r.day,r.month,r.year);	 // Llama a la funci�n d�a para calcular que d�a de la semana es
	printf(1,", %d de",r.day);  // Imprime en pantalla el n�mero de d�a
	mes(r.month);  // Llama a la funci�n mes para obtener el nombre del mes
	printf(1," del %d",r.year);  // Imprime en pantalla el a�o
	printf(1," UTC\n");	 //Se agrega que es en formato UTC
}

// Esta funci�n trasforma fecha en el d�a de la semana
void dia(int d,int m,int y)
{
	int primerdia = 3;
	int suma = 0;	
	if(y>1970) //Si el a�o es superior a 1970
	{
		for(int i=1970;i<y;i++) //Suma por cada a�o trascurrido despues de 1970 365 d�as por a�o si no es bisiesto y 366 en caso de serlo al contador suma
		{
			if(bisiesto(i))
				suma += 366;
			else
				suma += 365;
		}
	}
	for(int i=1;i<m;i++) //
	{
		if(i==2)//Verifica si es Febrero
		{
			if(bisiesto(y))//Si es bisiesto
				suma += 29;//Suma 29 d�as
			else//Si no lo es
				suma += 28;//Suma 28 d�as
		}
		else if((i<8)&&(i%2==1)) //Verifica si el mes es impar y esta antes de Agosto
			suma += 31;//Suma 31 d�as
		else if((i<8)&&(i%2==0)) //Verifica si el mes es par y esta antes de Agosto
			suma += 30;//Suma 30 d�as
		else if((i>=8)&&(i%2==0)) //Verifica si el mes es par y si es Agosto o despues
			suma += 31; //Suma 31 d�as
		else //En los otros casos
			suma += 30; //Suma 30 d�as
	}
	int intdia = ((suma+d+primerdia-1)%7);
	printf(1,"%s",dias[intdia]);
}

// this function prints the name of the month of the year
void mes(int m)
{
	printf(1," %s",meses[m-1]);
}

// Esta funci�n verifica si el a�o que se le da, es bisiesto
int bisiesto(int y)
{
	int bis = 0;
	if(y%400==0) //Si es divisible por 400 
		bis = 1; //es bisiesto
	else if(y%100==0) //Si no es divisible por 400 pero si por 100
		bis = 0; //entonces no es bisiesto
	else if(y%4==0) //Si no cumple las anteriores pero si es divisible por 4
		bis = 1; //entonces es bisiesto
	else 
		bis = 0;
	return(bis); //regresa un 1 si es bisiesto y 0 si no lo es
}


