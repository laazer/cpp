.PHONY: all clean

all: words_main

words_main: words_main.cpp words.cpp words.hpp
	g++ words_main.cpp words.cpp -g -o words_main
	
words: words.cpp
	g++ words.cpp -Wall -g -o words

clean:
	rm -f words_main
