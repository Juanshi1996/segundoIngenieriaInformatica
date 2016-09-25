OBJECTS = graph_matrix.o algoritmos.o entrada_salida.o main.o
CPPFLAGS = -c -g -ansi -Wall

main: $(OBJECTS)
	@g++ $(OBJECTS) -o main
	@echo
	@echo Se ha generado el ejecutable correctamente. Ejecutar con ./main
	@echo

main.o: main.cpp
	@g++ $(CPPFLAGS) main.cpp
	@echo creando main.o...

entrada_salida.o: entrada_salida.cpp
	@g++ $(CPPFLAGS) entrada_salida.cpp
	@echo creando entrada_salida.o...

algoritmos.o: algoritmos.cpp
	@g++ $(CPPFLAGS) algoritmos.cpp
	@echo creando algoritmos.o...

graph_matrix.o: graph_matrix.cpp
	@g++ $(CPPFLAGS) graph_matrix.cpp
	@echo creando graph_matrix.o...

clean:
	@rm $(OBJECTS) main
	@echo
	@echo Se ha eliminado el ejecutable y los .o
	@echo

cleanObjetos:
	@rm $(OBJECTS)
	@echo
	@echo Se ha eliminado los .o
	@echo