#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */

//Fabrica
#include "Fabrica.h"

//Interfaces
#include "ICAltaUsuario.h"
#include "ICInscripcionAsignatura.h"
#include "ICInicioClase.h"
#include "ICAltaAsignatura.h"

// DT's
#include "DtPerfil.h"
#include "DtIniciarMonitoreo.h"
#include "DtAsignatura.h"

#include <iostream>

using namespace std;

Fabrica* fab;
ICAltaUsuario* icaltausuario;
ICInscripcionAsignatura* icinscripcionasignatura;
ICInicioClase* icinicioclase;
ICAltaAsignatura* icalta_asignatura;

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
	cout << "10 ➢ Cargar datos de prueba" << endl;
    cout << "11 ➢ Salir" << endl;
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

//4 INSCRIPCION A UNA ASIGNATURA

void menuInscripcionAsignatura(){
	int quiereInscribirse = 0;
	int confirmar;
	string asignaturaElegida;

	while(quiereInscribirse == 0){
		list<string> asignaturas = icinscripcionasignatura->asignaturasNoInscripto("email del estudiante de la sesion");
		list<string>::iterator it;
		for(it = asignaturas.begin(); it != asignaturas.end(); it++){
			cout << *it << endl;
		}
		cout << "Elija una de las asignaturas listadas escribiendo su codigo" << endl;
		cin >> asignaturaElegida;
		icinscripcionasignatura->selectAsignatura(asignaturaElegida);
		cout << "Quiere confirmar su eleccion?(0 para confirmar, cualquier otro numero para cancelar)" << endl;
		cin >> confirmar;
		if(confirmar == 0)
			icinscripcionasignatura->inscribir("email del estudiante de la sesion");

		cout << "Desea seguir inscribiendose(0 para confirmar, cualquier otro numero para cancelar)" << endl;
		cin >> quiereInscribirse;
	}
}

//5 INICIO CLASE

void menuInicioClase(){
	string codigo;
	string nombre;
	DtTimeStamp* fechaHora;
	DtFecha* fecha;
	int dia;
	int mes;
	int anio;
	int hora;
	int minuto;
	int segundo;

	cout << "Ingrese el codigo" << endl;
	cin >> codigo;

	cout << "Ingrese el nombre" << endl;
	cin >> nombre;

	cout << "Ingrese la fecha" << endl;
	cout << "Dia: ";
	cin >> dia;
	cout << "Mes: ";
	cin >> mes;
	cout << "Anio: ";
	cin >> anio; 
	fecha = new DtFecha(dia, mes, anio);

	cout << "Ingrese la hora" << endl;
	cout << "Hora: ";
	cin >> hora;
	cout << "Minuto: ";
	cin >> minuto;
	cout << "segundo: ";
	cin >> segundo; 
	fechaHora = new DtTimeStamp(fecha, hora, minuto, segundo);

	int idGenerado = 1;
	DtIniciarMonitoreo* inicioClase = new DtIniciarMonitoreo(codigo, nombre, fechaHora, idGenerado); 

	list<string> asignaturas = icinicioclase->asignaturasAsignadas("email del docente de la sesion");
	list<string>::iterator it;
	for(it = asignaturas.begin(); it != asignaturas.end(); it++){
		cout << *it << endl;
	}
	bool deMonitoreo = icinicioclase->selectAsignatura(dynamic_cast<DtIniciarClase*>(inicioClase), "email del docente de la sesion");
	if(deMonitoreo){
		list<string> estudiantesInscriptos = icinicioclase->inscriptosAsignaturas();
		for(it = estudiantesInscriptos.begin(); it != estudiantesInscriptos.end(); it++){
			cout << *it << endl;
		}
		int quiereHabilitar = 0;
		while(quiereHabilitar == 0){
			string estudianteElegido;
			cout << "Habilite un estudiante ingresando el email" << endl;
			cin >> estudianteElegido;
			icinicioclase->habilitar(estudianteElegido);
			
			cout << "Quiere seguir habilitando estudiantes?(0 para confirmar, cualqueir otro numero para cancelar" << endl;
			cin >> quiereHabilitar;
		}
	}

	DtIniciarClaseFull* inicioClaseFull = icinicioclase->datosIngresados();
	cout << inicioClaseFull->getCodigo() << endl;
	cout << inicioClaseFull->getNombre() << endl;
	cout << inicioClaseFull->getFechaHora() << endl;
	cout << inicioClaseFull->getId() << endl;

	int opcion;
	cout << "Desea confirmar el inicio de esta clase(0 para confirmar, cualquier otro numero para cancelar)" << endl;
	cin >> opcion;
	if(opcion == 0)
		icinicioclase->iniciarClase("email del docente de la sesion");
	else
		icinicioclase->cancelar();
}


void cargarDatosDePrueba(){
	
	//CREACION DE PERFILES
	
	//Estudiante 1
	DtPerfil* datosperfil1 = new DtPerfil("juan", "img.jpg", "juan@gmail.com", "123");
	icaltausuario->ingresarDatosPerfil(datosperfil1);
	icaltausuario->ingresarEstudiante("5229001-1");
	icaltausuario->altaUsuario();

	//Docente 1
	DtPerfil* datosperfil2 = new DtPerfil("jose", "img.jpg", "jose@gmail.com", "456");
	icaltausuario->ingresarDatosPerfil(datosperfil2);
	icaltausuario->ingresarDocente("LATUTU");
	icaltausuario->altaUsuario();

	//CREACION DE ASIGNATURAS

	//Asignatura1
	DtInstanciaClase* instanciaClase1 = new DtInstanciaClase(true, false, false);
	DtAsignatura* datosAsignatura1 = new DtAsignatura("Matematica", "mat", instanciaClase1);
	icalta_asignatura->ingresar(datosAsignatura1);
	icalta_asignatura->altaAsignatura();
}

int main(){

	icaltausuario = fab->getCAltaUsuario();
	icinscripcionasignatura = fab->getCInscripcionAsignatura();
	icinicioclase = fab->getCInicioClase();
	icalta_asignatura = fab->getCAltaAsignatura();

    int opcion;
    menu();
    cin >> opcion;

    while(opcion != 11){
        switch(opcion){
            case 1: menuAltaUsuario();
                    break;
            case 2:	menuAltaAsignatura();
                    break;
            case 3:
                    break;
            case 4:
					menuInscripcionAsignatura();
                    break;
            case 5:
					menuInicioClase();
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 8:
                    break;
			case 9:
					break;
			case 10: cargarDatosDePrueba();
					break;
			case 11:
					break;
            default: cout << "Opcion invalida." << endl;
                    break;
        }
        menu();
        cin >> opcion;
    }
     return 0;
}