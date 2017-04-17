CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o abstractbook.o book.o csbook.o comicbook.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
