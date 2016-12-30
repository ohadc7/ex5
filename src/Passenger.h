
#ifndef EX1_VERSION_1_1_PASSENGER_H
#define EX1_VERSION_1_1_PASSENGER_H


#include "Point.h"
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

class Passenger {
private:
    Point source;
    Point destination;
    bool isLuxury;

public:


    friend class boost::serialization::access;


    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & source;
        ar & destination;
        ar & isLuxury;
    }

    Passenger();
    
    Passenger(Point source, Point destination, bool isLuxury);

    int getSatisfaction() const;

    bool getIsLuxury();

    int giveFeedBack();
};


#endif
