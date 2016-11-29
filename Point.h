#ifndef EX1_VERSION_1_1_POINT_H
#define EX1_VERSION_1_1_POINT_H

#include "Node.h"

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);
    //return the x coordinate of this Point
    int getX();
    //return the y coordinate of this Point
    int getY();
    //return true if this Point is passable.
    // false otherwise (=if there is an obstacle in this Point).
    bool isAvailable();
    //oprator overloading for printing point in the form (x,y)
    friend ostream& operator <<(ostream& os, Point &point);
    //definition of ordering relation between Points in order to enable
    //data structures (like Map) to maintain them efficiently.
    //(the exact ordering relation, that we defined, doesn't matter)
    bool operator<(const Point &other) const;
    //points comparison according to their coordinates
    bool operator==(const Point &other) const;
};

#endif //EX1_VERSION_1_1_POINT_H
