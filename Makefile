CPP = g++
CC = g++
OBJECTS = main.o
CFLAGS+= -g


all : $(OBJECTS)
	$(CPP) -o test $(OBJECTS)


sources = main.cpp
include $(sources:.cpp=.d)

%.d: %.cpp
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


clean:
	rm test $(OBJECTS)
