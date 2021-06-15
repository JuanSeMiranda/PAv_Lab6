//Fabrica
#include "Fabrica.h"

//Interfaces
#include "ICAltaUsuario.h"
#include "ICInscripcionAsignatura.h"
#include "ICInicioClase.h"

// DT's
#include "DtPerfil.h"
#include "DtIniciarMonitoreo.h"


#include <iostream>

using namespace std;

Fabrica* fab;
ICAltaUsuario* icaltausuario;
ICInscripcionAsignatura* icinscripcionasignatura;
ICInicioClase* icinicioclase;

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


int main(){

	icaltausuario = fab->getCAltaUsuario();
	icinscripcionasignatura = fab->getCInscripcionAsignatura();
	icinicioclase = fab->getCInicioClase();

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
            default: cout << "Opcion invalida." << endl;
                    break;
        }
        menu();
        cin >> opcion;
    }


     return 0;
}