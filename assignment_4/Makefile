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

clean:
	rm -f $(OBJECTS) main vector
