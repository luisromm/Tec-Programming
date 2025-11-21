#pragma once
#include <string>
#include <iostream>

using namespace std;

class Persona
{
public:
	//atributos
	string nombre;
	int edad;
	double estatura;

public:
	//métodos
	string Hablar()
	{
		return "Holaaaaa";
	}

	void Caminar()
	{
		cout << "Estoy caminando" << endl;
	}

	//definición de prototipos
	string ImprimirEdad();
};

