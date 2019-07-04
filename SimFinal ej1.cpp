//Simulacro examen final ej1

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace System;
using namespace std;

void generarMensaje(int * mensaje, int n, int &cont)
{
	Random x;
	cont++;
	int aux;
	
	for (int i = 0; i < n; i++)
	{
		aux = x.Next(0, 3);

		if (aux == 0)
		{
			mensaje[i] = 0;
		}
		if (aux == 1)
		{
			mensaje[i] = 2;
		}
		if (aux == 2)
		{
			mensaje[i] = 5;
		}


	}
}
void mostrarMensaje(int * mensaje, int n)
{
	cout << endl;
	cout << " ";
	for (int i = 0; i < n; i++)
	{
		cout << mensaje[i] << " ";

	}
	cout << endl;
}

bool evaluarFrio(int *mensaje, int n)
{
	if (mensaje[0] == 2 && mensaje[1] == 5 && mensaje[2] == 2)
	{
		return true;
	
	}
	else
	{
		return false;
	}
}
bool evaluarCalor(int *mensaje, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (mensaje[i] == 2 && mensaje[i + 2] == 0 && mensaje[i + 4] == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}
bool evaluarHambre(int *mensaje, int n)
{
	if (mensaje[n - 3] == 5 && mensaje[n - 2] == 0 && mensaje[n - 1] == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool evaluarPeligro(int * mensaje, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (mensaje[i] == 0 && mensaje[i + 1] == 0 && mensaje[i + 2] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void verificarMensaje(int *mensaje, int n, int &contfrio, int &contcalor, int &conthambre)
{
	if (evaluarFrio(mensaje, n))
	{
		cout << " Las personas tienen frio " << endl;
		contfrio++;
	}
	if (evaluarCalor(mensaje, n))
	{
		cout << " Las personas tienen calor " << endl;
		contcalor++;
	}
	if (evaluarHambre(mensaje, n))
	{
		cout << " Las personas tienen hambre " << endl;
		conthambre++;
	}
	if (evaluarPeligro(mensaje, n))
	{
		cout << " Peligro! " << endl;
	}

	cout << endl;
}

int main()
{
	Console::CursorVisible = false;
	Random r;

	bool todo = true;
	char tecla;
	
	int n;
	int contmensajes = 0;
	int contfrio = 0;
	int contcalor = 0;
	int conthambre = 0;
	   
	while (todo == true)
	{
		n = r.Next(10, 21);
		int *mensaje = new int[n];

		generarMensaje(mensaje, n, contmensajes);
		mostrarMensaje(mensaje, n);
		verificarMensaje(mensaje, n, contfrio, contcalor, conthambre);

		do
		{
			cout << " Presione 'T' para mostrar resumen o 'C' para continuar viendo los mensajes " << endl;
			tecla = _getch();

			if (toupper(tecla) == 'T')
			{
				todo = false;
				break;
			}
			if (toupper(tecla) == 'C')
			{
				todo = true;
				break;
			}

		} while (toupper(tecla) != 'T' || toupper(tecla) != 'C');

	}

	cout << endl;
	cout << " RESUMEN DE LOS MENSAJES " << endl;
	cout << " ======================= ";
	cout << endl;
	cout << " Cantidad de mensajes que se procesaron: " << contmensajes << endl;
	cout << " Cantidad de veces que se ha solicitado abrigo: " << contfrio << endl;
	cout << " Cantidad de veces que se ha solicitado agua: " << contcalor << endl;
	cout << " Cantidad de veces que se ha solicitado alimento: " << conthambre << endl;
	cout << endl;
	cout<< " PRESIONE CUALQUIER TECLA PARA SALIR ";
	_getch();
	return 0;

}