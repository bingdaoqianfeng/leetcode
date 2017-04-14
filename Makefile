objects = main.o 
test : $(objects)
	g++ -o test $(objects)

main.o : main.cpp
	g++ -c main.cpp

clean:
	rm test $(objects)
