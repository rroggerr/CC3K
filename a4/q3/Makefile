a4q3: a4q3.o grid.o cell.o textdisplay.o window.o
	g++ a4q3.o grid.o cell.o textdisplay.o window.o -o a4q3 -lX11
a4q3.o: a4q3.cc	grid.h
	g++ -c a4q3.cc
grid.o: grid.cc cell.h textdisplay.h window.h
	g++ -c grid.cc
cell.o: cell.h cell.cc window.h
	g++ -c cell.cc
textdisplay.o: textdisplay.h textdisplay.cc
	g++ -c textdisplay.cc
window.o: window.h window.cc
	g++ -c window.cc
.PHONY: clean
clear:
	rm *.o a4q3
