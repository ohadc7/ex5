a.out: main.o LuxuryCab.o ProgramFlow.o StandardCab.o TaxiCenter.o BfsAlgorithm.h Graph.h Grid.o Node.h Point.o InputParsing.o Trip.o Passenger.o Driver.o Cab.o Udp.o Socket.o
	g++ -g -Wall -std=c++0x -lboost_serialization main.o LuxuryCab.o ProgramFlow.o StandardCab.o TaxiCenter.o BfsAlgorithm.h Graph.h Grid.o Node.h Point.o InputParsing.o Trip.o Passenger.o Cab.o Driver.o Udp.o Socket.o

Udp.o: Udp.cpp Udp.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Udp.cpp

Socket.o: Socket.cpp Socket.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Socket.cpp

Passenger.o: Grid.cpp Passenger.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Passenger.cpp

Driver.o: Driver.cpp Driver.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Driver.cpp

InputParsing.o: InputParsing.cpp InputParsing.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization InputParsing.cpp

LuxuryCab.o: LuxuryCab.cpp LuxuryCab.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization LuxuryCab.cpp

ProgramFlow.o: ProgramFlow.cpp ProgramFlow.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization ProgramFlow.cpp

StandardCab.o: StandardCab.cpp StandardCab.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization StandardCab.cpp

TaxiCenter.o: TaxiCenter.cpp TaxiCenter.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization TaxiCenter.cpp

Trip.o: Trip.cpp Trip.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Trip.cpp

Grid.o: Grid.cpp Grid.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Grid.cpp

Cab.o: Cab.cpp Cab.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Cab.cpp

Point.o: Point.cpp Point.h
	g++ -g -Wall -c -std=c++0x -lboost_serialization Point.cpp

main.o: main.cpp
	g++ -g -Wall -c -std=c++0x -lboost_serialization main.cpp
