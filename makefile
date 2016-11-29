a.out: main.o BfsAlgorithm.h Graph.h Grid.o Node.h Point.o InputParsing.o
	g++ -g -Wall -std=c++0x main.o BfsAlgorithm.h Graph.h Grid.o Node.h Point.o InputParsing.o -o bfs.out
Grid.o: Grid.cpp Grid.h
	g++ -g -Wall -c -std=c++0x Grid.cpp
Node.o: Node.h
	g++ -g -Wall -c -std=c++0x Node.h
InputParsing.o: InputParsing.cpp InputParsing.h
	g++ -g -Wall -c -std=c++0x InputParsing.cpp
Point.o: Point.cpp Point.h
	g++ -g -Wall -c -std=c++0x Point.cpp
main.o: main.cpp
	g++ -g -Wall -c -std=c++0x main.cpp
