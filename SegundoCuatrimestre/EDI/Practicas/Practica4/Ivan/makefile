OBJECTS = main.o graph_matrix.o algoritmos.o entrada_salida.o
CPPFLAGS = -c -g -ansi -std=c++11

main: $(OBJECTS)
	g++ $(OBJECTS) -o main

graph_matrix.o: graph_matrix.cpp graph_matrix.hpp
	@g++ $(CPPFLAGS) graph_matrix.cpp

main.o: main.cpp
	@g++ $(CPPFLAGS) main.cpp

algoritmos.o: algoritmos.cpp algoritmos.cpp
	@g++ $(CPPFLAGS) algoritmos.cpp

entrada_salida.o: entrada_salida.cpp entrada_salida.hpp
	@g++ $(CPPFLAGS) entrada_salida.cpp

clean:
	@rm $(OBJECTS) main
