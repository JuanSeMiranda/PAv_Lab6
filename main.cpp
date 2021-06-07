//Fabrica
#include "Fabrica.h"

//Interfaces
#include "ICAltaUsuario.h"

// DT's
#include "DtPerfil.h"


#include <iostream>

Fabrica* fab;
ICAltaUsuario* icaltausuario;



using namespace std;

void menu(){
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Asignacion de docentes a una asignatura:" << endl;
    cout << "3. Inscripcion a las asignaturas" << endl;
    cout << "4. Inicio de clase" << endl;
    cout << "5. Asistencia a clase en vivo" << endl;
    cout << "6. Envio de mensaje" << endl;
    cout << "7. Eliminacion de asignatura" << endl;
    cout << "8. Listado de Clases" << endl;
    cout << "9. Salir" << endl;
}

void menuAltaUsuario(){
	bool seguirIngreasandoUsuario = true;
	string nombre;
	string imagen_url;
	string email;
	string password;

	while(seguirIngreasandoUsuario){
		cout << "Ingrese su nombre: ";
		cin >> nombre;
		cout << "Ingrese el URL de su imagen: ";
		cin >> imagen_url;
		cout << "Ingrese su email: ";
		cin >> email;
		cout << "Ingrese su password: ";
		cin >> password;
		DtPerfil* datosperfil = new DtPerfil(nombre, imagen_url, email, password);
		icaltausuario->ingresarDatosPerfil(datosperfil);
		

    	cout << "holi" << endl;// <-- Tan re cocos.
	}

	
}

int main(){

	icaltausuario = fab->getCAltaUsuario();

    int opcion;
    menu();
    cin >> opcion;

    while(opcion != 9){
        switch(opcion){
            case 1: menuAltaUsuario();
                    break;
            case 2:
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 5:
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 8:
                    break;
            default: cout << "Opcion invalida." << endl;
                    break;
        }
        menu();
        cin >> opcion;
    }


     return 0;
}