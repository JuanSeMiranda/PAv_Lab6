#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */

//Fabrica
#include "Fabrica.h"

//Interfaces
#include "ICAltaUsuario.h"
#include "ICAltaAsignatura.h"
#include "ICAsistenciaAClaseEnVivo.h"

// DT's
#include "DtPerfil.h"
#include "DtAsignatura.h"
#include "DtAsistir.h"

#include <iostream>

Fabrica* fab;
ICAltaUsuario* icaltausuario;
ICAltaAsignatura* icalta_asignatura;
ICAsistenciaAClaseEnVivo* icasistenciaaclaseenvivo;


using namespace std;

void menu(){
    cout << "Seleccione una opcion:" << endl;
    cout <<GREEN<<"1. Alta de usuario" <<RESET<< endl;
	cout <<GREEN<< "2. Alta de asignatura"<<RESET << endl;
    cout << "3 ➢ Asignacion de docentes a una asignatura:" << endl;
    cout << "4 ➢ Inscripcion a las asignaturas" << endl;
    cout << "5 ➢Inicio de clase" << endl;
    cout << "6 ➢ Asistencia a clase en vivo" << endl;
    cout << "7 ➢ Envio de mensaje" << endl;
    cout << "8 ➢ Eliminacion de asignatura" << endl;
    cout << "9 ➢ Listado de Clases" << endl;
    cout << "10 ➢ Salir" << endl;
}
// 1 ALTA USUARIO
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

		while(icaltausuario->existeUsuario(email)){
			cout << "Email ya ingresado, coloque otro email: ";
			cin >> email;
		}
		
		cout << "Ingrese su password: ";
		cin >> password;
		
		DtPerfil* datosperfil = new DtPerfil(nombre, imagen_url, email, password);
		icaltausuario->ingresarDatosPerfil(datosperfil);

		cout << "Usted es un estudiante o docente? (0 es estudiante, 1 es docente)" << endl;
		int opcionTipoPerfil;
		bool terminarTipoPerfil = false;
		
		while(!terminarTipoPerfil){
			cin >> opcionTipoPerfil;
            switch(opcionTipoPerfil){
				case 0: tipoPerfil = ESTUDIANTE;
						terminarTipoPerfil = true;
						cout << "Ingrese su documento: ";
						cin >> doc;
						icaltausuario->ingresarEstudiante(doc);
						break;
				case 1: tipoPerfil = DOCENTE;
						terminarTipoPerfil = true;
						cout << "Ingrese su instituto: ";
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
            cout << "Usuario creado con exito." << endl;
        } else {
			icaltausuario->cancelar();
		}

		cout << "Desea seguir agregando usuarios? (0 para seguir agregando, cualquier otro numero para cancelar)" << endl;
		int opcionSeguirAgregando;
		cin >> opcionSeguirAgregando;

		if(opcionSeguirAgregando != 0){
			seguirIngresandoUsuario = false;
		}
	}
}

// 2 ALTA ASIGNATURA
void menuAltaAsignatura(){
	string nombre;
	string codigo;
	bool teorico = false;
	bool practico = false;
	bool monitoreo = false;
	

	cout << "Ingrese el nombre de la Asignatura: ";
	cin >> nombre;

	cout << "Ingrese el codigo de la Asignatura: ";
	cin >> codigo;
	while(icalta_asignatura->existeAsignatura(codigo)){
		cout << "Ya existe una asignatura con ese codigo." << endl;
		cin >> codigo;
	}

	bool seguirAsignandoTipoClase = true;
	int opcionTipoClase;
	bool unTipoAsignado = false;

	while(seguirAsignandoTipoClase){
		cout << "Ingrese los tipos de clase para la Asignatura (1 teorico, 2 practico, 3 monitoreo)" << endl;
		cin >> opcionTipoClase;
		switch (opcionTipoClase){
		case 1:	teorico = true;
				unTipoAsignado = true;
				cout<< "Teoricos habilitados."<<endl;
				break;
		case 2:	practico = true;
				unTipoAsignado = true;
				cout<< "Practico habilitados."<<endl;
				break;
		case 3:	monitoreo = true;
				unTipoAsignado = true;
				cout<< "Monitoreo habilitados."<<endl;
				break;
		default: cout<< "Opcion incorrecta."<<endl;
				break;
		}
		
		if(unTipoAsignado){
			cout << "Quiere seguir asignando tipos de clase? (1 si, 2 no)"<< endl;
			int continua;
			cin >> continua;

			if(continua==2){
				seguirAsignandoTipoClase=false;
			}
		}else{
			cout << "No ha asignado ningun tipo de clase." << endl;
		}
		
	}

	DtInstanciaClase* dtic = new DtInstanciaClase(teorico, practico, monitoreo);
	DtAsignatura* dta = new DtAsignatura(nombre, codigo, dtic);
	icalta_asignatura->ingresar(dta);

	cout << *dta << endl;
	int opcionAsignatura;

	cout << "Desea dar de alta la Asignatura ingresada? (1 para si, cualquier otro numero para no)" << endl;
	cin >> opcionAsignatura;

	if(opcionAsignatura==1){
		icalta_asignatura->altaAsignatura();
		cout << "Se ingreso con exito la asignatura." << endl;
	} else{
		icalta_asignatura->cancelar();
		cout << "Se libero la memoria asignada a la Asignatura." << endl;
	}
	
}

