CXXFLAGS += #-Wall -Wextra
CPPFLAGS += -c -ansi -std=c++11
DEBUG = -g
OBJECTS = main.o algoritmos.o entrada_salida.o graph_matrix.o

all: main

main: $(OBJECTS)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(OBJECTS) -o $@

main.o: main.cpp
	$(CXX) $(DEBUG) $(CXXFLAGS) $(CPPFLAGS) $^

algoritmos.o: algoritmos.cpp
	$(CXX) $(DEBUG) $(CXXFLAGS) $(CPPFLAGS) $^

entrada_salida.o: entrada_salida.cpp
	$(CXX) $(DEBUG) $(CXXFLAGS) $(CPPFLAGS) $^

graph_matrix.o: graph_matrix.cpp
	$(CXX) $(DEBUG) $(CXXFLAGS) $(CPPFLAGS) $^

clean:
	$(RM) $(OBJECTS) monserrat_villatoro_victor_EDIJun1415P4.tar.gz *~ main

dist:
	tar zcvf monserrat_villatoro_victor_EDIJun1415P4.tar.gz *.cpp *.hpp *.txt Makefile
