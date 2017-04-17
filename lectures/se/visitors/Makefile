CXX = g++
CXXFLAGS = -Wall
EXEC = main
OBJECTS = main.o book.o csbook.o comicbook.o BookVisitor.o catalogue.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

main.o: main.cc book.h csbook.h comicbook.h

book.o: book.h book.cc

csbook.o: csbook.h csbook.cc book.h

comicbook.o: comicbook.h comicbook.cc book.h

clean:
	rm ${OBJECTS} ${EXEC}
