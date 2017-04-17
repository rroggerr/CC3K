CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o pizza.o crustandsauce.o topping.o dippingsauce.o stuffedcrust.o decorator.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
