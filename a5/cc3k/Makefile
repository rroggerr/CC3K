CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = cell.o character.o dungeon.o enemy.o gold.o item.o main.o player.o potion.o tile.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k 

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}