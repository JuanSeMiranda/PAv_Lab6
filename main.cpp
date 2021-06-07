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
	bool seguirIngresandoUsuario = true;

	string nombre;
	string imagen_url;
	string email;
	string password;
	TipoPerfil tipoPerfil;
	string doc;
	string inst;

	while(seguirIngresandoUsuario){
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

		cout << "Usted es un estudiante o docente? (0 es estudiante, 1 es docente)" << endl;
		int opcionTipoPerfil;
		bool terminarTipoPerfil = false;
		
		while(!terminarTipoPerfil){
            switch(opcionTipoPerfil){
				case 0: tipoPerfil = ESTUDIANTE;
						terminarTipoPerfil = true;
						cout << "Ingrese su documento:";
						cin >> doc;
						icaltausuario->ingresarEstudiante(doc);
						break;
				case 1: tipoPerfil = DOCENTE;
						terminarTipoPerfil = true;
						cout << "Ingrese su instituto:";
						cin >> inst;
						icaltausuario->ingresarDocente(inst);
						break;
				default: cout << "Opcion invalida." << endl;
						break;
			}
		}
		cout << "Desea confirmar el ingreso? (0 para confirmar, 1 para cancelar)" << endl;
		int opcionUsuario;
		cin >> opcionUsuario;
		
		if(opcionUsuario==0){
		    icaltausuario->altaUsuario();
            cout << "Usuario creado con exito." << endl; // <-- Tan re cocos. - ahora ya no crotolamo@dalto.com, uxiono, permatrago
        } else {
			
		}

		cout << "Desea seguir agregando usuarios?" << endl;
		int opcionSeguirAgregando;
		cin >> opcionSeguirAgregando;
		if(opcionSeguirAgregando == 0){
			
		} else if (opcionSeguirAgregando == 1){
			seguirIngresandoUsuario = false;
		}


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