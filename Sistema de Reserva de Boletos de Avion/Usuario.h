#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Usuario
{
	//atributos
public:
	int id=0;
	string nombre;
	string correo;
	string password;
	
	//métodos
public:
	//constructor parametrizado
	Usuario(int id, string nombre, string correo, string password)
		:id(id), nombre(nombre), correo(correo), password(password) {
	};

	//constructor por defecto
	Usuario() {};

	bool IniciarSesion();

	bool ValidarInicioSesion(const string& enteredEmail, 
		const string& enteredPassword) const {
		return (correo == enteredEmail && password == enteredPassword);
	};

	int getId() const;
	string getCorreo() const;

	bool RegistrarUsuario(string nombre, string correo, string password);

	vector<shared_ptr<Usuario>> ObtenerUsuarios();
};