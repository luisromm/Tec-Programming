// Clase 2 - Promedio Calificaciones.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

//Declaración de prototipos de funciones
double CalcularPromedioFinal();
void SetColor(int, int);

using namespace std;

int main()
{    
    cout << "La calificacion final es de " << CalcularPromedioFinal();
    SetColor(15, 0);
}

//declaracion de funciones
double CalcularPromedioFinal()
{
    //variables
    double promCalifs = 0, califPar;
    double califExamFinal;
    double trabajoFinal;
    double califFinal = 0;

    SetColor(5, 0);

    for (int i = 0; i < 3; i++)
    {
        cout << "Introduce la calificacion parcial " << i + 1 << endl;
        cin >> califPar;
        promCalifs += califPar;
    }

    //calcular el promedio de las calificaciones parciales
    promCalifs = promCalifs / 3;

    //agregar el porcentaje de los parciales a la calificación final
    califFinal += promCalifs * 0.55;

    cout << "Introduce la calificacion del Examen Final" << endl;
    cin >> califExamFinal;

    califFinal += califExamFinal * 0.30;

    cout << "Introuduce la calificacion del Proyecto Final" << endl;
    cin >> trabajoFinal;

    califFinal += trabajoFinal * 0.15;

    SetColor(7, 15);

    return califFinal;
}

void SetColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}