main: main.o subject.o persona.o generarpersona.o functions.o key.o
	g++ main.o subject.o persona.o generarpersona.o functions.o key.o -o main -g

key.o: key.cpp key.hpp
	@g++ -c key.cpp

main.o: main.cpp
	@g++ -c main.cpp -std=c++11

subject.o: subject.cpp subject.hpp
	@g++ -c subject.cpp

persona.o: persona.cpp persona.hpp
	@g++ -c persona.cpp

functions.o: functions.cpp functions.hpp
	@g++ -c functions.cpp -std=c++11

generarpersona.o: generarpersona.cpp generarpersona.hpp
	@g++ -c generarpersona.cpp

clean:
	@rm *.o main
