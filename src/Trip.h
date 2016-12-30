#ifndef EX2_TRIP_H
#define EX2_TRIP_H


#include <list>
#include <stack>
#include "Point.h"
#include "Passenger.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/stack.hpp>

class Trip {

private:
    int rideId;
    int passedMeters; //total meters passed at the current point
    Point startingPoint;
    Point endingPoint;
    //stack <Node<Point>> nextPointsOfPath;
    list <Passenger> customers; //passengers
    int numOfPassengers;
    double rateOfTrip; //tariff
public:

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & rideId;
        ar & passedMeters;
        ar & startingPoint;
        ar & endingPoint;
       // ar & nextPointsOfPath;
        ar & customers;
        ar & numOfPassengers;
        ar & rateOfTrip;
    }

    Trip();

    Trip(int rideId, Point startingPoint, Point endingPoint, int numOfPassengers, double taarif);
         //stack <Node<Point>> pathWithoutStartingPoint);

    int getRideId() const;

    int getPassedMeters() const;

    int getNumberOfPassengers() const;

    const Point &getStartingPoint() const;

    const Point &getEndingPoint() const;

    const list <Passenger> &getCustomers() const;

    double getRateOfTrip() const;

  //  const stack<Node<Point>> &getPath() const;

   // void removeNextPointOfPath();

    ~Trip();

};


#endif
