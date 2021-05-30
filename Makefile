main: main.o
	g++ main.o -g -o sistema
	
main.o: main.cpp
	g++ -g -c main.cpp

clean:
	rm -rf *.o sistema
	clear

