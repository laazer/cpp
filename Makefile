all: scrap

scrap: scrap.cpp
	g++ scrap.cpp -g -o scrap

clean:
	rm -f scrap
