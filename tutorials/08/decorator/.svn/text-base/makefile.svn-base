CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = main.o plaintaco.o topping.o lettuce.o greekyogurt.o guac.o beef.o cheese.o sourcream.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = tacos 

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