// 6 ASISTENCIA A CLASE EN VIVO
void menuAsistenciaAClaseEnVivo(){
	int id;
	string cod;
	string email;
	bool ingresaMail = true;

	if(icasistenciaaclaseenvivo->perfilesVacio()){
		if(icasistenciaaclaseenvivo->asignaturasVacio()){
			if(icasistenciaaclaseenvivo->clasesVacio()){
				cout << "Ingrese su Email: ";
				cin >> email;

				while(ingresaMail){
					if(!icasistenciaaclaseenvivo->existeUsuario(email)){
						cout << "No existe el usuario ingresado, ingrese otro email" << endl;
						cin >> email;
					}

					if(!icasistenciaaclaseenvivo->esEstudiante(email)){
						cout << "El email ingresado no es de un estudiante, ingrese otro email" << endl;
						cin >> email;
					}

					if(icasistenciaaclaseenvivo->existeUsuario(email) && icasistenciaaclaseenvivo->esEstudiante(email)){
						cout << "Se ha encontrado al perfil y es de un estudiante" << endl;
						ingresaMail = false;
					}
				}

				icasistenciaaclaseenvivo->asignaturasInscripto(email);

				cout << "Ingrese el codigo de la asignatura: ";
				cin >> cod;

				if(icasistenciaaclaseenvivo->asignaturaTieneClases(cod)){
					while(!icasistenciaaclaseenvivo->existeAsignatura(cod)){
						cout << "El codigo ingresado no existe, ingrese otro codigo." << endl;
						cin >> cod;
					}

					icasistenciaaclaseenvivo->clasesOnlineDisponibles(cod);

					cout << "Ingrese la ID de la clase: ";
					cin >> id;

					while(!icasistenciaaclaseenvivo->existeClase(id)){
						cout << "El codigo ingresado no existe, ingrese otro codigo." << endl;
						cin >> cod;
					}

					icasistenciaaclaseenvivo->selectClase(id);

					cout << icasistenciaaclaseenvivo->selectClase(id) << endl;

					cout << "Desea confirmar? (1 para si, cualquier otro numero para no)" << endl;
					int opcionFinal;
					cin >> opcionFinal;
					
					if(opcionFinal==1)
						icasistenciaaclaseenvivo->asistirClaseEnVivo();

				}else
					cout << "La Asignatura no tiene Clases registradas." << endl;
				
			}else
				cout << "No hay ninguna Clase registrada." << endl;
		}else
			cout << "No hay ninguna Asignatura registrada." << endl;

	}else{
		cout << "No hay ningun Perfil registrado." << endl;
	}
	
	
}

int main(){

	icaltausuario = fab->getCAltaUsuario();
	icalta_asignatura = fab->getCAltaAsignatura();
	icasistenciaaclaseenvivo = fab->getCAsistenciaAClaseEnVivo();

    int opcion;
    menu();
    cin >> opcion;

	

    while(opcion != 10){
        switch(opcion){
            case 1: menuAltaUsuario();
                    break;
            case 2:	menuAltaAsignatura();
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 5:
                    break;
            case 6: menuAsistenciaAClaseEnVivo();
                    break;
            case 7:
                    break;
            case 8:
                    break;
			case 9:
					break;
            default: cout << "Opcion invalida." << endl;
                    break;
        }
        menu();
        cin >> opcion;
    }


     return 0;
}