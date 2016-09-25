main: persistenciaFichero.o generarpersona.o persona.o edi_LinkedOrderedBinaryTree.o asignatura.o main.o clave.o
	@g++ *.o -o main
	@echo
	@echo Se ha generado el ejecutable correctamente. Ejecutar con ./main
	@echo

main.o: main.cpp
	@g++ -c main.cpp
	@echo creando main.o...

asignatura.o: asignatura.cpp
	@g++ -c asignatura.cpp
	@echo creando asignatura.o...

clave.o: clave.cpp
	@g++ -c clave.cpp
	@echo creando clave.o...

edi_LinkedOrderedBinaryTree.o: edi_LinkedOrderedBinaryTree.cpp
	@g++ -c edi_LinkedOrderedBinaryTree.cpp
	@echo creando edi_LinkedOrderedBinaryTree.o...

persona.o: persona.cpp persona.hpp
	@g++ -c persona.cpp
	@echo creando persona.o...

generarpersona.o: generarpersona.cpp generarpersona.hpp
	@g++ -c generarpersona.cpp
	@echo creando generarpersona.o...

persistenciaFichero.o: persistenciaFichero.cpp persistenciaFichero.hpp
	@g++ -c persistenciaFichero.cpp
	@echo creando persistenciaFichero.o...

clean:
	@rm main *.o
	@echo
	@echo Se ha eliminado el ejecutable y los .o
	@echo

cleanObjetos:
	@rm *.o
	@echo
	@echo Se ha eliminado los .o
	@echo

cleanFicheros:
	@rm *.txt *.idx
	@echo
	@echo Se han eliminado los .txt y los .idx
	@echo

cleanAll:
	@rm main *.o *.txt *.idx
	@echo
	@echo Se han eliminado los .o .txt .idx y el ejecutable
	@echo
