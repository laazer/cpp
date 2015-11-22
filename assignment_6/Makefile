BOOST_INCLUDE=boost

.PHONY: all clean

all: example1 example2

example1: example1.cpp
	g++ -I$(BOOST_INCLUDE) $< -o $@

example2: example2.cpp
	g++ -I$(BOOST_INCLUDE) $< -o $@

clean:
	rm -f example1 example2
