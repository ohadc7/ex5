#ifndef EX2_STANDARDCAB_H
#define EX2_STANDARDCAB_H

#define SPEED_OF_STANDARD_CAB 1
#define RATE_OF_STANDARD_CAB  100

#include "Cab.h"
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

class StandardCab : public Cab {
private:
    const double speed;
    const double rate;
public:

    friend class boost::serialization::access;


    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & speed;
        ar & rate;
    }

    StandardCab(int id, Model_Of_Car carModel, Color_Of_Car color);

    virtual Taxi_Type getTaxiType();

    double getSpeed() const;

    double getRate() const;

    virtual ~StandardCab();
};


#endif
