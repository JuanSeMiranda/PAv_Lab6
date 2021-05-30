main: main.o perfil.o estudiante.o docente.o DtTimeStamp.o DtFecha.o
	g++ main.o perfil.o estudiante.o docente.o DtTimeStamp.o DtFecha.o -g -o sistema
	
main.o: main.cpp
	g++ -g -c main.cpp

perfil.o: perfil.cpp

estudiante.o: estudiante.cpp

docente.o: docente.cpp

DtTimeStamp.o: DtTimeStamp.cpp

DtFecha.o: DtFecha.cpp

clean:
	rm -rf *.o sistema
	clear

