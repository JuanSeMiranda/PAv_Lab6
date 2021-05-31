main: main.o perfil.o estudiante.o docente.o DtTimeStamp.o DtFecha.o DtLog.o rol.o Participacion.o Practico.o clase.o Asignatura.o AsisteEnVivo.o
	g++ main.o perfil.o estudiante.o docente.o DtTimeStamp.o DtFecha.o DtLog.o rol.o Participacion.o Practico.o clase.o Asignatura.o AsisteEnVivo.o -g -o sistema
	
main.o: main.cpp
	g++ -g -c main.cpp

perfil.o: perfil.cpp
	g++ -g -c perfil.cpp

estudiante.o: estudiante.cpp
	g++ -g -c estudiante.cpp

docente.o: docente.cpp
	g++ -g -c docente.cpp

DtTimeStamp.o: DtTimeStamp.cpp
	g++ -g -c DtTimeStamp.cpp

DtFecha.o: DtFecha.cpp
	g++ -g -c DtFecha.cpp

DtLog.o: DtLog.cpp
	g++ -g -c DtLog.cpp

rol.o: rol.cpp
	g++ -g -c rol.cpp

Participacion.o: Participacion.cpp
	g++ -g -c Participacion.cpp

Practico.o: Practico.cpp
	g++ -g -c Practico.cpp

clase.o: clase.cpp
	g++ -g -c clase.cpp

Asignatura.o: Asignatura.cpp
	g++ -g -c Asignatura.cpp

AsisteEnVivo.o: AsisteEnVivo.cpp
	g++ -g -c AsisteEnVivo.cpp

clean:
	rm -rf *.o sistema
	clear
