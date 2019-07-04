//Simulacro examen final ej2

#include <iostream>
#include <conio.h>
#include <stdio.h>

#define ESCAPE 27

using namespace System;
using namespace std;

void genera_arreglo(int *horas, int *salidas, int n)
{
	Random x;

	for (int i = 0; i < n; i++)
	{
		horas[i] = i + 5;
	}
	for (int i = 0; i < n; i++)
	{
		salidas[i] = x.Next(5,41);
	}

}

void imprime_arreglo(int *horas, int *salidas, int n)
{
	cout << endl;
	cout << " Horas:  ";
	for (int i = 0; i < n; i++)
	{
		if (horas[i] < 10)
		{
			cout << horas[i] << "  ";
		}
		else
		{
			cout << horas[i] << " ";
		}
	}
	cout << endl;
	cout << " Buses:  ";
	for (int i = 0; i < n; i++)
	{
		if (salidas[i] < 10)
		{
			cout << salidas[i] << "  ";
		}
		else
		{
			cout << salidas[i] << " ";
		}
	}
	cout << endl;
	cout << endl;
}

void horas_mayor_salidas(int *horas, int *salidas, int n)
{
	int max = salidas[0];

	for (int i = 0; i < n; i++)
	{
		if (salidas[i] > max)
		{
			max = salidas[i];
		}

	}

	int contMax = 0;

	for (int i = 0; i < n; i++)
	{
		if (salidas[i] == max)
		{
			contMax++;
		}
	}

	int *variasHorasMax = new int[contMax];
	int aux = 0;

	for (int i = 0; i < n; i++)
	{
		if (salidas[i] == max)
		{
			variasHorasMax[aux] = horas[i];
			aux++;
		}
	}

	if (contMax == 1)
	{
		cout << " Maximo numero de salidas: " << max << endl;
		cout << " A las " << variasHorasMax[0] << " hrs " << endl;
	}
	if (contMax > 1)
	{
		cout << " Maximo numero de salidas: " << max << endl;
		for (int i = 0; i < contMax; i++)
		{
			cout << " A las " << variasHorasMax[i] << " hrs " << endl;
		}
	}

	cout << endl;
}

void promedio_salidas(int *salidas)
{
	int sumaSalidas= 0;
	int promedioSalidas = 0;

	for (int i = 0; i < 8; i++)
	{
		sumaSalidas += salidas[i];
	}

	promedioSalidas = sumaSalidas / 8;

	cout << " El promedio de salidas de la maniana es : " << promedioSalidas << endl;
	cout << endl;
}

void ordena_arreglo(int *horas, int *salidas, int n)
{
	cout << " ORDEN DESCENDENTE SEGUN LA CANTIDAD DE SALIDAS ";
	cout << endl;
	int auxhoras;
	int auxsalidas;

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (salidas[i] < salidas[j])
			{
				auxsalidas = salidas[i];
				salidas[i] = salidas[j];
				salidas[j] = auxsalidas;

				auxhoras = horas[i];
				horas[i] = horas[j];
				horas[j] = auxhoras;
			}
		}
	}

	cout << " Horas:  ";
	for (int i = 0; i < n; i++)
	{
		if (horas[i] < 10)
		{
			cout << horas[i] << "  ";
		}
		else
		{
			cout << horas[i] << " ";
		}
	}
	cout << endl;
	cout << " Buses:  ";
	for (int i = 0; i < n; i++)
	{
		if (salidas[i] < 10)
		{
			cout << salidas[i] << "  ";
		}
		else
		{
			cout << salidas[i] << " ";
		}
	}
	cout << endl;
	cout << endl;
}

int main()
{
	Console::CursorVisible = false;

	bool todo = true;
	int n;

	Random r;
	char tecla;

	while (todo == true)
	{
		Console::Clear();
		n = r.Next(10, 20);

		int *horas = new int[n];
		int *salidas = new int[n];

		genera_arreglo(horas, salidas, n);
		imprime_arreglo(horas, salidas, n);
		horas_mayor_salidas(horas, salidas, n);
		promedio_salidas(salidas);
		ordena_arreglo(horas, salidas, n);

		delete[] horas;
		delete[] salidas;
		do
		{
			cout << " Presione ESCAPE para salir o 'C' para continuar " << endl;
			tecla = _getch();
			if (tecla == ESCAPE)
			{
				todo = false;
				break;
			}
			if (tecla == 'C')
			{
				todo = true;
				break;
			}


		}while(toupper(tecla) != 'C' || tecla == ESCAPE);

	}

	return 0;
}