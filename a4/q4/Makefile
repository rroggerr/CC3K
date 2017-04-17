CXX = g++
OBJECTS = main.o decorator.o textprocess.o echo.o swapcase.o doublevowels.o skipword.o translate.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q4

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean:
