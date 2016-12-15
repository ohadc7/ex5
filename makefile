a.out: main.o LuxuryCab.o ProgramFlow.o StandardCab.o TaxiCenter.o BfsAlgorithm.h Graph.h Grid.o Node.h Point.o InputParsing.o Trip.o Passenger.o Driver.o Cab.o
	g++ -g -Wall -std=c++0x main.o LuxuryCab.o ProgramFlow.o StandardCab.o TaxiCenter.o BfsAlgorithm.h Graph.h Grid.o Node.h Point.o InputParsing.o Trip.o Passenger.o Cab.o Driver.o

Passenger.o: Grid.cpp Passenger.h
	g++ -g -Wall -c -std=c++0x Passenger.cpp

Driver.o: Driver.cpp Driver.h
	g++ -g -Wall -c -std=c++0x Driver.cpp

InputParsing.o: InputParsing.cpp InputParsing.h
	g++ -g -Wall -c -std=c++0x InputParsing.cpp

LuxuryCab.o: LuxuryCab.cpp LuxuryCab.h
	g++ -g -Wall -c -std=c++0x LuxuryCab.cpp

ProgramFlow.o: ProgramFlow.cpp ProgramFlow.h
	g++ -g -Wall -c -std=c++0x ProgramFlow.cpp

StandardCab.o: StandardCab.cpp StandardCab.h
	g++ -g -Wall -c -std=c++0x StandardCab.cpp

TaxiCenter.o: TaxiCenter.cpp TaxiCenter.h
	g++ -g -Wall -c -std=c++0x TaxiCenter.cpp

Trip.o: Trip.cpp Trip.h
	g++ -g -Wall -c -std=c++0x Trip.cpp

Grid.o: Grid.cpp Grid.h
	g++ -g -Wall -c -std=c++0x Grid.cpp

Cab.o: Cab.cpp Cab.h
	g++ -g -Wall -c -std=c++0x Cab.cpp

Point.o: Point.cpp Point.h
	g++ -g -Wall -c -std=c++0x Point.cpp

main.o: main.cpp
	g++ -g -Wall -c -std=c++0x main.cpp