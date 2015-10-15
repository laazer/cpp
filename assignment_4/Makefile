HEADERS = Circle.hpp IShape.hpp Matrix.hpp Triangle.hpp Vector.hpp
OBJECTS = Circle.o   IShape.o   Matrix.o   Triangle.o   Vector.o   main.o

.PHONY: all clean

all: main

main: $(OBJECTS)
	g++ $^ -o main

%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@

vector: Vector.cpp Vector.hpp
	g++ Vector.cpp -o vector

matrix: Vector.cpp Matrix.cpp  Vector.o Matrix.o
	g++ -Wall -c Vector.cpp  Matrix.cpp
	g++ -c Vector.o Matrix.o -o matrix

clean:
	rm -f $(OBJECTS) main vector matrix
