#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define ORANGE	"\033[33m"		/* orange */
#define BLUE	"\033[34m"		/* blue */
//Fabrica
#include "Fabrica.h"

//Interfaces
#include "ICAltaUsuario.h"
#include "ICAltaAsignatura.h"
#include "ICAsignarAsignaturaDocente.h" /*7777777777777*/

// DT's
#include "DtPerfil.h"
#include "DtAsignatura.h"

#include <iostream>
#include <list>

Fabrica* fab;
ICAltaUsuario* icaltausuario;
ICAltaAsignatura* icalta_asignatura;
ICAsignarAsignaturaDocente* icasig_docente; /*7777777777777*/



using namespace std;

void menu(){
    cout << "Seleccione una opcion:" << endl;
    cout <<GREEN<<"1 ➢ Alta de usuario" <<RESET<< endl;
	cout <<GREEN<< "2 ➢ Alta de asignatura"<<RESET << endl;
    cout << "3 ➢ Asignacion de docentes a una asignatura:" << endl;
    cout << "4 ➢ Inscripcion a las asignaturas" << endl;
    cout << "5 ➢ Inicio de clase" << endl;
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

// 3 ASIGNAR ASIGNATURA  DOCENTE

void menuAsignarAsignaturaDocente(){
	bool sigueasignado=true;
	while(sigueasignado){
		bool listavacia=false;
		list<string>::iterator it;
		list<string> listaA=icasig_docente->listarAsignaturas();
		if(!listaA.empty()){
			string codigo;
			string email;
			TipoRol rol_m;
			int opciondeRol=false;
			bool terminarTipoRol=true;
			bool selecciono_rol=false;
			int confirmar;

			cout << RED<< "Codigo de asignaturas:" <<RESET<< endl;
			for(it=listaA.begin(); it!=listaA.end();++it){
				cout << *(it) << endl;
			}

			cout<<"\nInserte codigo de Asignatura a Asignar:"<< endl;
			cin >> codigo;

			cout<< "\nDocentes sin asignacion: "<<endl;
			list<string> listaDs=icasig_docente->docentesSinLaAsignatura(codigo);
			if(!listaDs.empty()){//si no esta vacia
				for(it=listaDs.begin(); it!=listaDs.end(); ++it){
						cout<<*(it)<<endl;
					}
					cout<< "Ingrese uno de estos email para continuar:";
					cin>>email;

					while(terminarTipoRol){
						cout << "Ingrese el Rol a cumplir (1 TEORICO, 2 PRACTICO, 3 MONITOREO)" << endl;
						cin >> opciondeRol;
						switch (opciondeRol){
							case(1):rol_m= TEORICO;
									selecciono_rol=true;
									break;
							case(2):rol_m=PRACTICO;
									selecciono_rol=true;
									break;

							case(3):rol_m=MONITOREO;
									selecciono_rol=true;
									break;	
							default:cout<< "Opcion incorrecta."<<endl;
									break;
						}
						if (selecciono_rol){
							terminarTipoRol=false;
							icasig_docente->selectDocente(email,rol_m);
						}else{
							cout <<ORANGE<< "\nNo ha asignado ningun tipo de clase." <<RESET<< endl;
						}

					}

					cout << "\nDesea confirmar la asigancion? (1 para si, cualquier otro numero para no)" << endl;
					cin >> confirmar;

					if(confirmar==1){
						icasig_docente->asignarDocente();
						cout << "\nSe asigno el Docente con exito a la asignatura." << endl;
					} else{
						cout << "\nSe cancelo correctamente." << endl;
					}
			}else{
				cout<<RED<<"\nNo hay ningun Docente"<<RESET<<endl;
				listavacia=true;
				sigueasignado=false;
			}
		}else{
			cout<<RED<<"\nNo hay ningun Asignatura"<<RESET<<endl;
			listavacia=true;
			sigueasignado=false;
		}
		if(!listavacia){
			cout << "Desea seguir asignando Docentes? (0 para seguir asignando, cualquier otro numero para cancelar)" << endl;
			int opcionSeguirAsignando;
			cin >> opcionSeguirAsignando;

			if(opcionSeguirAsignando != 0){
				sigueasignado = false;
			}
		}
	}
}
int main(){

	icaltausuario = fab->getCAltaUsuario();
	icalta_asignatura = fab->getCAltaAsignatura();
	icasig_docente = fab->getCAsignarAsignaturaDocente();
	
    int opcion;
    menu();
    cin >> opcion;

    while(opcion != 10){
        switch(opcion){
            case 1: menuAltaUsuario();
                    break;
            case 2:	menuAltaAsignatura();
                    break;
            case 3: menuAsignarAsignaturaDocente();
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