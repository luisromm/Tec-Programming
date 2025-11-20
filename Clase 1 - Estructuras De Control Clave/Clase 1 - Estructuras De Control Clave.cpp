// Clase 1 - Estructuras De Control Clave.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Programa 1 - Estructuras de Control
//Desarrollado por: Luis Morales
//Fecha: 3/11/2025
//Empresa: Tec de Monterrey
//Area: Sistemas

#include <iostream>

using namespace std;

int main()
{
    //variables
    int edad;
    bool cond = 46;
    
    //Estructuras de control basicas
   //if - Condicional simple
    cout << "Introduce tu edad: ";
    std::cin >> edad;
    //estructura
    //if(operando1 operador operando2)
    if (edad >= 18)
    {
        cout << "Eres mayor de edad" << endl;
    }
    else
    {
        cout << "Con " << edad << "Aún no eres mayor de edad" << endl;
    }

    //Condicional multiple
    //estructura
    //switch(variable a evaluar)
    //case valor: accion a realizar
    switch (edad)
    {
    case 10: cout << "Eres aún un niño" << endl;
        //break;
    case 15: cout << "Eres un adolescente" << endl;
        //break;
    case 21: cout << "Eres un adulto formalmente" << endl;
        //break;
    default: cout << "La edad que tienes no es una opción válida" << endl;
        //break;
    }

    //Ciclos o bucles
    //Ciclo Para
    //estructura
    //for(valorInicial;condicion;incremento)
    for (int i = 0; i < 100; i+=100)
    {
        cout << "Esta es i: " << i << endl;
    }
    cond = false;
    //Ciclo Mientras
    //estructura
    //while(condicion)
    while (cond)
    {
        cout << "La condición es verdadera" << endl;
        
    }

    //Ciclo Hacer-Mientras
    //estructura
    //do{sentencias}while(condicion);
    do
    {
        cout << "Hacer mientras la condición sea verdadera" << endl;
        //cond = false;
    } while (cond);

    //valor de retorno tipo int
    return 0;
}