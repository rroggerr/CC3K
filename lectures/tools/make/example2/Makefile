main: main.o book.o csbook.o comicbook.o
	g++ main.o book.o csbook.o comicbook.o -o main

main.o: main.cc book.h csbook.h comicbook.h
	g++ -c main.cc

book.o: book.h book.cc
	g++ -c book.cc

csbook.o: csbook.h csbook.cc book.h
	g++ -c csbook.cc

comicbook.o: comicbook.h comicbook.cc book.h
	g++ -c comicbook.cc

.PHONY: clean

clean:
	rm *.o main
