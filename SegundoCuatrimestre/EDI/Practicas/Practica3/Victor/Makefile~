main: mainFile.o dis_Key.o persona.o generarpersona.o
	@echo
	@g++ -o main mainFile.o dis_Key.o persona.o generarpersona.o
	@echo El programa se ha compilado correctamente, ejecutar con ./main
	@echo

mainFile.o: mainFile.cpp
	@g++ -c mainFile.cpp

dis_Key.o: dis_Key.cpp dis_Key.hpp
	@g++ -c dis_Key.cpp

persona.o: persona.cpp persona.hpp
	@g++ -c persona.cpp

generarpersona.o: generarpersona.cpp generarpersona.hpp
	@g++ -c generarpersona.cpp

clean:
	@echo
	@rm main *.o
	@echo Se han eliminado los ficheros objetos, los ficheros de texto y el ejecutable
	@echo
