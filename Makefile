INCLUDE_PATH=-I.
LIB_PATH=-L.

all: doublylinkedlist
	
doublylinkedlist: main
	g++ ${INCLUDE_PATH} Main.o -o doublylinkedlist

main:
	g++ ${INCLUDE_PATH} -c Main.cc

clean:
	rm -rf *.o doublylinkedlist