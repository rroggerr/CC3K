CXX = g++
CXXFLAGS = -Wall

main: main.o book.o csbook.o comicbook.o
	${CXX} ${CXXFLAGS} main.o book.o csbook.o comicbook.o -o main

main.o: main.cc book.h csbook.h comicbook.h
	${CXX} ${CXXFLAGS} -c main.cc

book.o: book.h book.cc
	${CXX} ${CXXFLAGS} -c book.cc

csbook.o: csbook.h csbook.cc book.h
	${CXX} ${CXXFLAGS} -c csbook.cc

comicbook.o: comicbook.h comicbook.cc book.h
	${CXX} ${CXXFLAGS} -c comicbook.cc

.PHONY: clean

clean:
	rm *.o main
