#include<iostream>

using namespace std;

void menu(){
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Asignaciin de docentes a una asignatura:" << endl;
    cout << "3. Inscripciin a las asignaturas" << endl;
    cout << "4. Inicio de clase" << endl;
    cout << "5. Asistencia a clase en vivo" << endl;
    cout << "6. Envio de mensaje" << endl;
    cout << "7. Eliminacion de asignatura" << endl;
    cout << "8. Listado de Clases" << endl;
    cout << "9. Salir" << endl;
}

int main(){

    int opcion;
    menu();
    cin >> opcion;

    while(opcion != 9){
        switch(opcion){
            case 1:
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