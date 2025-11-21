#include "Usuario.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

bool Usuario::IniciarSesion()
{
    cout << "Usuario: ";
    cin >> correo;

    cout << "Password: ";
    cin >> password;

    //crear un vector de usuarios en memoria
    vector<shared_ptr<Usuario>> usuarios = ObtenerUsuarios();

    //recorrer el vector de usuarios y checar al usuario que está iniciando sesión
    for (const shared_ptr<Usuario> usuario : usuarios)
    {
        //usar el operador flecha para acceder a los punteros del vector
        cout << "ID: " << usuario->getId()
            << "| Correo: " << usuario->getCorreo() << endl;

        if (usuario->ValidarInicioSesion(correo, password))
        {
            cout << "Inicio de sesión exitoso!" << endl;
            getchar();
            return true;
        }
    }

    return false;
}

int Usuario::getId() const
{
	return id;
}

string Usuario::getCorreo() const
{
	return correo;
}

bool Usuario::RegistrarUsuario(string nombre, string correo, string password)
{
    vector<shared_ptr<Usuario>> usuarios = ObtenerUsuarios();

    for (const shared_ptr<Usuario> usuario : usuarios)
    {
        id = usuario->getId();
    }
    id++;   //incrementar en 1 el id para guardar el siguiente

	//Guardar usuario en archivo de texto
	ofstream outputFile("usuarios.txt",ios::app);
	
	if (outputFile.is_open())
	{
		outputFile << id << " " << nombre << " " << correo << " " << password << endl;
		outputFile.close();
        cout << "Usuario registrado exitosamente." << endl;
        getchar();
		return true;
	}
	else
		return false;
}

vector<shared_ptr<Usuario>> Usuario::ObtenerUsuarios()
{
    vector<shared_ptr<Usuario>> usuariosReg;
    //leer el archivo usuarios.txt y sacar los datos linea por linea
    ifstream inputFile("usuarios.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        return usuariosReg; // Salida con código de error
    }
    else
    {
        string line;

        vector<string> words;
        string word;
        //vector<shared_ptr<Usuario>> usuariosReg;

        while (getline(inputFile, line)) { // leer linea por linea
            std::cout << line << std::endl;

            //extraer los tokens de cada linea del archivo
            stringstream ss(line); // Crear un objeto stringstream desde la linea
            while (ss >> word) {
                words.push_back(word);
            }
            //llenar el vector de usuarios con los datos de cada linea del archivo
            usuariosReg.push_back(make_shared<Usuario>(stoi(words.at(0)), 
                words.at(1), words.at(2), words.at(3)));
            /*for (const std::string& w : words) {
                cout << w << std::endl;
            }*/
            words.clear();

            /*for (const shared_ptr<Usuario> usuario : usuariosReg)
            {
                cout << "ID: " << usuario->getId()
                    << "| Correo: " << usuario->getCorreo() << endl;
            }*/
        }
        inputFile.close();
        getchar();
        return usuariosReg;
    }
}
