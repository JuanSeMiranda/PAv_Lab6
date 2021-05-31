main: main.o Perfil.o Estudiante.o Docente.o DtTimeStamp.o DtFecha.o DtLog.o Rol.o Participacion.o Practico.o Teorico.o Monitoreo.o Clase.o Asignatura.o AsisteEnVivo.o AsisteDiferido.o 
	g++ main.o Perfil.o Estudiante.o Docente.o DtTimeStamp.o DtFecha.o DtLog.o Rol.o Participacion.o Practico.o Teorico.o Monitoreo.o Clase.o Asignatura.o AsisteEnVivo.o AsisteDiferido.o -g -o sistema
	
main.o: main.cpp
	g++ -g -c main.cpp

Perfil.o: Perfil.cpp
	g++ -g -c Perfil.cpp

Estudiante.o: Estudiante.cpp
	g++ -g -c Estudiante.cpp

Docente.o: Docente.cpp
	g++ -g -c Docente.cpp

DtTimeStamp.o: DtTimeStamp.cpp
	g++ -g -c DtTimeStamp.cpp

DtFecha.o: DtFecha.cpp
	g++ -g -c DtFecha.cpp

DtLog.o: DtLog.cpp
	g++ -g -c DtLog.cpp

Rol.o: Rol.cpp
	g++ -g -c Rol.cpp

Participacion.o: Participacion.cpp
	g++ -g -c Participacion.cpp

Practico.o: Practico.cpp
	g++ -g -c Practico.cpp

Teorico.o: Teorico.cpp
	g++ -g -c Teorico.cpp

Monitoreo.o: Monitoreo.cpp
	g++ -g -c Monitoreo.cpp

Clase.o: Clase.cpp
	g++ -g -c Clase.cpp

Asignatura.o: Asignatura.cpp
	g++ -g -c Asignatura.cpp

AsisteEnVivo.o: AsisteEnVivo.cpp
	g++ -g -c AsisteEnVivo.cpp

AsisteDiferido.o: AsisteDiferido.cpp
	g++ -g -c AsisteDiferido.cpp

clean:
	rm -rf *.o sistema
	clear
