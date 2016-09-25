main: main.o persona.o generarpersona.o
	@echo
	@g++ -o main main.o persona.o generarpersona.o
	@echo El programa se ha compilado correctamente, ejecutar con ./main
	@echo

main.o: main.cpp
	@g++ -c main.cpp

persona.o: persona.cpp persona.hpp
	@g++ -c persona.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp
	@g++ -c generarpersona.cpp

clean:
	@echo
	@rm main *.o
	@echo Se han eliminado los ficheros objetos y el ejecutable
	@echo
