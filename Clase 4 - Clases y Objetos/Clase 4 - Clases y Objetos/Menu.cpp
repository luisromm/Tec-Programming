#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::ImprimirMenu()
{
	int op;
	do {
		cout << "Menu" << endl;
		cout << "1 - Sumar \n2 - Restar" << endl;
		cout << "3 - Salir" << endl;
		cin >> op;
		switch (op)
		{
		case 1: Suma suma;
			suma.ImprimirSuma(2, 3);
			break;
		case 2: Resta resta;
			resta.ImprimirResta(2, 3);
			break;
		default:
			break;
		}
	} while (op != 3);

}
