// Clase 4 - Clases y Objetos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Persona.h"
#include "Menu.h"

int main()
{
    std::cout << "Hello World!\n";

    //creación del objeto
    Persona persona;
    persona.edad = 12;
    cout << "La edad de la persona es: "
        << persona.edad<< endl;
    cout<<persona.ImprimirEdad()<<endl;
    persona.Caminar();
    cout << persona.Hablar();
    Menu menu;
    menu.ImprimirMenu();
}