gcc_options = -std=c++14 -Wall --pedatic-error


run: main 
	./main

main: main.cpp all.h 


.PHONY: run build