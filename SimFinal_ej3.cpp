#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
using namespace System;

void genera_y_muestra_matriz(int **mapa)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if ((i == 3 && j >= 5 && j <= 19) || (i >= 4 && i <= 16 && j == 5) || (i >= 4 && i <= 16 && j == 10) || (i == 16 && j >= 6 && j <= 9)
				|| (i == 6 && j >= 11 && j <= 18) || (i >= 4 && i <= 8 && j == 19))
			{
				mapa[i][j] = 2;
			}
			else
			{
				mapa[i][j] = 1;
			}
		}

	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (mapa[i][j] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Yellow;
				cout << char(219);


			}
			if (mapa[i][j] == 2)
			{
				Console::ForegroundColor = ConsoleColor::Gray;
				cout << char(219);


			}
		}

		cout << endl;
	}
}

void DibujarMovil(int &PosX, int &PosY)
{
	Console::SetCursorPosition(PosX, PosY);
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "*";
}
void BorrarMovil(int &PosX, int &PosY)
{
	Console::SetCursorPosition(PosX, PosY);
	Console::BackgroundColor = ConsoleColor::Yellow;
	cout << " ";
}

void DibujarEnemigo(int &PosXE, int &PosYE, int &DireE)
{
	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(PosXE, PosYE);
	cout << " ";
	if (PosXE == 0 || PosXE == 22)
	{
		DireE *= -1;
	}
	if (DireE == 1)
	{
		Console::SetCursorPosition(PosXE += DireE, PosYE);
		cout << char(2);
	}
	if (DireE == -1)
	{
		Console::SetCursorPosition(PosXE += DireE, PosYE);
		cout << char(2);
	}

}

void desplazar_movil(int **mapa,char tecla,  int &PosX, int& PosY, int &PosXE, int &PosYE, int &DireE, int &PosXInicial, int &PosYInicial, int &comida)
{
	
	DibujarMovil(PosX, PosY);
	DibujarEnemigo(PosXE, PosYE, DireE);

	if (kbhit())
	{
		tecla = _getch();
		if (tecla == 77) {
			BorrarMovil(PosX, PosY);
			PosX++;
		}
		else {
			if (tecla == 75) {
				BorrarMovil(PosX, PosY);
				PosX--;
			}
			else {
				if (tecla == 72) {
					BorrarMovil(PosX, PosY);
					PosY--;

				}
				else {
					if (tecla == 80) {
						BorrarMovil(PosX, PosY);
						PosY++;

					}
				}
			}
		}
	}
	
	if (PosX == PosXE && PosY == PosYE)
	{
		PosX = PosXInicial;
		PosY = PosYInicial;

	}
	if (PosX > 22 || PosX <0 || PosY < 0 || PosY>19 )
	{
		PosX = PosXInicial;
		PosY = PosYInicial;

	}
	
	
	
	DibujarMovil(PosX, PosY);

}
int main()
{
	Console::SetWindowSize(60, 25);
	Console::CursorVisible = false;

	bool juego = true;

	int **mapa;
	char tecla;

	mapa = new int*[20];
	for (int i = 0; i < 20; i++)
	{
		mapa[i] = new int[23];
	}

	int comida = 60;
	int PosX;
	int PosY;

	do {
		cout << " Ingrese la posicion inicial X del movil: ";
		cin >> PosX;
	} while (PosX > 22 || PosX < 0);
	do
	{
		cout << " Ingrese la posicion inicial Y del movil: ";
		cin >> PosY;
	} while (PosY < 0 || PosY > 19);
	
	Console::Clear();
	
	int PosXE = 11;
	int PosYE = 1;
	int DireE = 1;

	int PosXInicial = PosX;
	int PosYInicial = PosY;

	genera_y_muestra_matriz(mapa);
	


	while (juego == true)
	{
		Console::BackgroundColor = ConsoleColor::Black;
		
		
		desplazar_movil(mapa, tecla,PosX, PosY, PosXE, PosYE, DireE, PosXInicial, PosYInicial, comida);
			
		if (comida == 0)
		{
			juego = false;
		}
		_sleep(50);

	}


	for (int i = 0; i < 20; i++)
	{
		delete[] mapa[i];
	}

	delete[] mapa;

	

	Console::Clear();


	return 0;
}