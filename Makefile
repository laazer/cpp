all: fizzbuzz

fizzbuzz: fizzbuzz.cpp
	g++ scrap.cpp -o scrap

clean:
	rm -f scrap
