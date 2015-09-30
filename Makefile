all: scrap

scrap: scrap.cpp
	g++ scrap.cpp -o scrap

clean:
	rm -f scrap
